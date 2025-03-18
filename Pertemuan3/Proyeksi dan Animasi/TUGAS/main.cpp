/* Nama File : LenganBergerakdenganTelapakJari
  Deskripsi : Program animasi lengan,telapak tangan, dan jari tangan yang dapat digerakkan dengan keyboard
  Pembuat   : Rafi Althaf Hendiansyah (24060123140158)
  Tanggal   : 18 Maret 2025
*/

#include <GL/glut.h>

// Variabel untuk rotasi sendi
static int shoulder = 0, elbow = 0, wrist = 0;
static int finger1 = 0, finger2 = 0, finger3 = 0, finger4 = 0, thumb = 0;

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();

    // Rotasi bahu
    glTranslatef(-1.0, 0.0, 0.0);
    glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);

    // Gambar lengan atas
    glPushMatrix();
    glScalef(2.0, 0.5, 1.0);
    glutWireCube(1.0);
    glPopMatrix();

    // Rotasi siku
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);

    // Gambar lengan bawah
    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    glutWireCube(1.0);
    glPopMatrix();

    // Rotasi pergelangan tangan 
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)wrist, 0.0, 0.0, 1.0);
    glTranslatef(0.3, 0.0, 0.0);

    // Gambar telapak tangan
    glPushMatrix();
    glScalef(0.6, 0.5, 0.2);
    glutWireCube(1.0);
    glPopMatrix();

    // Gambar jari-jari (dengan rotasi masuk dan keluar)
    float posisiJari[] = {0.15, 0.05, -0.05, -0.15}; 
    float panjangJari[] = {0.35, 0.45, 0.40, 0.30};
    int rotasiJari[] = {finger1, finger2, finger3, finger4};

    for (int i = 0; i < 4; i++) {
        glPushMatrix();
        glTranslatef(0.3, posisiJari[i], 0.0);
        glRotatef((GLfloat)rotasiJari[i], 0.0, 1.0, 0.0); // rotasi ke Y (gerakan masuk/keluar)
        glTranslatef(panjangJari[i] / 2, 0.0, 0.0);
        glScalef(panjangJari[i], 0.1, 0.1);
        glutWireCube(1.0);
        glPopMatrix();
    }

    // Gambar ibu jari dengan rotasi masuk/keluar
    glPushMatrix();
    glTranslatef(0.2, 0.265, 0.0);
    glRotatef((GLfloat)thumb, 0.0, 1.0, 0.0); // Rotasi ibu jari pada sumbu Y
    glTranslatef(0.15, 0.0, 0.0);
    glScalef(0.25, 0.1, 0.1);
    glutWireCube(1.0);
    glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 's': shoulder = (shoulder + 5) % 360; break;
        case 'S': shoulder = (shoulder - 5) % 360; break;
        case 'e': if (elbow < 135) elbow += 5; break;
        case 'E': if (elbow > 0) elbow -= 5; break;
        case 'w': if (wrist < 45) wrist += 5; break;
        case 'W': if (wrist > -45) wrist -= 5; break;
        case '1': if (finger1 < 90) finger1 += 5; break;
        case '!': if (finger1 > 0) finger1 -= 5; break;
        case '2': if (finger2 < 90) finger2 += 5; break;
        case '@': if (finger2 > 0) finger2 -= 5; break;
        case '3': if (finger3 < 90) finger3 += 5; break;
        case '#': if (finger3 > 0) finger3 -= 5; break;
        case '4': if (finger4 < 90) finger4 += 5; break;
        case '$': if (finger4 > 0) finger4 -= 5; break;
        case '5': if (thumb < 90) thumb += 5; break;
        case '%': if (thumb > 0) thumb -= 5; break;
        case 27: exit(0); break;
        default: break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(700, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("1 Tangan Bergerak");
    
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    
    glutMainLoop();
    return 0;
}

