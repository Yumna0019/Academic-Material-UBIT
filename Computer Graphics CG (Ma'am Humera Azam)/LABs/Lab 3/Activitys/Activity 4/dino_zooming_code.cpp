#include <GL/glut.h>           // Include OpenGL Utility Toolkit library
#include <fstream>             // Include file stream for file operations
#include <iostream>            // Include input/output stream for console output

using namespace std;

// Renamed variables to avoid conflicts with std::left and std::right
double viewLeft = 0.0, viewRight = 640.0, viewBottom = 0.0, viewTop = 480.0; // View boundaries for zooming

// Function to draw polylines from file data
void drawPolyLineFile(char *fileName) {
    fstream inStream;                      // Create an input file stream
    inStream.open(fileName, ios::in);      // Open the file in read mode
    if (inStream.fail())                   // Check if file opened successfully
        return;                            // Exit function if file failed to open
    
    GLint numpolys, numLines, x, y;        // Variables to hold file data
    inStream >> numpolys;                  // Read the number of polylines
    // Loop through each polyline
    for (int j = 0; j < numpolys; j++) {
        inStream >> numLines;              // Read the number of lines in the polyline
        glBegin(GL_LINE_STRIP);            // Begin drawing a connected line strip
        // Loop through each line in the polyline
        for (int i = 0; i < numLines; i++) {
            inStream >> x >> y;            // Read the next x, y coordinate pair
            glVertex2i(x, y);              // Specify vertex for current line segment
        }
        glEnd();                           // End drawing of the line strip
    }
    glFlush();                             // Ensure all OpenGL commands are executed
    inStream.close();                      // Close the input file stream
} 

// Display function to clear screen and draw the dinosaur
void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);          // Clear the screen with background color
    drawPolyLineFile("dino");              // Draw the dinosaur from file data
}

// Keyboard function to handle zooming and quitting
void Keyboard(unsigned char key, int x, int y) {
    switch(key) {
        case '-': // Zoom in
            viewLeft += 10.0;                  // Move left boundary inward
            viewRight -= 10.0;                 // Move right boundary inward
            viewBottom += 7.5;                 // Move bottom boundary upward
            viewTop -= 7.5;                    // Move top boundary downward
            break;

        case '+': // Zoom out
            viewLeft -= 10.0;                  // Move left boundary outward
            viewRight += 10.0;                 // Move right boundary outward
            viewBottom -= 7.5;                 // Move bottom boundary downward
            viewTop += 7.5;                    // Move top boundary upward
            break;

        case 'q': exit(0);                     // Quit the application when 'q' is pressed
    }

    glMatrixMode(GL_PROJECTION);               // Set matrix mode to projection for transformations
    glLoadIdentity();                          // Reset projection matrix to identity
    gluOrtho2D(viewLeft, viewRight, viewBottom, viewTop); // Update the coordinate system based on zoom
    glutPostRedisplay();                       // Redraw the scene with new view boundaries
}

// Initialization function for OpenGL settings
void init(void) {
    glClearColor(1.0, 1.0, 1.0, 1.0);          // Set background color to white
    glColor3f(0.0, 0.0, 0.0);                  // Set drawing color to black
    glMatrixMode(GL_PROJECTION);               // Set matrix mode to projection
    glLoadIdentity();                          // Load identity matrix to reset transformations
    gluOrtho2D(viewLeft, viewRight, viewBottom, viewTop); // Set up a 2D orthographic coordinate system
}

// Main function to initialize and start the GLUT loop
int main(int argc, char** argv) {
    glutInit(&argc, argv);                          // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);    // Set display mode to single-buffered and RGB color mode
    glutInitWindowSize(640, 480);                   // Set the window size
    glutInitWindowPosition(100, 150);               // Set the window position on the screen
    glutCreateWindow("Dinosaur Zooming");           // Create a window with a title
    glutDisplayFunc(display);                       // Register display callback function
    glutKeyboardFunc(Keyboard);                     // Register keyboard input callback function
    init();                                         // Call initialization function
    glutMainLoop();                                 // Enter the event-processing loop
    return 0;                                       // Exit the program
}
