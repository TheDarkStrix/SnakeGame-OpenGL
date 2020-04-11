#ifndef GAME_HEADER_INCLUDED
#define GAME_HEADER_INCLUDED

#define UP 1
#define DOWN -1
#define RIGHT 2
#define LEFT -2

#define Max_Length 60

void Grid(int,int);
void createGrid();
void createSnake();
void createFood();
void createRandom(int&,int&);
#endif
