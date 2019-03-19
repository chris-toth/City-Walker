#define GL_GLEXT_PROTOTYPES
#define DISPLAY_MOUSE_INFO "Mouse control information here?"
#define DISPLAY_KEY_INFO "Keyboard control information here?"

#include <stdlib.h>  // Useful for the following includes.
#include <stdio.h>    
#include <string.h>  // For string operations.

#include <GL/gl.h>   // OpenGL itself.
#include <GL/glu.h>  // GLU support library.
#include <GL/glut.h> // GLUT support library.

int Window_ID;

int Window_Width = 800;
int Window_Height = 600;

// eye variables
float eyex = -3.5f;
float eyey = 2.5f;
float eyez = -3.5f;

// Function for string rendering
static void PrintString(void *font, char *str)
{
   int i,len=strlen(str);

   for(i=0;i < len; i++)
      glutBitmapCharacter(font,*str++);
}

//******************************************************//
//                   DRAW OBJECTS HERE                  //
//******************************************************//
// Draw street 
void drawStreet() {
    //TODO
}

// Draw robot 
void drawRobot() {
    //TODO
}

// Draw buildings
void drawBuildings() {
    //TODO
}

// Temporary grid for visualizing movement
void drawGrid() {
    for (int i = 0; i < 40; i++) {
        glPushMatrix();

        if (i < 20) {
            glTranslatef(0, 0 , i);
        }
        else if (i >= 20) {
            glTranslatef(i-20, 0, 0);
            glRotatef(-90, 0, 1, 0);
        }

        glBegin(GL_LINES);
        glColor3f(0.0, 0.0, 0.0);
        glLineWidth(1);
        glVertex3f(0, -0.1, 0);
        glVertex3f(19, -0.1, 0);
        glEnd();

        glPopMatrix();
    }
}

// Draw Cube
void drawCube(float size = 0.5f) {
    glBegin(GL_QUADS); 

    // Far face.  Green
    glNormal3f( 0.0f, 0.0f,-1.0f);
    glColor4f(0.0, 1.0, 0.0, 0.0); // no opacity

    glTexCoord2f(0.995f, 0.005f); glVertex3f(-size, -size, -size); // TL
    glTexCoord2f(0.995f, 0.995f); glVertex3f(-size,  size, -size); // TR
    glTexCoord2f(0.005f, 0.995f); glVertex3f( size,  size, -size); // BR
    glTexCoord2f(0.005f, 0.005f); glVertex3f( size, -size, -size); // BL

    // Right face.  Blue
    glNormal3f( 1.0f, 0.0f, 0.0f);
    glColor4f(0.0, 0.0, 1.0, 0.0); // no opacity

    glTexCoord2f(0.005f, 0.995f); glVertex3f( size,  size,  size); // TL
    glTexCoord2f(0.005f, 0.005f); glVertex3f( size, -size,  size); // BL
    glTexCoord2f(0.995f, 0.005f); glVertex3f( size, -size, -size); // BR
    glTexCoord2f(0.995f, 0.995f); glVertex3f( size,  size, -size); // TR
    
    // Front face; offset. Red
    glNormal3f( 0.0f, 0.0f, 1.0f);
    glColor4f( 1.0f, 0.0f, 0.0f, 0.0f);

    glTexCoord2f( 0.995f, 0.005f); glVertex3f( size, -size,  size); // BR
    glTexCoord2f( 0.995f, 0.995f); glVertex3f( size,  size,  size); // TR
    glTexCoord2f( 0.005f, 0.995f); glVertex3f(-size,  size,  size); // TL
    glTexCoord2f( 0.005f, 0.005f); glVertex3f(-size, -size,  size); // BL

    // Left Face; offset.  Yellow
    glNormal3f(-1.0f, 0.0f, 0.0f);  
    glColor4f(0.9,0.9,0.2,0.0);

    glTexCoord2f(0.995f, 0.005f); glVertex3f(-size, -size,  size); // BR
    glTexCoord2f(0.995f, 0.995f); glVertex3f(-size,  size,  size); // TR
    glTexCoord2f(0.005f, 0.995f); glVertex3f(-size,  size, -size); // TL
    glTexCoord2f(0.005f, 0.005f); glVertex3f(-size, -size, -size); // BL

    // Top Face. Orange
    glNormal3f(0.0f, 1.0f, 0.0f);
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f); 

    glTexCoord2f(0.005f, 0.005f); glVertex3f( -size, size,  size); // front left - BL
    glTexCoord2f(0.995f, 0.005f); glVertex3f( size, size, size); // front right - BR
    glTexCoord2f(0.995f, 0.995f); glVertex3f( size, size,  -size); // rear right - TR
    glTexCoord2f(0.005f, 0.995f); glVertex3f( -size, size, -size); // rear left - TL

    // Bottom Face. Purple
    glNormal3f(0.0f, -1.0f, 0.0f);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);

    glTexCoord2f(0.005f, 0.995f); glVertex3f( -size, -size, -size); // rear left - TL
    glTexCoord2f(0.995f, 0.995f); glVertex3f( size, -size, -size); // rear left - TR
    glTexCoord2f(0.995f, 0.005f); glVertex3f( size, -size, size); // front right - BR
    glTexCoord2f(0.005f, 0.005f); glVertex3f( -size, -size, size); // front left - BL

    // All polygons have been drawn.
    glEnd();
}

