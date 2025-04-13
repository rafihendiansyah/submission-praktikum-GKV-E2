#include <math.h>  
#include <GL/glut.h> 
#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>   
#define PI 3.14 
 
// Global variables
float angle = 0.0, deltaAngle = 0.0, ratio;  
float x = -5.0f, y = 12.0f, z = 40.0f; // initial camera position  
float lx = 0.0f, ly = 0.0f, lz = -1.0f;  
int deltaMove = 0, h, w;  
static int rotAngleX = 0, rotAngleY = 0, rotAngleZ = 0; 
float posXKaki = 10, posXBola = -10, posYKaki = 6, posYBola = -5; 
float rotKaki = 0.0; 
int kick = 0, roll = 0, touch = 0; 
float jarak = 1; 
 
GLUquadricObj *IDquadric; 

// Lighting variables   
const GLfloat light_ambient[] = { 0.5f, 0.5f, 0.5f, 0.0f };  
const GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };  
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };  
const GLfloat light_position[] = { 0.0f, 20.0f, 10.0f, 1.0f };  
const GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };  
const GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };  
const GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };  
const GLfloat high_shininess[] = { 100.0f };  
 
// Function prototypes
void init(void);
void Reshape(int w1, int h1);
void orientMe(float ang);
void moveMeFlat(int i);
void keyboard(unsigned char key, int x, int y);
void pressKey(int k, int x, int y);
void releaseKey(int key, int x, int y);
void lighting(void);
void Grid(void);
void Grid2(void);
void Balok(float panjang, float lebar, float tinggi);
void pergerakanKaki(void);
void pergerakanBola(void);
void Object(void);
void display(void);

// Initialization function
void init(void)  
{  
    glEnable(GL_DEPTH_TEST);  
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);  
    IDquadric = gluNewQuadric();      // Create A Pointer To The Quadric Object
    gluQuadricNormals(IDquadric, GLU_SMOOTH);  // Create Smooth Normals
    gluQuadricTexture(IDquadric, GL_TRUE);    // Create Texture Coords
}  
 
// Reshape function
void Reshape(int w1, int h1)  
{  
    if(h1 == 0)  
        h1 = 1;  
    w = w1;  
    h = h1;  
    ratio = 1.0f * w / h;  
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity();  
    glViewport(0, 0, w, h);  
    gluPerspective(45, ratio, 0.1, 1000);  
    glMatrixMode(GL_MODELVIEW);  
    glLoadIdentity();  
    gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0.0f, 1.0f, 0.0f);  
}  
 
// Function to rotate camera direction (look left/right)
void orientMe(float ang)  
{ 
    lx = sin(ang/10);  
    lz = -cos(ang/10);   
    glLoadIdentity();  
    gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0.0f, 1.0f, 0.0f);  
}  
 
// Function to move camera forward/backward
void moveMeFlat(int i)  
{ 
    x = x + i * (lx) * 0.1;  
    z = z + i * (lz) * 0.1;  
    glLoadIdentity();   
    gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0.0f, 1.0f, 0.0f);  
}  
 
// Keyboard function
void keyboard(unsigned char key, int x, int y)  
{ 
    switch (key) 
    { 
        case 'w':  
            rotAngleX += 2;  
            break;  
        case 's':  
            rotAngleX -= 2;  
            break; 
        case 'a':  
            rotAngleY += 2; 
            break;  
        case 'd':  
            rotAngleY -= 2; 
            break; 
        case 'q':  
            rotAngleZ += 2; 
            break;  
        case 'e':  
            rotAngleZ -= 2; 
            break;   
        case 'o':  
            posXKaki -= 1;  
            // Check if touching
            if (posXBola < -2.9) { 
                posXBola += 1; 
            } 
            break;  
        case 'p':  
            posXKaki += 1;  
            posXBola -= 1; 
            break;  
        case 'k':  
            kick = 1; 
            break;  
        case 32: // Space bar
            rotAngleX = rotAngleY = rotAngleZ = 0; 
            posXKaki = 10, posXBola = -10, posYKaki = 6, posYBola = -5; 
            rotKaki = kick = roll = 0; 
            break; 
        case 27: // ESC key  
            exit(0);  
        default: 
            break; 
    } 
    glutPostRedisplay(); 
}  
 
