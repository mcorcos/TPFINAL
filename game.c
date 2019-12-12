#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "game.h"
#include "disdrv.h"
#include "joydrv.h"
#include <time.h>
#include <unistd.h>



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
    
    if(piezas[gen_pieza].rotacion){
        int i;
        
        
        
        for(i= 4-(piezas[gen_pieza].rotacion); i!=0 ;i--){
            printf("%d\n",i);
            reorder_pieza(gen_pieza);
        }
         piezas[gen_pieza].rotacion=0;
    }
   
    
/*
    order_values(gen_pieza,0);
*/
    
}

      
void check_board(void){
    
    int i,j,countf=0,score=0;
    
    
    for(i=VNFil-1;i>=4;i-- ){
        
        for(j=NCol-1;j>=0;j--){
            
            if(gameboard[i][j]){
            
                ++countf;
            
            }
        }
        
                   
        
        if(countf==NCol){
            
            
            ++score;
            
            for(j=0;j<NCol;j++){
                
                gameboard[i][j]=0;  //hacer titilar las barras y que se haga todas jntas
            
            }
            
        descend_board(i);
        ++i;
        usleep(100000);
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
    
    for(i=0;j<NCol;j++){
        
        gameboard[0][j]=0;
    }
   
    
}

int check_down (int n){     //argumento :numero de pieza  ______deuelvi 1 si me puedo mover ,0 si no
    
    int i,j,x=piezas[n].pos.x,y=(piezas[n].pos.y)+1,size=piezas[n].size,suma=0;
    
    if(x>NCol){
        x=x-256;
    }
    if (y<(VNFil+1)){ 
        
    
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            
            
            
                
            
                if((piezas[n].values[i*size+j] && gameboard[y+i][j+x]) ){
                
                
               
                    if(piezas[n].values[(i+1)*size+j] == gameboard[y+i][j+x]){
                    
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
        if(px>NCol){
            px=px-256;
        }
        
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
        
        if(px>NCol){
            px=px-256;
        }
        
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
    
    int x,y,size,i,j,found_piece=0;
    x=piezas[gen_pieza].pos.x;
    y=piezas[gen_pieza].pos.y;
    size=piezas[gen_pieza].size;
    if(x>=NCol-size){
        for(i=0;i<size && found_piece==0;i++){
            for(j=0;j<size && found_piece==0;j++){
                if(piezas[gen_pieza].values[i*size+j]){
                    if(NCol==j+x+1){
                        found_piece=1;
                    }
                }
            }        
        }
    }    
    else{
        
        for(i=0;i<size && found_piece==0;i++){
            for(j=0;j<size && found_piece==0;j++){
                if(piezas[gen_pieza].values[i*size+j]){

                    if(j<size-1){
                        found_piece= xor(gameboard[i+y][j+x+1],piezas[gen_pieza].values[i*size+j+1]);
                    }            
                    else{
                        if(gameboard[i+y][j+x+1]){
                            found_piece=1;
                        }
                    }
                }
            }
        }
    }
    return found_piece;
}


int xor (int a,int b){
    if (a == b){
        return 0;
    }
    else{
        return 1;
    }
}


int check_left (int gen_pieza){
    
    int x,y,size,i,j,found_piece=0;
    x=piezas[gen_pieza].pos.x;
    y=piezas[gen_pieza].pos.y;
    size=piezas[gen_pieza].size;
    if(x>NCol){
        x=x-256;
    }
    
    if(x<=0){
        for(i=0;i<size && found_piece==0;i++){
            for(j=0;j<size && found_piece==0;j++){
                if(piezas[gen_pieza].values[i*size+j]){
                    if((j+x-1)==-1){
                        found_piece=1;
                    }
                }
            }        
        }
    }    
    else{
        
        for(i=0;i<size && found_piece==0;i++){
            for(j=0;j<size && found_piece==0;j++){
                if(piezas[gen_pieza].values[i*size+j]){

                    if(j!=0){
                        found_piece= xor(gameboard[i+y][j+x-1],piezas[gen_pieza].values[i*size+j-1]);
                    }            
                    else{
                        if(gameboard[i+y][j+x-1]){
                            found_piece=1;
                        }
                    }
                }
            }
        }
    }
    return found_piece;
}

   
    
void print_pieza(int n){
	
    int i,j;
    
    for(i=0;i<piezas[n].size;i++){
        for(j=0;j<piezas[n].size;j++){
            
                
            
                gameboard[i+piezas[n].pos.y][j+piezas[n].pos.x]=piezas[n].values[i*piezas[n].size+j];
               
            
        }
    }
    
             
        
        
        
}

int rotate(int n){
    
    int i,j,cont=0;
    
    for(i=0;i<piezas[n].size;i++){
        for(j=0;j<piezas[n].size;j++){
            
                
            if(gameboard[i+piezas[n].pos.y][j+piezas[n].pos.x] != piezas[n].values[i*piezas[n].size+j]){
                cont++;
            } 
            
        }
    }
    
    
    if( piezas[n].pos.x+piezas[n].size < (NCol+1) && cont==0 ){
        
    
    
        int size=piezas[n].size;
	
        int mat[size][size];
	
	int i,j;
	
        for(i=0;i<size;i++){
		
		
		
		for(j=0;j<size;j++){

			mat[i][j]=piezas[n].values[(size-1-j)*size+i];
			
		}
	}
	
	
	for(i=0;i<size;i++){
		
		
		
		for(j=0;j<size;j++){

			piezas[n].values[i*size+j]=mat[i][j];
			
		}
	}
        
        ++piezas[n].rotacion;
        
        printf("pieza rotada=%d\n",piezas[n].rotacion);
        if (piezas[n].rotacion ==4){
            
            piezas[n].rotacion=0;
        }
        
      
    }
     return (!cont);   
}

void stayed_blocks(void){
    
    int i,j;
    for(i=0;i<VNFil;i++){
        for(j=0;j<NCol;j++){
            
                
            switch(gameboard[i][j]){
                
                
            case 1: gameboard[i][j]=11;
                 break;
            case 2:gameboard[i][j]=12;
                 break;
            case 3:gameboard[i][j]=13;
                 break;
            case 4:gameboard[i][j]=14;
                 break;
            case 5:gameboard[i][j]=15;
                 break;
            case 6:gameboard[i][j]=16;
                 break;
            case 7:gameboard[i][j]=17;
                 break;

                
            } 
            
        }
    }
    
    
}

void reorder_pieza(int n){
    
    int size=piezas[n].size;
	
        int mat[size][size];
	
	int i,j;
	
        for(i=0;i<size;i++){
		
		
		
		for(j=0;j<size;j++){

			mat[i][j]=piezas[n].values[(size-1-j)*size+i];
			
		}
	}
	
	
	for(i=0;i<size;i++){
		
		
		
		for(j=0;j<size;j++){

			piezas[n].values[i*size+j]=mat[i][j];
			
		}
	}
}
int move (void);

void down(int n){
    
    for(;check_down(n) && move()==-2;){
        piece_down(n);
        
        
        usleep(70000);
    }
}