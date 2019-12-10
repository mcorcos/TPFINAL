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


int gameboard[VNFil+1][NCol];


void update_board(void);
void inicializacion(void);
int move (void);

void printboard (void);

int main (void){
    
    create_floor();
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
        
        
        print_pieza(n);
        update_board();
        disp_update();
        
        while(cont && (joy_get_switch() == J_NOPRESS)){
            int get_move;
            get_move=move();
            
            cont=check_down(n);
            
            if(cont){
            
                piece_down(n); 
            }  
              
            if( get_move==2 && cont){
                 
                int rot;
                rot=rotate(n);
                
                if(rot){
                    print_pieza(n);
                }
            }
            
            if( get_move==1 && !check_right(n) && cont ){
                 
                 
                piece_right(n);
                
            
            }

            if( get_move==-1 && !check_left(n) && cont ){
                
                piece_left(n);
                 
                 
            }
            
            
                
            
            
            
            
            
                 
            
            update_board();
            disp_update();
            
            
                   
            
            usleep(200000);
    }
        stayed_blocks();
        clean_struct(n);
        check_board();
        disp_update();
        
    }while(joy_get_switch() == J_NOPRESS );

	

}  
    
  
   
