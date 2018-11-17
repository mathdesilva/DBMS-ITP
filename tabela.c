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
	if(verificar_existencia(nome) == 1){
		mostrar_erro(003);
		return 0;
	}
	// caso retorne erro
	else if(verificar_existencia(nome) == 2){
		return 0;
	}

	// criando um novo arquivo
	strcat(nome, ".txt");
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
