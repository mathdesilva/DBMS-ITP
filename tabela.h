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

// deletar uma tabela
int del_tabela();

// lista todas as tabelas e tem menu para voltar
int listar_todas_tabelas();

// lista todas as tabelas criadas
int listar_tabelas();

// se o arquivo já existe retorna 1, caso contrário 0 (2 se der erro)
int verificar_existencia(char nome[60]);


#endif