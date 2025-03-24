#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>
#include <windows.h>
#include <mmsystem.h>
#include "pixMap.h"
#include "Mario.h"

// Create Mario object
Mario m(Point2(0, 0)); // Create an instance of Mario at position (0, 0)
RGBApixmap bgImage;    // Declare a variable for the background image

// OpenGL initialization
void myInit(void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set the background color to white
    glEnable(GL_ALPHA_TEST);              // Enable alpha testing for transparency
    glAlphaFunc(GL_EQUAL, 1.0);           // Set the alpha test function to always pass
    glViewport(0, 0, 640, 480);           // Set the size of the viewport (screen size)
    glMatrixMode(GL_PROJECTION);          // Set the matrix mode to projection
    glLoadIdentity();                     // Load the identity matrix to reset transformations
    gluOrtho2D(0, 640, 0, 480);           // Set up orthogonal 2D projection (2D scene from 0 to 640, 0 to 480)
    glMatrixMode(GL_MODELVIEW);           // Set the matrix mode to modelview (for drawing objects)
    glLoadIdentity();                     // Load identity matrix again for modelview

    // Load background image
    bgImage.readBMPFile("bg.bmp", 1); // Read the background image (bg.bmp)

    // Set initial mode for Mario
    m.changeMode(Mario::STAY); // Set Mario to stay mode initially
}

// Draw background image
void drawBackground()
{
    float x_scale = 2.1f; // X-axis scaling factor for background image
    float y_scale = 2.7f; // Y-axis scaling factor for background image

    glPixelZoom(x_scale, y_scale); // Apply the scaling to the background image
    glRasterPos2i(0, 0);           // Set the position to draw the background at (0, 0)
    bgImage.mDraw();               // Draw the background image
    glPixelZoom(1.0f, 1.0f);       // Reset the scaling to normal after drawing
}

// The stay function definition
void Mario::stay()
{
    glRasterPos2i(this->pos_X, this->pos_Y); // Set the position of Mario at (pos_X, pos_Y)
    if (this->pos_Y > 0)
    {                                  // If Mario is in the air
        state = JUMPING;               // Change state to JUMPING
        changePosition(0.10, -(0.30)); // Move Mario upwards
    }
    if (this->pos_Y <= 0)
    {                     // If Mario is on the ground
        state = STANDING; // Change state to STANDING
    }
    pix[state].mDraw(); // Draw Mario's current state
}

// The run function definition
void Mario::run()
{
    switch (state) // Cycle through running states
    {
    case RUNNING1:
        state = RUNNING2; // Change to the next running state
        break;
    case RUNNING2:
        state = RUNNING3; // Change to the next running state
        break;
    case RUNNING3:
        state = RUNNING1; // Cycle back to the first running state
        break;
    }

    changePosition(0.15, 0);                 // Move Mario to the right
    glRasterPos2i(this->pos_X, this->pos_Y); // Set position for drawing Mario
    pix[state].mDraw();                      // Draw the current running state of Mario

    if (this->pos_Y > 0)
    {                                  // If Mario is in the air (jumping)
        state = JUMPING;               // Change to jumping state
        changePosition(0.10, -(0.30)); // Move Mario upwards while jumping
        pix[state].mDraw();            // Draw the jumping state
    }
}

// The jump function definition
void Mario::jump()
{
    changePosition(0.10, 0.10);              // Move Mario upwards
    glRasterPos2i(this->pos_X, this->pos_Y); // Set position for drawing Mario
    pix[state].mDraw();                      // Draw the jumping state of Mario
}

// The grounded function definition
void Mario::grounded()
{
    if (this->pos_Y > 0)
    {                                  // If Mario is in the air
        state = JUMPING;               // Set state to JUMPING
        changePosition(0.10, -(0.30)); // Move Mario downwards (falling)
    }
    glRasterPos2i(this->pos_X, this->pos_Y); // Set position for drawing Mario
    pix[state].mDraw();                      // Draw the grounded state of Mario

    if (this->pos_Y <= 0)
    {                     // If Mario is on the ground
        state = STANDING; // Change to the standing state
    }
}

