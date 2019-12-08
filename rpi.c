/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#define THRESHOLD 40
#include "structs.h"
#include "joydrv.h"
#include "disdrv.h"
void update_board(int n);

int move (void){
    
    jcoord_t coord={0,0}
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

void update_board(int n){
    
    int i,j;
    for(i=0;i<NFil;i++){
        for(j=0;j<NCol;j++){
            
            if(gameboard[i][j]){
                disp_write(piezas[n].pos,D_ON);
                
            }
            else{
                disp_write(piezas[n].pos,D_OFF);
            }
        }
    }
}

