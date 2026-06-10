#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>

int main(void) {

    // --- Inicialización ---
    if (!al_init()) {
        fprintf(stderr, "Error iniciando Allegro\n");
        return -1;
    }

    al_init_primitives_addon();
    al_install_keyboard();

    ALLEGRO_DISPLAY *display = al_create_display(600, 200);
    if (!display) {
        fprintf(stderr, "No se pudo crear display\n");
        return -1;
    }

    // --- Estados de 8 LEDs ---
    // 1 = encendido, 0 = apagado
    int leds[8] = {1, 0, 1, 0, 1, 1, 0, 1};

    // --- Dibujar una vez ---
    al_clear_to_color(al_map_rgb(0, 0, 0)); // fondo negro

    for (int i = 0; i < 8; i++) {

        float x = 50 + i * 70;  // separación horizontal
        float y = 100;
        float r = 25;           // radio del LED

        if (leds[i] == 1) {
            // LED encendido (verde)
            al_draw_filled_circle(x, y, r, al_map_rgb(0, 255, 0));
        } else {
            // LED apagado (gris)
            al_draw_filled_circle(x, y, r, al_map_rgb(80, 80, 80));
        }
    }

    al_flip_display();

    // --- Mantener la ventana abierta ---
    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(display));

    bool running = true;
    while (running) {

        ALLEGRO_EVENT event;
        al_wait_for_event(queue, &event);

        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            running = false;
        }

        if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
            if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
                running = false;
            }
        }
    }

    // --- Liberar recursos ---
    al_destroy_event_queue(queue);
    al_destroy_display(display);

    return 0;
}