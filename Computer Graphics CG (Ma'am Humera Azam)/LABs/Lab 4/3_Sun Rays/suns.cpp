#include <GL/glut.h> // Include the GLUT header for OpenGL utilities
#include <cmath>     // Include the cmath library for mathematical functions

// Define M_PI if it's not already defined
#ifndef M_PI
#define M_PI 3.14159265358979323846 // Define the value of pi
#endif

// Function to draw a circle
void drawCircle(float centerX, float centerY, float radius, int segments, float r, float g, float b)
{
    glColor3f(r, g, b);  // Set the circle color using RGB values
    glBegin(GL_POLYGON); // Begin drawing a polygon for the circle
    for (int i = 0; i <= segments; ++i)
    {                                             // Loop through each segment of the circle
        float theta = 2.0f * M_PI * i / segments; // Calculate the angle for the current segment
        float x = radius * cos(theta);            // Calculate the x-coordinate of the vertex
        float y = radius * sin(theta);            // Calculate the y-coordinate of the vertex
        glVertex2f(centerX + x, centerY + y);     // Define the vertex position in OpenGL
    }
    glEnd(); // End drawing the circle
}

// Function to draw sun rays
void drawSunRays(float centerX, float centerY, float circleRadius, int rays, float minLength, float maxLength)
{
    glColor3f(1.0f, 0.0f, 0.0f); // Set the line color (Red)
    glBegin(GL_LINES);           // Begin drawing lines for the rays
    for (int i = 0; i < rays; ++i)
    {                                                              // Loop through each ray
        float theta = 2.0f * M_PI * i / rays;                      // Calculate the angle for the current ray
        float x1 = centerX + circleRadius * cos(theta);            // Calculate the starting x-coordinate
        float y1 = centerY + circleRadius * sin(theta);            // Calculate the starting y-coordinate
        float length = (i % 2 == 0) ? maxLength : minLength;       // Alternate ray lengths
        float x2 = centerX + (circleRadius + length) * cos(theta); // Calculate the ending x-coordinate
        float y2 = centerY + (circleRadius + length) * sin(theta); // Calculate the ending y-coordinate
        glVertex2f(x1, y1);                                        // Define the starting vertex position in OpenGL
        glVertex2f(x2, y2);                                        // Define the ending vertex position in OpenGL
    }
    glEnd(); // End drawing the sun rays
}

// Function to draw triangles around the circle
void drawTriangles(float centerX, float centerY, float circleRadius, int triangles, float triangleBase, float triangleHeight)
{
    glColor3f(0.0f, 0.0f, 1.0f); // Set the triangle color (Blue)
    glBegin(GL_TRIANGLES);       // Begin drawing triangles
    for (int i = 0; i < triangles; ++i)
    {                                                                                           // Loop through each triangle
        float theta = 2.0f * M_PI * i / triangles;                                              // Calculate the angle for the triangle
        float x1 = centerX + circleRadius * cos(theta);                                         // Calculate the first vertex x-coordinate
        float y1 = centerY + circleRadius * sin(theta);                                         // Calculate the first vertex y-coordinate
        float x2 = centerX + (circleRadius + triangleHeight) * cos(theta + (triangleBase / 2)); // Calculate the second vertex x-coordinate
        float y2 = centerY + (circleRadius + triangleHeight) * sin(theta + (triangleBase / 2)); // Calculate the second vertex y-coordinate
        float x3 = centerX + (circleRadius + triangleHeight) * cos(theta - (triangleBase / 2)); // Calculate the third vertex x-coordinate
        float y3 = centerY + (circleRadius + triangleHeight) * sin(theta - (triangleBase / 2)); // Calculate the third vertex y-coordinate
        glVertex2f(x1, y1);                                                                     // Define the first vertex position in OpenGL
        glVertex2f(x2, y2);                                                                     // Define the second vertex position in OpenGL
        glVertex2f(x3, y3);                                                                     // Define the third vertex position in OpenGL
    }
    glEnd(); // End drawing the triangles
}

// Display function to render shapes
void display()
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

    // Draw the "sun" with yellow circle and red rays
    drawCircle(-0.5f, 0.0f, 0.2f, 50, 1.0f, 1.0f, 0.0f); // Draw a yellow circle for the sun
    drawSunRays(-0.5f, 0.0f, 0.2f, 12, 0.1f, 0.2f);      // Draw red rays for the sun

    // Draw the second circle with triangles attached
    drawCircle(0.5f, 0.0f, 0.2f, 50, 0.0f, 1.0f, 0.0f); // Draw a green circle
    drawTriangles(0.5f, 0.0f, 0.2f, 12, 0.05f, 0.15f);  // Draw blue triangles around the green circle

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
    glutInit(&argc, argv);                                            // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);                      // Set the display mode
    glutInitWindowSize(500, 500);                                     // Set the window size to 500x500 pixels
    glutCreateWindow("OpenGL Sun with Lines and Sun with Triangles"); // Create a window with a title
    init();                                                           // Call the initialization function
    glutDisplayFunc(display);                                         // Register the display callback function
    glutMainLoop();                                                   // Enter the GLUT event processing loop
    return 0;                                                         // Return 0 to indicate successful execution
}
