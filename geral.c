#include "geral.h"

void mostrar_erro(int codigo){
	char trash;
	limpar();

	switch(codigo){
		case 1:
			fprintf(stderr, "Erro 1: nome inválido\n");
			break;
		case 2:
			fprintf(stderr, "Erro 2: opção inválida\n");
			break;
		case 3:
			fprintf(stderr, "Erro 3: tabela já existente\n");
			break;
		case 4:
			fprintf(stderr, "Erro 4: arquivo tabelas.txt não encontrado\n");
			break;
		case 5:
			fprintf(stderr, "Erro 5: erro ao criar arquivo\n");
			break;
		case 6:
			fprintf(stderr, "Erro 6: tabela não existe\n");
			break;
		case 7:
			fprintf(stderr, "Erro 7: erro ao deletar tabela\n");
			break;
		case 8:
			fprintf(stderr, "Erro 8: chave primária não adicionada\n");
			break;
		case 9:
			fprintf(stderr, "Erro 9: coluna já existe\n");
			break;
		case 10:
			fprintf(stderr, "Erro 10: erro ao abrir arquivo\n");
			break;
		case 11:
			fprintf(stderr, "Erro 11: chave primária não encontrada\n");
			break;
		case 12:
			fprintf(stderr, "Erro 12: valor já existente na tabela\n");
			break;
	}

	printf("Aperte ENTER para voltar");
	getchar();
	scanf("%c", &trash);
	limpar();
}

int verificar_nome(char nome[60]){
	int size = strlen(nome);
	for(int i=0; i<size; i++){
		if((nome[i] < '0' || nome[i] > '9') && 
		(nome[i] < 'a' || nome[i] > 'z') && 
		(nome[i] < 'A' || nome[i] > 'Z')){
			mostrar_erro(1);
			return 0;
		}
	}

	return 1;
}

int verificar_valor(char nome[60], int tipo){
	switch(tipo){
		case 1: // String
			break;
		case 2: // char
			break;
		case 3: // int
			break;
		case 4: // float
			break;
		case 5: // double
			break;
	}
}

void limpar(){
	system("clear");
}