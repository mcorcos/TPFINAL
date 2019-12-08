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


void update_board(void);
void inicializacion(void);
int move (void);


int move (void){
    
    jcoord_t coord={0,0};
    joy_update();
    int get_move;
    
    coord=joy_get_coord();
    
    if(coord.x > THRESHOLD){
        get_move=1;
    }
    if(coord.x < THRESHOLD){
        get_move=-1;
    }
    
    return get_move;
}

void inicializacion (void){
    joy_init();
    disp_init();
    disp_clear();
}

void update_board(void){
    
    int i,j;
    dcoord_t pos;
    
    for(i=0;i<16;i++){
        for(j=0;j<NCol;j++){
            pos.x=j;
            pos.y=i;
            if(gameboard[i][j]){
                
                disp_write(pos,D_ON);
                
            }
            else{
                disp_write(pos,D_OFF);
            }
        }
    }
}

