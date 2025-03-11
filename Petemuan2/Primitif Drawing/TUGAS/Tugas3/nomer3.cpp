#include <GL/glut.h>

void drawCube(float x, float y) {
    float size = 0.2;  // Ukuran kubus
    glBegin(GL_QUADS);
    glColor4f(1.0, 0.0, 1.0, 1.0);  // Warna pink

    // Depan (2D tampilan depan)
    glVertex3f(x, y, 0.0);
    glVertex3f(x + size, y, 0.0);
    glVertex3f(x + size, y + size, 0.0);
    glVertex3f(x, y + size, 0.0);

    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    float spacing = 0.05;  // Jarak antar kubus

    // Baris terbawah (1 kubus)
    drawCube(-0.1, -0.85);

    // Baris kedua dari bawah (2 kubus)
    drawCube(-0.3, -0.65);
    drawCube( 0.1, -0.65);

    // Baris ketiga dari bawah (3 kubus)
    drawCube(-0.45, -0.45);
    drawCube(-0.10, -0.45);
    drawCube( 0.25, -0.45);

    // Baris keempat dari bawah (2 kubus)
    drawCube(-0.25, -0.25);
    drawCube( 0.05, -0.25);

    // Baris kelima dari bawah (1 kubus paling atas)
    drawCube(-0.1, -0.05);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Kubus Bertingkat");
    glClearColor(0.0, 0.0, 1.0, 1.0); //Backgorund biru
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

