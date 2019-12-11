/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

void update_board(void);
int inicializacion(void);
int move (void);



enum MYKEYS {
    KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT //arrow keys
};
#include "structs.h"
#include "joydrv.h"
#include "disdrv.h"
#include "game.h"
#include <stdio.h>

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

#include "termlib.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h> 
#include <allegro5/allegro_color.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_audio.h>

#define FPS    60.0
#define HEIGHT 836
#define WIDTH  1100
#define CUADRADITO_SIZE 32
#define MOVE_RATE  4.0

    ALLEGRO_DISPLAY  *display=NULL;     //punteros que apuntan a un estructuras de allegro, se los apuntan a NULL para controlar errores
    ALLEGRO_BITMAP *imagen=NULL;
    ALLEGRO_EVENT_QUEUE * event_queue =NULL;
    ALLEGRO_SAMPLE *sample=NULL;

    void closepro(void);

void create_pantalla(void);

 void update_board(void);
    
    

int inicializacion (void){
    

    int portAux;        //puerto que me guarda la configuracion actual del puerto para hacerlo parpadear
    int close_display = 0;
    
    if (!al_init()){        //inicializacion general del allegro
        fprintf (stderr, "error al inicializar el allegro\n");
        return -1;
    }
    
   
 
    
    
    event_queue = al_create_event_queue();       //se inicializa los eventos
    
    if (!event_queue) {                         //se controla si fallo la init de los eventos
        fprintf(stderr, "failed to create event_queue!\n");
        return -1;
    }
   
   
    if (!al_init_primitives_addon()){       //se controla si fallo la inicializacion de las primitivas
        fprintf (stderr, "error al inicializar las primitivas\n");
        return -1;
    }
    
    /*if (!al_init_image_addon()) { // ADDON necesario para manejo(no olvidar el freno de mano) de imagenes 
        fprintf(stderr, "failed to initialize image addon !\n");
        return -1;
    }
    
    image = al_load_bitmap("image.jpg");
    
    if (!image) {
        fprintf(stderr, "failed to load image !\n");
        return 0;
    }
    */
    
    
    
    display=al_create_display(WIDTH,HEIGHT); 
     
    //se crea el display
    
    al_register_event_source(event_queue, al_get_display_event_source(display)); //se registra la fuente de los eventos de cierre de display
    
    if(!display){
        al_shutdown_primitives_addon();      //se destruye la imagen porque ocupa espacio en heap y el programa fallo por otro motivo
       fprintf(stderr,"failed to create display");
        
        return -1;
    }
    
    
    al_clear_to_color(al_color_name("blue"));          //se pinta las dos caras del display con blanco
    al_flip_display();
    al_clear_to_color(al_color_name("blue"));
    //al_draw_bitmap(image,0 , 0 , 0);
   
    
    create_pantalla();  //se crea el puerto A 
    
    
    
}


void create_pantalla(void){           //se crea el grafico del puerto A(los 8flags)
    int i,j;
    
    for(i=0;i<16;i++)
    for(j=0;j<12;j++){  
        
     
                al_draw_rectangle( WIDTH*(j+6)/25, HEIGHT*(i+2)/19 ,WIDTH*(j+6+1)/25,HEIGHT*(i+1+2)/19,  al_color_name("grey"),0);
                al_draw_filled_rectangle( WIDTH*(j+6)/25, HEIGHT*(i+2)/19 ,WIDTH*(j+6+1)/25,HEIGHT*(i+1+2)/19,  al_color_name("black"));
                
                
    }
        al_draw_rectangle( WIDTH*6/25, HEIGHT*2/19 ,WIDTH*18/25,HEIGHT*18/19,  al_color_name("grey"),10);
        al_flip_display();
        
    
        
        
}

int move(void){
    
    
    return 0;
    
}

void closepro(void){
    
    al_destroy_bitmap(imagen);       //se libera la memoria dinamica , destruyendo los elemntos usados
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    al_shutdown_primitives_addon();
    al_destroy_sample(sample);
    al_uninstall_audio();
    printf ("bye\n");
    
    
}

void update_board(void){
    
    int i,j;
    
    for(i=0;i<NFil;i++){
        for(j=0;j<NCol;j++){
            
            if(gameboard[i+4][j]){
                
                switch(gameboard[i+4][j]){
                    
                    case 1: 
                    case 11:
                        al_draw_filled_rectangle( WIDTH*(j+6)/25, HEIGHT*(i+2)/19 ,WIDTH*(j+6+1)/25,HEIGHT*(i+1+2)/19,  al_color_name("blue"));
                         break;
                    case 2:
                    case 12:
                        al_draw_filled_rectangle( WIDTH*(j+6)/25, HEIGHT*(i+2)/19 ,WIDTH*(j+6+1)/25,HEIGHT*(i+1+2)/19,  al_color_name("yellow"));
                         break;
                    case 3:
                    case 13:
                        al_draw_filled_rectangle( WIDTH*(j+6)/25, HEIGHT*(i+2)/19 ,WIDTH*(j+6+1)/25,HEIGHT*(i+1+2)/19,  al_color_name("red"));
                         break;
                    case 4:
                    case 14:
                        al_draw_filled_rectangle( WIDTH*(j+6)/25, HEIGHT*(i+2)/19 ,WIDTH*(j+6+1)/25,HEIGHT*(i+1+2)/19,  al_color_name("green"));
                         break;
                    case 5:
                    case 15:
                        al_draw_filled_rectangle( WIDTH*(j+6)/25, HEIGHT*(i+2)/19 ,WIDTH*(j+6+1)/25,HEIGHT*(i+1+2)/19,  al_color_name("blue"));
                         break;
                    case 6:
                    case 16:
                        al_draw_filled_rectangle( WIDTH*(j+6)/25, HEIGHT*(i+2)/19 ,WIDTH*(j+6+1)/25,HEIGHT*(i+1+2)/19,  al_color_name("orange"));
                         break;
                    case 7:
                    case 17:
                        al_draw_filled_rectangle( WIDTH*(j+6)/25, HEIGHT*(i+2)/19 ,WIDTH*(j+6+1)/25,HEIGHT*(i+1+2)/19,  al_color_name("violet"));
                         break;

               
                }
            }
            else{
                al_draw_filled_rectangle( WIDTH*(j+6)/25, HEIGHT*(i+2)/19 ,WIDTH*(j+6+1)/25,HEIGHT*(i+1+2)/19,  al_color_name("black"));
                
            }
        }
    }
    
   
}