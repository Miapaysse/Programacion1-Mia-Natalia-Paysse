
simular: main.o simuladorPuertos.o
	gcc -Wall -g -o simular main.o simuladorPuertos.o

main.o: simuladorPuertos.h main.c
	gcc -c -Wall main.c

simuladorPuertos.o: simuladorPuertos.h simuladorPuertos.c
	gcc -c -Wall simuladorPuertos.c

# Limpieza
clean:
	rm -f *.o simular