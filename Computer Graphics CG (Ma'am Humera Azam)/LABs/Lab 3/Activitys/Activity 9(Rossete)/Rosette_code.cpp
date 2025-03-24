#include <GL/glut.h> // Include OpenGL Utility Toolkit library
#include <cmath>     // Include cmath for mathematical functions

const float PI = 3.14159265f; // Define a constant for the value of PI

// Define a structure to hold 2D points
struct Point2
{
    float x, y; // x and y coordinates of the point
};

// Function to draw a rosette with N points and a specified radius
void Rosette(int N, float radius)
{
    if (N < 3)
        return; // Ensure there are enough points to form a rosette

    // Create an array to hold the vertices
    Point2 *pt = new Point2[N];

    // Calculate the vertices of the rosette
    double angleInc = 2 * PI / N; // Calculate the angle increment for each point
    for (int i = 0; i < N; i++)
    {                                  // Loop through each point
        double angle = i * angleInc;   // Calculate the angle for the current point
        pt[i].x = radius * cos(angle); // Calculate x-coordinate
        pt[i].y = radius * sin(angle); // Calculate y-coordinate
    }

    // Draw lines connecting each pair of vertices
    glBegin(GL_LINES); // Begin drawing lines
    for (int i = 0; i < N - 1; i++)
    { // Loop through each vertex
        for (int j = i + 1; j < N; j++)
        {                                 // Loop through remaining vertices
            glVertex2f(pt[i].x, pt[i].y); // Specify the first vertex
            glVertex2f(pt[j].x, pt[j].y); // Specify the second vertex
        }
    }
    glEnd(); // End drawing lines

    // Clean up by deleting the dynamically allocated array
    delete[] pt;
}

// Display function for rendering the scene
void display()
{
    glClearColor(0.0314f, 0.0392f, 0.3216f, 1.0f); // Set the background color
    glClear(GL_COLOR_BUFFER_BIT);                  // Clear the color buffer

    // Draw the first rosette with 16 points at position (-10, 0)
    glColor3f(0.9294f, 0.1294f, 0.5333f); // Set color to a pinkish hue
    glPushMatrix();                       // Save the current matrix state
    glTranslatef(-10.0f, 0.0f, 0.0f);     // Move the drawing position to (-10, 0)
    Rosette(16, 5.0f);                    // Draw the rosette
    glPopMatrix();                        // Restore the previous matrix state

    // Draw the second rosette with 11 points at position (0, 0)
    glColor3f(0.1f, 0.9f, 0.1f); // Set color to green
    glPushMatrix();              // Save the current matrix state
    // No translation needed, already at (0, 0)
    Rosette(11, 5.0f); // Draw the rosette
    glPopMatrix();     // Restore the previous matrix state

    // Draw the third rosette with 5 points at position (10, 0)
    glColor3f(0.1f, 0.1f, 0.9f);     // Set color to blue
    glPushMatrix();                  // Save the current matrix state
    glTranslatef(10.0f, 0.0f, 0.0f); // Move the drawing position to (10, 0)
    Rosette(5, 5.0f);                // Draw the rosette
    glPopMatrix();                   // Restore the previous matrix state

    glFlush(); // Flush the OpenGL commands to the screen
}

// Function to handle window reshaping
void reshape(int width, int height)
{
    glViewport(0, 0, width, height);              // Set the viewport to cover the new window dimensions
    glMatrixMode(GL_PROJECTION);                  // Switch to projection matrix mode
    glLoadIdentity();                             // Load the identity matrix to reset transformations
    glOrtho(-20.0, 20.0, -10.0, 10.0, -1.0, 1.0); // Set the orthographic projection
    glMatrixMode(GL_MODELVIEW);                   // Switch back to model-view matrix mode
    glLoadIdentity();                             // Load the identity matrix to reset transformations
}

// Main function where the program execution begins
int main(int argc, char **argv)
{
    glutInit(&argc, argv);                                      // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);                // Set display mode to single-buffered and RGB color mode
    glutInitWindowSize(800, 600);                               // Set the window size
    glutCreateWindow("Lab Activity (6): Circle using Polygon"); // Create the window with a title

    glutDisplayFunc(display); // Register the display callback function
    glutReshapeFunc(reshape); // Register the reshape callback function

    glutMainLoop(); // Enter the GLUT main loop to handle events and render continuously
    return 0;       // Exit the program
}
