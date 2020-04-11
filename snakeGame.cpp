#include <GL/gl.h>
#include <GL/glut.h>
#include "snakeGame.h"

int gridX,gridY;

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
