#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *handle_export;
    FILE *handle_direction;
    FILE *handle;
    int nWritten;
    char *pin22 = "/sys/class/gpio/gpio22/value";

    // --- 1. EXPORTAR EL PIN ---
    if ((handle_export = fopen("/sys/class/gpio/export", "w")) == NULL) {
        printf("Cannot open EXPORT File. Try again later.\n");
        exit(1);
    }

    nWritten = fputs("22", handle_export); // Comillas rectas corregidas

    if (nWritten == -1) {
        printf("Cannot EXPORT PIN. Try again later.\n");
        exit(1);
    } else {
        printf("EXPORT File opened successfully\n");
    }
    fclose(handle_export); 


    // --- 2. CONFIGURAR DIRECCIÓN (SALIDA) ---
    if ((handle_direction = fopen("/sys/class/gpio/gpio22/direction", "w")) == NULL) {
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
    if ((handle = fopen(pin22, "w")) == NULL) {
        printf("Cannot open device. Try again later.\n");
        exit(1);
    } else {
        printf("Device successfully opened\n");
    }

    // Nota: Escribir '1' pone el pin en HIGH (Prende el LED)
    if (fputc('1', handle) == -1) { 
        printf("Set_Pin: Cannot write to file. Try again later.\n");
        exit(1);
    } else {
        printf("Write to file %s successfully done. LED encendido.\n", pin22);
    }
    fclose(handle);

    return 0;
}