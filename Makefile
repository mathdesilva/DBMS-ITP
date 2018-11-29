#Pastas
INC_DIR = ./include
SRC_DIR = ./src
OBJ_DIR = ./obj
BIN_DIR = ./bin

#Variaveis
CC = gcc
CFLAGS = -Wall -Wextra

output: $(OBJ_DIR)/main.o $(OBJ_DIR)/menu.o $(OBJ_DIR)/tabela.o $(OBJ_DIR)/uteis.o $(OBJ_DIR)/pesquisas.o 
	mkdir -p bin
	$(CC) $(CFLAGS) $(OBJ_DIR)/main.o $(OBJ_DIR)/menu.o $(OBJ_DIR)/tabela.o $(OBJ_DIR)/uteis.o $(OBJ_DIR)/pesquisas.o -o $(BIN_DIR)/dbms_itp
	
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c
	mkdir -p obj
	$(CC) -c $(SRC_DIR)/main.c -o $(OBJ_DIR)/main.o $(CFLAGS)

$(OBJ_DIR)/menu.o: $(SRC_DIR)/menu.c $(INC_DIR)/menu.h
	mkdir -p obj
	$(CC) -c $(SRC_DIR)/menu.c -o $(OBJ_DIR)/menu.o $(CFLAGS)

$(OBJ_DIR)/tabela.o: $(SRC_DIR)/tabela.c $(INC_DIR)/tabela.h
	mkdir -p obj
	$(CC) -c $(SRC_DIR)/tabela.c -o $(OBJ_DIR)/tabela.o $(CFLAGS)

$(OBJ_DIR)/uteis.o: $(SRC_DIR)/uteis.c $(INC_DIR)/uteis.h
	mkdir -p obj
	$(CC) -c $(SRC_DIR)/uteis.c -o $(OBJ_DIR)/uteis.o $(CFLAGS)

$(OBJ_DIR)/pesquisas.o: $(SRC_DIR)/pesquisas.c $(INC_DIR)/pesquisas.h
	mkdir -p obj
	$(CC) -c $(SRC_DIR)/pesquisas.c -o $(OBJ_DIR)/pesquisas.o $(CFLAGS)

clean:
	rm -r obj/ bin/*

cleanall:
	rm -r obj/ bin/* *.txt
