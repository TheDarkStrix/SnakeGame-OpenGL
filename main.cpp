#include <GL/glut.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void display(){
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(800,800);
    glutCreateWindow("SnakeGame OpenGL");
    glutDisplayFunc(display);
    glutMainLoop();
	return 0;
}


