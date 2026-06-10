#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include "e9.h"
#define ISLETTER(c) (  ( ('a'<=(c)) && ((c)<='z') )||( ('A'<=(c)) && ((c)<='Z') )  )
#define ISNUMBER(c) ( ('0'<=(c)) && ((c)<='9') )
#define TODO 0xFF
#define INTERVALO 0.5
void mostrar_LEDS(uint8_t* puerto, ALLEGRO_DISPLAY *display);
/*
Escribir un programa que utilice la librería escrita en el ejercicio 5 para simular que se
tienen 8 LEDs conectados al puerto A. Se debe usar la librería creada en el ejercicio 1,
y mostrar el estado de los LEDs en pantalla.
• Por teclado, el usuario ingresará el número (del 0 al 7) del LED que se desea prender, en tiempo real.
• Con la letra 't', todos los LEDs deben cambiar al estado opuesto (si están encendidos
apagarse y si están apagados encenderse).
• Con la letra 'c', se deberán apagar todos, y con 's', prender.
• Con la letra 'q', el programa finalizará.

*/

// ============================================================
//                      MAIN
// ============================================================

int main(void) {

    uint8_t *puertoA = getPuertoA();

    // ----- Init Allegro -----
    if (!al_init()) {
        fprintf(stderr, "Error iniciando Allegro\n");
        return -1;
    }

    al_init_primitives_addon();
    al_install_keyboard();

    ALLEGRO_DISPLAY *display = al_create_display(620, 200);
    if (!display) {
        fprintf(stderr, "No se pudo crear display\n");
        return -1;
    }
    
    ALLEGRO_TIMER *timer = al_create_timer(INTERVALO);  // 0.5 seg intervalo
    
    // ----- Cola de eventos -----
    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_timer_event_source(timer));
    
    
    al_start_timer(timer);

    // Dibujar por primera vez
    mostrar_LEDS(puertoA, display);

    // ============================================================
    //                   LOOP PRINCIPAL
    // ============================================================

    int running = 1;
    int parpadear=0;
    ALLEGRO_EVENT event;

    while (running) {
	
        al_wait_for_event(queue, &event);
        
        switch(event.type){

        	// ---- Cerrar ventana ----
        	case ALLEGRO_EVENT_DISPLAY_CLOSE:
            		running = 0;
        	break;
        
    		// === EVENTO: timer ===
    		case ALLEGRO_EVENT_TIMER:
       			if (parpadear) {
           	 		maskToggle(puertoA, TODO);
           	 		mostrar_LEDS(puertoA, display);
        		}
    		break;
        
        	// ---- Tecla presionada ----
        	case ALLEGRO_EVENT_KEY_DOWN:

        		int k = event.keyboard.keycode;
	
            		// Letras
           		 switch (k) {

                		case ALLEGRO_KEY_T:   // toggle
                   			maskToggle(puertoA, TODO);
                    			mostrar_LEDS(puertoA, display);
                    		break;

                		case ALLEGRO_KEY_C:   // apagar todo
                    			maskOff(puertoA, TODO);
                    			mostrar_LEDS(puertoA, display);
                    		break;

                		case ALLEGRO_KEY_S:   // prender todo
                    			maskOn(puertoA, TODO);
                    			mostrar_LEDS(puertoA, display);
                    		break;
                    
                		case ALLEGRO_KEY_B:   // parpadear todo
                			parpadear = !parpadear;

                    		break;
         
                		case ALLEGRO_KEY_ESCAPE:
                		
                		case ALLEGRO_KEY_Q:
                    			running = 0;
                    		break;
            		}
            

            		// Números 0–7 -> prender LED individual
            		if (k >= ALLEGRO_KEY_0 && k <= ALLEGRO_KEY_7 && parpadear!=1) {
                		int led = k - ALLEGRO_KEY_0;
                		bitToggle(puertoA, led);
                		mostrar_LEDS(puertoA, display);
            		}
        	break;
        	
        }
    }

    // ----- Liberar -----
    al_destroy_event_queue(queue);
    al_destroy_display(display);

    return 0;
}

void mostrar_LEDS(uint8_t* puerto, ALLEGRO_DISPLAY *display){
    int i;
    // --- Dibujar una vez ---
    al_clear_to_color(al_map_rgb(0, 0, 0)); // fondo negro

    for (i = 0; i < 8; i++) {

        float x = 50 + i * 70;  // separación horizontal
        float y = 100;
        float r = 10;           // radio del LED

        if (bitGet(puerto,7-i) == 1) {
            // LED encendido (verde)
            al_draw_filled_circle(x, y, r, al_map_rgb(255, 0, 255));
        } else {
            // LED apagado (gris)
            al_draw_filled_circle(x, y, r, al_map_rgb(80, 80, 80));
        }
    }

    al_flip_display();

}