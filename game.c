
int gen_pieza(){
    
   
    
    srand(time (NULL));
    
    int piezano= rand()%7 ;
 
    return piezano;

}


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int down_pieze(int piezano){

    int i,size;
    ARR_PIECES *pPieza=piezas[gen_pieza];
    size=pPieza->size;
    
    if(!cheq_down){
        pPieza->pos.y++;
    }
    else{
        stay=1;
        return stay;
    }
    
    if (move()>0 && ((pPieza->pos.x)+(size-1)>=(NCol-1)){       
        if(!cheq_right){
        pPieza->pos.x++;
        }
        else{
            stay=1;
        }
    }    
    
    if (move()<0 && ((pPieza->pos.x)-(size-1)<=0)){
        if(!cheq_left){
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
    if(down_piece()){
        int i,x,y,size,rot,*pValues;
        ARR_PIECES *pPieza=piezas[gen_pieza];
        size=pPieza->size;
        x=pPieza.pos.x;
        y=pPieza.pos.y;
        rot=pPieza.rotacion;
        *pValues=pPieza.values
        switch(rot){
            case 1: order_values(gen_pieza,1);
            break;
            case 2: order_values(gen_pieza,2);
            break;
            case 3: order_values(gen_pieza,3);
            break;
        }
        for(i=x,k=0;i<(size+x);i++){
            for(j=y;j<(size+y);j++){
                if(pValues[k++]){
                    game_board[i][j]=1;
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
    order_values(gen_pieza,0);
    
}

void cheq_right (int gen_pieza){
    int x=piezas[gen_pieza].pos.x,y=piezas[gen_pieza].pos.y,size=piezas[gen_piezas].size;
    for(;x<(size+x);){
        game_board[x+size]
    }
}
      


