#include <GL/glut.h>           // Include OpenGL Utility Toolkit library
#include <fstream>             // Include file stream for file operations
#include <iostream>            // Include input/output stream for console output

using namespace std;

// Define viewport boundaries
double viewportXmin = 0.0, viewportXmax = 640.0, viewportYmin = 0.0, viewportYmax = 480.0;
int ReferenceX = 0, ReferenceY = 0; // Reference points for mouse movement

// Function to draw polylines from a file
void drawPolyLineFile(char *fileName) {
    fstream inStream;                           // Create an input file stream
    inStream.open(fileName, ios::in);           // Open the file in read mode
    if (inStream.fail())                        // Check if the file opened successfully
        return;                                 // Exit function if file failed to open
    glClear(GL_COLOR_BUFFER_BIT);               // Clear the screen before drawing
    GLint numpolys, numLines, x, y;            // Variables to hold the number of polylines and coordinates
    inStream >> numpolys;                       // Read the number of polylines
    // Loop through each polyline
    for (int j = 0; j < numpolys; j++) {       // Read each polyline
        inStream >> numLines;                   // Read the number of lines in the polyline
        glBegin(GL_LINE_STRIP);                 // Begin drawing a connected line strip
        // Loop through each line in the polyline
        for (int i = 0; i < numLines; i++) {
            inStream >> x >> y;                 // Read the next x, y coordinate pair
            glVertex2i(x, y);                   // Specify vertex for the current line segment
        }
        glEnd();                                 // End drawing of the line strip
    }
    glFlush();                                   // Ensure all OpenGL commands are executed
    inStream.close();                            // Close the input file stream
}

// Display function to draw the dinosaur
void display(void) {
    drawPolyLineFile("dino");                   // Draw the dinosaur from file data
}

// Initialization function for OpenGL settings
void init(void) {
    glClearColor(1.0, 1.0, 1.0, 1.0);            // Set background color to white
    glColor3f(0.0, 0.0, 0.0);                    // Set drawing color to black
    glMatrixMode(GL_PROJECTION);                 // Set matrix mode to projection
    glLoadIdentity();                            // Load identity matrix to reset transformations
    gluOrtho2D(viewportXmin, viewportXmax, viewportYmin, viewportYmax); // Set up a 2D orthographic coordinate system
}

// Function to update the viewport settings
void SetViewport() {
    glMatrixMode(GL_PROJECTION);                 // Set matrix mode to projection
    glLoadIdentity();                            // Load identity matrix to reset transformations
    gluOrtho2D(viewportXmin, viewportXmax, viewportYmin, viewportYmax); // Update the coordinate system
}

// Mouse callback function to remember mouse position on button press
void myMouse(int button, int state, int x, int y) {
    // Check if the left mouse button is pressed
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        ReferenceX = x;                          // Save the current mouse x position
        ReferenceY = y;                          // Save the current mouse y position
    }
}

// Mouse motion callback function to translate the viewport
void myMotion(int x, int y) {
    // Calculate distance moved from the reference position
    int dx = x - ReferenceX;                    // Calculate change in x
    int dy = -(y - ReferenceY);                  // Calculate change in y (inverted due to coordinate system)
    viewportXmin += dx;                         // Update the left viewport boundary
    viewportXmax += dx;                         // Update the right viewport boundary
    viewportYmin += dy;                         // Update the bottom viewport boundary
    viewportYmax += dy;                         // Update the top viewport boundary
    SetViewport();                               // Update the coordinate system

    ReferenceX = x;                             // Update the reference x position
    ReferenceY = y;                             // Update the reference y position

    glutPostRedisplay();                        // Puts a "redraw" event in the event queue
}

// Keyboard callback function to move the viewport using keys
void myKey(unsigned char key, int x, int y) {
    switch (key) {
        case 'u': // Move the viewport up
            viewportYmin -= 2;                   // Move the bottom boundary upward
            viewportYmax -= 2;                   // Move the top boundary upward
            SetViewport();                       // Update the coordinate system
            break;
        case 'd': // Move the viewport down
            viewportYmin += 2;                   // Move the bottom boundary downward
            viewportYmax += 2;                   // Move the top boundary downward
            SetViewport();                       // Update the coordinate system
            break;
        case 'l': // Move the viewport left
            viewportXmin -= 2;                   // Move the left boundary outward
            viewportXmax -= 2;                   // Move the right boundary outward
            SetViewport();                       // Update the coordinate system
            break;
        case 'r': // Move the viewport right
            viewportXmin += 2;                   // Move the left boundary inward
            viewportXmax += 2;                   // Move the right boundary inward
            SetViewport();                       // Update the coordinate system
            break;
    }
    glutPostRedisplay();                        // Puts a "redraw" event in the event queue
}

// Main function to initialize and start the GLUT loop
int main(int argc, char** argv) {
    glutInit(&argc, argv);                      // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode to single-buffered and RGB color mode
    glutInitWindowSize(640, 480);               // Set the window size
    glutInitWindowPosition(100, 150);           // Set the window position on the screen
    glutCreateWindow("Dinosaur movement using Keyboard and Mouse"); // Create a window with a title
    glutDisplayFunc(display);                   // Register display callback function
    glutMouseFunc(myMouse);                     // Register mouse callback function
    glutMotionFunc(myMotion);                   // Register mouse motion callback function
    glutKeyboardFunc(myKey);                    // Register keyboard callback function
    init();                                     // Call initialization function
    glutMainLoop();                             // Enter the event-processing loop
    return 0;                                   // Exit the program
}
