# Compiler and flags
CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -O2

# Directories
SRC_DIR = src
BUILD_DIR = build
LIB_DIR = lib
BIN_DIR = bin

# Source and object files
UTILS_SRCS = $(SRC_DIR)/mystrfunctions.c $(SRC_DIR)/myfilefunctions.c
UTILS_OBJS = $(BUILD_DIR)/mystrfunctions.o $(BUILD_DIR)/myfilefunctions.o
LIBRARY = $(LIB_DIR)/libmyutils.a

MAIN_SRC = $(SRC_DIR)/main.c
# Compiler and flags
CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -O2

# Directories
SRC_DIR = src
BUILD_DIR = build
LIB_DIR = lib
BIN_DIR = bin

# Source and object files
UTILS_SRCS = $(SRC_DIR)/mystrfunctions.c $(SRC_DIR)/myfilefunctions.c
UTILS_OBJS = $(BUILD_DIR)/mystrfunctions.o $(BUILD_DIR)/myfilefunctions.o
LIBRARY = $(LIB_DIR)/libmyutils.a

MAIN_SRC = $(SRC_DIR)/main.c
MAIN_OBJ = $(BUILD_DIR)/main.o
TARGET = $(BIN_DIR)/client_static

# Installation directories
PREFIX = /usr/local
BINDIR = $(PREFIX)/bin
MANDIR = $(PREFIX)/share/man/man1

# Default target
all: $(TARGET)

# Link the final executable
$(TARGET): $(MAIN_OBJ) $(LIBRARY)
	$(CC) $(CFLAGS) $(MAIN_OBJ) $(LIBRARY) -o $(TARGET)

# Build the static library
$(LIBRARY): $(UTILS_OBJS)
	ar rcs $(LIBRARY) $(UTILS_OBJS)
	ranlib $(LIBRARY)

# Compile .c files into .o files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Install target (binary + man page)
install: $(TARGET)
	install -d $(BINDIR)
	install -m 755 $(TARGET) $(BINDIR)/client
	install -d $(MANDIR)
	install -m 644 man/man3/mycat.1 $(MANDIR)/mycat.1

# Uninstall target (removes installed files)
uninstall:
	rm -f $(BINDIR)/client
	rm -f $(MANDIR)/mycat.1

# Clean build artifacts
clean:
	rm -f $(BUILD_DIR)/*.o $(TARGET) $(LIBRARY)

.PHONY: all clean install uninstall


















