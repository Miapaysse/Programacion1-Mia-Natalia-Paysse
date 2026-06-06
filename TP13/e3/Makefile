cajero: main.o display.o 
	gcc -Wall  -o cajero main.o display.o

main.o: mensajes.h display.h main.c 
	gcc -Wall -c main.c

display.o: display.h display.c
	gcc -Wall -c display.c

# Limpieza
clean:
	rm -f *.o e3