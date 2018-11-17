#include "geral.h"

void mostrar_erro(int codigo){
	char trash;
	limpar();

	switch(codigo){
		case 001:
			fprintf(stderr, "Erro 001: nome inválido\n");
			break;
		case 002:
			fprintf(stderr, "Erro 002: opção inválida\n");
			break;
		case 003:
			fprintf(stderr, "Erro 003: tabela já existente\n");
			break;
		case 004:
			fprintf(stderr, "Erro 004: arquivo tabelas.txt não encontrado\n");
			break;
		case 005:
			fprintf(stderr, "Erro 005: arquivo não criado\n");
			break;
	}

	printf("Aperte ENTER para voltar\n");
	getchar();
	scanf("%c", &trash);
	limpar();
}

void limpar(){
	system("clear");
}