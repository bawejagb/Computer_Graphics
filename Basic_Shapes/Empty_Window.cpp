// Task 2.1: Empty Color window
/*

Made By : Gaurav Baweja
*/
#include <GLUT/glut.h>
#include <iostream>
using namespace std;

void init();
void display();

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(300, 200);
    glutInitWindowSize(500, 500);
    glutCreateWindow("OpenGL Task 1");
    glutDisplayFunc(display);
    init();
    
    glutMainLoop();
    return 0;
}

void init(){
    //glClearColor(0.0, 0.0, 0.0, 0.0); //Black Screen
    //glClearColor(1.0,1.0,1.0,1.0); //White Color
    glClearColor(1.0, 1.0, 0.0, 1.0); //Yellow Color
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    //draw
    glFlush();
}
