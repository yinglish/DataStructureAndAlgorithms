.RECIPEPREFIX =>

objects = commons.o heapsort.o main.o

main: $(objects)
>gcc -Wall $(objects) -o main

commons.o: commons.c commons.h
>gcc -Wall -c commons.c

heapsort.o: heapsort.c heapsort.h
>gcc -Wall -c heapsort.c

main.o: main.c
>gcc -Wall -c main.c 

.PHONY: clean
clean:
>rm $(objects) main