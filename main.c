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

int gameboard[NFil][NCol];
void update_board(void);
void inicializacion(void);
int move (void);
void print_pieza(int n);
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
    int n;
    disp_update();
    
    while(1){
        
        n=gen_pieza();
        printf("pieza numero:%d\n",n);
        int cont;
        cont=1;
        print_pieza(n);
        update_board();
        
        
        while(cont){
            int get_move;
            get_move=move();
            
            
            
            
            
            if(check_right(n) && get_move> 0){
                 
                 
                 piece_right(n);
                 
            
            }
            else if(check_left(n) && get_move< 0){
                
                piece_left(n);
                 
                 
            }
            
            cont=check_down(n);
            
            if(cont){
            
                piece_down(n);  
            }  
                 
            
            update_board();
            disp_update();
            
            
            usleep(1000000);
    }
        clean_struct(n);
}
}  
    
  
   