#include<stdio.h>
#include<GL/glut.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,1.0,0.0);
    glClearColor(255,255,255,1);
    glLineWidth(10);
    glBegin(GL_LINES);
    glVertex2f(0.6,0.6);
    glVertex2f(-0.6,-0.6);
    glEnd();
    
}
int main(itn argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitWinowSize(1280,780);
    glutCreateWindow("Simple Line");
    glutDisplayFunc(display);
    glutMainLoop();
}
}
