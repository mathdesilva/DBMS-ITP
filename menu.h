#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <stdlib.h>

// Limpar a tela
void limpar();

// Mostra o menu principal e retorna a opção escolhida
int menu_principal();

// Mostra o menu para adicionar nova coluna
int menu_addcoluna();

// Mostra o menu para escolha do tipo da coluna
int menu_tipo();

#endif