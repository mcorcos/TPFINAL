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
extern ARR_PIECES piezas[];


void update_board(void);
void inicializacion(void);
int move (void);



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
    for(i=0;i<NFil;i++){
        
        static dcoord_t pos;
        pos.y=i;
        pos.x=NCol;
        
        disp_write(pos,D_ON);
        
    }
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



