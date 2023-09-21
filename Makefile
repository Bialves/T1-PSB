CC = gcc
CFLAGS = -Wall -O2
ARCHIVE = ar rcs

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

lib_ppm.o: lib_ppm.c
	$(CC) $(CFLAGS) -c lib_ppm.c

filter_grayscale.o: filter_grayscale.c
	$(CC) $(CFLAGS) -c filter_grayscale.c

filter_threshold.o: filter_threshold.c
	$(CC) $(CFLAGS) -c filter_threshold.c

filter_sobel.o: filter_sobel.c
	$(CC) $(CFLAGS) -c filter_sobel.c

filter_roberts.o: filter_roberts.c
	$(CC) $(CFLAGS) -c filter_roberts.c

clean:
	rm -f *.o main *.ppm *.a

lib_ppm.a: lib_ppm.o filter_grayscale.o filter_threshold.o filter_sobel.o filter_roberts.o
	$(ARCHIVE) lib_ppm.a lib_ppm.o filter_grayscale.o filter_threshold.o filter_sobel.o filter_roberts.o

link: lib_ppm.a
	$(CC) -o main main.c -L. -l:lib_ppm.a

run: link
	./main