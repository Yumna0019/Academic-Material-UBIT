#include <GL/glut.h> // Include OpenGL Utility Toolkit (GLUT) library

// Display function to render graphics
void display()
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

    // Set the viewport to a specific area of the window
    glViewport(100, 100, 300, 300); // Define the viewport dimensions and position

    // Set the world window (orthographic projection)
    glMatrixMode(GL_PROJECTION);          // Switch to the projection matrix
    glLoadIdentity();                     // Load the identity matrix to reset transformations
    gluOrtho2D(-50.0, 50.0, -50.0, 50.0); // Define the orthographic projection parameters

    glMatrixMode(GL_MODELVIEW); // Switch back to the model-view matrix
    glLoadIdentity();           // Load the identity matrix for model transformations

    // Draw a simple red square
    glColor3f(1.0, 0.0, 0.0); // Set the drawing color to red
    glBegin(GL_POLYGON);      // Begin drawing a polygon
    glVertex2f(-25.0, -25.0); // Specify the first vertex of the square
    glVertex2f(25.0, -25.0);  // Specify the second vertex of the square
    glVertex2f(25.0, 25.0);   // Specify the third vertex of the square
    glVertex2f(-25.0, 25.0);  // Specify the fourth vertex of the square
    glEnd();                  // End drawing the polygon

    glFlush(); // Force execution of OpenGL commands and display the result
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);                         // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);   // Set display mode to single buffer and RGB color
    glutInitWindowSize(500, 500);                  // Set the window size
    glutCreateWindow("Viewport and World Window"); // Create the window with a title

    glutDisplayFunc(display); // Register the display callback function

    glutMainLoop(); // Start the GUI event loop
    return 0;       // Return success
}
