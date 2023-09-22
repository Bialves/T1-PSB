# Comandos
CC = gcc
CFLAGS = -Wall -O2
ARCHIVE = ar rcs
# Diretórios
OBJ = ./obj/
LIB = ./lib/

clean:
	rm -f main ./images/out/*.ppm ./obj/*.o ./lib/*.a

main.o: main.c
	$(CC) $(CFLAGS) -c main.c $(OBJ)main.o

lib_ppm.o: lib_ppm.c
	$(CC) $(CFLAGS) -c lib_ppm.c -o $(OBJ)lib_ppm.o

filter_grayscale.o: filter_grayscale.c
	$(CC) $(CFLAGS) -c filter_grayscale.c -o $(OBJ)filter_grayscale.o

filter_threshold.o: filter_threshold.c
	$(CC) $(CFLAGS) -c filter_threshold.c -o $(OBJ)filter_threshold.o

filter_sobel.o: filter_sobel.c
	$(CC) $(CFLAGS) -c filter_sobel.c -o $(OBJ)filter_sobel.o

filter_roberts.o: filter_roberts.c
	$(CC) $(CFLAGS) -c filter_roberts.c -o $(OBJ)filter_roberts.o

lib_ppm.a: lib_ppm.o filter_grayscale.o filter_threshold.o filter_sobel.o filter_roberts.o
	$(ARCHIVE) $(LIB)lib_ppm.a $(OBJ)lib_ppm.o $(OBJ)filter_grayscale.o $(OBJ)filter_threshold.o $(OBJ)filter_sobel.o $(OBJ)filter_roberts.o  

link: lib_ppm.a
	$(CC) -o main main.c -L. -l:$(LIB)lib_ppm.a

run: link
	./main