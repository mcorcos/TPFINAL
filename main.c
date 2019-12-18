/*
#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "game.h"

#include "rpi.h"
#include <unistd.h>
#include <pthread.h>



#define  ONE_MS    	1000	   // One mseg


#define ENTER '\n'


int gameboard[VNFil+1][NCol];
extern int score;




    

int piece_set_down=0,pausa=0;

unsigned int TimerTick=4;

int n,n2,end=1,palabra=0,numero=0,menu=1,set_menu=1,finish=1;

int get_move,conta,timer,lines=0;


extern int level;




void* thread_timer()  
{	       
    while(end)
    {
        usleep((timer-(level-1)*10)*ONE_MS); 
        if (TimerTick){

            TimerTick--;
              
        }
    }
    return 0;
}

void* thread_down(){ 


	
    while (end) {

        while(!menu ){            
            if( !TimerTick ){
                    
                   

                    if(piece_set_down){

                        switch(n){
                            
                        }

                        stayed_blocks(); 
                        
                        check_level(check_board(level));
                        printf("LEVEL=%d",level);
                        
                        clean_struct(n);
                        
                        check_fin();
                        
                        n=n2;
                        n2=gen_pieza();
                        print_n2();
                        print_pieza(n);
                        piece_set_down=0;
                        

                    }
                     if(check_down(n) ){

                       

                        piece_down(n);

                    }
                    else{
                        piece_set_down=1;
                        
                    }
                     
                    TimerTick=4;
            }
        }    
    }
    return 0;
}


void * thread_events(){ // Periodic Task Thread

    

        while (end){   
            
            
            
            if(pausa){
                
                
                menu=1;
                pausa=0;
                usleep(20000);
                
                print_stopmenu();
                
                
                
                
                
                
                
                
                
            }

        }
        
        closepro();
        return 0;
}







void * thread_move(){ // The APP


        while(end){
            
            while(!menu ){
                
            
                if(TimerTick && check_down(n)  ){

                                   
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
                        

                    }

                    if( get_move==-1 && !check_left(n)){

                        piece_left(n);

                    }

                    if( get_move==-2 ){

                        down(n);
                        
                    }    
                    if(get_move==9){
                        pausa=1;
                        menu=1;
                    }
                   
                    if(get_move==10){
                        pausa=1;
                        menu=1;
                    }
                   
                    if (!check_down(n)){

                        usleep((timer-10)*ONE_MS);

                    }

                }
            }
        }
        return 0;

}


void * thread_menu(){ // The APP


    while(finish){
        
        while(set_menu){
            
        while(menu){
            
            print_menu();
            print_screen(n2);
            menu=0;
            set_menu=0;
            usleep(20000);
        }
      
        }
        
    }
    
            
        
    return 0;
        

}


void * thread_init(){
    
    clean_struct(0);
    clean_struct(1);
    clean_struct(2);
    clean_struct(3);
    clean_struct(4);
    clean_struct(5);
    clean_struct(6);

    
    clean_words();
    
    
    init_blocks();
    inicializacion();
    


    n=gen_pieza();
    n2=gen_pieza();
    print_n2();
    printf("pieza numero:%d\n",n);

    print_pieza(n);

            
    while(end){
       
       
        while(!menu ){
            
            
            update_board();
            usleep(1000);
            
        }
        }
    return 0;
}



int main(void)
{
        pthread_t tid1,tid2,tid3,tid4,tid5,tid6;
        srand(time(NULL));    
        
        pthread_create(&tid4,NULL,thread_init,NULL);
        usleep(2000000);
       pthread_create(&tid5,NULL,thread_menu,NULL);
        usleep(1000000);        
        pthread_create(&tid1,NULL,thread_timer,NULL);
        usleep(1000000);
        pthread_create(&tid3,NULL,thread_move,NULL);
        usleep(1000000);
        pthread_create(&tid2,NULL,thread_down,NULL);
        usleep(1000000);
          pthread_create(&tid6,NULL,thread_events,NULL);
        usleep(1000000);
      
        pthread_join(tid1,NULL);
        pthread_join(tid2,NULL);
        pthread_join(tid3,NULL);     
        pthread_join(tid4,NULL);
        pthread_join(tid5,NULL);     
        pthread_join(tid6,NULL);
        return 0;
        
}*/
#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "game.h"





#include "rpi.h"


#include <unistd.h>
#include <pthread.h>



#define  ONE_MS    	1000	   // One mseg

#define ENTER '\n'




int gameboard[VNFil+1][NCol];


    
int piece_set_down=0,finish=1;
unsigned int TimerTick=4;
int n,n2,end=1,palabra=0,numero=0,menu=1,set_menu=1,block=1;
int get_move,conta,timer,lines=0;
int pausa=0;
unsigned int P0,P1,P2,P3,P4,P5,P6;



extern int level,score;

void* thread_timer()  // Time base Thread
{	       
    while(end)
    {
        usleep((timer-(level-1)*10)*ONE_MS);// timer definido con dificultad inicial
        if (TimerTick){                     // contador de segundos
                                            //TimerTick clock del juego
            TimerTick--;
        }
    }
    return 0;
}

