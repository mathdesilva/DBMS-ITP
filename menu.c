#include "menu.h"

int menu_principal(){
	int op, aux = 0;
	char trash;
	while(aux == 0){
		limpar();
		printf("======= MENU PRINCIPAL =======\n");
		printf("  1 - Adicionar nova tabela\n");
		printf("  2 - Adicionar nova linha/coluna\n");
		printf("  3 - Mostrar tabela\n");
		printf("  0 - Sair\n");
		printf("Escolha uma opção: ");
		scanf("%d", &op);

		if(op >= 0 && op <=3)
			aux++;
		else{
			limpar();
			printf("Erro 002 - opção inválida\n");
			printf("Aperte ENTER para voltar\n");
			getchar();
			scanf("%c", &trash);
		}
	}
	limpar();

	return op;
}

int menu_addcoluna(){
	int op, aux=0;
	char trash;
	
	while(aux == 0){
		limpar();
		printf("======= ADD COLUNA =======\n");
		printf("  1 - Add nova coluna\n");
		printf("  0 - Sair\n");
		printf("Digite uma opção: ");
		scanf("%d", &op);

		if(op >=0 && op <=1)
			aux++;
		else{
			limpar();
			printf("Erro 002 - opção inválida\n");
			printf("Aperte ENTER para voltar\n");
			getchar();
			scanf("%c", &trash);
		}
	}
	limpar();
	
	return op;
}

int menu_tipo(){
	int op, aux=0;
	char trash;

	while(aux == 0){
		limpar();
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
		else {
			limpar();
			printf("Erro 002 - opção inválida\n");
			printf("Aperte ENTER para voltar\n");
			getchar();
			scanf("%c", &trash);
		}
	}
	limpar();

	return op;
}

void limpar(){
	system("clear");
}