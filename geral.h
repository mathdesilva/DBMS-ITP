#ifndef GERAL_H
#define GERAL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// apresentar erros
void mostrar_erro(int codigo);

// verificar se o nome não possui caracteres especiais
// retorna 1 se for válido, 0 caso nao for válido
int verificar_nome(char nome[60]);

// limpar tela
void limpar();

#endif