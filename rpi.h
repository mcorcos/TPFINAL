
#ifndef rpi
#define rpi  //contiene todas las funciones de rpi las cuales estan explicadas en su respectivo arichivo rpi.c

void update_board(void);
void inicializacion(void);
int move (void);
void print_menu (void);
void cleanall(void);
void leavestop(int n);

void closepro(void);
void print_stopmenu(void);
void finish_game(void);
void print_n2(void);
void showscore(void);
void copy_board(int *pllegada,int *psalida);
void playsongg (void);
void print_screen(int n2);
void init_words(void);
void play_sample(void);

#endif /* RPI_H */

