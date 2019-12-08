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

int print_pieza(int n);
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
    
    for(i=0;i<VNFil;i++){
        for(j=0;j<NCol;j++){
            pos.x=j;
            pos.y=i;
            if(gameboard[i+5][j]){
                
                disp_write(pos,D_ON);
                
            }
            else{
                disp_write(pos,D_OFF);
            }
        }
    }
}

int print_pieza(int n){
	
    int cont=1,i,j;
    
    for(i=0;i<piezas[n].size;i++){
        for(j=0;j<piezas[n].size;j++){
            
            
            
                gameboard[i+piezas[n].pos.y][j+piezas[n].pos.x]=piezas[n].values[i*piezas[n].size+j];
            
            
        }
    }
    
             
        
        return cont;
        
}
   