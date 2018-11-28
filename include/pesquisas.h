#ifndef PESQUISAS_H
#define PESQUISAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/tabela.h"
#include "../include/uteis.h"

// imprime os valores maiores (código 1)
// imprime os valores maiores ou iguais (código 2)
// imprime os valores iguais (código 3)
// imprime os valores menores (código 4)
// imprime os valores menores ou iguais (código 5)
// imprime os valores próximos (códigos 6)
void pesquisar_print(char arquivo[60], char coluna[60], int codigo);


#endif