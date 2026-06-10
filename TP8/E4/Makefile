e4: backend.h main.o backend.o
	gcc -Wall -g -o e4 main.o backend.o

main.o: backend.h main.c
	gcc -Wall -c main.c

backend.o: backend.c backend.h
	gcc -Wall -c backend.c