#define GL_GLEXT_PROTOTYPES
#define DISPLAY_MOUSE_INFO "Mouse control information here?"
#define DISPLAY_KEY_INFO "Keyboard control information here?"
#include "drawobjects.cc"

int Window_ID;

int Window_Width = 800;
int Window_Height = 600;

// eye variables
float eyex = 5.0f;
float eyey = 5.0f;
float eyez = 5.0f;

// Function for string rendering
static void PrintString(void *font, char *str)
{
   int i,len=strlen(str);

   for(i=0;i < len; i++)
      glutBitmapCharacter(font,*str++);
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
    gluPerspective(45.0f,(GLfloat)Window_Width/(GLfloat)Window_Height,0.1f,100.0f);

    // Switch to modelview for drawing
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
    // Set up camera
	gluLookAt(eyex,eyey,eyez,0.0,0.0,0.0,0.0,1.0,0.0);
    
    // draw cube
    glPushMatrix();
    glTranslatef(0.0f,0.0f, 2.5f);
    drawCube();
    glPopMatrix();

    // draw pyramid
    glPushMatrix();
    glTranslatef(0, 0, -2.5f);
    drawPyramid();
	glPopMatrix();

    // draw sphere
	glPushMatrix();
    glTranslatef(0, 0.6f, 0.0f);
    glColor3f(0.5f,0.25f,0.5f); glutWireSphere(1.00, 100, 100);
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
    glCullFace(GL_BACK); 
    glEnable(GL_CULL_FACE); // back face culling enabled
	glutMainLoop();
}
