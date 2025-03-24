#include <iostream>  // Include standard input/output stream library
#include <fstream>   // Include file stream library for file operations
#include <string>    // Include string library for string manipulation
#include <GL/glut.h> // Include OpenGL Utility Toolkit (GLUT) library for OpenGL functions

using namespace std; // Use standard namespace to avoid prefixing standard functions

int screenWidth = 640, screenHeight = 480; // Set the width and height of the window

// Function to output a string at specified coordinates using a specified font
void bitmap_output(int x, int y, string s, void *font)
{
    int len, i;          // Declare variables for length and iteration
    glRasterPos2f(x, y); // Set the position for bitmap output
    len = s.length();    // Get the length of the string
    for (i = 0; i < len; i++)
    {                                    // Loop through each character in the string
        glutBitmapCharacter(font, s[i]); // Output each character using the specified font
    }
}

// Display function to render graphics
void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT); // Clears framebuffer with background color

    glColor3f(1, 0, 0);                                                                        // Set foreground color to red
    bitmap_output(40, 230, "This is written in GLUT bitmap font", GLUT_BITMAP_TIMES_ROMAN_24); // Output string using Times Roman 24 font

    glColor3f(1, 0, 0);                                                                 // Set foreground color to red
    bitmap_output(30, 210, "More bitmap in a fixed 9 by 15 font", GLUT_BITMAP_9_BY_15); // Output string using 9 by 15 font

    glColor3f(0, 1, 0);                                                                      // Set foreground color to green
    bitmap_output(70, 35, "Helvetica is yet another bitmap font", GLUT_BITMAP_HELVETICA_18); // Output string using Helvetica 18 font

    glFlush(); // Sends buffer pixels to display screen to ensure all rendering is completed
}

// Initialization function to set up the rendering environment
void myInit()
{
    glClearColor(0.9f, 0.9f, 0.9f, 1.0f); // Set background color to light gray
    glColor3f(1.0, 0.0, 0.0);             // Set drawing color to red

    glMatrixMode(GL_PROJECTION);                     // Select the Projection matrix
    glLoadIdentity();                                // Reset the matrix to the identity matrix
    gluOrtho2D(0.0, screenWidth, 0.0, screenHeight); // Set the coordinate system for 2D rendering
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);                         // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);   // Set display mode to single buffer and RGB color
    glutInitWindowSize(screenWidth, screenHeight); // Set the window size
    glutInitWindowPosition(30, 30);                // Set the initial window position
    glutCreateWindow("Experiment with Images");    // Create a window with a title

    myInit();                   // Call the initialization function
    glutDisplayFunc(myDisplay); // Register the display callback function
    glutMainLoop();             // Enter the event-processing loop

    return 0; // Return success
}
