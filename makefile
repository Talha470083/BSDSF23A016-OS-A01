# ==============================
# Makefile for Dynamic Build
# ==============================

CC      = gcc
CFLAGS  = -Wall -Iinclude -fPIC
LDFLAGS = -Llib -lmyutils

# Directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
LIB_DIR = lib

# Sources and Objects
SRCS = $(SRC_DIR)/myfilefunctions.c $(SRC_DIR)/mystrfunctions.c
OBJS = $(OBJ_DIR)/myfilefunctions.o $(OBJ_DIR)/mystrfunctions.o

# Targets
LIB  = $(LIB_DIR)/libmyutils.so
CLIENT = $(BIN_DIR)/client_dynamic

# Default target
all: $(CLIENT)

# Rule to build client
$(CLIENT): $(OBJ_DIR)/main.o $(LIB)
	$(CC) $(OBJ_DIR)/main.o -o $(CLIENT) $(LDFLAGS)

# Rule to build dynamic library
$(LIB): $(OBJS)
	$(CC) -shared -o $(LIB) $(OBJS)

# Compile main
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c include/myfilefunctions.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.c -o $(OBJ_DIR)/main.o

# Compile other .c files into position-independent .o files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c include/myfilefunctions.h
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJ_DIR)/*.o $(LIB) $(CLIENT)

.PHONY: all clean
























































