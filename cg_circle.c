#include <GL/glut.h>
//#include <math.h>
#include <stdio.h>
int pntX1,pntY1,r;
void plot(int x,int y) {
glBegin(GL_POINTS);
glVertex2i(x+pntX1, y+pntY1);
glEnd();
}
void myInit (void) {
glClearColor(1.0, 1.0, 1.0, 0.0);
glColor3f(0.0f, 0.0f, 0.0f);
glPointSize(4.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0, 800, 0, 900, 0, 1000);
}
void midPointCircle() {
int x = 0;
int y = r;
float decision = 5/4 -r;
plot(x,y);
while (x<=y) {
if (decision < 0) {
    x++;
    decision = decision + 2*x +1;
}
else {
    y--;
    x++;
    decision = decision + 2*(x-y) +1;
}
}
plot(x,y);
plot(x,-y);
plot(-x,y);
plot(-x,-y);
plot(y,x);
plot(-y,x);
plot(y,-x);
plot(-y,-x);
}
void display(void)
{
 glClear(GL_COLOR_BUFFER_BIT);
 midPointCircle(); 
 glutSwapBuffers();
}
int main(int argc, char** argv) {
printf("Give Radius: ");
scanf("%d",&r);
printf("Give centre: ");
scanf("%d%d",&pntX1,&pntY1);
//glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
glutInit(&argc,argv);
glutInitWindowPosition(150,150);
glutInitWindowSize(780,640);
glutCreateWindow("Midpoint Circle Drawing Algorithm");
glClearColor(1.0,1.0,1.0,0.0);
//glOrtho(0,640,0,480,0,480);
glutDisplayFunc(display);
myInit();
glutMainLoop();
return 0;
}

