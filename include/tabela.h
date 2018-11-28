#ifndef TABELA_H
#define TABELA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/menu.h"
#include "../include/uteis.h"

//criar uma nova tabela
int add_tabela();

// criar uma coluna
// retorna 1 caso tenha adicionado chave primária
// retorna 0 caso não tenha adicionado chave primária
int add_coluna(FILE * arquivo, int chave_adicionada);

// adicionar uma nova linha na tabelas
int add_linha();

// deletar uma tabela
int del_tabela();

// deleta uma linha de uma tabela
void del_linha();

// lista todas as tabelas e tem menu para voltar
void listar_todas_tabelas();

// lista todas as tabelas criadas
int listar_tabelas();

// lista todos os dados de uma tabela com menu
int listar_todos_dados_tabelas();

// listar todos os dados de uma tabela
int listar_dados_tabelas(char tabela[60]);

// pesquisa dados na tabela
void pesquisar();

// se o arquivo já existe retorna 1
// retorna 0 se o arquivo não existir (2 se der erro)
int verificar_existencia(char nome[60]);

// verifica se uma coluna existe em uma tabela
// retorna 1 se existe, 0 se não existe, 2 em caso de erro
int verificar_existencia_coluna(char arquivo[60], char coluna[60]);

// retorna o numero da coluna da chave primária
// retorna -1 em caso de erro
int pegar_chave_primaria(char nome[60]);

// retorna a quantidade de colunas na tabela
// retorna -1 em caso de erro
int num_colunas(char nome[60]);

// passar nome do arquivo (com ".txt") e o nome da coluna
// retorna a posição da coluna na tabela
// retorna -1 em caso de erro
int num_posicao_coluna(char arquivo[60], char coluna[60]);

// passar nome do arquivo (com ".txt") e o nome da coluna
// retorna o tamanho da maior string da coluna
// retorna -1 em caso de erro
int maior_tamanho_coluna(char arquivo[60], char coluna[60]);

// lista todas as colunas de uma tabela
// retorna 1 em caso de erro;
int listar_colunas(char arquivo[60]);

// retorna o int referente ao tipo da coluna
// retorna -1 em caso de erro
int pegar_tipo_coluna(char arquivo[60], char coluna[60]);

#endif