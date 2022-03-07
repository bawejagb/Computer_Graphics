/*
Task 4.1: Mid-Point Circle
Made By : Gaurav Baweja
*/
#include <GLUT/glut.h>
#include <iostream>
using namespace std;

void init();
void display();
void reshape(int,int);
void draw_pixel(int,int);
void circle(int);

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

void draw_pixel(int x, int y){
    glBegin(GL_POINTS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2i(x, y);
    glEnd();
}

void circle(int r){
    int x,y;
    float p=5.0/4-r;
    x=r;
    y=0;
    if(r==0){
        draw_pixel(0,0);
        return;
    }
    
    while(x!=y){
        draw_pixel(x, y);
        draw_pixel(x, -y);
        draw_pixel(-x, y);
        draw_pixel(-x, -y);
        draw_pixel(y, x);
        draw_pixel(-y, x);
        draw_pixel(y, -x);
        draw_pixel(-y, -x);
        if(p<=0){
            p+=2*(y+1)+1;
        }
        else{
            x--;
            p+=2*(y-x+2)+1;
        }
        y++;
    }
    
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    //glPointSize(10.0);
    int r;
    r=20;
    circle(r);
    glFlush();
}

void reshape(int w, int h){
    glViewport(0, 0,(GLsizei) w,(GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -100, 100);
    glMatrixMode(GL_MODELVIEW);
}
