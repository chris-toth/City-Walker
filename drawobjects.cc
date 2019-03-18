#include <stdlib.h>  // Useful for the following includes.
#include <stdio.h>    
#include <string.h>  // For string operations.

#include <GL/gl.h>   // OpenGL itself.
#include <GL/glu.h>  // GLU support library.
#include <GL/glut.h> // GLUT support library.

// Draw street 
void drawStreet() {

}

// Draw robot 
void drawRobot() {

}

// Draw buildings
void drawBuildings() {

}

// Draw Cube
void drawCube() {
    // OK, let's start drawing our planer quads.
    glBegin(GL_QUADS); 

    // Far face.  Green
    glNormal3f( 0.0f, 0.0f,-1.0f);
    glColor4f(0.0, 1.0, 0.0, 0.0); // no opacity

    glTexCoord2f(0.995f, 0.005f); glVertex3f(-0.5f, -0.5f, -0.5f); //TL
    glTexCoord2f(0.995f, 0.995f); glVertex3f(-0.5f,  0.5f, -0.5f); //TR
    glTexCoord2f(0.005f, 0.995f); glVertex3f( 0.5f,  0.5f, -0.5f); //BR
    glTexCoord2f(0.005f, 0.005f); glVertex3f( 0.5f, -0.5f, -0.5f); //BL

    // Right face.  Blue
    glNormal3f( 1.0f, 0.0f, 0.0f);
    glColor4f(0.0, 0.0, 1.0, 0.0); // no opacity

    glTexCoord2f(0.005f, 0.995f); glVertex3f( 0.5f,  0.5f,  0.5f); // TL
    glTexCoord2f(0.005f, 0.005f); glVertex3f( 0.5f, -0.5f,  0.5f); // BL
    glTexCoord2f(0.995f, 0.005f); glVertex3f( 0.5f, -0.5f, -0.5f); // BR
    glTexCoord2f(0.995f, 0.995f); glVertex3f( 0.5f,  0.5f, -0.5f); // TR
    
    // Front face; offset. Red
    glNormal3f( 0.0f, 0.0f, 1.0f);
    glColor4f( 1.0f, 0.0f, 0.0f, 0.0f);

    glTexCoord2f( 0.995f, 0.005f); glVertex3f( 0.5f, -0.5f,  0.5f); // BR
    glTexCoord2f( 0.995f, 0.995f); glVertex3f( 0.5f,  0.5f,  0.5f); // TR
    glTexCoord2f( 0.005f, 0.995f); glVertex3f(-0.5f,  0.5f,  0.5f); // TL
    glTexCoord2f( 0.005f, 0.005f); glVertex3f(-0.5f, -0.5f,  0.5f); // BL

    // Left Face; offset.  Yellow
    glNormal3f(-1.0f, 0.0f, 0.0f);  
    glColor4f(0.9,0.9,0.2,0.0);

    glTexCoord2f(0.995f, 0.005f); glVertex3f(-0.5f, -0.5f,  0.5f); //BR
    glTexCoord2f(0.995f, 0.995f); glVertex3f(-0.5f,  0.5f,  0.5f); //TR
    glTexCoord2f(0.005f, 0.995f); glVertex3f(-0.5f,  0.5f, -0.5f); //TL
    glTexCoord2f(0.005f, 0.005f); glVertex3f(-0.5f, -0.5f, -0.5f); //BL

    // Top Face. Orange
    glNormal3f(0.0f, 1.0f, 0.0f);
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f); 

    glTexCoord2f(0.005f, 0.005f); glVertex3f( -0.5f, 0.5f,  0.5f); // front left - BL
    glTexCoord2f(0.995f, 0.005f); glVertex3f( 0.5f, 0.5f, 0.5f); // front right - BR
    glTexCoord2f(0.995f, 0.995f); glVertex3f( 0.5f, 0.5f,  -0.5f); // rear right - TR
    glTexCoord2f(0.005f, 0.995f); glVertex3f( -0.5f, 0.5f, -0.5f); // rear left - TL

    // Bottom Face. Purple
    glNormal3f(0.0f, -1.0f, 0.0f);
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);

    glTexCoord2f(0.005f, 0.995f); glVertex3f( -0.5f, -0.5f, -0.5f); // rear left - TL
    glTexCoord2f(0.995f, 0.995f); glVertex3f( 0.5f, -0.5f, -0.5f); // rear left - TR
    glTexCoord2f(0.995f, 0.005f); glVertex3f( 0.5f, -0.5f, 0.5f); // front right - BR
    glTexCoord2f(0.005f, 0.005f); glVertex3f( -0.5f, -0.5f, 0.5f); // front left - BL

    // All polygons have been drawn.
    glEnd();
}

void drawPyramid() {
glBegin(GL_TRIANGLES);
    //Triangle 1
    glColor3f(1.0f,0.0f,0.0f); // Red face
    glVertex3f( 0.0f, 0.5f, 0.0f);   //V0
    glVertex3f(-0.5f,-0.5f, 0.5f);   //V1
    glVertex3f( 0.5f,-0.5f, 0.5f);   //V2
    //Triangle 2
    glColor3f(0.0f,1.0f,0.0f); // Green face
    glVertex3f( 0.0f, 0.5f, 0.0f);   //V0
    glVertex3f( 0.5f,-0.5f, 0.5f);   //V2
    glVertex3f( 0.5f,-0.5f,-0.5f);   //V3
    //Triangle 3
    glColor3f(0.0f,0.0f, 1.0f); // Blue face
    glVertex3f( 0.0f, 0.5f, 0.0f);   //V0 
    glVertex3f( 0.5f,-0.5f,-0.5f);   //V3
    glVertex3f(-0.5f,-0.5f,-0.5f);   //V4
    //Triangle 4
    glColor3f(0.5f,0.0f,0.5f);  // Purple face
    glVertex3f( 0.0f, 0.5f, 0.0f);   //V0
    glVertex3f(-0.5f,-0.5f,-0.5f);   //V4
    glVertex3f(-0.5f,-0.5f, 0.5f);   //V1
    //Triangle 5
    glColor3f(1.0f,1.0f,0.0f);  // Yellow face
    glVertex3f( 0.5f, -0.5f, 0.5f); //BR
    glVertex3f(-0.5f,-0.5f, -0.5f);   //TL
    glVertex3f(0.5f,-0.5f,-0.5f);  //TR
    //Triangle 6
    glColor3f(1.0f,1.0f,0.0f);  // Yellow face
    glVertex3f( -0.5f, -0.5f, 0.5f);   //BL
    glVertex3f(-0.5f,-0.5f, -0.5f);   //TL
    glVertex3f(0.5f,-0.5f, 0.5f);   //BR
glEnd();
}

// draws a solid sphere
void drawSphere() {
    glColor3f(1.0f,0.0f,0.0f); // Red ball
    GLUquadric *quad;
    quad = gluNewQuadric();
    gluSphere(quad,0.5f,100,20);
}