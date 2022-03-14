/*
Task 4.2: Ellipse Drawing(Mid-Point Theorem)
Made By : Gaurav Baweja
*/

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include<GL/glut.h>
#include<windows.h>
#endif
#include <iostream>
using namespace std;

void init();
void display();
void reshape(int,int);
void draw_pixel(int,int);
void elipse(int,int,int,int);

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

void elipse(int rx, int ry, int xc, int yc){
    float dx, dy, p1, p2, x, y;
        x = 0;
        y = ry;
     
        // Initial decision parameter of region 1
        p1 = (ry * ry) - (rx * rx * ry) +
                         (0.25 * rx * rx);
        dx = 2 * ry * ry * x;
        dy = 2 * rx * rx * y;
     
        // For region 1
        while (dx < dy)
        {
            draw_pixel(x+xc,y+yc);
            draw_pixel(-x+xc,y+yc);
            draw_pixel(x+xc,-y+yc);
            draw_pixel(-x+xc,-y+yc);
            // Print points based on 4-way symmetry
            cout << x + xc << " , " << y + yc << endl;
     
            // Checking and updating value of
            // decision parameter based on algorithm
            if (p1 < 0)
            {
                x++;
                dx = dx + (2 * ry * ry);
                p1 = p1 + dx + (ry * ry);
            }
            else
            {
                x++;
                y--;
                dx = dx + (2 * ry * ry);
                dy = dy - (2 * rx * rx);
                p1 = p1 + dx - dy + (ry * ry);
            }
        }
     
        // Decision parameter of region 2
        p2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) +
             ((rx * rx) * ((y - 1) * (y - 1))) -
              (rx * rx * ry * ry);
     
        // Plotting points of region 2
        while (y >= 0)
        {
            draw_pixel(x+xc,y+yc);
            draw_pixel(-x+xc,y+yc);
            draw_pixel(x+xc,-y+yc);
            draw_pixel(-x+xc,-y+yc);
            // Print points based on 4-way symmetry
            cout << x + xc << " , " << y + yc << endl;
     
            // Checking and updating parameter
            // value based on algorithm
            if (p2 > 0)
            {
                y--;
                dy = dy - (2 * rx * rx);
                p2 = p2 + (rx * rx) - dy;
            }
            else
            {
                y--;
                x++;
                dx = dx + (2 * ry * ry);
                dy = dy - (2 * rx * rx);
                p2 = p2 + dx - dy + (rx * rx);
            }
        }
    
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    //glPointSize(2.0);
    int a,b;
    a = 40;
    b  = 20;
    elipse(a,b,0,0);
    glFlush();
}

void reshape(int w, int h){
    glViewport(0, 0,(GLsizei) w,(GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -100, 100);
    glMatrixMode(GL_MODELVIEW);
}
