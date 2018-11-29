#ifndef GERAL_H
#define GERAL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/menu.h"


// apresenta erros
void mostrar_erro(int codigo);

// verifica se o nome não possui caracteres especiais
// retorna 1 se for válido
// retorna 0 se nao for válido
int verificar_nome(char nome[60]);

// verifica se o valor atende ao tipo
// retorna 1 caso o valor for válido
// retorna 0 caso não for válido
int verificar_valor(char valor[60], int tipo);

// pegar o ponteiro de char de acordo com o tipo
// retorna ponteiro de char com o nome do tipo
char* pegar_tipo(int num);

// limpa a tela
void limpar();

// cria os arquivos locais
void criar_arquivos_locais();

// printa uma string em maiúsculo
void printar_uppercase(char name[60]);

// printa o numero de espaços que foi definido
void tab(int num);

#endif