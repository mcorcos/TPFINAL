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
#include <pthread.h>



#define  ONE_MS    	1000	   // One mseg
#define  time_delay(x)  (x/100)    // x in ms , minvalue 100mseg


int gameboard[VNFil+1][NCol];


void update_board(void);
void inicializacion(void);
int move (void);

void printboard (void);
 
/*

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
*/

int piece_set_down=0,finish=0,moving=0;
unsigned int TimerTick=4;
int n,end=1;
int get_move,conta,timex;





void* thread_timer()  // Time base Thread
{
    while(end)
    {
        if(conta>=7){
            timex-=20;
            conta=0;
        }
		usleep(timex*ONE_MS); // 100ms * 
		if (TimerTick){
			
                    TimerTick--;
                        printf("soy tick--\n\n");
                }
    }
}

void* thread_down(){ // Periodic Task Thread


	
	while (end) 
	{
            if(!TimerTick && finish){
                printf("soy Down\n\n");
                if(check_down(n)){
                   
                    printf("bajo");
                    
                    piece_down(n);
                                      
                }
                else{
                    piece_set_down=1;
                }
                finish=0;
                TimerTick=4;
            }
	}
}


void * thread_joy(){ // Periodic Task Thread


	
	while (end) 
	{
            printf("%d\n",end);
            if(joy_get_switch() == J_NOPRESS){
                end=0;
            }

	}
}





void * thread_newpiece(){ // Periodic Task Thread



	
	while (end){
            if(piece_set_down && moving){
                
                printf("soy newpiece\n\n");
                n=gen_pieza();
                printf("pieza numero:%d\n",n);
                print_pieza(n);
                piece_set_down=0;
                moving=0;
                conta++;
                
            }

	}
}

void * thread_move(){ // The APP
	while (end){
            if(TimerTick && piece_set_down==0){
                printf("soy move\n\n");
                get_move=move();
                
                usleep(timex*ONE_MS);               
                if( get_move==2 ){

                    int rot;
                    rot=rotate(n);

                    if(rot){
                        print_pieza(n);
                    }
                }

                if( get_move==1 && !check_right(n) ){


                    piece_right(n);


                }

                if( get_move==-1 && !check_left(n)){

                    piece_left(n);


                }
                if( get_move==-2 ){

                    down(n);

                }                

                update_board();
                disp_update();
                finish=1;

            }
        }

}

void * thread_check_board(){
    while(end){
        
        if(piece_set_down && (!moving)){
            printf("soy chek\n\n");
            stayed_blocks(); 
            clean_struct(n);
 //           check_board();
            moving=1;
            
        }
    }
}



int main()
{
        pthread_t tid1,tid2,tid3,tid4,tid5;
        srand(time(NULL));
        
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
        
        n=gen_pieza();
        printf("pieza numero:%d\n",n);

        print_pieza(n);
        update_board();
        disp_update();

        pthread_create(&tid1,NULL,thread_timer,NULL);
        pthread_create(&tid4,NULL,thread_newpiece,NULL);
        pthread_create(&tid2,NULL,thread_down,NULL);
        pthread_create(&tid3,NULL,thread_move,NULL);
        pthread_create(&tid5,NULL,thread_check_board,NULL);        
 //       pthread_create(&tid5,NULL,thread_joy,NULL);        
        pthread_join(tid1,NULL);
        pthread_join(tid2,NULL);
        pthread_join(tid3,NULL);
        pthread_join(tid4,NULL);
        pthread_join(tid5,NULL);
        return 0;
}
  
   
