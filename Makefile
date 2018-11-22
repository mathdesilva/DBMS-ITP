#Pastas
INC_DIR = ./include
SRC_DIR = ./src
OBJ_DIR = ./obj
BIN_DIR = ./bin

#Variaveis
CC = gcc
CFLAGS = -Wall -Wextra

output: $(OBJ_DIR)/main.o $(OBJ_DIR)/menu.o $(OBJ_DIR)/tabela.o $(OBJ_DIR)/geral.o
	mkdir -p bin
	$(CC) $(CFLAGS) $(OBJ_DIR)/main.o $(OBJ_DIR)/menu.o $(OBJ_DIR)/tabela.o $(OBJ_DIR)/geral.o -o $(BIN_DIR)/dbms_itp

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c
	mkdir -p obj
	$(CC) -c $(SRC_DIR)/main.c -o $(OBJ_DIR)/main.o $(CFLAGS)

$(OBJ_DIR)/menu.o: $(SRC_DIR)/menu.c $(INC_DIR)/menu.h
	mkdir -p obj
	$(CC) -c $(SRC_DIR)/menu.c -o $(OBJ_DIR)/menu.o $(CFLAGS)

$(OBJ_DIR)/tabela.o: $(SRC_DIR)/tabela.c $(INC_DIR)/tabela.h
	mkdir -p obj
	$(CC) -c $(SRC_DIR)/tabela.c -o $(OBJ_DIR)/tabela.o $(CFLAGS)

$(OBJ_DIR)/geral.o: $(SRC_DIR)/geral.c $(INC_DIR)/geral.h
	mkdir -p obj
	$(CC) -c $(SRC_DIR)/geral.c -o $(OBJ_DIR)/geral.o $(CFLAGS)

clean:
	rm -r obj/ bin/*
