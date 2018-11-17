
output: main.o menu.o tabela.o geral.o
	gcc main.o menu.o tabela.o geral.o -o dbms_itp

main.o: main.c
	gcc -W -c main.c

menu.o: menu.c menu.h
	gcc -W -c menu.c

tabela.o: tabela.c tabela.h
	gcc -W -c tabela.c

geral.o: geral.c geral.h
	gcc -W -c geral.c

clean:
	rm *.o dbms_itp

test:
	gcc -W tests.c -o test
	./test
	rm test