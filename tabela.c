#include "tabela.h"

int add_tabela(){
	char nome[60], trash;

	limpar();
	printf("Nome da tabela (letras e numeros): ");
	scanf("%s", nome);
	int size = strlen(nome);
	
	for(int i=0; i<size; i++){ // tratando o nome
		if((nome[i] < '0' || nome[i] > '9') && 
		(nome[i] < 'a' || nome[i] > 'z') && 
		(nome[i] < 'A' || nome[i] > 'Z')){
			limpar();
			printf("Erro 001 - nome inválido\n");
			printf("Aperte ENTER para voltar\n");
			getchar();
			scanf("%c", &trash);
			limpar();
			return 0;
		}
	}

	limpar();
	printf("Tabela criada com sucesso!\n");
	printf("Aperte ENTER para voltar\n");
	getchar();
	scanf("%c", &trash);
	limpar();

	strcat(nome, ".txt");
	FILE * arq = fopen(nome, "w");
	fclose(arq);
	//adicionar colunas
	int op = menu_addcoluna();
	while(op != 0){
		
		add_coluna(nome);
		op = menu_addcoluna();
	}
}

int add_coluna(char nome[60]){
	char titulo[60], tipo[60];
	int chave=0, op;
	printf("Nome da coluna: ");
	scanf("%s", titulo);
	op = menu_tipo();
	// TODO: add chave primaria

	FILE * arq = fopen(nome, "w");

	fclose(arq);
}