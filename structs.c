
#include <disdrv.h>
#include <stdio.h>
#include <stdlib.h>
#include "structs.h"




ARR_PIECES piezas[7];
const int gameboard[NFil][NCol];

const struct pieza1_T{
        
        int values[16];
        int size;
        
    };

    
    
const struct pieza2_T{
        
        int values[4];
        int size;
        
    };

    
const struct pieza3_T{
        
        int values[9];
        int size;
        
    };
    
    
const struct pieza4_T{
        
        int values[9];
        int size;
        
    };

    
const struct pieza5_T{
        
        int values[9];
        int size;
        
    };

    
const struct pieza6_T{
        
        int values[9];
        int size;
        
    };
  
    
const struct pieza7_T{
        
        int values[9];
        int size;
        
    };
    
 
    




const struct pieza1_T PIEZA_1={{
                        0,0,0,0,
                        1,1,1,1,
                        0,0,0,0,
                        0,0,0,0
                                },4};

const struct pieza2_T PIEZA_2={{
                        2,2,
                        2,2
                            },2};

const struct pieza3_T PIEZA_3={{
                        0,0,0,
                        3,3,0,
                        0,3,3
                         },3};

const struct pieza4_T PIEZA_4={{
			0,0,0,
			0,4,4,
			4,4,0},3};
			

const struct pieza5_T PIEZA_5={{
                        0,5,0,
                        0,5,0,
                        5,5,0
                            },3};

const struct pieza6_T PIEZA_6={{
                        0,6,0,
                        0,6,0,
                        0,6,6
                             },3};

const struct pieza7_T PIEZA_7={{
                        0,0,0,
                        7,7,7,
                        0,7,0
                              },3};






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
    
          
         
}