#include <stdio.h>
#include <stdlib.h>
#include "simuladorPuertos.h"

/*
//PINES DE MI PLACA DE IZQUIERDA A DERECHA
//0
pin_t pin17;
pin17.value_path="/sys/class/gpio/gpio17/value";
pin17.direction_path="/sys/class/gpio/gpio17/direction";
pin17.number="17";

//01
pin_t pin4;
pin4.value_path="/sys/class/gpio/gpio4/value";
pin4.direction_path="/sys/class/gpio/gpio4/direction";
pin4.number="4";

//02
pin_t pin18;
pin18.value_path="/sys/class/gpio/gpio18/value";
pin18.direction_path="/sys/class/gpio/gpio18/direction";
pin18.number="18";

//03
pin_t pin23;
pin23.value_path="/sys/class/gpio/gpio23/value";
pin23.direction_path="/sys/class/gpio/gpio23/direction";
pin23.number="23";

//04
pin_t pin24;
pin23.value_path="/sys/class/gpio/gpio24/value";
pin23.direction_path="/sys/class/gpio/gpio24/direction";
pin23.number="24";

//05
pin_t pin25;
pin23.value_path="/sys/class/gpio/gpio25/value";
pin23.direction_path="/sys/class/gpio/gpio25/direction";
pin23.number="25";

//06
pin_t pin22;
pin22.value_path="/sys/class/gpio/gpio22/value";
pin22.direction_path="/sys/class/gpio/gpio22/direction";
pin22.number="22";

//07
pin_t pin27;
pin22.value_path="/sys/class/gpio/gpio27/value";
pin22.direction_path="/sys/class/gpio/gpio27/direction";
pin22.number="27";

*/

pin_t pines[8] = {
    {"/sys/class/gpio/gpio17/value", "/sys/class/gpio/gpio17/direction", "17", '0'}, // 0
    {"/sys/class/gpio/gpio4/value",  "/sys/class/gpio/gpio4/direction",  "4",  '0'}, // 1
    {"/sys/class/gpio/gpio18/value", "/sys/class/gpio/gpio18/direction", "18", '0'}, // 2
    {"/sys/class/gpio/gpio23/value", "/sys/class/gpio/gpio23/direction", "23", '0'}, // 3
    {"/sys/class/gpio/gpio24/value", "/sys/class/gpio/gpio24/direction", "24", '0'}, // 4
    {"/sys/class/gpio/gpio25/value", "/sys/class/gpio/gpio25/direction", "25", '0'}, // 5
    {"/sys/class/gpio/gpio22/value", "/sys/class/gpio/gpio22/direction", "22", '0'}, // 6
    {"/sys/class/gpio/gpio27/value", "/sys/class/gpio/gpio27/direction", "27", '0'}  // 7
};

int mostrarLED(pin_t pin) {
    FILE *handle_export;
    FILE *handle_direction;
    FILE *handle;
    int nWritten;

    // --- 1. EXPORTAR EL PIN ---
    if ((handle_export = fopen("/sys/class/gpio/export", "w")) == NULL) {
        printf("Cannot open EXPORT File. Try again later.\n");
        exit(1);
    }

    nWritten = fputs(pin.number, handle_export); // Comillas rectas corregidas

    if (nWritten == -1) {
        printf("Cannot EXPORT PIN. Try again later.\n");
        exit(1);
    } else {
        printf("EXPORT File opened successfully\n");
    }
    fclose(handle_export); 


    // --- 2. CONFIGURAR DIRECCIÓN (SALIDA) ---
    if ((handle_direction = fopen(pin.direction_path, "w")) == NULL) {
        printf("Cannot open DIRECTION File.\n");
        exit(1);
    }

    if ((nWritten = fputs("out", handle_direction)) == -1) {
        printf("Cannot open DIRECTION pin. Try again later.\n");
        exit(1);
    } else {
        printf("DIRECTION File for PIN opened successfully\n");
    }
    fclose(handle_direction); 


    // --- 3. PRENDER EL LED (ESCRIBIR '1') ---
    if ((handle = fopen(pin.value_path, "w")) == NULL) {
        printf("Cannot open device. Try again later.\n");
        exit(1);
    } else {
        printf("Device successfully opened\n");
    }

    // Nota: Escribir '1' pone el pin en HIGH (Prende el LED)
    if (fputc(pin.value, handle) == -1) { 
        printf("Set_Pin: Cannot write to file. Try again later.\n");
        exit(1);
    } else {
        printf("Write to file %s successfully done. LED encendido.\n", pin.value_path);
    }
    fclose(handle);

    return 0;
}

void mostrarLEDS(puertoUsuario_t puertoUsado){

    int i;

			for(i=7; i>=0; i--){
                
                (pines[i]).value = '0'+ bitGet(puertoUsado,i);

				mostrarLED(pines[i]);
			}

}