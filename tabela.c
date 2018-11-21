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
	fprintf(arq, "|\n");
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

int add_linha(){
	char nome[60];

	// pegar o nome da tabela
	listar_tabelas();
	printf("Digite o nome da tabela: ");
	scanf("%s", nome);
	strcat(nome, ".txt");

	// verificar se o arquivo existe
	if(verificar_existencia(nome) == 0){
		mostrar_erro(6);
		return 0;
	}
	else if(verificar_existencia(nome) == 2)
		return 0;

	// pegar posição da coluna da cheva primária
	int col_chavePrimaria = pegar_chave_primaria(nome);
	if(col_chavePrimaria == -1)
		return 0;

	// pegar número de colunas da tabela
	int num_col = num_colunas(nome);
	if(num_col == -1)
		return 0;

	// pegar valor da chave primária
	char chavep[60];
	int num_aux;
	FILE * arq = fopen(nome, "r");
	if(arq == NULL){
		mostrar_erro(10);
		return 0;
	}
	for(int i=0; i<col_chavePrimaria; i++)
		fscanf(arq, "%s %d", chavep, &num_aux);
	chavep[0] = ' ';
	limpar();
	printf("Digite o valor de%s (int): ", chavep);
	scanf("%s", chavep);
	if(verificar_valor(chavep, 3) == 0)
		return 0;

	// validar chave primária
	char valor[60];
	rewind(arq);
	for(int i=0; i<(2*num_col)+col_chavePrimaria; i++)
		fscanf(arq, "%s", valor);
	while(fscanf(arq, "%s", valor) != EOF){
		if(strcmp(valor, chavep) == 0){
			mostrar_erro(12);
			return 0;
		}
		for(int i=0; i<num_col-1; i++)
			fscanf(arq, "%s", valor);
	}
	
	// criar arquivo auxiliar e passando os nomes das colunas
	rewind(arq);
	FILE * arq_aux = fopen("auxiliar3.txt", "w");
	if(arq_aux == NULL){
		mostrar_erro(5);
		return 0;
	}
	for(int i=0; i<num_col*2; i++){
		fscanf(arq, "%s", valor);
		fprintf(arq_aux, "%s ", valor);
	}
	fclose(arq_aux);
	fclose(arq);

	// pegando os valores da linha e colocando em buffer.txt
	int numtipo;
	char coluna[60];
	arq_aux = fopen("auxiliar3.txt", "r");
	if(arq_aux == NULL){
		mostrar_erro(10);
		return 0;
	}
	arq = fopen("buffer.txt", "w");
	if(arq == NULL){
		mostrar_erro(10);
		remove("auxiliar3.txt");
		return 0;
	}
	for(int i=0; i<num_col; i++){
		if(i == (col_chavePrimaria-1)){
			fscanf(arq_aux, "%s %d", coluna, &numtipo);
			fprintf(arq, "%s ", chavep);
		}
		else{
			fscanf(arq_aux, "%s %d", coluna, &numtipo);
			printf("Digite o valor de %s (%s): ", coluna, tipo(numtipo));
			scanf("%s", valor);
			if(verificar_valor(valor, numtipo) == 0){
				fclose(arq);
				fclose(arq_aux);
				remove("buffer.txt");
				remove("auxiliar3.txt");
				return 0;
			}
			fprintf(arq, "%s ", valor);
		}
	}
	fclose(arq);
	fclose(arq_aux);
	remove("auxiliar3.txt");
	
	// pega os valores de buffer.txt e coloca na tabela
	arq = fopen(nome, "a");
	if(arq == NULL){
		mostrar_erro(10);
		return 0;
	}
	arq_aux = fopen("buffer.txt", "r");
	if(arq_aux == NULL){
		mostrar_erro(10);
		fclose(arq);
		return 0;
	}
	while(fscanf(arq_aux, "%s", valor) != EOF)
		fprintf(arq, "%s ", valor);
	fprintf(arq, "\n");
	fclose(arq);
	fclose(arq_aux);
	remove("buffer.txt");

	return 0;
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

	int size = strlen(nome);
	if(nome[size-4] != '.')
		strcat(nome, ".txt");

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

int pegar_chave_primaria(char nome[60]){
	char coluna[60];
	int counter = 0, aux;

	// abrindo arquivo
	FILE * arq = fopen(nome, "r");
	if(arq == NULL){
		mostrar_erro(10);
		return -1;
	}

	// procurando chave primaria
	while(fscanf(arq, "%s %d", coluna, &aux) != EOF){
		if(coluna[0] == '*'){
			fclose(arq);
			return counter+1;
		}
		else
			counter++;
	}

	// caso não ache a chave primaria
	fclose(arq);
	mostrar_erro(11);
	return -1;
}

int num_colunas(char nome[60]){
	char valor[60];
	int counter = 0, aux;

	// abrindo o arquivo
	FILE * arq = fopen(nome, "r");
	if(arq == NULL){
		mostrar_erro(10);
		return -1;
	}

	// contando o número de colunas
	while(fscanf(arq, "%s", valor) != EOF && strcmp(valor, "|") != 0){
		counter++;
		fscanf(arq, "%d", &aux);
	}

	// fechando arquivo e retornando resultado
	fclose(arq);
	return counter;
}