// Function to change Mario's mode (stay, run, jump, grounded)
void Mario::changeMode(ModeType m)
{
    if (mode == m)
        return; // If already in the requested mode, no need to change
    switch (m)
    {
    case STAY:
        state = STANDING; // Set state to STANDING when Mario is staying
        break;
    case RUN:
        state = RUNNING1; // Set state to RUNNING1 when Mario is running
        break;
    case JUMP:
        state = JUMPING; // Set state to JUMPING when Mario is jumping
        break;
    case GROUNDED:
        state = GROUND; // Set state to GROUND when Mario is grounded
        break;
    }
    mode = m; // Change Mario's mode to the new mode
}

// Function to render Mario's current state based on the mode
void Mario::render()
{
    switch (mode)
    {
    case STAY:
        stay(); // Call the stay function if the mode is STAY
        break;
    case RUN:
        run(); // Call the run function if the mode is RUN
        break;
    case JUMP:
        jump(); // Call the jump function if the mode is JUMP
        break;
    case GROUNDED:
        grounded(); // Call the grounded function if the mode is GROUNDED
        break;
    }
}

// Display callback function (called every frame)
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the screen
    drawBackground();                                   // Draw the background
    m.render();                                         // Render Mario's current state
    glFlush();                                          // Ensure all OpenGL commands are executed
}

// Flags for key presses
bool fKeyPressed = false; // Flag to check if the right arrow key is pressed
bool jKeyPressed = false; // Flag to check if the up arrow key is pressed

// Keyboard handler for special keys (e.g., arrow keys)
void myKB_Handler(int key, int mx, int my)
{
    switch (key)
    {
    case GLUT_KEY_RIGHT:
        if (!fKeyPressed)
        {                             // If the right arrow key is not pressed yet
            m.changeMode(Mario::RUN); // Start running
            fKeyPressed = true;       // Set flag to true to avoid repeated changes
        }
        break;

    case GLUT_KEY_UP:
        if (m.pos_Y <= 0)
        {                              // If Mario is on the ground
            m.changeMode(Mario::JUMP); // Start jumping
        }
        break;
    }
    glutPostRedisplay(); // Redraw the screen to reflect the changes
}

// Key release handler (when key is released)
void pressKeySpecial(int key, int mx, int my)
{
    if (key == GLUT_KEY_RIGHT)
    {
        m.changeMode(Mario::STAY); // Stop running when the right arrow key is released
        fKeyPressed = false;       // Reset the flag
    }
    if (key == GLUT_KEY_UP)
    {
        m.changeMode(Mario::GROUNDED); // Change to grounded mode when the up key is released
        jKeyPressed = false;           // Reset the flag
    }
}

// Main entry point
int main(int argc, char **argv)
{
    glutInit(&argc, argv);                                     // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH); // Set display mode (single buffer, RGBA, depth buffer)
    glutInitWindowSize(640, 480);                              // Set window size (640x480)
    glutInitWindowPosition(10, 10);                            // Set window position on screen
    glutCreateWindow("Mario Game");                            // Create the window with the title "Mario Game"
    glutDisplayFunc(display);                                  // Set the display callback function
    glutSpecialFunc(myKB_Handler);                             // Set the special key press callback function
    glutSpecialUpFunc(pressKeySpecial);                        // Set the special key release callback function

    // Play background music
    PlaySound(TEXT("bg.wav"), NULL, SND_ASYNC | SND_LOOP); // Play background music in a loop

    // Initialize OpenGL and start the main loop
    myInit();              // Initialize OpenGL settings
    glutIdleFunc(display); // Set the idle function (this function will be called constantly)
    glutMainLoop();        // Start the GLUT main loop (this will keep the window open and continuously update)
}
