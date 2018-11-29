#include "../include/tabela.h"

void add_tabela(){
	char nome[60];

	// pegar o nome da nova tabela
	limpar();
	printf("Nome da tabela (letras e numeros): ");
	scanf("%s", nome);	
	
	// verificar tamanho da string
	if(strlen(nome) > 54){
		mostrar_erro(1);
		return;
	}
	// verificar se o nome não possui caracteres especiais
	if(verificar_nome(nome) == 0)
		return;

	// verificar se a tabela já existe
	strcat(nome, ".txt");
	if(verificar_existencia_tabela(nome) == 1){
		mostrar_erro(3);
		return;
	}
	// caso retorne erro
	else if(verificar_existencia_tabela(nome) == 2){
		return;
	}

	// criando um novo arquivo
	FILE * arq = fopen(nome, "w");
	if(arq == NULL){
		mostrar_erro(5);
		return;
	}
	fclose(arq);

	// adicionando tabela no tabelas.txt
	arq = fopen("tabelas.txt", "a");
	if(arq == NULL){
		mostrar_erro(4);
		return;
	}
	fprintf(arq, "%s\n", nome);
	fclose(arq);

	// mensagem de tabela criada com sucesso
	limpar();
	printf("Tabela criada com sucesso!\n");
	menu_voltar();

	//adicionar colunas
	arq = fopen(nome, "wr");
	if(arq == NULL){
		mostrar_erro(6);
		return;
	}
	FILE * aux = NULL;
	do{
		aux = fopen("auxiliar2.txt", "w");
	}while(aux == NULL);
	fclose(aux);
	int op = 1, chave = 0;
	while(op != 0){
		if(add_coluna(arq, chave) == 1)
			chave = 1;
		op = menu_addcoluna();
		if(op == 0 && chave == 0){
			op = 1;
			mostrar_erro(8);
		}
	}

	// fechando o arquivo da tabela
	fprintf(arq, "|\n");
	fclose(arq);
	remove("auxiliar2.txt");
}

int add_coluna(FILE * arquivo, int chave_adicionada){
	char titulo[60];
	int chave=0, op;
	
	// pegando nome da coluna
	printf("======= ADD COLUNA =======\n");
	printf("Nome da coluna: ");
	scanf("%s", titulo);

	// verificar se o nome não possui caracteres especiais
	if(verificar_nome(titulo) == 0)
		return 0;

	// verificando se a coluna já existe
	FILE * aux = fopen("auxiliar2.txt", "r");
	char cmp_titulo[60];
	while(fscanf(aux, "%s", cmp_titulo) != EOF){
		if(strcmp(cmp_titulo, titulo) == 0){
			mostrar_erro(9);
			return 0;
		}
	}
	fclose(aux);
	aux = fopen("auxiliar2.txt", "a");
	fprintf(aux, "%s\n", titulo);
	fclose(aux);

	// pegando o tipo da coluna
	op = menu_tipo();

	// pegando chave primária
	if(op == 3 && chave_adicionada == 0)
		chave = menu_chaveprimaria();

	// mensagem de coluna adicionada com sucesso
	printf("Coluna adicionada com sucesso\n");
	menu_voltar();

	// adicionando informações na tabela
	if(chave == 1){
		fprintf(arquivo, "*%s %d ", titulo, op);
		return 1;
	}
	else{
		fprintf(arquivo, "%s %d ", titulo, op);
		return 0;
	}
}

