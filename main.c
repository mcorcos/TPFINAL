/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: manucorcos
 *
 * Created on December 4, 2019, 4:21 PM
 */
#include <stdio.h>
#include <stdlib.h>
#include    "structs.h"
#include    "game.h"
#include    "disdrv.h"
#include <unistd.h>
#include "joydrv.h"


int gameboard[VNFil][NCol];

void update_board(void);
void inicializacion(void);
int move (void);
int print_pieza(int n);
void printboard (void);

int main (void){
    
    clean_struct(0);
    clean_struct(1);
    clean_struct(2);
    clean_struct(3);
    clean_struct(4);
    clean_struct(5);
    clean_struct(6);
    
    init_blocks();
    inicializacion();
    
    disp_update();
    
    do{
        
        int n;
        n=gen_pieza();
        printf("pieza numero:%d\n",n);
        int cont;
        cont=1;
        
        cont=print_pieza(n);
        update_board();
        disp_update();
        
        while(cont){
            int get_move;
            get_move=move();
            
            
            
            
            
            if( get_move> 0 && !check_right(n) ){
                 
                 
                piece_right(n);
                printf("its moving,Well done sir\n");
            
            }
/*
            else if( get_move< 0 && check_left(n)){
                
                piece_left(n);
                 
                 
            }
*/
            
            cont=check_down(n);
            
            if(cont){
            
                piece_down(n);  
            }  
                 
            
            update_board();
            disp_update();
            
            
            usleep(200000);
    }
        clean_struct(n);

    }while(joy_get_switch() == J_NOPRESS);

	

}  
    
  
   
