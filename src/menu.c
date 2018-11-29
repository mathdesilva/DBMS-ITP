#include "../include/menu.h"

int menu_principal(){
	char op[60];
	int aux = 0;
	while(aux == 0){
		limpar();
		printf("======= MENU PRINCIPAL =======\n");
		printf("  1 - Adicionar nova tabela \n");
		printf("  2 - Adicionar nova linha  \n");
		printf("  3 - Listar tabelas existentes\n");
		printf("  4 - Mostra dados de tabela\n");
		printf("  5 - Pesquisar dado\n");
		printf("  6 - Deletar tabela\n");
		printf("  7 - Deletar linha\n");
		printf("  0 - Sair\n");
		printf("Escolha uma opção: ");
		scanf("%s", op);

		if(strlen(op) == 1 && op[0] >= '0' && op[0] <= '7')
			aux++;
		else
			mostrar_erro(2);
	}
	limpar();

	return atoi(op);
}

int menu_addcoluna(){
	char op[60];
	int aux=0;
	
	while(aux == 0){
		limpar();
		printf("======= ADD COLUNA =======\n");
		printf("  1 - Add nova coluna\n");
		printf("  0 - Sair\n");
		printf("Digite uma opção: ");
		scanf("%s", op);

		if(strlen(op) == 1 && op[0] >= '0' && op[0] <= '1')
			aux++;
		else
			mostrar_erro(2);
	}
	limpar();
	
	return atoi(op);
}

int menu_tipo(){
	char op[60];
	int aux=0;

	while(aux == 0){
		printf("Tipo:\n");
		printf("  1 - String\n");
		printf("  2 - Char\n");
		printf("  3 - Int\n");
		printf("  4 - Float\n");
		printf("  5 - Double\n");
		printf("Digite uma opção: ");
		scanf("%s", op);

		if(strlen(op) == 1 && op[0] >= '1' && op[0] <= '5')
			aux++;
		else
			mostrar_erro(2);
	}
	limpar();

	return atoi(op);
}

int menu_chaveprimaria(){
	char op[60];
	int aux=0;

	while(aux == 0){
		printf("Esta coluna é uma chave primaria?\n");
		printf("  1 - Sim\n");
		printf("  0 - Não\n");
		printf("Escolha uma opção: ");
		scanf("%s", op);

		if(strlen(op) == 1 && (op[0] == '0' || op[0] == '1'))
			aux++;
		else
			mostrar_erro(2);
	}
	limpar();
	
	return atoi(op);
}

int menu_continuar(){
	char op[60];
	int aux=0;

	while(aux == 0){
		printf("Deseja continuar?\n");
		printf("  1 - Sim\n");
		printf("  0 - Sair\n");
		printf("Escolha uma opção: ");
		scanf("%s", op);

		if(strlen(op) == 1 && (op[0] == '0' || op[0] == '1'))
			aux++;
		else
			mostrar_erro(2);
	}
	limpar();
	
	return atoi(op);
}

int menu_pesquisa1(){
	char op[60];
	int aux=0;

	while(aux == 0){
		limpar();
		printf("======= PESQUISA =======\n");
		printf("  1 - Valores maiores\n");
		printf("  2 - Valores maiores ou iguais\n");
		printf("  3 - Valores iguais\n");
		printf("  4 - Valores menores\n");
		printf("  5 - Valores menores ou iguais\n");
		printf("  0 - Sair\n");
		printf("Digite uma opção: ");
		scanf("%s", op);

		if(strlen(op) == 1 && op[0] >= '0' && op[0] <= '5')
			aux++;
		else
			mostrar_erro(2);
	}
	limpar();

	return atoi(op);
}

int menu_pesquisa2(){
	char op[60];
	int aux=0;

	while(aux == 0){
		limpar();
		printf("======= PESQUISA =======\n");
		printf("  1 - Valores maiores\n");
		printf("  2 - Valores maiores ou iguais\n");
		printf("  3 - Valores iguais\n");
		printf("  4 - Valores menores\n");
		printf("  5 - Valores menores ou iguais\n");
		printf("  6 - Valores próximos\n");
		printf("  0 - Sair\n");
		printf("Digite uma opção: ");
		scanf("%s", op);

		if(strlen(op) == 1 && op[0] >= '0' && op[0] <= '6')
			aux++;
		else
			mostrar_erro(2);
	}
	limpar();

	return atoi(op);
}

void menu_voltar(){
	char trash;
	printf("Aperte ENTER para voltar");
	getchar();
	scanf("%c", &trash);
	limpar();
}