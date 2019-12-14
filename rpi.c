/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#define THRESHOLD 40
#include "structs.h"
#include "joydrv.h"
#include "disdrv.h"
#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

extern ARR_PIECES piezas[];
extern NUM nums[5];

void update_board(void);
void inicializacion(void);
int move (void);
void print_menu (void);


void print_menu (void){
    
    int i,j,chosen_mode,chosen_diff,palabra,numero,get_move;
    
                while(move()!=10){

                    get_move=move();
                    
                    switch(get_move){
                        case 2: 
                                printf("llegue\n");
                                if(palabra>0){
                                    palabra--;
                                    clear_board();
                                }
                                break;

                        case -2:
                                printf(" llegue 646\n");                            
                                if(palabra<1){
                                    palabra++;
                                }
                                break;
                    }
                    letter_left(palabra);
                }
                
                clear_board();
                chosen_mode=palabra;
                
                get_move=1;
     
                while(get_move != 10){
                    
                    get_move=move();
                    
                    switch(get_move){
                        case 1: 
                                printf("llegue a la x");
                                if(numero<5){
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
                    for(i=0;i<nums[numero].size;i++){
                        for(j=0;j<nums[numero].size;j++){

                            if(nums[numero].values[i*(nums[numero].size)+j] ){


                             gameboard[nums[numero].pos.y+i][j+nums[numero].pos.x]=nums[numero].values[i*(nums[numero].size)+j];

                            }

                        }
                    } 
                }
                
                clear_board();
                chosen_diff=numero;
                create_floor();
                init_game(chosen_mode,chosen_diff);    

}


int move (void){
    
    jcoord_t coord={0,0};
    joy_update();
    int get_move=0;
    
    coord=joy_get_coord();
    
    usleep(25000);
    if(coord.x > THRESHOLD){
        get_move=1;
    }
    if(coord.x < (-1)*THRESHOLD){
        get_move=-1;
    }
    if(coord.y > (2*THRESHOLD)){
        get_move=2;
        usleep(50000);
    }
    if(coord.y < (-2)*THRESHOLD){
        get_move=-2;
    }
    if(joy_get_switch()==J_PRESS){
        get_move=10;
    }
    return get_move;
}

void inicializacion (void){
    joy_init();
    disp_init();
    disp_clear();
    int i;
}

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
    disp_update();
}



