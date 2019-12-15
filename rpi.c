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
extern int storage[][NCol];
extern ARR_PIECES piezas[];
extern NUM nums[5];

void update_board(void);
void inicializacion(void);
int move (void);
void print_menu (void);
void cleanall(void);
void leavestop(int n);
extern int pausa,level,piece_set_down,end;

void print_menu (void){
    
    int i,j,chosen_mode,chosen_diff,palabra=0,numero,get_move;
    
                while(move()!=10){

                    get_move=move();
                    
                    switch(get_move){
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
                    letter_left(palabra);
                    disp_update();
                }
                
                usleep(500000);
                cleanall();
                chosen_mode=palabra;
                
                get_move=0;
                while(move()==10);
                
                while(get_move != 10){
                    
                    get_move=move();
                    
                    switch(get_move){
                        case 1: 
                                printf("llegue a la x");
                                if(numero<4){
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
                    update_board();
                }
               
                    
                printf("ARRANCO");
                
                clear_board();
                update_board;
                chosen_diff=numero;
                
                
                create_floor();
                init_game(chosen_mode,chosen_diff); 
                while(move()==10);

}


int move (void){
    
    jcoord_t coord={0,0};
    joy_update();
    int get_move=0;
    
    coord=joy_get_coord();
    
    usleep(35000);
    if(coord.x > THRESHOLD){
        get_move=1;
    }
    if(coord.x < (-1)*THRESHOLD){
        get_move=-1;
    }
    if(coord.y > (100)){
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

void print_stopmenu(void){
    
    int i,j,palabra=0,numero,get_move;
        
    while(move()==10);
    cleanall();
    while(move()!=10){

                    get_move=move();
                    
                    switch(get_move){
                        case 1: 
                                printf("llegue\n");
                                if(palabra>0){
                                    palabra--;
                                    cleanall();
                                }
                                break;

                        case -1:
                                printf(" llegue 646\n");                            
                                if(palabra<5){
                                    palabra++;
                                    cleanall();
                                }
                                break;
                    }
                    
                    letter_left(palabra);
                    disp_update();
                }
                
                usleep(500000);
                cleanall();
                
                
                leavestop(palabra);
               
              
    
    
    
}

void leavestop(int n){
    
    switch(n){
        
        case 0: clear_board();
                create_floor();
               
                
                break;
       
        case 1: copy_board(gameboard,storage);
                create_floor();
                break;
       
        case 2:copy_board(storage,gameboard);
                clear_board();
                copy_board(gameboard,storage);
                
        
                create_floor();
                
                break;
        case 3: end=0;
                break;  
        case 4: create_floor();
                break;
        
        case 5: showscore();
                pausa=1;
        break;
        
            
                
            
                
                
        
        
    }
}
void showscore(void){
    
    
    
    
    
}

void copy_board(int *pllegada,int *psalida){
    
    int i,j;
    
    for(i=0;i<20;i++){
        for(j=0;j<12;j++){
            
            if(psalida[i*12+j]>7 || psalida[i*12+j]==0){
                
            
            pllegada[i*12+j]=psalida[i*12+j];
            }
        }
    }
}

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
}