void* thread_down(){ // Periodic Task Thread


	
    while (end) {

        while(!menu){ 
            
            if(!TimerTick){ //si TimerTick es 0


                    if(check_down(n)){ // analiza si puede bajar


                        piece_down(n);  //si es positivo baja la pieza
                    }
                    
                    else{               // si es negativo la deja donde esta
                        
                        switch(n){
                                case 0: P0++;
                                break;
                                case 1: P1++;
                                break;
                                case 2: P2++;
                                break;
                                case 3: P3++;
                                break;
                                case 4: P4++;
                                break;
                                case 5: P5++;
                                break;
                                case 6: P6++;
                                break;                            
                            }
                     
                            stayed_blocks(); // todas las piezas que cayeron las deja estaticas en el gameboard
                            
                            check_level(check_board(level)); // se fija si se aumenta el nivel o si se completaron filas
                            clean_struct(n); // vuelve a poner las coordenadas de la estructura en 0

                            n=n2; 
                            
                            n2=gen_pieza(); //utilizo un generador de piezas aleatorio
                            print_screen(n2);  

                            check_fin(n); // me fijo si el juego termino
                            
                            usleep(20000);

                            print_pieza(n);// imprimo la pieza correspondiente en el gameboard
                                             
                    }               
                    block=1;             
                    TimerTick=4;
            }
        }  
    }
    return 0;
}


void * thread_events(){ // Periodic Task Thread
        

    while (end){  //recibe los eventos de teclado y del switch para el menu de pausa

        if(pausa){


            menu=1; // pongo menu en 1 asi no uso mas la logica del juego
            pausa=0;
            usleep(100000);
            print_stopmenu(); // imprimo el menu de pausa
        }
    }
    closepro();       
    return 0;
}







void * thread_move(){ // The APP


        while(end){
        
            while(!menu){
                
            
                if(TimerTick && block){

                                    
                    get_move=move(); // recibo del teclado que tecla se apreto y la guardo en get_move
                            
                    if( get_move==2 ){ // si se apreto la tecla para arriba, se fija si puede rotar

                        int rot;
                        rot=rotate(n);

                        if(rot){
                            print_pieza(n);
                        }
                    }

                    if( get_move==1 && !check_right(n) ){ // si se apreto la tecla para la derecha , me fijo si el movimiento es valido

                        piece_right(n);
                  

                    }

                    if( get_move==-1 && !check_left(n)){// si se apreto la tecla para la izquierda, me fijo si el movimiento es valido

                        piece_left(n);

                    }

                    if( get_move==-2 ){ // si se apreto la tecla para abajo, llama a la funcion down que acelera el movimiento hacia abajo

                        down(n);
                        
                    }
                    
                    if(get_move==9){ // si se apreto el escape o la cruz de la ventana , salta el menu de pausa
                        pausa=1;
                        menu=1;
                    }
                    if(get_move==10){
                        pausa=1;
                        menu=1;
                    } 
                    
                    if (!check_down(n)){ // pongo un timer para movepara alentizar el movimiento lateral

                        usleep((timer-10)*ONE_MS);

                    }

                }
            }
        }
        return 0;
}


void * thread_menu(){ 
    while(finish){
        
        while(set_menu){ // cada vez que el juego termine , se muestra el menu principal
            
            while(menu){
                    print_menu(); // muestra el menu principal
                    print_screen(n2); // muestra el estado de lineas , stadisticas de piezas y le next piece
                    menu=0;
                    set_menu=0;
                    usleep(20000);
                }
        }  
    
    }
    return 0;
}


void * thread_init(){ // thread encargado de la inicializacion y de actualizar el board cada poco tiempo
    
    create_floor();
    clean_struct(0);
    clean_struct(1);
    clean_struct(2);
    clean_struct(3);
    clean_struct(4);
    clean_struct(5);
    clean_struct(6);

    
    clean_words(); 

    init_blocks();
    inicializacion();



    n=gen_pieza();
    n2=gen_pieza();
    print_pieza(n);

            
    while(end){
        
        while(!menu){   
            update_board();
            usleep(1000);
        }
    }
    return 0;
}
    



int main(){
    
        pthread_t tid1,tid2,tid3,tid4,tid5,tid6;
        srand(time(NULL));    
        
        pthread_create(&tid4,NULL,thread_init,NULL); // inicializo todos los threads con delay entre los mismos
        usleep(2000000);
        pthread_create(&tid5,NULL,thread_menu,NULL); // este delay esta dado ya que quizas unthread quiere actuar sobre algo que no esta iniializado aun
        usleep(1000000);        
        pthread_create(&tid1,NULL,thread_timer,NULL);
        usleep(1000000);
        pthread_create(&tid3,NULL,thread_move,NULL);
        usleep(1000000);
        pthread_create(&tid2,NULL,thread_down,NULL);
        usleep(1000000);
        pthread_create(&tid6,NULL,thread_events,NULL);
        usleep(1000000);
        
      
        pthread_join(tid1,NULL); // espero a los threads a que terminen
        pthread_join(tid2,NULL);
        pthread_join(tid3,NULL);  
        pthread_join(tid4,NULL);
        pthread_join(tid5,NULL);
        pthread_join(tid6,NULL);
        return 0;
        
}


   
 