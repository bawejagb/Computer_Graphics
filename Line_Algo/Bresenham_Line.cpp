/*
Task 3.2: Bresenham Line Algorithm

Made By : Gaurav Baweja
*/
#include <GLUT/glut.h>
#include <iostream>
using namespace std;

void init();
void display();
void reshape(int,int);
void draw_pixel(int,int);
void bresenhamLine(int,int,int,int);

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
void bresenhamLine(int x0, int y0, int x1, int y1){
    int dy, dx, incx, incy, x, y, p, inc1, inc2;
    dx = x1-x0;
    dy = y1-y0;
    if (dx < 0) dx = -dx;
    if (dy < 0) dy = -dy;
    incx = 1;
    if (x1 < x0) incx = -1;
    incy = 1;
    if (y1 < y0) incy = -1;
    x = x0; y = y0;
    if (dx > dy) {
        draw_pixel(x, y);
        p = 2 * dy-dx;
        inc1 = 2*(dy-dx);
        inc2 = 2*dy;
        for (int i=0; i<dx; i++) {
            if (p >= 0) {
                y += incy;
                p += inc1;
            }
            else
                p += inc2;
            x += incx;
            draw_pixel(x, y);
        }

    }
    else {
        draw_pixel(x, y);
        p = 2*dx-dy;
        inc1 = 2*(dx-dy);
        inc2 = 2*dx;
        for (int i=0; i<dy; i++) {
            if (p >= 0) {
                x += incx;
                p += inc1;
            }
            else
                p += inc2;
            y += incy;
            draw_pixel(x, y);
        }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    //draw DDA Line
    int x0,x1,y0,y1;
    x0 = y0 = 10;
    x1 = y1 = 90;
    bresenhamLine(x0,y0,x1,y1);

    glFlush();
}

void reshape(int w, int h){
    glViewport(0, 0,(GLsizei) w,(GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 100, 0, 100);
    glMatrixMode(GL_MODELVIEW);
}
