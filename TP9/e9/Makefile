
e9: main.o e9.o
	gcc -Wall -g -o e9 main.o e9.o

main.o: e9.h main.c
	gcc -c -Wall main.c

e9.o: e9.h e9.c
	gcc -c -Wall e9.c

# Limpieza
clean:
	rm -f *.o e9