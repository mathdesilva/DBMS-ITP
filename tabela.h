#ifndef TABELA_H
#define TABELA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "geral.h"

// alocar uma nova tabela
int add_tabela();

// alocar uma nova coluna
int add_coluna(char nome[60]);

// se o arquivo já existe retorna 1, caso contrário 0 (2 se der erro)
int verificar_existencia(char nome[60]);


#endif