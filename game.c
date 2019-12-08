void game_update(int gen_pieza);
int down_pieze(int piezano);
int gen_pieza(void);
void clean_struct (int gen_pieza);
void cheq_right (int gen_pieza);
void check_board(void);
void descend_board(int lastf);
int check_piso(int n);
void piece_left(int n);
void piece_right(int n);
void piece_down(int n);


extern const int gameboard;
#define NCol 12
#define NFil 19

int gen_pieza(void){
    
   
    srand(time (NULL));
    
    int piezano= rand()%7 ;
 
    return piezano;

}

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
        
        game_board[x+size];
        
    
    }
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

int check_piso(int n){     //argumento :numero de pieza  ______deuelvi 1 si me puedo mover ,0 si no
    
    int suma=0,flag=0,i;
    if(lastline > NFil){
        
        for(i=0;i<piezas[n].size;i++){

            suma+=((gameboard[lastline][i+(piezas[n].pos.x)]) && (gameboard[lastline-1][i+(piezas[n].pos.x)]));
        }
        

    }
    else{
        
        int excess=lastline-NFil-1;
        
        for(i=0;i<piezas[n].size;i++){

            suma+=gameboard[lastline-excess][i+(piezas[n].pos.x))] ;
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