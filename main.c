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
    
  
    init_blocks();
    inicializacion();
    int n;
    
    while(1){
        
        n=gen_pieza();
        
        int cont=1;
        
        while(cont){
                
            if(check_right(n) && move()> 0){
                 
                 
                 piece_right(n);
                 update_piece(n);
            
            }
            else if(check_left(n) && move < 0){
                
                piece_left(n);
                 update_piece(n);
                 
            }
            else{
                 cont=check_down(n)
                  piece_down;  
                 update_piece;
                 
            }
            update_board();
            uspleep(200000);
    }
}
}  
    
    
    
   