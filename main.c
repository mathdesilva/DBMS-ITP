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
			case 2: // adicionar linha
				add_linha();
				break;
			case 3: // mostrar tabelas
				listar_todas_tabelas();
				break;
			case 4: // pesquisar
				break;
			case 5: // deletar tabela
				del_tabela();
				break;
			case 6: // deletar linha
				break;
			case 0: // sair
				break;
		}
		op = menu_principal();
	}

}