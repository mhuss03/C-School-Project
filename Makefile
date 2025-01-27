# Compiler and flags
CC = gcc
CFLAGS = -Wall -g -Iinclude

# Directories
SRCDIR = src
INCDIR = include
OBJDIR = obj

# Source and object files
SRCS = main.c $(SRCDIR)/student.c $(SRCDIR)/teacher.c $(SRCDIR)/cli.c $(SRCDIR)/grade.c
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)

# Output executable
TARGET = program

# Default rule to build the program
all: $(TARGET)

# Rule to link object files into the final executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

# Rule to compile .c files into .o files
$(OBJDIR)/%.o: %.c
	mkdir -p $(OBJDIR)/$(dir $<)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule to remove compiled files
clean:
	rm -rf $(OBJDIR) $(TARGET)

# Phony targets
.PHONY: all clean
