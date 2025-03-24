# Makefile with variables
P = main
OBJECTS = main.o MyDLL.o 
CFLAGS = -g -Wall -O3
LDLIBS = 
CC = gcc

# Compilação do projeto 
$(P): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(P) $(OBJECTS)

# Compilação dos arquivos
%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza dos arquivos compilados 
clean:
	rm *.o $(P)