#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
// Define the initial vertices of a square
float vertices[][2] = {{-0.5, -0.5}, {0.5, -0.5}, {0.5, 0.5}, {-0.5, 0.5}};
// Initialize transformation matrix
float transformationMatrix[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
// Function to multiply two 3x3 matrices
void multiplyMatrix(float A[3][3], float B[3][3]) {
 float result[3][3] = {{0}};
 for (int i = 0; i < 3; i++) {
 for (int j = 0; j < 3; j++) {
 for (int k = 0; k < 3; k++) {
 result[i][j] += A[i][k] * B[k][j];
 }
 }
 }
 for (int i = 0; i < 3; i++) {
 for (int j = 0; j < 3; j++) {
 A[i][j] = result[i][j];
 }
 }
}
// Function to apply transformation matrix to vertices
void applyTransformation() {
 for (int i = 0; i < 4; i++) {
 float x = vertices[i][0];
 float y = vertices[i][1];
 vertices[i][0] = x * transformationMatrix[0][0] + y * transformationMatrix[0][1] +
transformationMatrix[0][2];
 vertices[i][1] = x * transformationMatrix[1][0] + y * transformationMatrix[1][1] +
transformationMatrix[1][2];
 }
}
// Function to display the transformed shape
void display() {
 glClear(GL_COLOR_BUFFER_BIT);
 glBegin(GL_POLYGON);
 glColor3f(1.0, 0.0, 0.0); // Red color
 for (int i = 0; i < 4; i++) {
 glVertex2f(vertices[i][0], vertices[i][1]);
 }
 glEnd();
glFlush();
}
// Function to handle key presses for different transformations
void keyPressed(unsigned char key, int x, int y) {
 float angle, shearX, shearY; 
 char axis;
 switch (key) {
 case 'R':
 case 'r':
 // Rotation
 printf("Enter the rotation angle (in degrees): ");
 scanf("%f", &angle);
 angle = angle * (3.14159265359 / 180.0); // Convert to radians
 float rotationMatrix[3][3] = {{cos(angle), -sin(angle), 0},
 {sin(angle), cos(angle), 0},
 {0, 0, 1}};
 multiplyMatrix(transformationMatrix, rotationMatrix);
 applyTransformation();
 display();
 break;
 case 'S':
 case 's':
 // Shear
 printf("Enter the shear factors (X Y): ");
 scanf("%f %f", &shearX, &shearY);
 float shearMatrix[3][3] = {{1, shearX, 0},
 {shearY, 1, 0},
 {0, 0, 1}};
 multiplyMatrix(transformationMatrix, shearMatrix);
 applyTransformation();
 display();
 break;
 case 'F':
 case 'f':
 // Reflection
 
 printf("Enter the reflection axis (X or Y): ");
 scanf(" %c", &axis);
 if (axis == 'X' || axis == 'x') {
 float reflectionMatrixX[3][3] = {{1, 0, 0},
 {0, -1, 0},
 {0, 0, 1}};
 multiplyMatrix(transformationMatrix, reflectionMatrixX);
 } else if (axis == 'Y' || axis == 'y') {
 float reflectionMatrixY[3][3] = {{-1, 0, 0},
 {0, 1, 0},
 {0, 0, 1}};
 multiplyMatrix(transformationMatrix, reflectionMatrixY);
 }
applyTransformation();
 display();
 break;
 default:
 break;
 }
}
int main(int argc, char **argv) {
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize(500, 500);
 glutCreateWindow("2D Transformations");
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
 glutDisplayFunc(display);
 glutKeyboardFunc(keyPressed);
 printf("Press 'R' for Rotation, 'S' for Shear, 'F' for Reflection\n");
 printf("Press 'Q' to quit.\n");
 glutMainLoop();
 return 0;
}
