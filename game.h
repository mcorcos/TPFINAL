/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   newfile.h
 * Author: enrique
 *
 * Created on December 8, 2019, 2:01 AM
 */

#ifndef GAME

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




#define GAME




