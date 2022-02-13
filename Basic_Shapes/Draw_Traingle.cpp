// Task 2.4: Draw a triangle on Black background
/*

Made By : Gaurav Baweja
*/
#include <GLUT/glut.h>
#include <iostream>
using namespace std;

void init();
void display();
void reshape(int,int);

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(300, 200);
    glutInitWindowSize(500, 500);
    glutCreateWindow("OpenGL Task 1");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    init();
    
    glutMainLoop();
    return 0;
}

void init(){
    glClearColor(0.0, 0.0, 0.0, 0.0); //Black Screen
    
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    //draw
    glPointSize(10.0);
    
    glBegin(GL_TRIANGLES);
    
    glVertex2f(0.0, 5.0);
    glVertex2f(4.0, -3.0);
    glVertex2f(-4.0, -3.0);
    
    glEnd();
    
    glFlush();
}

void reshape(int w, int h){
    glViewport(0, 0,(GLsizei) w,(GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10, 10, -10, 10);
    glMatrixMode(GL_MODELVIEW);
}