// Function for special keys (arrow keys)
void pressKey(int k, int x, int y)  
{ 
    // This function runs when keyboard keys are pressed but not released
    switch (k)  
    {  
        case GLUT_KEY_UP: 
            deltaMove = 1;
            break;  
        case GLUT_KEY_DOWN: 
            deltaMove = -1;
            break;   
        case GLUT_KEY_LEFT: 
            deltaAngle = -0.01f;
            break;  
        case GLUT_KEY_RIGHT: 
            deltaAngle = 0.01f;
            break; 
    }  
}  
 
// Function for special key release
void releaseKey(int key, int x, int y)  
{ 
    // This function runs when keyboard pressure is released
    switch (key)  
    {  
        case GLUT_KEY_UP: 
            if (deltaMove > 0)  
                deltaMove = 0;  
            break;  
        case GLUT_KEY_DOWN: 
            if (deltaMove < 0)  
                deltaMove = 0;  
            break;  
        case GLUT_KEY_LEFT: 
            if (deltaAngle < 0.0f)  
                deltaAngle = 0.0f;  
            break;  
        case GLUT_KEY_RIGHT: 
            if (deltaAngle > 0.0f)  
                deltaAngle = 0.0f;  
            break;  
    }  
}  
 
// Lighting function
void lighting()
{ 
    glEnable(GL_DEPTH_TEST);  
    glDepthFunc(GL_LESS);  
    glEnable(GL_LIGHT0);  
    glEnable(GL_NORMALIZE);  
    glEnable(GL_COLOR_MATERIAL);  
    glEnable(GL_LIGHTING);  
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);  
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);  
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);  
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);  
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);  
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);  
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);  
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);  
}  
 
// Function to create grid on floor
void Grid()  
{ 
    double i;  
    const float Z_MIN = -50, Z_MAX = 50;  
    const float X_MIN = -50, X_MAX = 50;  
    const float gap = 2;  
    glColor3f(0.5, 0.5, 0.5);  
    glBegin(GL_LINES);  
    for(i = Z_MIN; i < Z_MAX; i += gap)  
    {  
        glVertex3f(i, 0, Z_MIN);  
        glVertex3f(i, 0, Z_MAX);   
    }  
 
    for(i = X_MIN; i < X_MAX; i += gap)  
    {  
        glVertex3f(X_MIN, 0, i);  
        glVertex3f(X_MAX, 0, i);  
    }  
    glEnd();  
}  
 
// Function to create floor surface
void Grid2() 
{ 
    glColor3f(1.0f, 1.0f, 1.0f); 
    glBegin(GL_QUADS);  
        glVertex3f(-50, 0, 50);  
        glVertex3f(-50, 0, -50);  
        glVertex3f(50, 0, -50); 
        glVertex3f(50, 0, 50);  
    glEnd();  
}
 
// Function to create box
void Balok(float panjang, float lebar, float tinggi) 
{ 
    glPushMatrix();  
    float p = panjang/2; 
    float l = lebar/2; 
    float t = tinggi/2; 
    
    // Front
    glBegin(GL_QUADS);  
        glVertex3f(-p, 0, l);  
        glVertex3f(p, 0, l);  
        glVertex3f(p, -t*2, l);  
        glVertex3f(-p, -t*2, l);  
    glEnd(); 
   
    // Back
    glBegin(GL_QUADS); 
        glVertex3f(-p, 0, -l);  
        glVertex3f(p, 0, -l);  
        glVertex3f(p, -t*2, -l);  
        glVertex3f(-p, -t*2, -l); 
    glEnd();  
  
    // Top
    glBegin(GL_QUADS); 
        glTexCoord2f(0.0f, 0.0f);   
        glVertex3f(-p, 0, -l);  
        glTexCoord2f(0.0f, 1.0f);   
        glVertex3f(p, 0, -l);  
        glTexCoord2f(1.0f, 0.0f);   
        glVertex3f(p, 0, l);  
        glTexCoord2f(1.0f, 1.0f);   
        glVertex3f(-p, 0, l); 
    glEnd(); 
       
    // Bottom
    glBegin(GL_QUADS); 
        glTexCoord2f(0.0f, 0.0f);   
        glVertex3f(-p, -t*2, -l);  
        glTexCoord2f(0.0f, 1.0f);   
        glVertex3f(p, -t*2, -l);  
        glTexCoord2f(1.0f, 0.0f);   
        glVertex3f(p, -t*2, l);  
        glTexCoord2f(1.0f, 1.0f);   
        glVertex3f(-p, -t*2, l); 
    glEnd(); 
  
    // Right
    glBegin(GL_QUADS);  
        glTexCoord2f(0.0f, 0.0f);   
        glVertex3f(-p, -t*2, -l);  
        glTexCoord2f(1.0f, 0.0f);   
        glVertex3f(-p, -t*2, l);  
        glTexCoord2f(0.0f, 1.0f);   
        glVertex3f(-p, 0, l);  
        glTexCoord2f(1.0f, 1.0f);   
        glVertex3f(-p, 0, -l); 
    glEnd(); 
     
    // Left
    glBegin(GL_QUADS); 
        glTexCoord2f(0.0f, 0.0f);   
        glVertex3f(p, -t*2, -l);  
        glTexCoord2f(1.0f, 0.0f);   
        glVertex3f(p, -t*2, l);  
        glTexCoord2f(0.0f, 1.0f);   
        glVertex3f(p, 0, l);  
        glTexCoord2f(1.0f, 1.0f);   
        glVertex3f(p, 0, -l);  
    glEnd(); 
    glPopMatrix(); 
} 
 
