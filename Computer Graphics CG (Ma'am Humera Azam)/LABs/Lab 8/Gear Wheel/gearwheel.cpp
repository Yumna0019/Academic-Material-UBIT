#include <GL/glut.h> // Include the GLUT library for OpenGL
#include <cmath>     // Include cmath for mathematical functions
#include <iostream>  // Include iostream for console output
using namespace std;

float deg = 0.0; // Initialize degree variable for rotation

void tooth0() // Function to define the basic shape of a gear tooth
{
    glBegin(GL_LINE_STRIP); // Begin drawing a line strip
    glVertex2f(0, 0);       // Specify the first vertex
    glVertex2f(0.2, 0.2);   // Specify the second vertex
    glVertex2f(0.6, 0.2);   // Specify the third vertex
    glVertex2f(0.6, 0.8);   // Specify the fourth vertex
    glVertex2f(0.2, 0.8);   // Specify the fifth vertex
    glVertex2f(0, 1.0);     // Specify the last vertex, connecting back to start
    glEnd();                // End the line strip
}

void tooth1(double r) // Function to position and scale each tooth
{
    double rad = 6 * 3.1416 / 180.0;       // Convert 6 degrees to radians
    double sin6 = r * sin(rad);            // Calculate the scaled sine value
    double cos6 = r * cos(rad);            // Calculate the scaled cosine value
    glPushMatrix();                        // Save the current transformation
    glTranslatef(cos6, -sin6, 0.0);        // Translate to position for tooth
    glScalef(2.0 * sin6, 2.0 * sin6, 1.0); // Scale the tooth
    tooth0();                              // Call function to draw the tooth shape
    glPopMatrix();                         // Restore previous transformation
}

void gear(double r) // Function to draw the entire gear
{
    glPushMatrix();               // Save the current transformation
    for (int i = 0; i <= 30; ++i) // Loop to create all teeth around the gear
    {
        tooth1(r);                  // Call function to position and scale each tooth
        glRotatef(12.0, 0, 0, 1.0); // Rotate by 12 degrees for the next tooth
    }
    glPopMatrix(); // Restore previous transformation
}

void move() // Function to update rotation based on time
{
    float speed = 0.000001;                // Set speed for rotation
    static int oldTime = clock(), newTime; // Store old and new time for delta calculation
    newTime = clock();                     // Get the current clock time
    deg += (newTime - oldTime) * speed;    // Update rotation based on time difference
    oldTime = newTime;                     // Update old time to the new time
    glutPostRedisplay();                   // Request display update
}

void display() // Display function to render the gear
{
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    glClearColor(0.0, 0.0, 0.0, 1); // Set background color to black
    glColor3f(0.0f, 1.0f, 0.0f);    // Set drawing color to green
    move();                         // Update rotation angle
    glRotatef(deg, 0.0, 0.0, 1.0);  // Apply rotation transformation
    gear(10.0);                     // Draw the gear with radius 10.0
    glFlush();                      // Flush drawing commands
}

void reshape(GLsizei w, GLsizei h) // Reshape function for window resizing
{
    glViewport(0, 0, w, h);       // Set viewport to window dimensions
    glMatrixMode(GL_PROJECTION);  // Switch to projection matrix mode
    glLoadIdentity();             // Reset the projection matrix
    gluOrtho2D(-20, 20, -20, 20); // Set orthographic projection
    glMatrixMode(GL_MODELVIEW);   // Switch back to modelview matrix mode
    glLoadIdentity();             // Reset the modelview matrix
}

void init() // Initialization function for OpenGL settings
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to white

    glMatrixMode(GL_PROJECTION);  // Switch to projection matrix mode
    glLoadIdentity();             // Reset the projection matrix
    gluOrtho2D(-20, 20, -20, 20); // Set orthographic projection
    glMatrixMode(GL_MODELVIEW);   // Switch to modelview matrix mode
    glLoadIdentity();             // Reset the modelview matrix
}

int main(int argc, char **argv) // Main function
{
    glutInit(&argc, argv);                       // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode to single buffer and RGB
    glutInitWindowSize(500, 500);                // Set initial window size
    glutCreateWindow("Gear Wheel");              // Create window with title "Gear Wheel"
    init();                                      // Call initialization function
    glutDisplayFunc(display);                    // Set display callback function
    glutReshapeFunc(reshape);                    // Set reshape callback function
    glutMainLoop();                              // Enter the GLUT main loop
    return 0;                                    // Return with exit status 0
}
