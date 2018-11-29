#include "../include/pesquisas.h"

void pesquisar_print(char arquivo[60], char coluna[60], int codigo){
	int tipo, tot_col, pos_col, linhaAtual, teveResultado = 0;
	char valor[60], valor_busca[60];

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
			if(menu_continuar() == 0){
				fclose(arq);
				return;
			}
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


	/////// P E S Q U I S A ///////////////////////////////////////////////////////////
	// variaveis para as pesquisas
	int valorb_convert_int, valor_convert_int, valido;
	double valorb_convert_double, valor_convert_double;

	while(fscanf(arq, "%s", valor) != EOF){
		valido = 0;

		// passando linhas que são resultado para print.txt
		switch(codigo){
			case 1: // maiores
				switch(tipo){
					case 1: // string
						if(strcmp(valor_busca, valor) < 0)
							valido = 1;
						break;
					case 2: // char
						if(valor_busca[0] < valor[0])
							valido = 1;
						break;
					case 3: // int
						valorb_convert_int = atoi(valor_busca);
						valor_convert_int = atoi(valor);
						if(valorb_convert_int < valor_convert_int)
							valido = 1;
						break;
					case 4: // float
					case 5: // double
						valorb_convert_double = atof(valor_busca);
						valor_convert_double = atof(valor);
						if(valorb_convert_double < valor_convert_double)
							valido = 1;
						break;
				}
				break;
			case 2: // maiores ou iguais
				switch(tipo){
					case 1: // string
						if(strcmp(valor_busca, valor) <= 0)
							valido = 1;
						break;
					case 2: // char
						if(valor_busca[0] <= valor[0])
							valido = 1;
						break;
					case 3: // int
						valorb_convert_int = atoi(valor_busca);
						valor_convert_int = atoi(valor);
						if(valorb_convert_int <= valor_convert_int)
							valido = 1;
						break;
					case 4: // float
					case 5: // double
						valorb_convert_double = atof(valor_busca);
						valor_convert_double = atof(valor);
						if(valorb_convert_double <= valor_convert_double)
							valido = 1;
						break;
				}
				break;
			case 3: // iguais
				switch(tipo){
					case 1: // string
						if(strcmp(valor_busca, valor) == 0)
							valido = 1;
						break;
					case 2: // char
						if(valor_busca[0] == valor[0])
							valido = 1;
						break;
					case 3: // int
						valorb_convert_int = atoi(valor_busca);
						valor_convert_int = atoi(valor);
						if(valorb_convert_int == valor_convert_int)
							valido = 1;
						break;
					case 4: // float
					case 5: // double
						valorb_convert_double = atof(valor_busca);
						valor_convert_double = atof(valor);
						if(valorb_convert_double == valor_convert_double)
							valido = 1;
						break;
				}
				break;
			case 4: // menores
				switch(tipo){
					case 1: // string
						if(strcmp(valor_busca, valor) > 0)
							valido = 1;
						break;
					case 2: // char
						if(valor_busca[0] > valor[0])
							valido = 1;
						break;
					case 3: // int
						valorb_convert_int = atoi(valor_busca);
						valor_convert_int = atoi(valor);
						if(valorb_convert_int > valor_convert_int)
							valido = 1;
						break;
					case 4: // float
					case 5: // double
						valorb_convert_double = atof(valor_busca);
						valor_convert_double = atof(valor);
						if(valorb_convert_double > valor_convert_double)
							valido = 1;
						break;
				}
				break;
			case 5: // menores ou iguais
				switch(tipo){
					case 1: // string
						if(strcmp(valor_busca, valor) >= 0)
							valido = 1;
						break;
					case 2: // char
						if(valor_busca[0] >= valor[0])
							valido = 1;
						break;
					case 3: // int
						valorb_convert_int = atoi(valor_busca);
						valor_convert_int = atoi(valor);
						if(valorb_convert_int >= valor_convert_int)
							valido = 1;
						break;
					case 4: // float
					case 5: // double
						valorb_convert_double = atof(valor_busca);
						valor_convert_double = atof(valor);
						if(valorb_convert_double >= valor_convert_double)
							valido = 1;
						break;
				}
				break;
			case 6:
				switch(tipo){
					case 1:
						if(strcmp(valor_busca, valor) == 0 || strstr(valor_busca, valor) != NULL || strstr(valor, valor_busca) != NULL)
							valido = 1;
						break;
					case 2:
					case 3:
					case 4:
					case 5:
						break;
				}
		}

		if(valido == 1){
			teveResultado = 1;
			rewind(arq_aux);
			for(i=0; i<(tot_col)*(linhaAtual+2)+1; i++)
				fscanf(arq_aux, "%s", valor);
			for(i=0; i<tot_col; i++){
				fscanf(arq_aux, "%s", valor);
				fprintf(arq_print, "%s ", valor);
			}
		}

		linhaAtual++;
		for(int i=0; i<(tot_col-1); i++)
			fscanf(arq, "%s", valor);
	}
	
	fclose(arq_aux);
	fclose(arq_print);
	remove("auxiliar.txt");



	
	///////////////////////////////////////////////////////////////////////////////////
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

	// verificando se há resultados
	if(teveResultado == 0){
		limpar();
		fclose(arq_print);
		remove("print.txt");
		free(tamanhos);
		printf("Não há resultados para a busca\n");
		menu_voltar();
		return;
	}

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

	menu_voltar();
}