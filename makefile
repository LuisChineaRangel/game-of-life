# Compilador C++
CC=g++

# Flags del Compilador (-g, -std=c++11, -Wall, -Wextra)
CFLAGS=-g

# ESTRUCTURA CLÁSICA EN UN PROYECTO C++
# -Proyecto
#  |-bin       (Ejecutables)
#  |-build     (Ficheros Objeto)
#  |-include   (Cabeceras)
#  |-lib       (Librerías)
#  |-src       (Código Fuente)
#  |-tmp       (Ficheros Temporales)

# Directorio de los ejecutables
BIN_DIR=bin
# Directorio de los ficheros objeto (.o)
OBJECTS_DIR=build
# Directorio del código fuente (.cpp)
SRC_DIR=src
# Directorio de las cabeceras (.hpp)
INCLUDE_DIR=include

# Aquí poner todos los .cpp de tu proyecto cambiando el formato por .o
_OBJ = Juego.o Tablero.o Celula.o
OBJ = $(patsubst %,$(OBJECTS_DIR)/%,$(_OBJ))

# Nombre del Ejecutable
BIN_NAME = Juego

# Target all (lo que se ejecuta cuando haces make)
all: Juego

Juego: $(OBJ)
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$(BIN_NAME) $^

$(OBJECTS_DIR)/Celula.o: $(SRC_DIR)/Celula.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJECTS_DIR)/Tablero.o: $(SRC_DIR)/Tablero.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJECTS_DIR)/Juego.o: $(SRC_DIR)/Juego.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

# Ejecuta el programa
.PHONY: run
run:
	@./$(BIN_DIR)/$(BIN_NAME)

# Limpia el directorio del proyecto (Borra ejecutables y ficheros objeto)
.PHONY: clean
clean:
	@rm -rf $(BIN_DIR)/* $(OBJECTS_DIR)/*