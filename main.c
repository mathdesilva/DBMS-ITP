#include  <stdio.h>
#include "menu.h"
#include "tabela.h"
#include "geral.h"

int main(){
	int op = menu_principal();
	char trash;
	while(op != 0){
		switch(op){
			case 1: // adicionar tabela
				add_tabela();
				break;
			case 2: // adicionar linha/coluna
				break;
			case 3: // mostrar tabela
				break;
			case 4: // deletar tabela
				break;
			case 5: // deletar linha/coluna
				break;
			case 0: // sair
				break;
		}
		op = menu_principal();
	}

}