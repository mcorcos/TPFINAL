
#include "disdrv.h"
#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "game.h"




typedef struct {
    
    int *values;
    int size;
    dcoord_t pos;
    int rotacion;
    
}ARR_PIECES; 

typedef struct {
    
    int *values;
    int size;
    dcoord_t pos;    
    
}NUM; 

typedef struct {
    
    int *values;
    int sizex;
    int sizey;
    dcoord_t pos;    
    
}WORD; 

ARR_PIECES piezas[7];

NUM nums[9];
WORD words[5]; 


struct pieza1_T{
        
        int values[16];
        int size;
        
    };

    
    
struct pieza2_T{
        
        int values[4];
        int size;
        
    };

    
struct pieza3_T{
        
        int values[9];
        int size;
        
    };
    
    
struct pieza4_T{
        
        int values[9];
        int size;
        
    };

    
struct pieza5_T{
        
        int values[9];
        int size;
        
    };

    
struct pieza6_T{
        
        int values[9];
        int size;
        
    };
  
    
struct pieza7_T{
        
        int values[9];
        int size;
        
    };
    
 
    




struct pieza1_T PIEZA_1={{
                        0,0,0,0,
                        1,1,1,1,
                        0,0,0,0,
                        0,0,0,0
                                },4};

struct pieza2_T PIEZA_2={{
                        2,2,
                        2,2
                            },2};

struct pieza3_T PIEZA_3={{
                        0,0,0,
                        3,3,0,
                        0,3,3
                         },3};

struct pieza4_T PIEZA_4={{
			0,0,0,
			0,4,4,
			4,4,0},3};
			

struct pieza5_T PIEZA_5={{
                        0,5,0,
                        0,5,0,
                        5,5,0
                            },3};

struct pieza6_T PIEZA_6={{
                        0,6,0,
                        0,6,0,
                        0,6,6
                             },3};

struct pieza7_T PIEZA_7={{
                        0,0,0,
                        7,7,7,
                        0,7,0
                              },3};





struct num1_T{
        
        int values[25];
        int size;
        
};

struct num2_T{
        
        int values[25];
        int size;
        
};

struct num3_T{
        
        int values[25];
        int size;
        
};

struct num4_T{
        
        int values[25];
        int size;
        
};

struct num5_T{
        
        int values[25];
        int size;
        
};

struct num1_T NUM_1={{
			0,1,1,0,0,
			0,0,1,0,0,
			0,0,1,0,0,
                        0,0,1,0,0,
                        0,1,1,1,0
                            },5};

struct num2_T NUM_2={{
			0,1,1,1,0,
			0,0,0,1,0,
			0,0,1,0,0,
                        0,1,0,0,0,
                        0,1,1,1,0        
                            },5};

struct num3_T NUM_3={{
			0,1,1,0,0,
			0,0,0,1,0,
			0,0,1,1,0,
                        0,0,0,1,0,
                        0,1,1,0,0     
                            },5};
									
struct num4_T NUM_4={{
			0,1,0,1,0,
			0,1,0,1,0,
			0,1,1,1,0,
                        0,0,0,1,0,
                        0,0,1,1,1        
                            },5};

struct num5_T NUM_5={{
			0,1,1,1,0,
			0,1,0,0,0,
			0,1,1,1,0,
                        0,0,0,1,0,
                        0,1,1,1,0        
                            },5};

struct letra_T{
        
        int values[20];
        int size;
        
};

struct word1_T{
        
        int values[28*5];
        int sizex;
        int sizey;
        
};

struct word1_T WORD_1={{
                        0,0,1,0,1,1,1,0,1,0,1,0,1,1,1,0,0,1,0,0,1,0,1,0,1,1,1,0,  
                        1,0,1,0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,1,0,1,1,1,0,1,0,0,0,   
                        1,1,1,0,1,1,0,0,1,0,1,0,1,1,1,0,1,1,1,0,1,0,1,0,1,1,0,0, 
                        1,0,1,0,1,0,0,0,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,
                        1,0,0,0,1,1,1,0,1,0,1,0,1,1,1,0,1,0,1,0,1,0,1,0,1,1,1,0                             
                       },28,5};


                           


struct letra_T LETRA_A={{
0,1,0,0,1,0,1,0,1,1,1,0,1,0,1,0,1,0,1,0,        
                              },4};

struct letra_T LETRA_B={{
                        1,1,1,0,
                        1,0,1,0,
                        1,1,0,0,
                        1,0,1,0,
                        1,1,1,0,        
                              },4};

struct letra_T LETRA_C={{
                        1,1,1,0,
                        1,0,0,0,
                        1,0,0,0,
                        1,0,0,0,
                        1,1,1,0,        
                              },4};


struct letra_T LETRA_D={{
                        0,1,1,0,
                        1,0,0,1,
                        1,0,0,1,
                        1,0,0,1,
                        1,1,1,0,        
                              },4};


struct letra_T LETRA_E={{
1,1,1,0,1,0,0,0,1,1,0,0,1,0,0,0,1,1,1,0,        
                              },4};

struct letra_T LETRA_F={{
                        1,1,1,0,
                        1,0,0,0,
                        1,1,1,0,
                        1,0,0,0,
                        1,0,0,0,        
                              },4};

struct letra_T LETRA_G={{
1,1,1,0,1,0,0,0,1,1,1,0,1,0,1,0,1,1,1,0,        
                              },4};


