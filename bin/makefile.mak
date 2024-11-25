# Definisikan variabel
CC = gcc
CFLAGS = -Wall -std=c99
OBJDIR = obj
BINDIR = bin
SRCDIR = src
INCDIR = include

# Nama file output
TARGET = mainall

# File sumber
SOURCES = $(wildcard $(SRCDIR)/*.c) $(wildcard $(SRCDIR)/ADT/*.c)
# File objek (setelah dikompilasi)
OBJECTS = $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Direktori objek dan binari
OBJDIR = $(OBJDIR)
BINDIR = $(BINDIR)

# Target utama untuk membuat file eksekusi
all: $(BINDIR)/$(TARGET)

# Membuat direktori obj dan bin jika belum ada
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

# Membuat direktori bin jika belum ada
$(BINDIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

# Untuk membersihkan file objek dan binari yang sudah dikompilasi
clean:
	rm -rf $(OBJDIR) $(BINDIR)

# Memastikan Makefile tahu file sumber yang diproses
.PHONY: all clean
