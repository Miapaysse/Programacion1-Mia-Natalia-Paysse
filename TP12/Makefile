
simular: main.o simuladorPuertos.o manejoLEDS.o
	gcc -Wall -g -o simular main.o simuladorPuertos.o manejoLEDS.o

main.o: simuladorPuertos.h main.c
	gcc -c -Wall main.c

manejoLEDS.o: manejoLEDS.h simuladorPuertos.h manejoLEDS.c
	gcc -c -Wall manejoLEDS.c

simuladorPuertos.o: simuladorPuertos.h simuladorPuertos.c
	gcc -c -Wall simuladorPuertos.c

# Limpieza
clean:
	rm -f *.o simular