#include <iostream>            // For standard input/output operations
#include <GL/glut.h>           // For OpenGL and GLUT functions

using namespace std;

// Function to draw the 2D picture
void myDisplay(void) {
    glClear(GL_COLOR_BUFFER_BIT);         // Clear framebuffer with background color
    glClearColor(0.9f, 0.9f, 0.9f, 0.0);  // Set background color to light grey

    glColor3f(0.5, 0.5, 0.5);             // Set color to grey for drawing lines
    glBegin(GL_LINES);                    // Begin drawing lines

    // Draw left wall
    glVertex2i(25, 50);                   // Set first point of left wall
    glVertex2i(25, 30);                   // Set second point of left wall
    
    // Draw right wall
    glVertex2i(50, 50);                   // Set first point of right wall
    glVertex2i(50, 30);                   // Set second point of right wall
    
    // Draw floor line
    glVertex2i(25, 30);                   // Set first point of floor line
    glVertex2i(50, 30);                   // Set second point of floor line

    // Draw door
    glVertex2i(30, 30);                   // Set first point of left door line
    glVertex2i(30, 40);                   // Set second point of left door line
    glVertex2i(35, 30);                   // Set first point of right door line
    glVertex2i(35, 40);                   // Set second point of right door line
    glVertex2i(30, 40);                   // Set first point of top door line
    glVertex2i(35, 40);                   // Set second point of top door line

    // Draw window
    glVertex2i(42, 40);                   // Set first point of left window line
    glVertex2i(42, 45);                   // Set second point of left window line
    glVertex2i(45, 40);                   // Set first point of right window line
    glVertex2i(45, 45);                   // Set second point of right window line
    glVertex2i(42, 40);                   // Set first point of bottom window line
    glVertex2i(45, 40);                   // Set second point of bottom window line
    glVertex2i(42, 45);                   // Set first point of top window line
    glVertex2i(45, 45);                   // Set second point of top window line

    // Draw roof
    glVertex2i(50, 50);                   // Set first point of right roof line
    glVertex2i(38, 62);                   // Set second point of right roof line (peak of roof)
    glVertex2i(38, 62);                   // Set first point of left roof line
    glVertex2i(32, 57);                   // Set second point of left roof line

    // Draw chimney
    glVertex2i(32, 57);                   // Set first point of chimney bottom line
    glVertex2i(32, 62);                   // Set second point of chimney left line
    glVertex2i(30, 55);                   // Set first point of chimney base
    glVertex2i(30, 62);                   // Set second point of chimney right line
    glVertex2i(32, 62);                   // Set first point of chimney top
    glVertex2i(30, 62);                   // Set second point of chimney top line

    // Complete left roof edge
    glVertex2i(25, 50);                   // Set first point of left roof edge
    glVertex2i(30, 55);                   // Set second point of left roof edge

    glEnd();                              // End line drawing

    glFlush();                            // Send the drawing to the display screen
}

// Function to initialize the viewing region
void Initialize() {
    gluOrtho2D(0.0, 100.0, 0.0, 100.0);   // Set up a 2D orthographic viewing region
}

int screenWidth = 640, screenHeight = 480; // Screen dimensions for the window

// Main function
int main(int argc, char **argv) {
    glutInit(&argc, argv);                          // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);    // Set display mode to single buffering and RGB
    glutInitWindowSize(screenWidth, screenHeight);  // Set initial window size
    glutInitWindowPosition(30, 30);                 // Set initial window position on screen
    glutCreateWindow("MY 2D House");        // Create window with title

    Initialize();                                   // Initialize the projection matrix
    glutDisplayFunc(myDisplay);                     // Register display function as callback
    glutMainLoop();                                 // Enter GLUT event-processing loop
    return 0;                                       // Exit main function
}
