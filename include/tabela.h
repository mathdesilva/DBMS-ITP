#ifndef TABELA_H
#define TABELA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/menu.h"
#include "../include/uteis.h"

//criar uma nova tabela
void add_tabela();

// criar uma coluna
// retorna 1 caso tenha adicionado chave primária
// retorna 0 caso não tenha adicionado chave primária
int add_coluna(FILE * arquivo, int chave_adicionada);

// adicionar uma nova linha na tabelas
void add_linha();

// deletar uma tabela
void del_tabela();

// deleta uma linha de uma tabela
void del_linha();

// lista todas as tabelas e tem menu para voltar
void listar_todas_tabelas();

// lista todas as tabelas criadas
// retorna -1 em caso de erro
int listar_tabelas();

// lista todos os dados de uma tabela com menu
void listar_todos_dados_tabelas();

// listar todos os dados de uma tabela
// retorna -1 em caso de erro
int listar_dados_tabelas(char tabela[60]);

// pesquisa dados na tabela
void pesquisar();

// verifica se uma tabela já existe
// retorna 1 se a tabela existe
// retorna 0 se a tabela não existe
// retorna 2 em caso de erro
int verificar_existencia_tabela(char nome[60]);

// verifica se uma coluna já existe em uma tabela
// retorna 1 se a coluna já existe
// retorna 0 se a coluna não existe
// retorna 2 em caso de erro
int verificar_existencia_coluna(char arquivo[60], char coluna[60]);

// pega a posição da coluna que é chave primária na tabela
// retorna a posição da chave primária
// retorna -1 em caso de erro
int pegar_chave_primaria(char nome[60]);

// pegar a quantidade de colunas em uma tabela
// string nome deve estar concatenado com ".txt"
// retorna a quantidade de colunas na tabela
// retorna -1 em caso de erro
int num_colunas(char nome[60]);

// pegar a posição de uma coluna na tabela
// string arquivo deve estar concatenado com ".txt"
// retorna a posição da coluna na tabela
// retorna -1 em caso de erro
int num_posicao_coluna(char arquivo[60], char coluna[60]);

// pega o número de chars da maior string da coluna
// string arquivo deve estar concatenado com ".txt"
// retorna o tamanho da maior string da coluna
// retorna -1 em caso de erro
int maior_tamanho_coluna(char arquivo[60], char coluna[60]);

// lista todas as colunas de uma tabela
// retorna -1 em caso de erro;
int listar_colunas(char arquivo[60]);

// pega o código de tipo de uma coluna em uma tabela
// string arquivo deve estar concatenado com ".txt"
// retorna o int referente ao tipo da coluna
// retorna -1 em caso de erro
int pegar_tipo_coluna(char arquivo[60], char coluna[60]);

// verifica se há tabelas registradas
// retorna 1 caso haja tabelas no registo
// retorna 0 caso não haja tabelas no registro
int ha_tabelas();

#endif