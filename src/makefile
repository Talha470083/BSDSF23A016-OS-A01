# src/Makefile -- builds objects and links to ../bin/client
CC ?= gcc
CFLAGS ?= -Wall -Wextra -g -I../include
LDFLAGS ?= 
SRCDIR := .
OBJDIR := obj
BINDIR := ../bin

SOURCES := $(wildcard $(SRCDIR)/*.c)
OBJECTS := $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SOURCES))
TARGET := $(BINDIR)/client

.DEFAULT_GOAL := all

.PHONY: all clean run test

all: $(TARGET)

# ensure directories
$(BINDIR):
	@mkdir -p $(BINDIR)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

# Link rule: links object files into final executable
$(TARGET): $(OBJECTS) | $(BINDIR)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJECTS)

# Pattern rule: compile each .c -> obj/.o
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	@echo "Running $(TARGET)..."
	@./$(TARGET)

test: run

clean:
	@rm -rf $(OBJDIR) $(BINDIR)

