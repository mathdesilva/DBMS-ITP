#include "tabela.h"

int add_tabela(){
	char nome[60], trash;

	// pegar o nome da nova tabela
	limpar();
	printf("Nome da tabela (letras e numeros): ");
	scanf("%s", nome);	
	
	// verificar se o nome não possui caracteres especiais
	if(verificar_nome(nome) == 0)
		return 0;

	// verificar se a tabela já existe
	strcat(nome, ".txt");
	if(verificar_existencia(nome) == 1){
		mostrar_erro(3);
		return 0;
	}
	// caso retorne erro
	else if(verificar_existencia(nome) == 2){
		return 0;
	}

	// criando um novo arquivo
	FILE * arq = fopen(nome, "w");
	if(arq == NULL){
		mostrar_erro(5);
		return 0;
	}
	fclose(arq);

	// adicionando tabela no tabelas.txt
	arq = fopen("tabelas.txt", "a");
	if(arq == NULL){
		mostrar_erro(4);
		return 0;
	}
	fprintf(arq, "%s\n", nome);
	fclose(arq);

	// mensagem de tabela criada com sucesso
	limpar();
	printf("Tabela criada com sucesso!\n");
	printf("Aperte ENTER para voltar\n");
	getchar();
	scanf("%c", &trash);
	limpar();

	//adicionar colunas
	arq = fopen(nome, "wr");
	if(arq == NULL){
		mostrar_erro(6);
		return 0;
	}
	FILE * aux = NULL;
	do{
		aux = fopen("auxiliar2.txt", "w");
	}while(aux == NULL);
	fclose(aux);
	int op = 1, chave = 0;
	while(op != 0){
		if(add_coluna(arq, chave) == 1)
			chave = 1;
		op = menu_addcoluna();
		if(op == 0 && chave == 0){
			op = 1;
			mostrar_erro(8);
		}
	}
	fprintf(arq, "\n");
	fclose(arq);
	remove("auxiliar2.txt");

	return 0;
}

int add_coluna(FILE * arquivo, int chave_adicionada){
	char titulo[60], trash;
	int chave=0, op;
	
	// pegando nome da coluna
	printf("======= ADD COLUNA =======\n");
	printf("Nome da coluna: ");
	scanf("%s", titulo);

	// verificar se o nome não possui caracteres especiais
	if(verificar_nome(titulo) == 0)
		return 0;

	// TODO: verificando se a coluna já existe
	FILE * aux = fopen("auxiliar2.txt", "r");
	char cmp_titulo[60];
	while(fscanf(aux, "%s", cmp_titulo) != EOF){
		if(strcmp(cmp_titulo, titulo) == 0){
			mostrar_erro(9);
			return 0;
		}
	}
	fclose(aux);
	aux = fopen("auxiliar2.txt", "a");
	fprintf(aux, "%s\n", titulo);
	fclose(aux);

	// pegando o tipo da coluna
	op = menu_tipo();

	// pegando chave primária
	if(op == 3 && chave_adicionada == 0)
		chave = menu_chaveprimaria();

	// mensagem de coluna adicionada com sucesso
	printf("Coluna adicionada com sucesso\n");
	printf("Aperte ENTER para voltar\n");
	getchar();
	scanf("%c", &trash);
	limpar();

	// adicionando informações na tabela
	if(chave == 1){
		fprintf(arquivo, "*%s %d ", titulo, op);
		return 1;
	}
	else{
		fprintf(arquivo, "%s %d ", titulo, op);
		return 0;
	}
}

int del_tabela(){
	char nome[60], trash;

	//listar todas as tabelas existentes
 	if(listar_tabelas() == 2)
		return 0;

	// pegar a tabela a ser deletada
	printf("escreva o nome da tabela para ser deletada: ");
	scanf("%s", nome);
	strcat(nome, ".txt");

	// verificar existencia da tabela
	if(verificar_existencia(nome) == 0){
		mostrar_erro(6);
		return 0;
	} 
	// caso retorne erro
	else if(verificar_existencia(nome) == 2)
		return 0;

	// deletando do tabelas.txt
	char swap[60];
	FILE *aux = fopen("auxiliar.txt", "w");
	if(aux == NULL){
		mostrar_erro(7);
		return 0;
	}
	FILE *arq = fopen("tabelas.txt", "r");
	if(arq == NULL){
		mostrar_erro(4);
		remove("auxiliar.txt");
		return 0;
	}
	while(fscanf(arq, "%s", swap) != EOF){
		if(strcmp(nome, swap) != 0)
			fprintf(aux, "%s\n", swap);
	}
	fclose(aux);
	fclose(arq);
	remove("tabelas.txt");
	rename("auxiliar.txt", "tabelas.txt");

	// deletando tabela
	remove(nome);

	limpar();
	printf("tabela deletada com sucesso\n");
	printf("Aperte ENTER para voltar\n");
	getchar();
	scanf("%c", &trash);
	limpar();
}

int listar_todas_tabelas(){
	char trash;
	limpar();
	listar_tabelas();
	printf("Aperte ENTER para voltar\n");
	getchar();
	scanf("%c", &trash);
	limpar();
}

int listar_tabelas(){
	FILE *arq = fopen("tabelas.txt", "r");
	char nome[60];
	int tamanho;
	if(arq == NULL){
		mostrar_erro(4);
		return 2;
	}

	printf("======= TABELAS =======\n");
	while(fscanf(arq, "%s", nome) != EOF){
		tamanho = strlen(nome);
		char saida[60] = "";
		strncpy(saida, nome, tamanho - 4);
		printf("  - %s\n", saida);
	}

	fclose(arq);
}

int verificar_existencia(char nome[60]){
	FILE *arq = fopen("tabelas.txt", "r");
	char trash;
	if(arq == NULL){
		mostrar_erro(4);
		return 2;
	}
	char arquivo[60];
	while(fscanf(arq, "%s", arquivo) != EOF){
		if(strcmp(arquivo, nome) == 0){
			fclose(arq);
			return 1;
		}
	}
	fclose(arq);
	return 0;
}
