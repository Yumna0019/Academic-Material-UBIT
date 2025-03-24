#include <GL/glut.h> // Include OpenGL Utility Toolkit library
#include <cmath>     // Include cmath for mathematical functions

// Function to draw a circle
void drawCircle(float centerX, float centerY, float radius)
{
    glBegin(GL_LINE_LOOP); // Begin drawing a line loop (circle outline)
    for (int i = 0; i < 360; i++)
    {                                            // Loop through 360 degrees
        float theta = i * (M_PI / 180);          // Convert degrees to radians
        float x = centerX + radius * cos(theta); // Calculate x coordinate
        float y = centerY + radius * sin(theta); // Calculate y coordinate
        glVertex2f(x, y);                        // Specify the vertex for the circle
    }
    glEnd(); // End the line loop
}

// Display function
void display()
{
    // Clear the screen with a white background
    glClear(GL_COLOR_BUFFER_BIT);

    // Set circle color to blue
    glColor3f(0.0, 0.0, 1.0); // Define the color for the circle
    // Draw a circle at the origin with a radius of 50
    drawCircle(0.0, 0.0, 50.0); // Call the function to draw the circle

    // Flush the drawing to the screen
    glFlush(); // Ensure all OpenGL commands are executed
}

// Initialization function
void init()
{
    // Set the background color to white
    glClearColor(1.0, 1.0, 1.0, 1.0); // Define the clear color for the window

    // Set up the projection (orthographic projection in this case)
    glMatrixMode(GL_PROJECTION);              // Switch to the projection matrix
    glLoadIdentity();                         // Load the identity matrix to reset transformations
    gluOrtho2D(-100.0, 100.0, -100.0, 100.0); // Define the visible area (2D orthographic projection)

    // Switch to model view matrix
    glMatrixMode(GL_MODELVIEW); // Switch to the model-view matrix
    glLoadIdentity();           // Load the identity matrix to reset transformations
}

// Main function where the program execution begins
int main(int argc, char **argv)
{
    // Initialize GLUT
    glutInit(&argc, argv);                       // Initialize the GLUT library
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode to single-buffered and RGB color mode
    glutInitWindowSize(500, 500);                // Set the window size to 500x500 pixels
    glutCreateWindow("Draw Circle");             // Create the window with a title

    // Call the initialization function
    init(); // Perform initialization tasks

    // Register the display callback function
    glutDisplayFunc(display); // Register the display function to be called when the window needs to be redrawn

    // Enter the GLUT main loop
    glutMainLoop(); // Start the main event loop to handle events and render continuously
    return 0;       // Exit the program
}
