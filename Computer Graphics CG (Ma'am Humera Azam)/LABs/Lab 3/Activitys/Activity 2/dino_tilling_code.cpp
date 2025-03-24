#include <GL/glut.h> // Include the OpenGL Utility Toolkit library
#include <fstream>   // Include file stream for reading files
#include <iostream>  // Include input/output stream for console output

using namespace std;

// Function to draw polylines from file data
void drawPolyLineFile(char *fileName)
{
    fstream inStream;                 // Create an input file stream
    inStream.open(fileName, ios::in); // Open the file in read mode
    if (inStream.fail())              // Check if file opened successfully
        return;                       // Exit function if file failed to open

    GLint numpolys, numLines, x, y; // Variables to hold file data
    inStream >> numpolys;           // Read the number of polylines
    // Loop through each polyline
    for (int j = 0; j < numpolys; j++)
    {
        inStream >> numLines;   // Read the number of lines in the polyline
        glBegin(GL_LINE_STRIP); // Begin drawing a connected line strip
        // Loop through each line in the polyline
        for (int i = 0; i < numLines; i++)
        {
            inStream >> x >> y; // Read the next x, y coordinate pair
            glVertex2i(x, y);   // Specify vertex for current line segment
        }
        glEnd(); // End drawing of the line strip
    }
    inStream.close(); // Close the input file stream
}

// Display function that clears the screen and draws the tiled pattern
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear the screen with background color

    // Tiling: Draw the dinosaur multiple times in a grid pattern
    for (int i = 0; i < 14; ++i)
    { // Loop through grid columns
        for (int j = 0; j < 14; ++j)
        {                                       // Loop through grid rows
            glViewport(i * 64, j * 44, 64, 44); // Set the viewport for each tile
            drawPolyLineFile("dino");           // Draw the dinosaur in the current tile
        }
    }

    glFlush(); // Ensure all OpenGL commands are executed
}

// Initialization function for OpenGL settings
void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);   // Set background color to white
    glColor3f(0.0, 0.0, 0.0);           // Set drawing color to black
    glMatrixMode(GL_PROJECTION);        // Set matrix mode to projection
    glLoadIdentity();                   // Load identity matrix to reset transformations
    gluOrtho2D(0.0, 640.0, 0.0, 480.0); // Set up a 2D orthographic coordinate system
}

// Main function to initialize and start the GLUT loop
int main(int argc, char **argv)
{
    glutInit(&argc, argv);                       // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode to single-buffered and RGB color mode
    glutInitWindowSize(640, 480);                // Set the window size
    glutInitWindowPosition(100, 150);            // Set the window position on the screen
    glutCreateWindow("Dinosaur Tiling Drawing"); // Create a window with a title
    glutDisplayFunc(display);                    // Register display callback function
    init();                                      // Call initialization function
    glutMainLoop();                              // Enter the event-processing loop
    return 0;                                    // Exit the program
}