void add_linha(){
	char nome[60];

	// verificando se há tabelas
	if(ha_tabelas() == 0){
		mostrar_erro(19);
		return;
	}

	// pegar o nome da tabela
	if(listar_tabelas() == -1)
		return;
	printf("Digite o nome da tabela: ");
	scanf("%s", nome);
	strcat(nome, ".txt");

	// verificar se o arquivo existe
	if(verificar_existencia_tabela(nome) == 0){
		mostrar_erro(6);
		return;
	}
	else if(verificar_existencia_tabela(nome) == 2)
		return;

	// pegar posição da coluna da cheva primária
	int col_chavePrimaria = pegar_chave_primaria(nome);
	if(col_chavePrimaria == -1)
		return;

	// pegar número de colunas da tabela
	int num_col = num_colunas(nome);
	if(num_col == -1)
		return;

	// pegar valor da chave primária
	char nome_chavep[60], valor[60], chavep[60];
	int num_aux, sair1=0;
	FILE * arq = fopen(nome, "r");
	if(arq == NULL){
		mostrar_erro(10);
		return;
	}
	for(int i=0; i<col_chavePrimaria; i++)
		fscanf(arq, "%s %d", nome_chavep, &num_aux);
	nome_chavep[0] = ' ';
	while(sair1 == 0){
		limpar();
		printf("Digite o valor de%s (int): ", nome_chavep);
		scanf("%s", chavep);
		if(verificar_valor(chavep, 3) == 0){
			if(menu_continuar() == 0)
				return;
			else
				continue;
		}
			
		// validar chave primária
		rewind(arq);
		for(int i=0; i<(2*num_col)+col_chavePrimaria; i++)
			fscanf(arq, "%s", valor);
		while(fscanf(arq, "%s", valor) != EOF){
			if(strcmp(valor, chavep) == 0){
				mostrar_erro(12);
				if(menu_continuar() == 0)
					return;
				else{
					sair1 = 1;
					break;
				}
			}
			for(int i=0; i<num_col-1; i++)
					fscanf(arq, "%s", valor);
		}
		if(sair1 == 1){
			sair1 = 0;
			continue;
		}
		sair1 = 1;
	}

	// criando arquivo auxiliar e passando os nomes das colunas
	rewind(arq);
	FILE * arq_aux = fopen("auxiliar3.txt", "w");
	if(arq_aux == NULL){
		mostrar_erro(5);
		return;
	}
	for(int i=0; i<num_col*2; i++){
		fscanf(arq, "%s", valor);
		fprintf(arq_aux, "%s ", valor);
	}
	fclose(arq_aux);
	fclose(arq);

	// pegando os valores da linha e colocando em buffer.txt
	int numtipo;
	char coluna[60];
	sair1 = 0;
	arq_aux = fopen("auxiliar3.txt", "r");
	if(arq_aux == NULL){
		mostrar_erro(10);
		return;
	}
	arq = fopen("buffer.txt", "w");
	if(arq == NULL){
		mostrar_erro(10);
		remove("auxiliar3.txt");
		return;
	}
	for(int i=0; i<num_col; i++){
		if(i == (col_chavePrimaria-1)){
			fscanf(arq_aux, "%s %d", coluna, &numtipo);
			fprintf(arq, "%s ", chavep);
		}
		else{
			fscanf(arq_aux, "%s %d", coluna, &numtipo);
			sair1 = 0;
			while(sair1 == 0){
				printf("Digite o valor de %s (%s): ", coluna, pegar_tipo(numtipo));
				scanf("%s", valor);
				if(verificar_valor(valor, numtipo) == 0){
					if(menu_continuar() == 0){
						fclose(arq);
						fclose(arq_aux);
						remove("buffer.txt");
						remove("auxiliar3.txt");
						return;
					}
				}
				else
					sair1 = 1;
			}
			fprintf(arq, "%s ", valor);
		}
	}
	fclose(arq);
	fclose(arq_aux);
	remove("auxiliar3.txt");
	
	// pega os valores de buffer.txt e coloca na tabela
	arq = fopen(nome, "a");
	if(arq == NULL){
		mostrar_erro(10);
		return;
	}
	arq_aux = fopen("buffer.txt", "r");
	if(arq_aux == NULL){
		mostrar_erro(10);
		fclose(arq);
		return;
	}
	while(fscanf(arq_aux, "%s", valor) != EOF)
		fprintf(arq, "%s ", valor);
	fprintf(arq, "\n");
	fclose(arq);
	fclose(arq_aux);
	remove("buffer.txt");

	//finalizando
	limpar();
	printf("Linha adicionada com sucesso!!\n");
	menu_voltar();
}

