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

// character starting position
float charX = 0.0f;
float charY = 0.0f;
float charZ = 0.0f;

// eye variables
float eyex = -0.5f;
float eyey = 2.0f;
float eyez = 2.0f;

// Function for string rendering
static void PrintString(void *font, char *str) {
   int i,len=strlen(str);

   for(i=0;i < len; i++)
      glutBitmapCharacter(font,*str++);
}

//******************************************************//
//                   DRAW OBJECTS HERE                  //
//******************************************************//
// single road tile
void drawDashedLine() {
    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    // dashed line
    glBegin(GL_QUADS);
        glVertex3f(1.0f,0.0f,4.0f);
        glVertex3f(1.1f,0.0f,4.0f);
        glVertex3f(1.1f,0.0f,3.00f);
        glVertex3f(1.0f,0.0f,3.00f);
    glEnd();
    glBegin(GL_QUADS);
        glVertex3f(1.0f,0.0f,2.50f);
        glVertex3f(1.1f,0.0f,2.50f);
        glVertex3f(1.1f,0.0f,1.50f);
        glVertex3f(1.0f,0.0f,1.50f);
    glEnd();
    glBegin(GL_QUADS);
        glVertex3f(1.0f,0.0f,1.00f);
        glVertex3f(1.1f,0.0f,1.00f);
        glVertex3f(1.1f,0.0f,0.00f);
        glVertex3f(1.0f,0.0f,0.00f);
    glEnd();
}

void drawRoadSurface() {
    glColor3f(0.25,0.25,0.25);
    // road surface
    glBegin(GL_QUADS);
        glVertex3f(0.5f,-0.01f,4.00f);
        glVertex3f(1.7f,-0.01f,4.00f);
        glVertex3f(1.7f,-0.01f,0.00f);
        glVertex3f(0.5f,-0.01f,0.00f);
    glEnd();
    glPopMatrix();
}

void drawOuterRoad() {
    glColor3f(0.25,0.25,0.25);
    // road surface
    glBegin(GL_QUADS);
        glVertex3f(0.0f,-0.02f,4.00f);
        glVertex3f(2.2f,-0.02f,4.00f);
        glVertex3f(2.2f,-0.02f,0.00f);
        glVertex3f(0.0f,-0.02f,0.00f);
    glEnd();
    glPopMatrix();
}

void drawGrass() {
    glColor3f(0.0,0.25,0.0);
    // road surface
    glBegin(GL_QUADS);
        glVertex3f(0.0f,-0.03f,80.00f);
        glVertex3f(80.0f,-0.03f,80.00f);
        glVertex3f(80.0f,-0.03f,0.00f);
        glVertex3f(0.0f,-0.03f,0.00f);
    glEnd();
    glPopMatrix();
}

// Draw street
void drawStreet() {
    glPushMatrix();
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef(90, 0.0, 1.0, 0.0);

    glPushMatrix();
    for (float i = 0.0f; i < 20; i++) {
        glPushMatrix();
        glTranslatef(4*i, 0.0f, 0.0f);
        for (float j = 0.0f; j < 20; j++) {
            glPushMatrix();
            glTranslatef(0.0f, 0.0f, 4*j);
            drawDashedLine();
            drawRoadSurface();
            glPopMatrix();
        }
        glPopMatrix();
    }
    glPopMatrix();

    glPushMatrix();
    for (float i = 0.0f; i < 20; i++) {
        glPushMatrix();
        glTranslatef(0.0f, 0.0f, 4*i);
        glRotatef(90,0.0,1.0,0.0);
        for (float j = 0.0f; j < 20; j++) {
            glPushMatrix();
            glTranslatef(0.0f, 0.0f, 4*j);
            drawDashedLine();
            drawRoadSurface();
            glPopMatrix();
        }
        glPopMatrix();
    }
    drawGrass();
    glPopMatrix();

    // outer roads
    glPushMatrix();
    glTranslatef(0.0f, 0.00f, -4);
    for (float i = 0.0f; i < 20; i++) {
        glPushMatrix();
        glTranslatef(0.0f, -0.03f, -4*i);
        drawOuterRoad();
        glPopMatrix();
    }
    glPopMatrix();
    for (float i = 0.0f; i < 20; i++) {
        glPushMatrix();
        glTranslatef(4*i, 0.0f, 0.0f);
        glRotatef(90,0.0,1.0,0.0);
        drawOuterRoad();
        glPopMatrix();
    }

    // need to double check this when movement is implemented
    glPushMatrix();
    glTranslatef(-40.0f, 0.0f, -40.0f);
    glRotatef(180, 0.0, 1.0, 0.0);
    glTranslatef(40.0f, 0.0f, 40.0f);
    glPushMatrix();
    glTranslatef(0.0f, 0.00f, -4);
    for (float i = 0.0f; i < 20; i++) {
        glPushMatrix();
        glTranslatef(0.0f, -0.03f, -4*i);
        drawOuterRoad();
        glPopMatrix();
    }
    glPopMatrix();
    for (float i = 0.0f; i < 20; i++) {
        glPushMatrix();
        glTranslatef(4*i, 0.0f, 0.0f);
        glRotatef(90,0.0,1.0,0.0);
        drawOuterRoad();
        glPopMatrix();
    }
    glPopMatrix();
    glPopMatrix();
}

