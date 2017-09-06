CC=gcc
CFLAGS=-Wall -Wextra -Werror 
OBJ = insertion_sort.o commons.o main.o 

Goal: $(OBJ) build clean

commons.o: commons.c commons.h
	$(CC) -c commons.c $(CFLAGS)

insertion_sort.o: insertion_sort.c insertion_sort.h
	$(CC) -c insertion_sort.c $(CFLAGS)
main.o: main.c
	$(CC) -c main.c $(CFLAGS)
build: $(OBJ)
	$(CC) -o main $(OBJ) $(CFLAGS)

clean:
	rm *.o