void del_tabela(){
	char nome[60];

	// verificando se há tabelas
	if(ha_tabelas() == 0){
		mostrar_erro(19);
		return;
	}

	//listar todas as tabelas existentes
 	if(listar_tabelas() == 2)
		return;

	// pegar a tabela a ser deletada
	printf("escreva o nome da tabela para ser deletada: ");
	scanf("%s", nome);
	strcat(nome, ".txt");

	// verificar existencia da tabela
	if(verificar_existencia_tabela(nome) == 0){
		mostrar_erro(6);
		return;
	} 
	// caso retorne erro
	else if(verificar_existencia_tabela(nome) == 2)
		return;

	// deletando do tabelas.txt
	char swap[60];
	FILE *aux = fopen("auxiliar.txt", "w");
	if(aux == NULL){
		mostrar_erro(7);
		return;
	}
	FILE *arq = fopen("tabelas.txt", "r");
	if(arq == NULL){
		mostrar_erro(4);
		remove("auxiliar.txt");
		return;
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

	// mensagem de tabela deletada com sucesso
	limpar();
	printf("tabela deletada com sucesso\n");
	menu_voltar();

	return;
}

void del_linha(){
	int tot_col, pos_chavep, sair = 0, retorno, linha, auxlinha;
	char tabela[60], chavep[60], valor[60];
	FILE * arq;

	// verificando se há tabelas
	if(ha_tabelas() == 0){
		mostrar_erro(19);
		return;
	}

	// pegando o nome da tabela
	while(sair == 0){
		limpar();
		listar_tabelas();
		printf("Digite o nome da tabela: ");
		scanf("%s", tabela);
		strcat(tabela, ".txt");

		// verificando se a tabela existe
		retorno = verificar_existencia_tabela(tabela);
		if(retorno == 0){
			mostrar_erro(6);
			if(menu_continuar() == 0)
				return;
		}
		else if(retorno == 2)
			return;
		else
			sair = 1;
	}
	
	// pegando o número total de colunas na tabela
	tot_col = num_colunas(tabela);

	// pegando chave primaria da linha
	sair = 0;
	while(sair == 0){
		limpar();
		listar_dados_tabelas(tabela);
		printf("Digite a chave primaria da linha a ser deletada: ");
		scanf("%s", chavep);

		// pegando posição da chave primária
		pos_chavep = pegar_chave_primaria(tabela);
		if(pos_chavep == -1)
			return;

		// abrindo arquivo da tabela
		arq = fopen(tabela, "r");
		if(arq == NULL){
			mostrar_erro(10);
			return;
		}

		// verificando se a chave primaria existe
		linha = 0;
		for(int i=0; i<(2*tot_col)+pos_chavep; i++){
			fscanf(arq, "%s", valor);
		}
		while(fscanf(arq, "%s", valor) != EOF){
			linha++;
			if(strcmp(valor, chavep) == 0){
				sair = 1;
				break;
			}
			for(int i=0; i<tot_col-1; i++)
				fscanf(arq, "%s", valor);
		}
		fclose(arq);
		if(sair == 0){
			mostrar_erro(11);
			if(menu_continuar() == 0)
				return;
		}
	}

	// verificando se há linhas na tabela
	if(linha == 0){
		mostrar_erro(18);
		return;
	}

	// abrindo arquivo da tabela
	arq = fopen(tabela, "r");
	if(arq == NULL){
		mostrar_erro(10);
		return;
	}

	// criando arquivo auxiliar
	FILE * arq_aux = fopen("auxiliar.txt", "w");
	if(arq_aux == NULL){
		mostrar_erro(10);
		fclose(arq);
		return;
	}

	// passando linhas não deletadas para auxiliar.txt
	rewind(arq);
	auxlinha = 0;
	for(int i=0; i<(2*tot_col)+1; i++){
		fscanf(arq, "%s", valor);
		fprintf(arq_aux, "%s ", valor);
	}
	fprintf(arq_aux, "\n");
	while(fscanf(arq, "%s", valor) != EOF){
		auxlinha++;
		if(auxlinha == linha){
			for(int i=0; i<tot_col-1; i++)
				fscanf(arq, "%s", valor);
			continue;
		}

		fprintf(arq_aux, "%s ", valor);
		for(int i=0; i<tot_col-1; i++){
			fscanf(arq, "%s", valor);
			fprintf(arq_aux, "%s ", valor);
		}
		fprintf(arq_aux, "\n");
	}

	// renomeando auxiliar.txt para o nome da tabela
	fclose(arq);
	fclose(arq_aux);
	remove(tabela);
	rename("auxiliar.txt", tabela);

	// mensagem de linha deletada com sucesso
	limpar();
	printf("linha deletada com sucesso!\n");
	menu_voltar();
}

void listar_todas_tabelas(){
	limpar();

	// verificando se há tabelas
	if(ha_tabelas() == 0){
		mostrar_erro(19);
		return;
	}

	// chamando função que lista todas as tabelas
	if(listar_tabelas() == -1)
		return;

	// menu para voltar
	menu_voltar();
}

int listar_tabelas(){
	char nome[60];
	int tamanho;
	
	// abrindo arquivo
	FILE * arq = fopen("tabelas.txt", "r");
	if(arq == NULL){
		mostrar_erro(4);
		return -1;
	}

	// printando
	printf("======= TABELAS =======\n");
	while(fscanf(arq, "%s", nome) != EOF){
		tamanho = strlen(nome);
		char saida[60] = "";
		strncpy(saida, nome, tamanho - 4);
		printf("  - %s\n", saida);
	}

	// fechando arquivo
	fclose(arq);

	return 0;
}

void listar_todos_dados_tabelas(){
	char nome[60];

	// verificando se há tabelas
	if(ha_tabelas() == 0){
		mostrar_erro(19);
		return;
	}

	// pegar nome da tabela
	if(listar_tabelas() == -1)
		return;
	printf("Digite o nome da tabela a ser listada: ");
	scanf("%s", nome);
	strcat(nome, ".txt");
	limpar();

	// verificando existencia
	if(verificar_existencia_tabela(nome) == 0){
		mostrar_erro(6);
		return;
	}
	else if(verificar_existencia_tabela(nome) == 2)
		return;

	// listar os dados da tabela
	if(listar_dados_tabelas(nome) == -1)
		return;

	// finalizar
	menu_voltar();
}

int listar_dados_tabelas(char tabela[60]){
	int num_col;

	// pegar numero de colunas
	num_col = num_colunas(tabela);
	if(num_col == -1)
		return -1;

	// clonando tabela em outro arquivo "clone.txt"
	char valor[60];
	int tipo;
	FILE * arq = fopen(tabela, "r");
	if(arq == NULL){
		mostrar_erro(10);
		return -1;
	}
	FILE * clone = fopen("clone.txt", "w");
	if(arq == NULL){
		mostrar_erro(10);
		fclose(arq);
		return -1;
	}
	while(fscanf(arq, "%s", valor) != EOF)
		fprintf(clone, "%s ", valor);
	fclose(clone);

	// alocando o tamanho das maiores strings de cada coluna
	rewind(arq);
	int *tamanhos = (int *) malloc(num_col * sizeof(int));
	if(tamanhos == NULL){
		mostrar_erro(16);
		fclose(arq);
		return -1;
	}
	for(int i=0; i<num_col; i++){
		fscanf(arq, "%s %d", valor, &tipo);
		tamanhos[i] = maior_tamanho_coluna("clone.txt", valor);
	}

	// printando os titulos das colunas
	rewind(arq);
	for(int i=0; i<num_col; i++){
		fscanf(arq, "%s %d", valor, &tipo);
		printar_uppercase(valor);
		tab(tamanhos[i] - strlen(valor) + 1);
	}
	printf("\n");
	fscanf(arq, "%s", valor);

	// printando os valores da tabela
	int aux = 0;
	while(fscanf(arq, "%s", valor) != EOF){
		printf("%s", valor);
		tab(tamanhos[aux%num_col] - strlen(valor) + 1);
		aux++;
		if(aux%num_col == 0)
			printf("\n");
	}

	// fechando o arquivo da tabela
	fclose(arq);
	free(tamanhos);
	remove("clone.txt");

	return 0;
}

void pesquisar(){
	int sair=0, retorno, op;
	char tabela[60], coluna[60];

	// verificando se há tabelas
	if(ha_tabelas() == 0){
		mostrar_erro(19);
		return;
	}

	// pegando o nome da tabela
	while(sair == 0){
		limpar();
		listar_tabelas();
		printf("Digite o nome da tabela para pesquisa: ");
		scanf("%s", tabela);
		strcat(tabela, ".txt");

		// verificando se a tabela existe
		retorno = verificar_existencia_tabela(tabela);
		if(retorno == 0){
			mostrar_erro(6);
			if(menu_continuar() == 0)
				return;
		}
		else if(retorno == 2)
			return;
		else
			sair = 1;
	}

	// pegando o nome da coluna
	sair = 0;
	while(sair == 0){
		limpar();
		if(listar_colunas(tabela) == -1)
			return;
		printf("Digite o nome da coluna para pesquisa: ");
		scanf("%s", coluna);

		// verificando se a coluna existe
		retorno = verificar_existencia_coluna(tabela, coluna);
		if(retorno == 0){
			mostrar_erro(17);
			if(menu_continuar() == 0)
				return;
		}
		else if(retorno == 2)
			return;
		else
			sair = 1;
	}

	// escolhendo tipo de pesquisa
	int tipo = pegar_tipo_coluna(tabela, coluna);
	if(tipo != 1)
		op = menu_pesquisa1();
	else
		op = menu_pesquisa2();
	if(op == 0)
		return;
	else
		pesquisar_print(tabela, coluna, op);
}

int verificar_existencia_tabela(char nome[60]){
	int size = strlen(nome);

	// abrindo arquivo
	FILE *arq = fopen("tabelas.txt", "r");
	if(arq == NULL){
		mostrar_erro(4);
		return 2;
	}

	// adicionando .txt no nome da tabela
	if(nome[size-4] != '.')
		strcat(nome, ".txt");

	// verificando existencia
	char arquivo[60];
	while(fscanf(arq, "%s", arquivo) != EOF){
		if(strcmp(arquivo, nome) == 0){
			fclose(arq);
			return 1;
		}
	}

	// finalizando
	fclose(arq);
	return 0;
}

int verificar_existencia_coluna(char arquivo[60], char coluna[60]){
	char valor[60];
	int tipo;

	// abrindo arquivo
	FILE * arq = fopen(arquivo, "r");
	if(arq == NULL){
		mostrar_erro(10);
		return 2;
	}

	// procurando coluna
	while(fscanf(arq, "%s %d", valor, &tipo) != EOF && strcmp(valor, "|") != 0){
		if(strcmp(coluna, valor) == 0){
			fclose(arq);
			return 1;
		}
	}

	// em caso de não existencia
	fclose(arq);
	return 0;
}

int pegar_chave_primaria(char nome[60]){
	char coluna[60];
	int counter = 0, aux;

	// abrindo arquivo
	FILE * arq = fopen(nome, "r");
	if(arq == NULL){
		mostrar_erro(10);
		return -1;
	}

	// procurando chave primaria
	while(fscanf(arq, "%s %d", coluna, &aux) != EOF){
		if(coluna[0] == '*'){
			fclose(arq);
			return counter+1;
		}
		else
			counter++;
	}

	// caso não ache a chave primaria
	fclose(arq);
	mostrar_erro(11);
	return -1;
}

int num_colunas(char nome[60]){
	char valor[60];
	int counter = 0, aux;

	// abrindo o arquivo
	FILE * arq = fopen(nome, "r");
	if(arq == NULL){
		mostrar_erro(10);
		return -1;
	}

	// contando o número de colunas
	while(fscanf(arq, "%s", valor) != EOF && strcmp(valor, "|") != 0){
		counter++;
		fscanf(arq, "%d", &aux);
	}

	// fechando arquivo e retornando resultado
	fclose(arq);
	return counter;
}

int num_posicao_coluna(char arquivo[60], char coluna[60]){
	char valor[60];
	int tipo, contador = 0;

	// abrindo arquivo
	FILE * arq = fopen(arquivo, "r");
	if(arq == NULL){
		mostrar_erro(10);
		return -1;
	}

	// procurando coluna
	while(fscanf(arq, "%s %d", valor, &tipo) != EOF){
		contador++;
		if(strcmp(coluna, valor) == 0){
			fclose(arq);
			return contador;
		}
	}

	// em caso de erro na busca
	fclose(arq);
	mostrar_erro(15);
	return -1;
}

int maior_tamanho_coluna(char arquivo[60], char coluna[60]){
	int size, maior=0, tipo;
	char valor[60];

	// pegando o número de colunas da tabela
	int num_col = num_colunas(arquivo);

	// pegando a posição da coluna na tabela
	int num_pos_coluna = num_posicao_coluna(arquivo, coluna);

	// procurando maior valor
	FILE * arq = fopen(arquivo, "r");
	if(arq == NULL){
		mostrar_erro(10);
		return -1;
	}
	for(int i=0; i<num_pos_coluna-1; i++)
		fscanf(arq, "%s %d", valor, &tipo);

	fscanf(arq, "%s %d", valor, &tipo);
	maior = strlen(valor);

	for(int i=0; i<num_col - num_pos_coluna; i++)
		fscanf(arq, "%s %d", valor, &tipo);

	fscanf(arq, "%s", valor);

	for(int i=0; i<num_pos_coluna-1; i++)
		fscanf(arq, "%s", valor);

	while(fscanf(arq, "%s", valor) != EOF){
		size = strlen(valor);
		if(size > maior)
			maior = size;
		for(int i=0; i<num_col-1; i++)
			fscanf(arq, "%s", valor);
	}
	fclose(arq);

	// retornando o maior tamanho
	return maior;
}

int listar_colunas(char arquivo[60]){
	int tipo;
	char valor[60];

	// abrindo o arquivo
	FILE * arq = fopen(arquivo, "r");
	if(arq == NULL){
		mostrar_erro(10);
		return -1;
	}

	// listando colunas
	printf("======= COLUNAS =======\n");
	while(fscanf(arq, "%s %d", valor, &tipo) != EOF && strcmp(valor, "|") != 0)
		printf("  - %s\n", valor);

	// fechando o arquivo
	fclose(arq);

	return 0;
}

int pegar_tipo_coluna(char arquivo[60], char coluna[60]){
	char valor[60];
	int tipo;

	// abrindo arquivo
	FILE * arq = fopen(arquivo, "r");
	if(arq == NULL){
		mostrar_erro(10);
		return -1;
	}

	// procurando coluna e pegando o tipo
	while(fscanf(arq, "%s %d", valor, &tipo) != EOF && strcmp(valor, "|") != 0){
		if(strcmp(valor, coluna) == 0){
			fclose(arq);
			return tipo;
		}
	}

	// em caso de erro na busca
	mostrar_erro(15);
	fclose(arq);
	return -1;
}

int ha_tabelas(){
	// abrindo arquivo
	FILE * arq = fopen("tabelas.txt", "r");
	if(arq == NULL){
		mostrar_erro(4);
		return 2;
	}

	// verificando
	char valor[60];
	if(fscanf(arq, "%s", valor) != EOF){
		fclose(arq);
		return 1;
	}
	else{
		fclose(arq);
		return 0;
	}
}