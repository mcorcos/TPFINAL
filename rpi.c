/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#define THRESHOLD 110
#include "structs.h"
#include "joydrv.h"
#include "disdrv.h"
#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "rpi.h"
#include "libaudio.h"

#include <SDL/SDL.h>

typedef struct {
    
    int *values;
    int size;
    dcoord_t pos;
    int rotacion;
    
}ARR_PIECES; 


typedef struct {
    
    int *values;
    int size;
    dcoord_t pos;    
    
}NUM; 

typedef struct {
    
    int *values;
    int sizex;
    int sizey;
    dcoord_t pos;    
    
}WORD; 


extern int storage[][NCol];
extern ARR_PIECES piezas[];
extern NUM nums[10];

extern WORD words[7];
char mySong[]= "Tetris.wav";

extern int pausa,level,piece_set_down,end,score,menu,set_menu,finish;


void print_menu (void){
    
    clean_words();
    init_words();
    int i,j,chosen_mode,chosen_diff,palabra=0,numero=0,get_move;
    
                while(move()!=10){ // espero a que se sellecione una opcion

                    get_move=move();
                    
                    switch(get_move){               //casos de joystick hacia la derecha o izquierda
                        case 1:                         
                                printf("llegue\n");
                                if(palabra>0){
                                    palabra--;
                                    cleanall();
                                }
                                break;

                        case -1:
                                printf(" llegue 646\n");                            
                                if(palabra<1){
                                    palabra++;
                                    cleanall();
                                }
                                break;
                    }
                    letter_left(palabra);      // paso la palabras por el display
                    disp_update();
                }
                
                usleep(500000); 
                cleanall();                     //una vez seleccionada la opcion,borro el display
                create_floor();
                clear_board();                  
                chosen_mode=palabra;
                
                get_move=0;
                while(move()==10);
                
                while(get_move != 10){          //casos para elegir el nivel ,sigue hasta que se seleccione un nivel
                    
                    get_move=move();
                    
                    switch(get_move){
                        case 1: 
                                printf("llegue a la x");
                                if(numero<3){
                                    numero++;
                                    clear_board();
                                }
                                break;
                        case -1:
                                printf("llegue a la x2");
                                if(numero>0){
                                    numero--;
                                    clear_board();
                                }
                                break;
                    }
                   
                    for(i=0;i<nums[numero].size;i++){               // funion que imprime el numero en el display a medida que se van eligiendo
                        for(j=0;j<nums[numero].size;j++){

                            if(nums[numero].values[i*(nums[numero].size)+j] ){


                             gameboard[nums[numero].pos.y+i][j+nums[numero].pos.x]=nums[numero].values[i*(nums[numero].size)+j];
                               
                            
                             
                            }

                        }
                    } 
                    update_board();
                    
                }
               
                    
                printf("ARRANCO");
                
                clear_board();          // limpio el numero del display
                
                chosen_diff=numero;
                
                
                create_floor();
                init_game(chosen_mode,chosen_diff);   //inicalizo el juego con lsa opciones elegidas
                while(move()==10);

}//Funcion que imrpime el menu de inicio

void print_screen(int n2){
    
}//Fuhcion que imprime stadisticas en pantalla 

int move (void){
    
    jcoord_t coord={0,0};
    joy_update();
    int get_move=0;
    
    coord=joy_get_coord();       //lee las coordenadas
    
    
    if(coord.x > THRESHOLD){         //joystick hacia la derecha
        usleep(90000);
        get_move=1;
    }
    if(coord.x < (-1)*THRESHOLD){  //joystick hacia la izquierda
       usleep(90000);
        get_move=-1;
    }
    if(coord.y > THRESHOLD){       //joystick hacia arriba 
        get_move=2;
        
        usleep(250000);
    }
    if(coord.y <  (-1)*THRESHOLD){    // joystick hacia abajo
        get_move=-2;
    }
    if(joy_get_switch()==J_PRESS){   //joystick presionado
        get_move=10;
    }
    
    return get_move;
}//Funcion que toma los movimientos del joystick

void inicializacion (void){
    joy_init();
    disp_init();
    disp_clear();
    init_sound();
    
    
} //Funcion que inicaliza jpystick,audio y display

void init_words(void){
    int i;
    for(i=0;i<7;i++){   //son 7 palabras
        
        init_word(i);
    }
}//Funcion que inicializa todas las palabras del menu

void playsongg (void){
   
    
    
    
    if(player_status()== READY){ //si es la primera vez, incia a reproducir
        
        set_file_to_play("Tetris.wav");
        play_sound();
    }
    else if(player_status()==FINISHED){ // si no es laprimera, lo cierra,lo abre y lo reproduce
        stop_sound();
        set_file_to_play("Tetris.wav");
        play_sound();
        
    }
    
   

}//Funcion que reproduce la musica

