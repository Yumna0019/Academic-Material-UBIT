#include <iostream>  // For standard input/output operations
#include <GL/glut.h> // For OpenGL and GLUT functions
#include <cmath>     // For mathematical functions like sqrt and pow

using namespace std;

// Function to draw a triangle
void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3)
{
    glBegin(GL_TRIANGLES); // Start drawing a triangle
    glVertex2f(x1, y1);    // Specify the first vertex of the triangle
    glVertex2f(x2, y2);    // Specify the second vertex of the triangle
    glVertex2f(x3, y3);    // Specify the third vertex of the triangle
    glEnd();               // End drawing the triangle
}

// Recursive function to draw the Sierpinski Gasket
void sierpinski(float x1, float y1, float x2, float y2, float x3, float y3, int depth)
{
    if (depth == 0) // Base case: if depth is zero, draw the triangle
    {
        drawTriangle(x1, y1, x2, y2, x3, y3); // Draw the triangle
    }
    else // Recursive case
    {
        float mx1 = (x1 + x2) / 2.0; // Calculate midpoint between x1 and x2
        float my1 = (y1 + y2) / 2.0; // Calculate midpoint between y1 and y2
        float mx2 = (x2 + x3) / 2.0; // Calculate midpoint between x2 and x3
        float my2 = (y2 + y3) / 2.0; // Calculate midpoint between y2 and y3
        float mx3 = (x3 + x1) / 2.0; // Calculate midpoint between x3 and x1
        float my3 = (y3 + y1) / 2.0; // Calculate midpoint between y3 and y1

        // Recursively draw three smaller Sierpinski triangles
        sierpinski(x1, y1, mx1, my1, mx3, my3, depth - 1); // Top-left triangle
        sierpinski(x2, y2, mx1, my1, mx2, my2, depth - 1); // Bottom triangle
        sierpinski(x3, y3, mx2, my2, mx3, my3, depth - 1); // Top-right triangle
    }
}

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);        // Clears framebuffer with background color
    glClearColor(0.9f, 0.9f, 0.9f, 0.0); // Set background color to a light gray
    glColor3f(1, 0, 0);                  // Set drawing color to red

    // Define vertices of the initial large triangle
    float x1 = -0.5, y1 = -0.5; // Bottom-left vertex of the triangle
    float x2 = 0.5, y2 = -0.5;  // Bottom-right vertex of the triangle
    float x3 = 0.0, y3 = 0.5;   // Top vertex of the triangle

    // Draw the Sierpinski Gasket with depth 5
    sierpinski(x1, y1, x2, y2, x3, y3, 5); // Call recursive function to draw gasket

    glFlush(); // Sends buffer pixels to display screen
}

int screenWidth = 640, screenHeight = 480; // Screen dimensions for the window

int main(int argc, char **argv)
{
    glutInit(&argc, argv);                         // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);   // Set display mode to single buffering and RGB
    glutInitWindowSize(screenWidth, screenHeight); // Set initial window size
    glutInitWindowPosition(30, 30);                // Set initial window position on screen
    glutCreateWindow("Sierpinski Gasket");         // Create window with title

    glMatrixMode(GL_PROJECTION); // Set up projection mode
    glLoadIdentity();            // Load identity matrix for reset
    gluOrtho2D(-1, 1, -1, 1);    // Set orthographic projection to fit the triangle

    glutDisplayFunc(myDisplay); // Register display function as callback
    glutMainLoop();             // Enter GLUT event-processing loop
    return 0;                   // Exit main function
}
