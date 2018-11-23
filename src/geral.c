#include "../include/geral.h"

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
		case 13:
			fprintf(stderr, "Erro 13: valor não compatível ao tipo\n");
			break;
		case 14:
			fprintf(stderr, "Erro 14: sistema operacional não suportado\n");
			break;
		case 15:
			fprintf(stderr, "Erro 15: erro ao procurar coluna\n");
			break;
		case 16:
			fprintf(stderr, "Erro 16: memória insuficiente\n");
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
	int size;
	size = strlen(nome);

	switch(tipo){
		case 1: // String
			break;
		case 2: // char
			if(strlen(nome) != 1){
				mostrar_erro(13);
				return 0;
			}
			break;
		case 3: // int
			for(int i=0; i<size; i++){
				if(nome[i] < '0' || nome[i] > '9'){
					mostrar_erro(13);
					return 0;
				}
			}
			break;
		case 4: // float
		case 5: // double
			if(size < 3 || nome[0] == '.' || nome[size-1] == '.'){
				mostrar_erro(13);
				return 0;
			}
			for(int i=0; i<size; i++){
				if((nome[i] < '0' || nome[i] > '9') && nome[i] != '.'){
					mostrar_erro(13);
					return 0;
				}
			}
			break;
	}

	return 1;
}

char* tipo(int num){
	switch(num){
		case 1:
			return "string";
			break;
		case 2:
			return "char";
			break;
		case 3:
			return "int";
			break;
		case 4:
			return "float";
			break;
		case 5:
			return "double";
			break;
	}
}


void limpar(){
	#ifdef LINUX
		system("clear");
	#elif defined uns
		system("clear");
	#elif defined linux
		system("clear");
	#elif defined Linux
		system("clear");
	#elif defined WIN32
		system("cls");
	#elif defined win32
		system("cls");
	#elif defined Win32
		system("cls");
	#else
		mostrar_erro(14);
	#endif
}

void criar_arquivos_locais(){
	FILE * arq = fopen("tabelas.txt", "r");
	if(arq == NULL){
		arq = fopen("tabelas.txt", "w");
		fclose(arq);
	}
}

void printar_uppercase(char name[60]){
	while(*name != '\0'){
		if(*name >= 'a' && *name <= 'z'){
			printf("%c", (*name)-32);
		} else {
			printf("%c", *name);
		}
		name++;
	}
}

void tab(int num){
	for(int i=0; i<num; i++)
		printf(" ");
}