void drawPyramid(float size = 0.5f) {
glBegin(GL_TRIANGLES);
    //Triangle 1
    glColor3f(1.0f,0.0f,0.0f); // Red face
    glVertex3f( 0.0f, size, 0.0f);   //V0
    glVertex3f(-size,-size, size);   //V1
    glVertex3f( size,-size, size);   //V2
    //Triangle 2
    glColor3f(0.0f,1.0f,0.0f); // Green face
    glVertex3f( 0.0f, size, 0.0f);   //V0
    glVertex3f( size,-size, size);   //V2
    glVertex3f( size,-size,-size);   //V3
    //Triangle 3
    glColor3f(0.0f,0.0f, 1.0f); // Blue face
    glVertex3f( 0.0f, size, 0.0f);   //V0 
    glVertex3f( size,-size,-size);   //V3
    glVertex3f(-size,-size,-size);   //V4
    //Triangle 4
    glColor3f(0.5f,0.0f,0.5f);  // Purple face
    glVertex3f( 0.0f, size, 0.0f);   //V0
    glVertex3f(-size,-size,-size);   //V4
    glVertex3f(-size,-size, size);   //V1
    //Triangle 5
    glColor3f(1.0f,1.0f,0.0f);  // Yellow face
    glVertex3f( size, -size, size); //BR
    glVertex3f(-size,-size, -size);   //TL
    glVertex3f(size,-size,-size);  //TR
    //Triangle 6
    glColor3f(1.0f,1.0f,0.0f);  // Yellow face
    glVertex3f( -size, -size, size);   //BL
    glVertex3f(-size,-size, -size);   //TL
    glVertex3f(size,-size, size);   //BR
glEnd();
}

// draws a solid sphere
void drawSphere(float size = 0.5f, 
                float r = 0.5f, float g = 0.5f, float b = 0.5f) {
    glColor3f(r, g, b);
    GLUquadric *quad;
    quad = gluNewQuadric();
    gluSphere(quad,size,100,20);
}

// Draw cylinder
void drawCylinder(float base = 0.5f, float top = 0.5f, float height = 1.0f, 
             float r = 0.5f, float g = 0.0f, float b = 0.5f) {
    glColor3f(r, g, b);
    GLUquadric *quad;
    quad = gluNewQuadric();
    gluCylinder(quad, base, top, height, 100, 20);
}

