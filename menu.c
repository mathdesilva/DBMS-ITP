#include "menu.h"

int menu_principal(){
	int op, aux = 0;
	while(aux == 0){
		limpar();
		printf("======= MENU PRINCIPAL =======\n");
		printf("  1 - Adicionar nova tabela (pronto)\n");
		printf("  2 - Adicionar nova linha (fazendo)\n");
		printf("  3 - Listar tabelas (pronto)\n");
		printf("  4 - Pesquisar (fazendo)\n");
		printf("  5 - Deletar tabela (pronto)\n");
		printf("  6 - Deletar linha (fazendo)\n");
		printf("  0 - Sair\n");
		printf("Escolha uma opção: ");
		scanf("%d", &op);

		if(op >= 0 && op <=6)
			aux++;
		else
			mostrar_erro(2);
	}
	limpar();

	return op;
}

int menu_addcoluna(){
	int op, aux=0;
	
	while(aux == 0){
		limpar();
		printf("======= ADD COLUNA =======\n");
		printf("  1 - Add nova coluna\n");
		printf("  0 - Sair\n");
		printf("Digite uma opção: ");
		scanf("%d", &op);

		if(op >=0 && op <=1)
			aux++;
		else
			mostrar_erro(2);
	}
	limpar();
	
	return op;
}

int menu_tipo(){
	int op, aux=0;

	while(aux == 0){
		printf("Tipo:\n");
		printf("  1 - String\n");
		printf("  2 - Char\n");
		printf("  3 - Int\n");
		printf("  4 - Float\n");
		printf("  5 - Double\n");
		printf("Digite uma opção: ");
		scanf("%d", &op);

		if(op >= 1 && op <= 5)
			aux++;
		else
			mostrar_erro(2);
	}
	limpar();

	return op;
}

int menu_chaveprimaria(){
	int op, aux=0;

	while(aux == 0){
		printf("Esta coluna é uma chave primaria?\n");
		printf("  1 - Sim\n");
		printf("  0 - Não\n");
		printf("Escolha uma opção: ");
		scanf("%d", &op);

		if(op == 0 || op == 1)
			aux++;
		else
			mostrar_erro(2);
	}
	limpar();
	
	return op;
}