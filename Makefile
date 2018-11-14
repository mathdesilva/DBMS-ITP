
output: main.o menu.o tabela.o
	gcc main.o menu.o tabela.o -o dbms_itp

main.o: main.c
	gcc -W -c main.c

menu.o: menu.c menu.h
	gcc -W -c menu.c

tabela.o: tabela.c tabela.h
	gcc -W -c tabela.c

clean:
	rm *.o dbms_itp

test:
	gcc -W tests.c -o test
	./test
	rm test