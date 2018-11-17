#include "tabela.h"

int add_tabela(){
	char nome[60], trash;

	// pegar o nome da nova tabela
	limpar();
	printf("Nome da tabela (letras e numeros): ");
	scanf("%s", nome);	
	int size = strlen(nome);
	
	// verificar se o nome não possui caracteres especiais
	for(int i=0; i<size; i++){
		if((nome[i] < '0' || nome[i] > '9') && 
		(nome[i] < 'a' || nome[i] > 'z') && 
		(nome[i] < 'A' || nome[i] > 'Z')){
			mostrar_erro(001);
			return 0;
		}
	}

	// verificar se a tabela já existe
	strcat(nome, ".txt");
	if(verificar_existencia(nome) == 1){
		mostrar_erro(003);
		return 0;
	}
	// caso retorne erro
	else if(verificar_existencia(nome) == 2){
		return 0;
	}

	// criando um novo arquivo
	FILE * arq = fopen(nome, "w");
	if(arq == NULL){
		mostrar_erro(005);
		return 0;
	}
	fclose(arq);

	// adicionando tabela no tabelas.txt
	arq = fopen("tabelas.txt", "a");
	if(arq == NULL){
		mostrar_erro(004);
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
	int op = menu_addcoluna();
	while(op != 0){
		add_coluna(nome);
		op = menu_addcoluna();
	}

	return 0;
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
		mostrar_erro(006);
		return 0;
	} 
	// caso retorne erro
	else if(verificar_existencia(nome) == 2)
		return 0;

	// deletando do tabelas.txt
	char swap[60];
	FILE *aux = fopen("auxiliar.txt", "w");
	if(aux == NULL){
		mostrar_erro(007);
		return 0;
	}
	FILE *arq = fopen("tabelas.txt", "r");
	if(arq == NULL){
		mostrar_erro(004);
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
		mostrar_erro(004);
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
		mostrar_erro(004);
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
