#include <GL/glut.h>

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    // **1. Titik Alternatif menggunakan GL_QUADS (kotak kecil)**
    glColor3f(1.0, 0.0, 0.0); // Warna merah
    glBegin(GL_QUADS);
    glVertex2f(-0.01, -0.01);
    glVertex2f( 0.01, -0.01);
    glVertex2f( 0.01,  0.01);
    glVertex2f(-0.01,  0.01);
    glEnd();

    // **2. Garis Vertikal Alternatif menggunakan GL_LINE_STRIP**
    glColor3f(0.0, 1.0, 0.0); // Warna hijau
    glBegin(GL_LINE_STRIP);
    glVertex2f( 0.1, -0.5);  // Titik bawah
    glVertex2f( 0.1,  0.5);  // Titik atas
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Garis Vertikal Alternatif");
    glClearColor(0.0, 0.0, 0.0, 1.0); // Latar belakang hitam
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

