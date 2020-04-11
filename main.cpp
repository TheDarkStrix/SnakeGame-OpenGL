#include <GL/gl.h>
#include <GL/glut.h>
#include "snakeGame.h"

#define COL 50
#define ROW 50
#define FPS 10

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int index=0;

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    //Calls create grids from SnakeGame.c
    //More number of ROW and COL decides the width and 
    //height of each cell
    createGrid();
    glRectd(index,20,index+2,22);
    index++;
    //this is just for testing
    if(index>40){
        index=0;
    }
    glutSwapBuffers();
}

void reshape(int width , int height){
    glViewport(0,0,(GLsizei)width,(GLsizei)height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,COL,0.0,ROW,-1.0,1.0);
    glMatrixMode(GL_MODELVIEW);
}

void timer(int){
glutPostRedisplay();
// We need to refresh the display "FPS" times in 1 sec 
// if the FPS is 20 , the display is refreshed 20 times in 1 sec
// higher the fps value higher the speed for the snake
glutTimerFunc(1000/FPS,timer,0);
}

void init(){
//Black is the default color background in glut, this function can be ignored also
glClearColor(0.0,0.0,0.0,1.0);
Grid(COL,ROW);
}

int main(int argc, char** argv) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(800,800);
    glutCreateWindow("SnakeGame OpenGL");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0,timer,0);
    init();
    glutMainLoop();
	return 0;
}
