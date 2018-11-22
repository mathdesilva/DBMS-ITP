#Pastas
INC_DIR = ./include
SRC_DIR = ./src

#Variaveis
CC = gcc
CFLAGS = -Wall -Wextra

output: main.o menu.o tabela.o geral.o
	$(CC) $(CFLAGS) main.o menu.o tabela.o geral.o -o dbms_itp

main.o: $(SRC_DIR)/main.c
	$(CC) -c $(SRC_DIR)/main.c $(CFLAGS)

menu.o: $(SRC_DIR)/menu.c $(INC_DIR)/menu.h
	$(CC) -c $(SRC_DIR)/menu.c $(CFLAGS)

tabela.o: $(SRC_DIR)/tabela.c $(INC_DIR)/tabela.h
	$(CC) -c $(SRC_DIR)/tabela.c $(CFLAGS)

geral.o: $(SRC_DIR)/geral.c $(INC_DIR)/geral.h
	$(CC) -c $(SRC_DIR)/geral.c $(CFLAGS)

clean:
	rm *.o dbms_itp
