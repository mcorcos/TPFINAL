#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "game.h"
#include "disdrv.h"
#include "joydrv.h"


extern const int gameboard[NFil][NCol];
extern ARR_PIECES piezas[];


int gen_pieza(void){
    
   
    srand(time (NULL));
    
    int piezano= rand()%7 ;
 
    return piezano;

}

int down_pieze(int piezano){

    int i,size,stay,get_move;
    ARR_PIECES *pPieza=piezas[gen_pieza];
    size=pPieza->size;
    get_move=move();
    if(!check_down){
        pPieza->pos.y++;
    }
    else{
        stay=1;
        return stay;
    }
    
    if (get_move>0){       
        if(!check_right){
        pPieza->pos.x++;
        
        }
        else{
            stay=1;
        }
    }    
    
    if (get_move<0){
        if(!check_left){
        pPieza->pos.x--;
        }
        else{
            stay=1;
        }
        
    }  
    
    return stay;   
}
// game_board[NFil][NCol]
void game_update(int gen_pieza){
    if(down_pieze()){
        int i,j,k,x,y,size,rot,*pValues;
        ARR_PIECES *pPieza=piezas[gen_pieza];
        size=pPieza->size;
        x=pPieza.pos.x;
        y=pPieza.pos.y;
        rot=pPieza.rotacion;
        pValues= pPieza->values;
/*
        switch(rot){
            case 1: order_values(gen_pieza,1);
            break;
            case 2: order_values(gen_pieza,2);
            break;
            case 3: order_values(gen_pieza,3);
            break;
        }
*/
        for(i=x,k=0;i<(size+x);i++){
            for(j=y;j<(size+y);j++){
                if(pValues[k++]){
                    gameboard[i][j]=1;
                }
            }
        }
        
    }
    clean_struct(gen_pieza);
    
}

void clean_struct (int gen_pieza){
    int *pValues;
    ARR_PIECES *pPieza=piezas[gen_pieza];
    pPieza.pos.x=7;
    pPieza.pos.y=0;
    pPieza.rotacion=0;
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
        
        if(countf=NCol){
            
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

int check_down (int gen_pieza){     //argumento :numero de pieza  ______deuelvi 1 si me puedo mover ,0 si no
    
    int suma=0,flag=0,i,lastline;
    if(lastline > NFil){
        
        for(i=0;i<piezas[gen_pieza].size;i++){

            suma+=((gameboard[lastline][i+(piezas[gen_pieza].pos.x)]) && (gameboard[lastline-1][i+(piezas[gen_pieza].pos.x)]));
        }
        

    }
    else{
        
        int excess=lastline-NFil-1;
        
        for(i=0;i<piezas[gen_pieza].size;i++){

            suma+=gameboard[lastline-excess][i+(piezas[gen_pieza].pos.x)] ;
        }
        
    }

    if(!suma){
            
        flag=1;
    }

    return suma;
}

void piece_down(int n){
    
    if(check_piso(n)){
        int i,j;
        int py,px;
        
        py=++piezas[n].pos.y;
        px=piezas[n].pos.x;
        
        for(j=0;j<piezas[n].size;j++){
            
            gameboard[py-1][j+px]=0;
        }
        
        for(i=0;i<piezas[n].size;i++){
            for(j=0;j<piezas[n].size;j++){
                
                gameboard[py+i][j+px]=piezas[n].values[i*(piezas[n].size)+j];
            }
        }
    }
}


void piece_right(int n){
    
    if(check_right(n)){
        int i,j;
        int py,px;
        
        py=piezas[n].pos.y;
        px=++piezas[n].pos.x;
        
        for(j=0;j<piezas[n].size;j++){
            
            gameboard[py+j][px-1]=0;
        }
        
        for(i=0;i<piezas[n].size;i++){
            for(j=0;j<piezas[n].size;j++){
                
                gameboard[py+i][j+px]=piezas[n].values[i*(piezas[n].size)+j];
            }
        }
    }
}


void piece_left(int n){
    
    if(check_left(n)){
        int i,j;
        int py,px;
        
        py=piezas[n].pos.y;
        px=--piezas[n].pos.x;
        
        for(j=0;j<piezas[n].size;j++){
            
            gameboard[py+j][px+piezas[n].size]=0;
        }
        
        for(i=0;i<piezas[n].size;i++){
            for(j=0;j<piezas[n].size;j++){
                
                gameboard[py+i][j+px]=piezas[n].values[i*(piezas[n].size)+j];
            }
        }
    }
}
int check_right (int gen_pieza){
    int i,x,y,size,conta,loop;
    x=piezas[gen_pieza].pos.x;
    y=piezas[gen_pieza].pos.y;
    size=piezas[gen_pieza].size;
    if(x==NCol){
        return 1;
    }
    
    if(x<NCol-size){

        for(i=0,conta=0;i<size;i++,y++){
            if(!(gameboard[y][NCol] && gameboard[y][NCol-1])){
                conta++;
            }
        }
        if(conta==size){
            loop=0;
        }
    }
    else{
        x+=size;
        while(loop){
            for(i=1,conta=0;i<size;i++,y++){
                if(!(gameboard[y][x] && gameboard[y][x-1])){
                    conta++;
                }   
            }
            if(conta==size){
                loop=0;
            }
        }
    }
    if(!loop){
        return 0;
    }
    else{
        return 1;
    }
}

int check_left (int gen_pieza){
    int i,x,y,size,conta,loop;
    x=piezas[gen_pieza].pos.x;
    y=piezas[gen_pieza].pos.y;
    size=piezas[gen_pieza].size;
    if((x-size)<=0){

        for(i=0,conta=0;i<size;i++,y++){
            if(gameboard[y][0] && gameboard[y][1]){
                
            }
        }
        if(conta==size){
            loop=0;
        }
    }
    else{
        x-=size;
        while(loop){
            for(i=1,conta=0;i<size;i++,y++){
                if(!(gameboard[y][x] && gameboard[y][x+1])){
                    conta++;
                }   
            }
            if(conta==size){
                loop=0;
            }
        }
    }
    if(!loop){
        return 0;
    }
    else{
        return 1;
    }
}

