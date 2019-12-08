/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   structs.h
 * Author: enrique
 *
 * Created on December 8, 2019, 2:02 AM
 */

#ifndef STRUCTS_H


typedef struct {
    
    int *values;
    int size;
    dcoord_t pos;
    int rotacion;
    
}ARR_PIECES; 

void init_blocks(void);

#define NCol 12
#define NFil 19

#define STRUCTS_H

#endif
