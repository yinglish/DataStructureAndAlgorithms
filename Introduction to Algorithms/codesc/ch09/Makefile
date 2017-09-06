.RECIPEPREFIX = >

objects = main.o commons.o find_max_min.o randomized_select.o

main: $(objects)
> gcc -Wall $(objects) -o main

commons.o: commons.h commons.c 
> gcc -Wall -c commons.c

find_max_min.o: find_max_min.h find_max_min.c 
> gcc -Wall -c find_max_min.c 

randomized_select.o: randomized_select.h randomized_select.c 
> gcc -Wall -c randomized_select.c 

main.o: commons.h find_max_min.h main.c randomized_select.h
> gcc -Wall -c main.c

.PHONY: clean

clean: 
> rm main $(objects)