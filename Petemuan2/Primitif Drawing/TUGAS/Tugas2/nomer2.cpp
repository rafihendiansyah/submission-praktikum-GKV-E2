#include <GL/glut.h>

// Fungsi menggambar garis tersambung (GL_LINE_STRIP)
void drawLineStrip() {
    glBegin(GL_LINE_STRIP);
	glVertex2f(0.0, 0.5);  // Titik mulai (tengah atas, mbuat leher) 
	
	glVertex2f(0.0, 0.3);  // Titik tengah badan
	glVertex2f(0.2, 0.4);  // Tangan kanan
	glVertex2f(0.0, 0.3);  // Balik ke titik tengah badan
	glVertex2f(-0.2, 0.1);  // Tangan kiri
	glVertex2f(0.0, 0.3);  // Balik ke titik tengah badan
	
    glVertex2f(0.0, 0.1);  // Turun ke bawah (badan)
    glVertex2f(-0.2, -0.3); // Kaki kiri
    glVertex2f(0.0, 0.1);  // Kembali ke badan
    glVertex2f(0.2, -0.3);  // Kaki kanan  (catetan: cara gambarnya ini dia 1 garis ga ke potong")
    glEnd();
}

// Fungsi menggambar garis tertutup (GL_LINE_LOOP)
void drawLineLoop() {
    glBegin(GL_LINE_LOOP); // Gambar kepala
    glVertex2f(-0.2, 0.9); // Titik kiri atas kepala
    glVertex2f(0.2, 0.9);  // Titik kanan atas kepala
    glVertex2f(0.2, 0.5);  // Titik kanan bawah kepala
    glVertex2f(-0.2, 0.5); // Titik kiri bawah kepala (catetan: cara gambarnya dia buat titiknya lalu semua di gabungkan)
    glEnd();
}

// Fungsi menggambar kipas segitiga (GL_TRIANGLE_FAN)
void drawTriangleFan() {
    glBegin(GL_TRIANGLE_FAN); // Gambar mata kiri
    glVertex2f(-0.15, 0.8);  
    glVertex2f(-0.03, 0.7);
    glVertex2f(-0.15, 0.7);	 //(catetan: ini dia membuat semua titik lalu digabungkan dan yg didalamnya jadi bewarna)
    glEnd();
}

// Fungsi menggambar pita segitiga (GL_TRIANGLE_STRIP)
void drawTriangleStrip() {
    glBegin(GL_TRIANGLE_STRIP); // gambar mulut
    glVertex2f(-0.07, 0.6);
    glVertex2f(-0.05, 0.55);
    glVertex2f(0.05, 0.55);
	glVertex2f(0.07, 0.6);
	
    glEnd();
}

// Fungsi menggambar kotak (GL_QUADS)
void drawQuads() {
    glBegin(GL_QUADS); //gambar mata kanan
    glVertex2f(0.15, 0.8);
    glVertex2f(0.05, 0.8);
    glVertex2f(0.05, 0.7);
    glVertex2f(0.15, 0.7); //catetan: urutan membuat titik mempengaruhi hasil
    
    glEnd();
}

// Fungsi menggambar pita persegi (GL_QUAD_STRIP)
void drawQuadStrip() {
    glBegin(GL_QUAD_STRIP); //mbuat sajam
    glVertex2f(-0.2, 0.1);
    glVertex2f(-0.4, 0.43);
    glVertex2f(-0.2, 0.1);
    glVertex2f(-0.43, 0.6);
    glVertex2f(-0.2, 0.03);
    glVertex2f(-0.15, 0.05);
    glEnd();
}

// Fungsi utama untuk menggambar semua objek
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor4f(1.0, 1.0, 1.0, 0.0);  // Warna putih

    drawLineStrip();
    drawLineLoop();
    drawTriangleFan();
    drawTriangleStrip();
    drawQuads();
    drawQuadStrip();

    glFlush();
}

// Fungsi utama program
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("stickman bawa sajam");
    glClearColor(0.0, 0.0, 0.0, 1.0); // Latar belakang hitam
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

