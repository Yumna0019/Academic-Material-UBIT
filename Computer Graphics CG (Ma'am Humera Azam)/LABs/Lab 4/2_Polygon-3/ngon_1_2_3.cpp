#include <GL/glut.h>                // Include the GLUT header for OpenGL utilities
#include <cmath>                    // Include the cmath library for mathematical functions
#define M_PI 3.14159265358979323846 // Define the value of pi

// Function to draw an n-sided polygon (n-gon)
void ngon(int n, float radius, float centerX, float centerY, float r, float g, float b)
{
    glColor3f(r, g, b);  // Set the color for the polygon using RGB values
    glBegin(GL_POLYGON); // Begin drawing a polygon
    for (int i = 0; i < n; ++i)
    {                                         // Loop through each vertex of the polygon
        float angle = 2.0f * M_PI * i / n;    // Calculate the angle for the current vertex
        float x = radius * cos(angle);        // Calculate the x-coordinate of the vertex
        float y = radius * sin(angle);        // Calculate the y-coordinate of the vertex
        glVertex2f(centerX + x, centerY + y); // Define the vertex position in OpenGL
    }
    glEnd(); // End drawing the polygon
}

// Function to display the polygons
void display()
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

    // Output 1: Triangle (3-sided polygon)
    ngon(3, 0.2f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f); // Draw a red triangle

    // Output 2: Hexagon (6-sided polygon)
    ngon(6, 0.3f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f); // Draw a green hexagon

    // Output 3: Octagon (8-sided polygon)
    ngon(8, 0.25f, 0.0f, -0.5f, 0.0f, 0.0f, 1.0f); // Draw a blue octagon

    glFlush(); // Flush the OpenGL commands to the screen
}

// Initialization function
void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set the background color to white
    glMatrixMode(GL_PROJECTION);          // Set the current matrix mode to projection
    glLoadIdentity();                     // Load the identity matrix to reset transformations
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);     // Define a 2D orthographic projection matrix
}

// Main function
int main(int argc, char **argv)
{
    glutInit(&argc, argv);                       // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set the display mode
    glutInitWindowSize(500, 500);                // Set the window size to 500x500 pixels
    glutCreateWindow("N-gons with OpenGL");      // Create a window with a title
    init();                                      // Call the initialization function
    glutDisplayFunc(display);                    // Register the display callback function
    glutMainLoop();                              // Enter the GLUT event processing loop
    return 0;                                    // Return 0 to indicate successful execution
}
