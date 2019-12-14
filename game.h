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
#define GAME
int check_left (int gen_pieza);
void game_update(int gen_pieza);
int down_pieze(int piezano);
int gen_pieza(void);
void clean_struct (int gen_pieza);
int check_right(int gen_pieza);
int check_board(int level);
void descend_board(int lastf);
int check_down(int n);
void piece_left(int n);
void piece_right(int n);
void piece_down(int n);
int xor(int a,int b);
int rotate(int n);
void print_pieza(int n);
void stayed_blocks(void);
void reorder_pieza(int n);
void down (int n);
void letter_left(int palabra);
void clean_word (int palabra);
void clear_board(void);
int check_level(int score);
void init_word(int palabra);
void init_game(int chosen_mode,int chosen_diff);

#endif





