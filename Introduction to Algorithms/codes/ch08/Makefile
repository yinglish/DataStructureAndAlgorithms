.RECIPEPREFIX = >

objects = commons.o counting_sort.o main.o radix_sort.o

main: $(objects)
> gcc -Wall $(objects) -o main

commons.o: commons.h commons.c 
> gcc -Wall -c commons.c 

counting_sort.o: counting_sort.h counting_sort.c 
> gcc -Wall -c counting_sort.c 

radix_sort.o: radix_sort.h counting_sort.h radix_sort.c

main.o: main.c radix_sort.h counting_sort.h
> gcc -Wall -c main.c 

.PHONY: clean

clean:
> rm $(objects) main