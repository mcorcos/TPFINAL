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
    
    while(1){
        
        n=gen_pieza();
        
        int cont=1;
        
        while(cont){
                
            if(check_right(n) && move()> 0){
                 
                 
                 piece_right(n);
                 
            
            }
            else if(check_left(n) && move < 0){
                
                piece_left(n);
                 
                 
            }
            else{
                 cont=check_down(n);
                  piece_down;  
                 
                 
            }
            update_board();
            clean_struct(n);
            uspleep(200000);
    }
}
}  
    
    
    
   