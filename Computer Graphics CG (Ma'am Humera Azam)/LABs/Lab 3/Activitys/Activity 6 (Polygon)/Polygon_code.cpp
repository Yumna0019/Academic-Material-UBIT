#include <GL/glut.h>          // Include OpenGL Utility Toolkit library
#include <cmath>              // Include cmath for mathematical functions

const float PI = 3.14159265f; // Define constant for PI

// Function to draw a regular n-sided polygon (ngon)
void ngon(int n, float cx, float cy, float radius, float rotAngle) {
    if (n < 3) return; // Check for valid number of sides (must be at least 3)

    glBegin(GL_POLYGON); // Begin drawing the polygon
    double angle = rotAngle * PI / 180; // Convert rotation angle from degrees to radians
    double angleInc = 2 * PI / n;       // Calculate the angle increment for each vertex

    for (int k = 0; k < n; k++) {       // Loop through each vertex
        // Calculate the vertex position using polar coordinates and add it to the center
        glVertex2f(radius * cos(angle) + cx, radius * sin(angle) + cy);
        angle += angleInc;                // Increment the angle for the next vertex
    }

    glEnd(); // End drawing the polygon
}

// Function for the display callback
void display() {
    glClearColor(0.0314f, 0.0392f, 0.3216f, 1.0f); // Set the clear color (background color)
    glClear(GL_COLOR_BUFFER_BIT);                  // Clear the color buffer

    glColor3f(0.9294f, 0.1294f, 0.5333f);          // Set the drawing color

    // Draw a polygon (hexagon) centered at (0, 0) with a radius of 5
    ngon(16, 0, 0, 5, 0);                          // Draw a 16-sided polygon (should be a circle)

    glFlush();                                      // Ensure all OpenGL commands are executed
}

// Function for handling window reshaping
void reshape(int width, int height) {
    glViewport(0, 0, width, height);              // Set the viewport to cover the new window dimensions
    glMatrixMode(GL_PROJECTION);                   // Switch to projection matrix mode
    glLoadIdentity();                              // Load the identity matrix to reset transformations
    glOrtho(-10.0, 10.0, -10.0, 10.0, -1.0, 1.0); // Set up a 2D orthographic projection
    glMatrixMode(GL_MODELVIEW);                    // Switch back to model-view matrix mode
    glLoadIdentity();                              // Load the identity matrix to reset transformations
}

// Main function to initialize and start the GLUT loop
int main(int argc, char** argv) {
    glutInit(&argc, argv);                         // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);   // Set display mode to single-buffered and RGB color mode
    glutInitWindowSize(800, 600);                  // Set the window size
    glutCreateWindow("Polygon");                   // Create a window with a title

    glutDisplayFunc(display);                       // Register display callback function
    glutReshapeFunc(reshape);                       // Register reshape callback function

    glutMainLoop();                                 // Enter the event-processing loop
    return 0;                                       // Exit the program
}
