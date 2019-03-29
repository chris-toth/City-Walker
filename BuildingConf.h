/**
 * Create buildings to render onto the grid
 * @author Jayden Stoll
 * @date March 24, 2019
 */

 struct RGBColour {
    float R, G, B;
};

 /**
 * Set a state on the buildings to check if they are unbreakable or not
 */
 enum Destructable {
    WEAK,
    STRONG,
    UNBREAKABLE
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
    CreateTallBuilding(rgb);
    glTranslatef(1, 1, 0);
    CreateShortBuilding(rgb1);
    glTranslatef(-1, 1, 2);
    glRotatef(90, 1, 0, 0);
    drawCylinder();
    // for the 20x20 grid layout
        // repeat until three buildings created
            // draw a building
            // if the building to create is a cylinder
                // rotate by 90 degrees on x-axis first
            // add colour to the building
            // set if destructable
            // set position
        // move the block to the proper position
}

 void CreateTallBuilding(struct RGBColour rgb) {
    CreateRect(2, 0.5, rgb.R, rgb.G, rgb.B);
 }

 void CreateShortBuilding(struct RGBColour rgb) {
    CreateRect(1, 0.5, rgb.R, rgb.G, rgb.B);
 }

/**
 * used as a controller for the Create(Tall/Short)Building functions
 * @param height, the height of the rectangle
 * @param width, the width of the rectangle
 * @param rgb, the rgb colour of the building
 */
void CreateRect(float height, float width, float r, float g, float b) {
   glBegin(GL_QUADS);
      glColor3f(r, g, b);
      glVertex3f( width, height, -1.0f);
      glVertex3f(-width, height, -1.0f);
      glVertex3f(-width, height,  1.0f);
      glVertex3f( width, height,  1.0f);

      glVertex3f( width, -height,  1.0f);
      glVertex3f(-width, -height,  1.0f);
      glVertex3f(-width, -height, -1.0f);
      glVertex3f( width, -height, -1.0f);

      glVertex3f( width,  height, 1.0f);
      glVertex3f(-width,  height, 1.0f);
      glVertex3f(-width, -height, 1.0f);
      glVertex3f( width, -height, 1.0f);
      glVertex3f( width, -height, -1.0f);
      glVertex3f(-width, -height, -1.0f);
      glVertex3f(-width,  height, -1.0f);
      glVertex3f( width,  height, -1.0f);

      glVertex3f(-width,  height,  1.0f);
      glVertex3f(-width,  height, -1.0f);
      glVertex3f(-width, -height, -1.0f);
      glVertex3f(-width, -height,  1.0f);

      glVertex3f(width,  height, -1.0f);
      glVertex3f(width,  height,  1.0f);
      glVertex3f(width, -height,  1.0f);
      glVertex3f(width, -height, -1.0f);
   glEnd();
}
