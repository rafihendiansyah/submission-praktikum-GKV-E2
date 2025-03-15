#include <GL/glut.h>
#include <cmath>

// Fungsi untuk menggambar lingkaran (roda mobil)
void drawCircle(float radius, int segments) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < segments; i++) {
        float angle = 2.0f * 3.1415926f * float(i) / float(segments);
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

// Fungsi untuk menggambar badan mobil 
void drawCarBody() {
    glColor4f(0.9, 0.0, 0.0, 2.0); // Warna merah
    glBegin(GL_POLYGON);
    glVertex2f(-0.7, -0.2); // Kiri bawah
    glVertex2f(0.7, -0.2);  // Kanan bawah
    glVertex2f(0.6, 0.05);  // Kanan depan atas
    glVertex2f(-0.5, 0.05); // Kiri belakang atas
    glEnd();
}

// Fungsi untuk menggambar bagian atas mobil 
void drawCarTop() {
    glColor3f(0.9, 0.0, 0.0); // Warna merah
    glBegin(GL_POLYGON);
    glVertex2f(-0.5, 0.05);  // Kiri bawah
    glVertex2f(0.4, 0.05);   // Kanan bawah
    glVertex2f(0.25, 0.25);  // Kanan atas miring ke belakang
    glVertex2f(-0.2, 0.25);  // Kiri atas
    glEnd();
}

// Fungsi untuk menggambar jendela mobil
void drawCarWindows() {
    glColor3f(0.2, 0.2, 0.2); 
    glBegin(GL_POLYGON);
    glVertex2f(-0.2, 0.07);
    glVertex2f(0.3, 0.08);
    glVertex2f(0.2, 0.22);
    glVertex2f(-0.15, 0.22);
    glEnd();
}

// Fungsi untuk menggambar roda mobil
void drawCarWheels() {
    glColor3f(0.0, 0.0, 0.0);

    // Roda kiri 
    glPushMatrix();
    glTranslatef(-0.5, -0.15, 0.0); 
    drawCircle(0.13, 30); 
    glPopMatrix();

    // Roda kanan 
    glPushMatrix();
    glTranslatef(0.5, -0.15, 0.0); 
    drawCircle(0.13, 30); 
    glPopMatrix();
}

// Fungsi untuk menggambar spoiler mobil sport
void drawSpoiler() {
    glColor3f(0.0, 0.0, 0.0); // Warna merah
    glBegin(GL_POLYGON);
    glVertex2f(-0.6, 0.05);
    glVertex2f(-0.4, 0.05);
    glVertex2f(-0.4, 0.12);
    glVertex2f(-0.6, 0.12);
    glEnd();
}

// Fungsi untuk menggambar seluruh mobil
void drawCar() {
    glPushMatrix();
    drawCarBody();
    drawSpoiler();
    drawCarTop();
    drawCarWindows();
    drawCarWheels();
    glPopMatrix();
}

// Fungsi display untuk menggambar mobil
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    drawCar(); // Panggil fungsi untuk menggambar mobil

    glFlush();
}

// Inisialisasi tampilan
void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1); // Koordinat tampilan
}

// Fungsi main untuk menjalankan program
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Mobil porse");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

