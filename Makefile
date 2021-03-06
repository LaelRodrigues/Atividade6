RM = rm -rf

CC=g++

LIB_DIR=./lib
INC_DIR=./include
SRC_DIR=./src
OBJ_DIR=./build
BIN_DIR=./bin
DOC_DIR=./doc
TEST_DIR=./test


CFLAGS = -Wall -pedantic -ansi -std=c++11 -I. -I$(INC_DIR)

.PHONY: all init clean doxy debug doc

all: init questao1 questao2 questao3

debug: CFLAGS += -g -O0
debug: all

init:
	@mkdir -p $(OBJ_DIR)/questao1
	@mkdir -p $(OBJ_DIR)/questao2
	@mkdir -p $(OBJ_DIR)/questao3
	@mkdir -p $(BIN_DIR)


questao1: CFLAGS+= -I$(INC_DIR)/questao1
questao1: $(OBJ_DIR)/questao1/main1.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/palindromo $^
	@echo "+++ [Executavel 'palindromo' criado em $(BIN_DIR)] +++"
	@echo "============="

$(OBJ_DIR)/questao1/main1.o: $(SRC_DIR)/questao1/main1.cpp $(INC_DIR)/questao1/pilha.h
	$(CC) -c $(CFLAGS) -o $@ $<

questao2: CFLAGS+= -I$(INC_DIR)/questao2
questao2: $(OBJ_DIR)/questao2/main2.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/lista $^
	@echo "+++ [Executavel 'lista' criado em $(BIN_DIR)] +++"
	@echo "============="

$(OBJ_DIR)/questao2/main2.o: $(SRC_DIR)/questao2/main2.cpp $(INC_DIR)/questao2/lista.h
	$(CC) -c $(CFLAGS) -o $@ $<

questao3: CFLAGS+= -I$(INC_DIR)/questao3
questao3: $(OBJ_DIR)/questao3/aluno.o $(OBJ_DIR)/questao3/turma.o $(OBJ_DIR)/questao3/main3.o 
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/turmas $^
	@echo "+++ [Executavel 'turmas' criado em $(BIN_DIR)] +++"
	@echo "============="

$(OBJ_DIR)/questao3/aluno.o: $(SRC_DIR)/questao3/aluno.cpp $(INC_DIR)/questao3/aluno.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJ_DIR)/questao3/turma.o: $(SRC_DIR)/questao3/turma.cpp $(INC_DIR)/questao3/turma.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJ_DIR)/questao3/main3.o: $(SRC_DIR)/questao3/main3.cpp
	$(CC) -c $(CFLAGS) -o $@ $<
doxy:
	doxygen -g

doc:
	$(RM) $(DOC_DIR)/*
	doxygen

clean:
	$(RM) $(BIN_DIR)/*
	$(RM) $(OBJ_DIR)/*