struct letra_T LETRA_H={{
                        1,0,1,0,
                        1,0,1,0,
                        1,1,1,0,
                        1,0,1,0,
                        1,0,1,0,        
                              },4};


struct letra_T LETRA_I={{
                        0,1,0,0,
                        0,0,0,0,
                        0,1,0,0,
                        0,1,0,0,
                        0,1,0,0,        
                              },4};

struct letra_T LETRA_J={{
                        1,1,1,0,
                        0,0,1,0,
                        0,0,1,0,
                        1,0,1,0,
                        1,1,1,0,        
                              },4};

struct letra_T LETRA_K={{
                        1,0,1,0,
                        1,1,0,0,
                        1,1,0,0,
                        1,0,1,0,
                        1,0,1,0,        
                              },4};


struct letra_T LETRA_L={{
                        1,0,0,0,
                        1,0,0,0,
                        1,0,0,0,
                        1,0,0,0,
                        1,1,1,0,        
                              },4};

struct letra_T LETRA_M={{
1,0,1,0,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,        
                              },4};


struct letra_T LETRA_N={{
                        0,0,1,0,
                        0,0,1,0,
                        1,1,1,0,
                        1,0,1,0,
                        1,0,0,0,        
                              },4};




struct letra_T LETRA_O={{
                        1,1,1,0,
                        1,0,1,0,
                        1,0,1,0,
                        1,0,1,0,
                        1,1,1,0,        
                              },4};


struct letra_T LETRA_P={{
                        1,1,1,0,
                        1,0,1,0,
                        1,1,1,0,
                        1,0,0,0,
                        1,0,0,0,        
                              },4};


struct letra_T LETRA_Q={{
                        1,1,1,0,
                        1,0,1,0,
                        1,0,1,0,
                        1,1,1,0,
                        0,1,1,0,        
                              },4};



struct letra_T LETRA_R={{
                        1,1,1,0,
                        1,0,1,0,
                        1,1,1,0,
                        1,0,1,0,
                        1,0,1,0,        
                              },4};



struct letra_T LETRA_S={{
                        1,1,1,0,
                        1,0,0,0,
                        1,1,1,0,
                        0,0,1,0,
                        1,1,1,0,        
                              },4};


struct letra_T LETRA_T={{
                        1,1,1,0,
                        0,1,0,0,
                        0,1,0,0,
                        0,1,0,0,
                        0,1,0,0,        
                              },4};


struct letra_T LETRA_U={{
                        1,0,1,0,
                        1,0,1,0,
                        1,0,1,0,
                        1,0,1,0,
                        1,1,1,0,        
                              },4};



struct letra_T LETRA_V={{
                        1,0,1,0,
                        1,0,1,0,
                        1,0,1,0,
                        1,0,1,0,
                        0,1,0,0,        
                              },4};


struct letra_T LETRA_W={{
1,0,1,0,
1,0,1,0,
1,0,1,0,
1,1,1,0,
1,0,1,0,        
                              },4};

struct letra_T LETRA_Y={{
1,0,1,0,
1,0,1,0,
1,1,1,0,
0,1,0,0,
0,1,0,0,        
                              },4};

struct letra_T LETRA_Z={{
1,1,1,0,
0,0,1,0,
0,1,0,0,
1,0,0,0,
1,1,1,0,        
                              },4};




void init_blocks(void){
    
    
    
    piezas[0].values=(PIEZA_1.values);
    piezas[0].size=PIEZA_1.size;
    
    piezas[1].values=(PIEZA_2.values);
    piezas[1].size=PIEZA_2.size;
    
    piezas[2].values=(PIEZA_3.values);
    piezas[2].size=PIEZA_3.size;
    
    piezas[3].values=(PIEZA_4.values);
    piezas[3].size=PIEZA_4.size;
    
    piezas[4].values=(PIEZA_5.values);
    piezas[4].size=PIEZA_5.size;
    
    piezas[5].values=(PIEZA_6.values);
    piezas[5].size=PIEZA_6.size;
    
    piezas[6].values=(PIEZA_7.values);
    piezas[6].size=PIEZA_7.size;
    
    words[0].values=(WORD_1.values);
    words[0].sizex=WORD_1.sizex;
    words[0].sizey=WORD_1.sizey;
    
    nums[0].values=(NUM_1.values);
    nums[0].size=NUM_1.size;
    nums[0].pos.x=3;
    nums[0].pos.y=7;
    
    nums[1].values=(NUM_2.values);
    nums[1].size=NUM_2.size;
    nums[1].pos.x=3;
    nums[1].pos.y=7;   
    
    nums[2].values=(NUM_3.values);
    nums[2].size=NUM_3.size;  
    nums[2].pos.x=3;
    nums[2].pos.y=7;
    
    nums[3].values=(NUM_4.values);
    nums[3].size=NUM_4.size; 
    nums[3].pos.x=3;
    nums[3].pos.y=7;
    
    nums[4].values=(NUM_4.values);
    nums[4].size=NUM_4.size;  
    nums[4].pos.x=3;
    nums[4].pos.y=7;              
         
}

void create_floor(void){
    int i;
    for(i=0;i<NCol;i++){
        
        gameboard[VNFil][i]=-1;
        
    }
    
    for(i=0;i<NFil;i++){

        static dcoord_t pos;
        pos.y=i;
        pos.x=NCol;

        disp_write(pos,D_ON);
    }
}