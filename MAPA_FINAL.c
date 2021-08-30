#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define TAM 5

typedef struct dados {
	int RA_Aluno;
	char nome_arq[20];
	char ext_arq[20];
	int matricula_prof;
}dados;

typedef struct fila{
	int inicio;
	int final;
	int cont;
	dados atividade[TAM];
}fila;

void esvazia();
void enfileira();
void desenfileira();

int menu(int *op,fila *p_fila){
	system("color 0A");
	int valor,i;
	setlocale(LC_ALL, "Portuguese");
	printf("\t\t=======================================\n");
	printf("\t\t    LISTA DE CORREÇÃO DE ATIVIDADES    \n");
	printf("\t\t=======================================\n\n");
	if(p_fila->final==0){
		printf("Seja Bem Vindo.\n\n");
	}else{
		for(i=0;i<p_fila->final;i++){
			printf("===================================\n");
			printf("| ");
			printf("R.A do Aluno: %d \n", p_fila->atividade[i].RA_Aluno);
			
			printf("| ");
			printf("Nome do Arquivo: %s \n", p_fila->atividade[i].nome_arq);
			
			printf("| ");
			printf("Extensão do Aquivo: %s \n", p_fila->atividade[i].ext_arq);
			
			printf("| ");
			printf("Matricula do Professor: %d \n", p_fila->atividade[i].matricula_prof);
				
			printf("===================================");
			printf("\n\n");
		};
	}
	
	printf("====================================\n");
	printf("| ");
	printf("1 - Inserir um Elemento na Fila");
	printf("  |\n");
	printf("| ");
	printf("2 - Remover um Elemento da Fila");
	printf("  |\n");
	printf("| ");
	printf("3 - Esvaziar a Fila");
	printf("              |\n");
	printf("| ");
	printf("0 - Sair");
	printf("                         |\n");
	printf("====================================\n\n");
	
	printf("OPÇÃO: ");
	
	scanf("%d",&valor);
	*op = valor;	
	return(op);
};

int main(){	
	setlocale(LC_ALL, "Portuguese");
	int op;

	fila fla;
	fla.inicio=0;
	fla.final=0;
	fla.cont = 0;
	fila *p_fila = &fla;	
	
	p_fila->inicio = 0;
	
	while(menu(&op,p_fila)!= 0){					
		switch (op)
		{		
			case 1:
				enfileira(p_fila);
			break;
			case 2:
				desenfileira(p_fila);
			break;
			case 3:
				esvazia(p_fila);
			break;
			case 0:
				printf(" \nVocê saiu do sistema!");
			exit(0);			
			break;
			default:
				printf("Numero invalido\n");
				system("pause");
				system("cls");
			break;
			
		};	
	};
	
	return(0);
};

void enfileira(fila *p_fila){	
	if(p_fila->final==TAM){
		printf("Fila cheia.\n");
		system("pause");
	}else{
		printf("R.A do Aluno: ");
		scanf("%d", &p_fila->atividade[p_fila->final].RA_Aluno);
		fflush(stdin);
		printf("Nome do Arquivo: ");
		gets(p_fila->atividade[p_fila->final].nome_arq);
		fflush(stdin);
		printf("Extensão do Arquivo: ");
		gets(p_fila->atividade[p_fila->final].ext_arq);
		fflush(stdin);
		printf("Matricula do Professor: ");
		scanf("%d", &p_fila->atividade[p_fila->final].matricula_prof);
		fflush(stdin);
				
		p_fila->final = p_fila->final+1;
		system("cls");				
	};	
};

void desenfileira(fila *p_fila){	
		int i;
		if(p_fila->inicio==p_fila->final){
		printf("Fila Vazia!\nNão é Possivel Remover!!\n.");
		system("pause");
		system("cls");
		}else{
			printf("\nESSE REGISTRO FOI REMOVIDO DA LISTA!!\n");
			printf("R.A do Aluno: %d\n", p_fila->atividade[p_fila->inicio].RA_Aluno);
			printf("Nome do Arquivo: %s\n", p_fila->atividade[p_fila->inicio].nome_arq);
			printf("Extensão do Arquivo: %s\n", p_fila->atividade[p_fila->inicio].ext_arq);	
			printf("Matricula do Professor: %d\n", p_fila->atividade[p_fila->inicio].matricula_prof);	
			printf("--------------------------------");
			printf("\n\n");
			system("pause");
			for(i=0;i<p_fila->final;i++){
				p_fila->atividade[i].RA_Aluno = p_fila->atividade[i+1].RA_Aluno;
				p_fila->atividade[i].matricula_prof =  p_fila->atividade[i+1].matricula_prof;
				strcpy(p_fila->atividade[i].nome_arq,p_fila->atividade[i+1].nome_arq);
				strcpy(p_fila->atividade[i].ext_arq , p_fila->atividade[i+1].ext_arq);	
			}
		
		p_fila->final = p_fila->final-1;
		system("cls");	
	}
}

void esvazia(fila *p_fila){	
	int inicio = 0;
	int final = 0;
	if(p_fila->inicio == final && p_fila->final == inicio ){
		printf("Fila Vazia!\n");
		system("pause");
		system("cls");	
	}else{	
		p_fila->inicio = inicio;
		p_fila->final = final;
		printf("Fila esvaziada com SUCESSO!\n");
		system("pause");
		system("cls");
	}
}

