#include <GL/gl.h>
#include <GL/glut.h>
#include <ctime>
#include "snakeGame.h"

int gridX,gridY;
int snake_length = 5;
bool food=true;
int foodX,foodY;
short direction = RIGHT;
extern bool gameOver;
int positionX[60]={20,20,20,20,20},positionY[60]={20,19,18,17,16};
void Grid(int x,int y){
    gridX=x;
    gridY=y;
}

void cells(int,int);

void createGrid(){
    for(int x=0;x<gridX;x++){
        for(int y=0;y<gridY;y++){
            cells(x,y);
        }
    }
    
}

void cells(int x,int y){
    if(x==0 || y==0 || x==gridX-1 || y==gridY-1){
        glLineWidth(3.0);
        glColor3f(0.5,0.5,1.0);
    }else{
    glLineWidth(1.0);
    glColor3f(1.0,1.0,1.0);
    }
    glBegin(GL_LINE_LOOP);
    glVertex2f(x,y);
    glVertex2f(x+1,y);
    glVertex2f(x+1,y+1);
    glVertex2f(x,y+1);
    glEnd();
}
void createRandom(int &x,int &y){
    int mxxval = gridX -2;
    int mxyval = gridY -2;
    int mmval = 1;
    srand(time(NULL));
    x = mmval + rand() %(mxxval-mmval);
    y = mmval + rand() %(mxyval-mmval);
}
void createFood(){
    if(food)
    createRandom(foodX,foodY);
    food=false;
    glColor3f(1.0,0.0,0.0);
    glRectd(foodX,foodY,foodX+1,foodY+1);
}
void createSnake(){
    for(int i= snake_length-1;i>0;i--){
        positionX[i] = positionX[i-1];
        positionY[i] = positionY[i-1];
    }
    if(direction==UP)
    positionY[0]++;
    else if(direction==DOWN)
    positionY[0]--;
    else if(direction==RIGHT)
    positionX[0]++;
    else if(direction==LEFT)
    positionX[0]--;
    for(int i = 0;i<snake_length;i++){
        if(i==0)
        glColor3f(0.0,1.0,0.0);
        else
        glColor3f(0.0,0.0,1.0);
        glRectd(positionX[i],positionY[i],positionX[i]+1,positionY[i]+1);
    }
     if(positionX[0]==0 || positionX[0] == gridX-1 || positionY[0]==0 || positionY[0] == gridY-1){
     gameOver=true;
    }
    if(positionX[0] == foodX && positionY[0] == foodY){
    snake_length++;
    if(snake_length>Max_Length)
    snake_length=Max_Length;
    food=true;
    }
}
