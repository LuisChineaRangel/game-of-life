CC=g++
CFLAGS=-g

BIN_DIR=bin
OBJECTS_DIR=build
SRC_DIR=src
INCLUDE_DIR=include

_OBJ = Game.o Board.o Cell.o
OBJ = $(patsubst %,$(OBJECTS_DIR)/%,$(_OBJ))

BIN_NAME = Game

all: $(BIN_DIR)/$(BIN_NAME)

$(BIN_DIR)/$(BIN_NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJECTS_DIR)/Cell.o: $(SRC_DIR)/Cell.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJECTS_DIR)/Board.o: $(SRC_DIR)/Board.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJECTS_DIR)/Game.o: $(SRC_DIR)/Game.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: run
run:
	@./$(BIN_DIR)/$(BIN_NAME)

.PHONY: clean
clean:
	@rm -rf $(BIN_DIR)/$(BIN_NAME) $(OBJECTS_DIR)/*.o
