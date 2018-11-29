#include  <stdio.h>
#include "../include/menu.h"
#include "../include/tabela.h"
#include "../include/uteis.h"

int main(){
	criar_arquivos_locais();
	int op = menu_principal();
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
			case 4: // mostrar dados de tabela
				listar_todos_dados_tabelas();
				break;
			case 5: // pesquisar
				pesquisar();
				break;
			case 6: // deletar tabela
				del_tabela();
				break;
			case 7: // deletar linha
				del_linha();
				break;
			case 0: // sair
				break;
		}
		op = menu_principal();
	}
	
	return 0;
}