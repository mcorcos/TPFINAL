/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

int move (void){
    
    joy_init();
    jcoord_t coord={0,0}
    joy_update();
    coord=joy_get_coord();
    
    if(coord.x > THRESHOLD){
        get_move=1;
    }
    if(coord.x < THRESHOLD){
        get_move=-1;
    }
    
    return get_move;
}
