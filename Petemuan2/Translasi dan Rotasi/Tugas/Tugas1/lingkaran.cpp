#include <GL/glut.h>
#include <cmath>

void drawCircle(float radius, int segments) {
    glBegin(GL_LINE_LOOP); 
    for (int i = 0; i < segments; i++) {
        float angle = 2.0f * 3.1415926f * float(i) / float(segments); // Sudut dalam radian
        float x = radius * cos(angle); // Posisi X
        float y = radius * sin(angle); // Posisi Y
        glVertex2f(x, y); // Menambahkan titik ke lingkaran
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT); 
    glLoadIdentity(); 

    glColor3f(0.0, 1.0, 1.0); 
    drawCircle(0.5, 100); 

    glFlush(); 
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1); 
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Lingkaran");
    
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    
    return 0;
}