// Draw buildings
void drawBuildings() {
    //TODO
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

// Draw robot
void drawRobot() {
    /*
    * Drawing the robot from the bottom up starting with the body.
    * Adding in parts from the bottom up and translating
    * parts to the proper location.
    */
    // draw body
    glPushMatrix();
    glTranslatef(charX, charY + 0.5f, charZ);
    glScalef(0.5f, 1.0f, 0.5f);
    drawCube(0.5f);
    glPopMatrix();

    // draw body details
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
    glVertex3f(0.2f, 0.8f, -0.26f);
    glVertex3f(-0.2f, 0.8f, -0.26f);
    glVertex3f(-0.2f, 0.2f, -0.26f);
    glVertex3f(0.2f, 0.2f, -0.26f);
    glEnd();

    glPushMatrix();
    glBegin(GL_TRIANGLES);
    glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
    glVertex3f(0.0f, 0.85f , 0.26f);
    glVertex3f(0.2f, 0.55f, 0.26f);
    glVertex3f(-0.2f, 0.55f, 0.26f);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glBegin(GL_TRIANGLES);
    glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
    glVertex3f(0.0f, 0.55f , 0.26f);
    glVertex3f(0.2f, 0.25f, 0.26f);
    glVertex3f(-0.2f, 0.25f, 0.26f);
    glEnd();
    glPopMatrix();

    // draw neck
    glPushMatrix();
    glTranslatef(0.0f, 1.0f, 0.0f);
    glRotatef(-90, 1.0f, 0.0f, 0.0f);
    drawCylinder(0.15f, 0.15f, 0.09f, 1.0f, 0.5f, 1.0f);
    glPopMatrix();

    // draw head
    glPushMatrix();
    glTranslatef(0.0f, 1.25f, 0.0f);
    drawCube(0.16f);
    glPopMatrix();

    // draw eyes and antenna
    glPushMatrix();
    glTranslatef(-0.07f, 1.26f, -0.18f);
    glutSolidSphere(0.04, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.07f, 1.26f, -0.18f);
    glutSolidSphere(0.04, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 1.28f, 0.0f);
    glRotatef(-90, 1, 0, 0);
    drawCylinder(0.05f, 0.05f, 0.3f, 0.0f, 1.0f, 1.0f);
    glPopMatrix();
}

/**
* Draw lines to help visualize the origin and each axis
* By default,
* Z axis line = green
* X axis line = red
* y axis line = blue
*/
void drawAxisLines(float xMin, float xMax, float yMin, float yMax, float zMin, float zMax) {
    // draw Z axis
    glPushMatrix();
    glBegin(GL_LINES);
    glColor4f(0.0f, 1.0f, 0.0f, 1.0f); // GREEN
    glVertex3f(0.0f, 0.0f, zMin);
    glVertex3f(0.0f, 0.0f, zMax);
    glEnd();
    glPopMatrix();

    // Draw X axis
    glPushMatrix();
    glBegin(GL_LINES);
    glColor4f(1.0f, 0.0f, 0.0f, 1.0f); // RED
    glVertex3f(xMin, 0.0f, 0.0f);
    glVertex3f(xMax, 0.0f, 0.0f);
    glEnd();
    glPopMatrix();

    // Draw Y axis
    glPushMatrix();
    glBegin(GL_LINES);
    glColor4f(0.0f, 0.0f, 1.0f, 1.0f); // BLUE
    glVertex3f(0.0f, yMin, 0.0f);
    glVertex3f(0.0f, yMax, 0.0f);
    glEnd();
    glPopMatrix();
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
    glClearColor(0.2f, 0.4f, 1.0f, 1);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    // Set up ortho view
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	//glOrtho(-5.0, 5.0, -5.0, 5.0, -50.0, 50.0);
    gluPerspective(90.0f,(GLfloat)Window_Width/(GLfloat)Window_Height,0.1f,100.0f);

    // Switch to modelview for drawing
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
    // Set up camera
	gluLookAt(eyex,eyey,eyez,0.0,0.0,0.0,0.0,1.0,0.0);

    // draw street
    drawStreet();

    // Draw Robot Character
    drawRobot();

    drawAxisLines(-1.0f, 5.0f, -1.0f, 5.0f, 1.0f, -5.0f); // Draw axis lines to help visualize 3D space

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
