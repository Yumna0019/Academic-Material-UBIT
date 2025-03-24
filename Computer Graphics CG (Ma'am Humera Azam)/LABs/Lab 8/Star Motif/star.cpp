#include <GL/glut.h> // Include the GLUT library for OpenGL
#include <cmath>     // Include cmath for mathematical functions

const int WINDOW_WIDTH = 600;    // Set window width
const int WINDOW_HEIGHT = 600;   // Set window height
const float SCALE_FACTOR = 13.0; // Define a scale factor for motif size

void drawFlakeMotif()
{                                                     // Function to draw one motif of the snowflake
    glBegin(GL_LINE_STRIP);                           // Begin drawing a connected line strip
    glVertex2f(3 * SCALE_FACTOR, 3 * SCALE_FACTOR);   // First vertex of the motif
    glVertex2f(0 * SCALE_FACTOR, 8 * SCALE_FACTOR);   // Second vertex of the motif
    glVertex2f(-3 * SCALE_FACTOR, 0 * SCALE_FACTOR);  // Third vertex of the motif
    glVertex2f(-2 * SCALE_FACTOR, -1 * SCALE_FACTOR); // Fourth vertex of the motif
    glVertex2f(0 * SCALE_FACTOR, 5 * SCALE_FACTOR);   // Fifth vertex of the motif
    glVertex2f(2 * SCALE_FACTOR, 3 * SCALE_FACTOR);   // Sixth vertex of the motif
    glVertex2f(3 * SCALE_FACTOR, 3 * SCALE_FACTOR);   // Return to starting vertex to close shape
    glEnd();                                          // End the line strip
}

void display()
{                                 // Display function for rendering the snowflake
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer
    glColor3f(1.0, 1.0, 1.0);     // Set drawing color to white

    glPushMatrix();                                             // Save the current transformation matrix
    glTranslatef(WINDOW_WIDTH / 2.0, WINDOW_HEIGHT / 2.0, 0.0); // Move to the center of the window
    for (int count = 0; count < 5; count++)
    {                                   // Loop to draw 5 motifs for the snowflake
        drawFlakeMotif();               // Draw one motif
        glRotatef(72.2, 0.0, 0.0, 1.0); // Rotate 72.2 degrees for the next motif
    }
    glPopMatrix(); // Restore the original transformation matrix

    glFlush(); // Force rendering of the drawings
}

void init()
{                                                  // Initialization function for setting up the environment
    glClearColor(0.0, 0.0, 0.0, 1.0);              // Set background color to black
    glMatrixMode(GL_PROJECTION);                   // Switch to projection matrix mode
    glLoadIdentity();                              // Reset the projection matrix
    gluOrtho2D(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT); // Set orthographic projection
}

int main(int argc, char **argv)
{                                                    // Main function
    glutInit(&argc, argv);                           // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);     // Set display mode to single buffer and RGB color
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT); // Set initial window size
    glutInitWindowPosition(100, 100);                // Set initial window position
    glutCreateWindow("Star");                        // Create window with title "Star"

    init(); // Call initialization function

    glutDisplayFunc(display); // Set the display callback function
    glutMainLoop();           // Enter the GLUT main loop

    return 0; // Return success
}