void update_board(void){            
    
    int i,j;
    dcoord_t pos;
    
    for(i=0;i<NFil;i++){
        for(j=0;j<NCol;j++){
            pos.x=j;
            pos.y=i;
            if(gameboard[i+4][j]){
                
                disp_write(pos,D_ON);
                
            }
            else{
                disp_write(pos,D_OFF);
            }
        }
    }
    disp_update();      //se actualiza el display
    playsongg();        //checkeo el estado de la musica
}//Fuhncion que actualiza el display con los datos del gameboard donde se juega

void print_stopmenu(void){
    
    
    int palabra=0,get_move;
    clean_words();
    init_words();
    while(move()==10);
    cleanall();
    
    while(move()!=10){              // espero a que se seleccione un opcion

                    get_move=move();
                    
                    switch(get_move){
                        case 1:                 //hacia laizqueirda
                                
                                if(palabra>0){
                                    palabra--;
                                    cleanall();
                                }
                                break;

                        case -1:            //hacia la derecha
                                                          
                                if(palabra<5){
                                    palabra++;
                                    cleanall();
                                }
                                break;
                    }
                    
                    letter_left(palabra);           //hago pasar la opcion hacia la izquierda por el display
                    disp_update();
                }
                
                usleep(500000);
                cleanall();         //limpio el display
                
                
                leavestop(palabra);
               
              
    
    
    
}//Funcion que imprime el menu de pausa

void leavestop(int n){
    
    switch(n){
        
        case 0: level=1;                // si es el caso de new game,incio un  nuevo juego y me djea elegir la dificultad
                clear_board();
                create_floor();
                
                
                int i,j,numero=0,get_move;
                while(get_move != 10){
                    
                    get_move=move();
                    
                    switch(get_move){
                        case 2: 
                                
                                if(numero<3){
                                    numero++;
                                    clear_board();
                                }
                                break;
                        case -2:
                                
                                if(numero>0){
                                    numero--;
                                    clear_board();
                                }
                                break;
                    }
                   
                    for(i=0;i<nums[numero].size;i++){           //imprimo los numero en display
                        for(j=0;j<nums[numero].size;j++){

                            if(nums[numero].values[i*(nums[numero].size)+j] ){


                             gameboard[nums[numero].pos.y+i][j+nums[numero].pos.x]=nums[numero].values[i*(nums[numero].size)+j];
                               
                            
                             
                            }

                        }
                    } 
                    update_board();
                }
                while(move()==10);
                init_game(1,numero);    //seteo variabkes para comenzar un nuevo juego
                clear_board();
                create_floor(); 
                piece_set_down=1;
                menu=0;
                break;
       
        case 1: copy_board((int*)gameboard,(int*)storage); // cargo el board en el display
        
                create_floor();
                menu=0;
                piece_set_down=1;
                break;
       
        case 2:copy_board((int*)storage,(int*)gameboard);       //guardo la partida en memoria para luego poder cargarla
                clear_board();                                    //borro el display
                copy_board((int*)gameboard,(int*)storage);          //vuelvo a cargar la partida
                create_floor();
                menu=0;
                
                break;
        case 3: menu=1;                                     //termino el programa
                finish=0;
                set_menu=0;
                end=0;
                break;  
        case 4: create_floor();                             //saco la pausa y continuo jugando
                menu=0;
                
                break;
        
        case 5: showscore();                            //muestro el score y vuelvo al menu de pausa
                pausa=1;
        break;
        
            
                
            
                
                
        
        
    }
}// Funcion que analiza la opcion slecciona en el menu de pausa

void showscore(void){
    
    
    int i;
    for( i=0;i<46;i++){
   
        letter_left(6);         //hago pasar el puntaje por el display
        printf("LL\n");
        disp_update();
        printf("disp\n");
    }
   
    
    
}//Funcion quemuestra el puntaje en el display

void finish_game(void){
    
    
    
    menu=1;
    usleep(500000);
    cleanall();             //borro  el diplay
    clean_words();
    usleep(500000);
    int i;
        
    for( i=0;i<36;i++){             //hago pasar la palabra score
   
        letter_left(5);
        printf("LL\n");
        disp_update();
        printf("disp\n");
    }
    
    showscore();                //muestro el score
    
    
    printf("termino");
    
    set_menu=1;
    
    
    
    
    
    
}//Funcion que muestra el score ucando termino la parrtida

void copy_board(int *pllegada,int *psalida){
    
    int i,j;
    
    for(i=0;i<20;i++){
        for(j=0;j<12;j++){
            
            if(psalida[i*12+j]>7 || psalida[i*12+j]==0){
                
            
            pllegada[i*12+j]=psalida[i*12+j];
            }
        }
    }
}//Funcion que copia un arrglo en otro y recibe un puntero al arreglo de destino y otro de salida

void cleanall(void){
    
    int i,j;
    dcoord_t pos;
    
    for(i=0;i<16;i++){
        for(j=0;j<16;j++){
            pos.x=j;
            pos.y=i;
            
                disp_write(pos,D_OFF);
            
        }
    }
    disp_update();
}//Funcion que apaga todo el dislpay

void play_sample(void){
    
}
void print_n2(void){
    
   
}//Funcion que muestra la pieza siguiente

void closepro(void){
    
}//Funcion que cierra todos los partidos