//******************************************************//
//              CALLBACK FUNCTIONS HERE                 //
//******************************************************//
// mouse bindings
void mouseCallback(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) { // destroy a building
        //TODO
    } else {
        //TODO  
    }
}

// keyboard bindings
void keyboardCallback(unsigned char key, int x, int y) {
    if (key == 'x'){
        glutDestroyWindow(Window_ID);
        exit(1);
    }

    if (key == 'z') { // push the robot forward
        //TODO
    }
    else if (key == 'a') { // turn robot left if at an intersection
        //TODO
    }
    else if (key == 'q') { // turn robot right if at an intersection
        //TODO
    }
    else if (key == 'p') { // pause the game
        //TODO
    }
    else if (key == 'r') { // return the robot to origin
        //TODO
    }
}

// function bindings
void functionCallback(int key, int x, int y) {
    if (key == GLUT_KEY_F1) { // turn robot head to face forward (default)
        //TODO
    }
    else if (key == GLUT_KEY_F2) { // turn head right
        //TODO
    }
    else if (key == GLUT_KEY_F3) { // turn head right
        //TODO
    }
    else if (key == GLUT_KEY_F4) { // return to default LookAt setting
        //TODO    
    }
    else if (key == GLUT_KEY_F5) { // back left LookAt
        //TODO
    }
    else if (key == GLUT_KEY_F6) { // back right LookAt
        //TODO
    }
    else if (key == GLUT_KEY_F7) { // front left LookAt
        //TODO
    }
    else if (key == GLUT_KEY_F8) { // front right LookAt
        //TODO
    }
    else if (key == GLUT_KEY_F9) { // further back left LookAt
        //TODO
    }
    else if (key == GLUT_KEY_F10) { // further back right LookAt
        //TODO
    }
    else if (key == GLUT_KEY_F11) { // further front left LookAt
        //TODO
    }
    else if (key == GLUT_KEY_F12) { // further front right LookAt
        //TODO
    }
    else { // face forward
        //TODO
    }
}

void display(void) {
    char buf[160];

    // set clear color to gray and clear window
    glClearColor(0.5f, 0.5f, 0.5f, 1);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    // Set up ortho view
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	//glOrtho(-5.0, 5.0, -5.0, 5.0, -50.0, 50.0);
    gluPerspective(60.0f,(GLfloat)Window_Width/(GLfloat)Window_Height,0.1f,100.0f);

    // Switch to modelview for drawing
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
    // Set up camera
	gluLookAt(eyex,eyey,eyez,0.0,0.0,0.0,0.0,1.0,0.0);

    // draw grid
    drawGrid();
    
    // draw cube
    glPushMatrix();
    glTranslatef(1.0f, 0.5f, 1.0f);
    drawCube(0.5);
    glPopMatrix();

    // Display help string
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0,Window_Width,0,Window_Height,-1.0,1.0);
    glColor4f(0.6,1.0,0.6,1.00);
    sprintf(buf,"%s", DISPLAY_MOUSE_INFO); // Print the string into a buffer
    glWindowPos2i(3,20);                         // Set the coordinate
    PrintString(GLUT_BITMAP_HELVETICA_12, buf);  // Display the string.
    sprintf(buf,"%s", DISPLAY_KEY_INFO); // Print the string into a buffer
    glWindowPos2i(3,3);                         // Set the coordinate
    PrintString(GLUT_BITMAP_HELVETICA_12, buf);  // Display the string.
    glPopMatrix();

	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(Window_Width,Window_Height);
	glutInitWindowPosition(0,0);
	Window_ID = glutCreateWindow("Interactive Robot Game");
	glutDisplayFunc(display);
    glutIdleFunc(display);

    glutMouseFunc(mouseCallback);
    glutKeyboardFunc(keyboardCallback);
    glutSpecialFunc(functionCallback);

	glEnable(GL_DEPTH_TEST); // enable depth testing
    //glCullFace(GL_BACK); 
    //glEnable(GL_CULL_FACE); // back face culling enabled
	glutMainLoop();
}
