e3: e3.o e9.o
	gcc -Wall -o e3 e3.o e9.o -lallegro -lallegro_main -lallegro_primitives -lallegro_image -lallegro_font -lallegro_ttf

e3.o: e9.h e3.c
	gcc -c -Wall e3.c

e9.o: e9.h e9.c
	gcc -c -Wall e9.c

clean:
	rm -f *.o e3