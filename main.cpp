#include <GL/gl.h>
#include <GL/glut.h>
#include "snakeGame.h"

#define COL 40
#define ROW 40

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    //Calls create grids from SnakeGame.c
    createGrid();
    glutSwapBuffers();
}

void reshape(int width , int height){
    glViewport(0,0,(GLsizei)width,(GLsizei)height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,COL,0.0,ROW,-1.0,1.0);
    glMatrixMode(GL_MODELVIEW);
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
    init();
    glutMainLoop();
	return 0;
}
