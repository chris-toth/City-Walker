/**
 * Create buildings to render onto the grid
 * @author Jayden Stoll, Chris Toth
 * @date March 24, 2019
 */

 struct RGBColour {
    float R, G, B;
};

// create a rectangle
void CreateRect(float height, float width, float r, float g, float b);
// create a tall rectangle
void CreateTallBuilding(struct RGBColour rgb);
void CreateShortBuilding(struct RGBColour rgb);

 // Draw cylinder
void drawCylinder(float base = 0.5f, float top = 0.5f, float height = 1.0f,
             float r = 0.5f, float g = 0.0f, float b = 0.5f) {
    glColor3f(r, g, b);
    GLUquadric *quad;
    quad = gluNewQuadric();
    gluCylinder(quad, base, top, height, 100, 20);
}


void CreateBlock() {
    RGBColour rgb = {1.0, 0.0, 0.0};
    RGBColour rgb1 = {0.0, 0.0, 0.0};
//    glScalef(0, 5, 0);
//    glutSolidCube(0.5);
    CreateTallBuilding(rgb);
//    glTranslatef(-1, 0, 1);
//    CreateShortBuilding(rgb1);
//    glTranslatef(-1, 1, 2);
//    drawCylinder();
    glPopMatrix();
}

 void CreateTallBuilding(struct RGBColour rgb) {
    CreateRect(2, 0.25, rgb.R, rgb.G, rgb.B);
}

 void CreateShortBuilding(struct RGBColour rgb) {
    CreateRect(0.7, 0.25, rgb.R, rgb.G, rgb.B);
 }

/**
 * used as a controller for the Create(Tall/Short)Building functions
 * @param height, the height of the rectangle
 * @param width, the width of the rectangle
 * @param rgb, the rgb colour of the building
 */
void CreateRect(float height, float width, float r, float g, float b) {
    glPushMatrix();
    glColor3f(r, g, b);
    glScalef(width, height, width);
    glutSolidCube(1);
    glPopMatrix();
}
