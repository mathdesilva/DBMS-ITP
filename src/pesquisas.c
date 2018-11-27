#include "../include/pesquisas.h"

void pesquisar_iguais(char arquivo[60], char coluna[60]){
	int tipo, tot_col, pos_col, linhaAtual;
	char valor[60], valor_busca[60], trash;

	// pegando o número total de colunas na tabela
	tot_col = num_colunas(arquivo);
	if(tot_col == -1)
		return;

	// pegando a posição da coluna na tabela
	pos_col = num_posicao_coluna(arquivo, coluna);
	if(pos_col == -1)
		return;

	// pegando o tipo da coluna
	tipo = pegar_tipo_coluna(arquivo, coluna);
	if(tipo == -1)
		return;

	// criando arquivo auxiliar
	FILE * arq_aux = fopen("auxiliar.txt", "w");
	if(arq_aux == NULL){
		mostrar_erro(5);
		return;
	}

	// fazendo cópia da tabela em arquivo auxiliar
	FILE * arq = fopen(arquivo, "r");
	if(arq == NULL){
		mostrar_erro(10);
		fclose(arq_aux);
		remove("auxiliar.txt");
		return;
	}
	while(fscanf(arq, "%s", valor) != EOF)
		fprintf(arq_aux, "%s ", valor);
	fclose(arq_aux);

	// pegando valor para busca
	int sair = 0;
	while(sair == 0){
		limpar();
		printf("Digite o valor para busca (%s): ", pegar_tipo(tipo));
		scanf("%s", valor_busca);
		if(verificar_valor(valor_busca, tipo) == 0){
			mostrar_erro(13);
			if(menu_continuar() == 0)
				return;
		}
		else
			sair = 1;
	}

	// abrindo o auxiliar.txt e criando o arquivo print.txt
	arq_aux = fopen("auxiliar.txt", "r");
	if(arq_aux == NULL){
		mostrar_erro(10);
		remove("auxiliar.txt");
		return;
	}
	FILE * arq_print = fopen("print.txt", "w");
	if(arq_aux == NULL){
		mostrar_erro(10);
		remove("auxiliar.txt");
		return;
	}

	// passando nome das colunas para print.txt
	int i;
	rewind(arq);
	linhaAtual = 0;
	for(int i=0; i<(2*tot_col) + 1; i++){
		fscanf(arq_aux, "%s", valor);
		fscanf(arq, "%s", valor);
		fprintf(arq_print, "%s ", valor);
	}
	for(int i=0; i<(pos_col-1); i++){
		fscanf(arq, "%s", valor);
	}

	// passando linhas que são resultado para print.txt
	while(fscanf(arq, "%s", valor) != EOF){
		switch(tipo){
			case 1: // string
			case 2: // char
			case 3: // int
				if(strcmp(valor, valor_busca) == 0){
					rewind(arq_aux);
					for(i=0; i<(tot_col)*(linhaAtual+2)+1; i++)
						fscanf(arq_aux, "%s", valor);
					for(i=0; i<tot_col; i++){
						fscanf(arq_aux, "%s", valor);
						fprintf(arq_print, "%s ", valor);
					}
				}
				break;
			case 4: // float
				break;
			case 5: // double
				break;
		}
		linhaAtual++;
		for(int i=0; i<(tot_col-1); i++)
			fscanf(arq, "%s", valor);
	}
	fclose(arq_aux);
	fclose(arq_print);
	remove("auxiliar.txt");

	// alocando o tamanho das maiores strings de cada coluna
	rewind(arq);
	int *tamanhos = (int *) malloc(tot_col * sizeof(int));
	if(tamanhos == NULL){
		mostrar_erro(16);
		fclose(arq);
		remove("print.txt");
		return;
	}
	for(int i=0; i<tot_col; i++){
		fscanf(arq, "%s %d", valor, &tipo);
		tamanhos[i] = maior_tamanho_coluna("print.txt", valor);
	}

	// abrindo o arquivo da tabela a ser printada
	arq_print = fopen("print.txt", "r");
	if(arq_print == NULL){
		mostrar_erro(10);
		remove("print.txt");
		return;
	}

	// printando os titulos das colunas
	limpar();
	for(int i=0; i<tot_col; i++){
		fscanf(arq_print, "%s %d", valor, &tipo);
		printar_uppercase(valor);
		tab(tamanhos[i] - strlen(valor) + 1);
	}
	printf("\n");
	fscanf(arq_print, "%s", valor);

	// printando os valores da tabela
	int aux = 0;
	while(fscanf(arq_print, "%s", valor) != EOF){
		printf("%s", valor);
		tab(tamanhos[aux%tot_col] - strlen(valor) + 1);
		aux++;
		if(aux%tot_col == 0)
			printf("\n");
	}

	// finalizando
	fclose(arq_print);
	remove("print.txt");
	free(tamanhos);

	printf("Aperte ENTER para voltar");
	getchar();
	scanf("%c", &trash);
	limpar();
}