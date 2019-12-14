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


// el viejo

/*
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


 int piece_set_down=0,finish=0;
unsigned int TimerTick=2;
int n,end=1;
int get_move,conta,timex=150;
void closepro(void);

void closepro(void){
    
    return 0;
}


void* thread_timer()  // Time base Thread
{	       
    while(end)
    {
        if(conta>=7){
            timex-=15;
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


	
	while (end) {
            if( piece_set_down || (!TimerTick)){
                    printf("soy Down\n\n");
                    if(check_down(n)){

                        printf("bajo");

                        piece_down(n);

                    }
                    else{
                        piece_set_down=1;
                    }
                
                    if(piece_set_down){

                    printf("soy newpiece\n\n");
                    
                    stayed_blocks(); 
                    check_board();
                    clean_struct(n);
                    
                    n=gen_pieza();
                    printf("pieza numero:%d\n",n);
                    print_pieza(n);
                    piece_set_down=0;
                    conta++;

                    }
                    TimerTick=4;
            }
    }
}


void * thread_joy(){ // Periodic Task Thread



        while (end) 
        {   

            if(move()==10){
                end=0;
                closepro();
            }

        }
}







void * thread_move(){ // The APP


        while(end){
            
           
            if(TimerTick && check_down(n) && piece_set_down==0){
                printf("soy move\n\n");                
                get_move=move();
                
                               
                
                if( get_move==2 ){

                    int rot;
                    rot=rotate(n);
                    
                    if(rot){
                        print_pieza(n);
                    }
                }

                if( get_move==1 && !check_right(n) ){


                    piece_right(n);
                    printf("soy move derecha \n\n");

                }

                if( get_move==-1 && !check_left(n)){

                    piece_left(n);


                }
                if( get_move==-2 ){

                    down(n);
                   
                }    
                
                 if(move()==10){
                    end=0;
                }
                
                if (!check_down(n)){
                    
                    usleep((timex-10)*ONE_MS);
                    
                }

            }

        }

}


void * thread_init(){
    
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



    n=gen_pieza();
    printf("pieza numero:%d\n",n);

    print_pieza(n);

            
    while(end){
            update_board();
            usleep(10000);
        }
}



int main()
{
        pthread_t tid1,tid2,tid3,tid4;
        srand(time(NULL));    
        
        pthread_create(&tid4,NULL,thread_init,NULL);
        usleep(1000000);
        pthread_create(&tid1,NULL,thread_timer,NULL);
        usleep(1000000);
         pthread_create(&tid3,NULL,thread_move,NULL);
        usleep(1000000);
        pthread_create(&tid2,NULL,thread_down,NULL);
        usleep(1000000);
      
        pthread_join(tid1,NULL);
        pthread_join(tid2,NULL);
        pthread_join(tid3,NULL);     
        pthread_join(tid4,NULL);
        
        return 0;
        
}
*/

//nuevo main
#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "game.h"
/*
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h> 
#include <allegro5/allegro_color.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_audio.h>
*/
#include <unistd.h>
#include <pthread.h>



#define  ONE_MS    	1000	   // One mseg
#define  time_delay(x)  (x/100)    // x in ms , minvalue 100mseg

#define ENTER '\n'


int gameboard[VNFil+1][NCol];


void update_board(void);
void inicializacion(void);
int move (void);

void printboard (void);

typedef struct { 
    unsigned int x;
    unsigned int y;
    
}dcoord_t;


typedef struct {
    
    int *values;
    int size;
    dcoord_t pos;    
    
}WORD; 

WORD words[2];
    
int piece_set_down=0,finish=0;
unsigned int TimerTick=2,level=1;
int n,end=1,palabra=0,numero=0,chosen_mode,chosen_diff,menu=1,wait1,wait2;
int get_move,conta,timex=70;
void closepro(void);



void closepro(void){
    
    return 0;
}


void* thread_timer()  // Time base Thread
{	       
    while(end)
    {
        usleep(timex*ONE_MS); // 100ms * 
        if (TimerTick){

            TimerTick--;
                printf("soy tick--\n\n");
        }
    }
}

void* thread_down(){ // Periodic Task Thread


	
    while (end) {

        while(!menu && end){            
            if(piece_set_down || (!TimerTick)){
                    printf("soy Down\n\n");
                    if(check_down(n)){

                        printf("bajo");

                        piece_down(n);

                    }
                    else{
                        piece_set_down=1;
                    }

                    if(piece_set_down){

                        printf("soy newpiece\n\n");

                        stayed_blocks(); 
                        level=check_level(check_board(level));
                        switch(level){
                            case 2:timex=70000;
                            case 3:timex=50000;
                        }
                        clean_struct(n);

                        n=gen_pieza();
                        printf("pieza numero:%d\n",n);
                        print_pieza(n);
                        piece_set_down=0;
                        conta++;

                    }
                    TimerTick=4;
            }
        }    
    }
}


void * thread_joy(){ // Periodic Task Thread



        while (end){   

            if(move()==10){
                end=0;
                closepro();
            }

        }
}







void * thread_move(){ // The APP


        while(end){
            
            while(!menu && end){
                
            
                if(TimerTick && check_down(n) && piece_set_down==0 ){

                    printf("soy move\n\n");                
                    get_move=move();



                    if( get_move==2 ){

                        int rot;
                        rot=rotate(n);

                        if(rot){
                            print_pieza(n);
                        }
                    }

                    if( get_move==1 && !check_right(n) ){


                        piece_right(n);
                        printf("soy move derecha \n\n");

                    }

                    if( get_move==-1 && !check_left(n)){

                        piece_left(n);

                    }

                    if( get_move==-2 ){

                        down(n);
                        
                    }    

                    if(move()==10){
                        end=0;
                    }
                    if (!check_down(n)){

                        usleep((timex-10)*ONE_MS);

                    }

                }
            }
        }

}


void * thread_menu(){ // The APP


        while(end){
            while(menu){
                print_menu();
                menu=0;
            }

        }

}


void * thread_init(){
    
    clean_struct(0);
    clean_struct(1);
    clean_struct(2);
    clean_struct(3);
    clean_struct(4);
    clean_struct(5);
    clean_struct(6);

    
    clean_word(0);

    init_blocks();
    inicializacion();



    n=gen_pieza();
    printf("pieza numero:%d\n",n);

    print_pieza(n);

            
    while(end){
            update_board();
            usleep(1000);
        }
}



int main()
{
        pthread_t tid1,tid2,tid3,tid4,tid5;
        srand(time(NULL));    
        
        pthread_create(&tid4,NULL,thread_init,NULL);
        usleep(1000000);
       pthread_create(&tid5,NULL,thread_menu,NULL);
        usleep(1000000);        
        pthread_create(&tid1,NULL,thread_timer,NULL);
        usleep(1000000);
        pthread_create(&tid3,NULL,thread_move,NULL);
        usleep(1000000);
        pthread_create(&tid2,NULL,thread_down,NULL);
        usleep(1000000);
        
      
        pthread_join(tid1,NULL);
        pthread_join(tid2,NULL);
        pthread_join(tid3,NULL);     
        pthread_join(tid4,NULL);
        pthread_join(tid5,NULL);        
        return 0;
        
}

   
 