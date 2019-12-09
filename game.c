#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "game.h"
#include "disdrv.h"
#include "joydrv.h"
#include <time.h>
void print_pieza(int n);


typedef struct {
    
    int *values;
    int size;
    dcoord_t pos;
    int rotacion;
    
}ARR_PIECES; 


extern int gameboard[VNFil][NCol];

extern ARR_PIECES piezas[7];




int gen_pieza(void){
    
   
    srand(time(NULL));
    
    int piezano= rand()%7 ;
 
    return piezano;

}



void clean_struct (int gen_pieza){
    
    piezas[gen_pieza].pos.x=5;
    piezas[gen_pieza].pos.y=0;
    piezas[gen_pieza].rotacion=0;
/*
    order_values(gen_pieza,0);
*/
    
}

      
void check_board(void){
    
    int i,j,countf=0,score=0;
    
    
    for(i=NFil-1;i>=0;i-- ){
        
        for(j=NCol-1;j>=0;j--){
            
            ++countf;
            
        }
        
        if(countf==NCol){
            
            ++score;
            
            for(j=0;j<NCol;j++){
                
                gameboard[i][j]=0;  //hacer titilar las barras y que se haga todas jntas
            
            }
        
        descend_board(i);    
        }
        countf=0;
            
        
        
    }
       
}

void descend_board(int lastf){
    
    int i,j;
    for (i=lastf;i>0;i--){
        
        for(j=0;j<NCol;j++){
            
            gameboard[i][j]=gameboard[i-1][j];
            
        }
    }
    
    for(j=0;j<NCol;j++){
        
        gameboard[0][j]=0;
    }
   
    
}

int check_down (int n){     //argumento :numero de pieza  ______deuelvi 1 si me puedo mover ,0 si no
    
    int i,j,x=piezas[n].pos.x,y=piezas[n].pos.y+1,size=piezas[n].size,suma=0;
    
    if (y<VNFil){
        
    
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            
            if(piezas[n].values[i*size+j] && gameboard[y+i][j+x]){
                
                if(piezas[n].values[(i+1)*size+j] && gameboard[y+i][j+x]){
                    suma++;
                }
                
            }
            else{
                
                suma++;
            }
            
        }
    }
    }
    
    if(suma!=(size*size) ){
        
        suma=0;
        
        
    }
    
    return suma;
    /*int suma=0,flag=0,i,lastline=(piezas[n].size)+(piezas[n].pos.y);
    if(lastline < VNFil){
        
        for(i=0;i<piezas[n].size;i++){

            suma+=gameboard[lastline][i+(piezas[n].pos.x)];
        }
        

    }
    else{
        
        int excess=lastline-VNFil-1;
        
        for(i=0;i<piezas[n].size;i++){

            suma+=gameboard[lastline-excess][i+(piezas[n].pos.x)] ;
        }
        
    }

    if(!suma){
            
        flag=1;
    }

    return flag;*/
}

void piece_down(int n){
    
    if(check_down(n)){
        int i,j;
        int py,px;
        
        py=++piezas[n].pos.y;
        px=piezas[n].pos.x;
        
        for(j=0;j<piezas[n].size;j++){
           for(i=0;i<piezas[n].size;i++){
                if(piezas[n].values[i*(piezas[n].size)+j]){
                
                   gameboard[py+i-1][j+px]=0;
                }
            } 
            
        }
        
        for(i=0;i<piezas[n].size;i++){
            for(j=0;j<piezas[n].size;j++){
                
                if(piezas[n].values[i*(piezas[n].size)+j]){
                    
                    gameboard[py+i][j+px]=piezas[n].values[i*(piezas[n].size)+j];
                }
                
            }
        }
    }
}


void piece_right(int n){
    
    if(!check_right(n)){
        int i,j;
        int py,px;
        
        py=piezas[n].pos.y;
        px=++(piezas[n].pos.x);
        
        for(j=0;j<piezas[n].size;j++){
            for(i=0;i<piezas[n].size;i++){
                if(piezas[n].values[i*(piezas[n].size)+j]){
                
                    gameboard[py+i][px-1+j]=0;
                }
            } 
        }
        
        for(i=0;i<piezas[n].size;i++){
            for(j=0;j<piezas[n].size;j++){
                
                if(piezas[n].values[i*(piezas[n].size)+j] ){
                    
                
                gameboard[py+i][j+px]=piezas[n].values[i*(piezas[n].size)+j];
                
                }
                
            }
        }
    }
}


void piece_left(int n){
    
    if(!check_left(n)){
        int i,j;
        int py,px;
        
        py=piezas[n].pos.y;
        px=--piezas[n].pos.x;
        
        for(j=0;j<piezas[n].size;j++){
            for(i=0;i<piezas[n].size;i++){
                if(piezas[n].values[i*(piezas[n].size)+j]){
                
                    gameboard[py+i][px+1+j]=0;
                }
            } 
            
        }
        
        for(i=0;i<piezas[n].size;i++){
            for(j=0;j<piezas[n].size;j++){
                
                if(piezas[n].values[i*(piezas[n].size)+j] ){
                
                    gameboard[py+i][j+px]=piezas[n].values[i*(piezas[n].size)+j];
                }
                
            }
        }
    }
}
int check_right (int gen_pieza){
    
    int i,x,y,size,conta,move=1;
    x=piezas[gen_pieza].pos.x;
    y=piezas[gen_pieza].pos.y;
    size=piezas[gen_pieza].size;
    conta=0;
    if(x==NCol-1){
        return 1;
    }
    
    if(x>=NCol-size){

        for(i=0;i<size;i++,y++){
            if(!(gameboard[y][NCol-1] && gameboard[y][(NCol-1)-1])){
                conta++;
            }
        }
        if(conta==size){
            move=0;
        }
        
    }
    else{
        x=x+size;
        for(i=0;i<size;i++,y++){
            if(!(gameboard[y][x] && gameboard[y][x-1])){
                conta++;
            }   
        }
        if(conta==size){
            move=0;
        }
    }
    return move;
}

int check_left (int gen_pieza){
    
    int i,x,y,size,conta,loop=1;
    x=piezas[gen_pieza].pos.x;
    y=piezas[gen_pieza].pos.y;
    size=piezas[gen_pieza].size;
    
    if(x<=0){

        for(i=0,conta=0;i<size;i++,y++){
            if(!(gameboard[y][0] && gameboard[y][1])){
                
                conta++;
            }
        }
        if(conta==size){
            loop=0;
        }
    }
    else{
        
        for(i=0,conta=0;i<size;i++,y++){
            
            if(!(gameboard[y][x] && gameboard[y][x-1])){
                conta++;
            }   
        }
        if(conta==size){
            loop=0;
        }
        
    }
    return loop;
}