// Function for leg movement
void pergerakanKaki()
{ 
    // Condition for pulling back leg
    if (kick == 1) {
        if (rotKaki <= 45) {
            rotKaki += 1.03;        // kecepatan
        }
        if (rotKaki > 44.9) {
            kick = 2;   
        }
    }
    
    // Detect if ball is touching
    if (posXBola > -2.9) {
        touch = 1;
    } else if (posXBola < -12) {
        touch = 0;
    }
    
    // Condition for kicking
    if (kick == 2) {
        if (rotKaki >= -90) {
            rotKaki -= 1.2; // kecepatan
            if (rotKaki < 1 && touch == 1) {  
                roll = 1;  
            }
        }
        if (rotKaki < -90) {
            kick = 3;  
        }
    }
    
    // Condition for returning leg
    if (kick == 3) {
        if (rotKaki <= 0) {
            rotKaki += 1.05; // kecepatan
        }
        if (rotKaki > -1) {
            kick = 0;
        }
    }
} 
 
// Function for ball movement
void pergerakanBola()
{ 
    // Condition if leg has touched ball
    if (roll == 1) {
        if (jarak > 0) {    
            posXBola -= 0.33; // Controls speed & distance covered in one iteration
            jarak -= 0.01;    // Controls number of iterations
        }
        if (jarak < 0) {  
            roll = 0;
            jarak = 1;    
        }
    }
} 
 
// Function to create objects
void Object() 
{ 
    glPushMatrix(); 
        glTranslatef(posXKaki, posYKaki, 0); 
        glPushMatrix(); 
            pergerakanKaki(); 
            glRotatef(rotKaki, 0, 0, 1); // Execute leg rotation  
            glColor3f(1.0, 3.0, 0.9); 
            Balok(2, 3, 6); 
        glPopMatrix(); 
       
        glPushMatrix(); 
            pergerakanBola(); 
            glColor3f(1.0, 0.0, 0.0); 
            glTranslatef(posXBola, posYBola, 0); 
            glutSolidSphere(1, 20, 20); 
        glPopMatrix(); 
    glPopMatrix(); 
  
    glFlush(); 
}     
 
// Display function
void display()
{  
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  
    
    // If move and angle are not zero, move camera...  
    if (deltaMove)  
        moveMeFlat(deltaMove);  
    if (deltaAngle) {  
        angle += deltaAngle;  
        orientMe(angle);   
    }  
    
    glPushMatrix(); 
        glRotated(rotAngleX, 1, 0, 0);   
        glRotated(rotAngleY, 0, 1, 0); 
        glRotated(rotAngleZ, 0, 0, 1); 
        
        // Draw grid  
        Grid();  
        //Grid2(); 
        
        // Draw objects  
        Object();  
    glPopMatrix();  
    
    glFlush();  
    glutSwapBuffers(); 
}   
 
// Main function
int main(int argc, char **argv)  
{  
    glutInit(&argc, argv);  
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);  
    glutInitWindowPosition(100, 100);  
    glutInitWindowSize(640, 480);  
    glutCreateWindow("Tendangan");  
    glutSpecialFunc(pressKey); 
    glutSpecialUpFunc(releaseKey);  
    glutDisplayFunc(display);  
    glutKeyboardFunc(keyboard); 
    glutIdleFunc(display);  
    glutReshapeFunc(Reshape); 
    lighting(); 
    init(); 
    glutMainLoop(); 
    return(0); 
}
