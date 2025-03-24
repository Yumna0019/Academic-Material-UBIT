#include <iostream>  // Include standard input/output stream library
#include <fstream>   // Include file stream library
#include <string>    // Include string library
#include <GL/glut.h> // Include OpenGL Utility Toolkit (GLUT) library

using namespace std; // Use the standard namespace

int screenWidth = 640, screenHeight = 480; // Define screen width and height

// User-defined display function
void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT); // Clears the framebuffer with the background color
    glFlush();                    // Sends buffer pixels to the display screen
}

// Mouse button event handler
void myMouse(int button, int state, int mx, int my)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {                        // Check if left button is pressed
        glutPostRedisplay(); // Request a redraw of the scene
    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {                                 // Check if right button is pressed
        glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer
        glFlush();                    // Send the buffer to the display
    }
}

// Initialization function
void myInit()
{
    glClearColor(0.9f, 0.9f, 0.9f, 0.0); // Set the clear color to a light gray
    glColor3f(3, 0, 0);                  // Set the drawing color (although it is out of range)
}

// Window reshape event handler
void myReshape(int w, int h)
{
    screenHeight = h;                                                    // Update screen height
    screenWidth = w;                                                     // Update screen width
    glMatrixMode(GL_PROJECTION);                                         // Switch to projection matrix
    glLoadIdentity();                                                    // Load the identity matrix
    gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight); // Define the 2D orthographic projection
    glMatrixMode(GL_MODELVIEW);                                          // Switch back to model-view matrix
    glLoadIdentity();                                                    // Load the identity matrix
}

// Mouse motion event handler
void mouseMove(int x, int y)
{
    glutPostRedisplay(); // Request a redraw of the scene
}

// Keyboard event handler
void myKeys(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'q':    // If 'q' is pressed
        exit(0); // Exit the program
        break;
    case 's':
        // Add any action you want to trigger when 's' is pressed
        break;
    }
    glutPostRedisplay(); // Redraw the scene after handling the key press
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);                         // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);   // Set display mode to single buffer and RGB color
    glutInitWindowSize(screenWidth, screenHeight); // Set the window size
    glutInitWindowPosition(30, 30);                // Set the window position on the screen
    glutCreateWindow("Experiment with Images");    // Create the window with a title
    myInit();                                      // Call initialization function
    glutReshapeFunc(myReshape);                    // Register the reshape callback function
    glutDisplayFunc(myDisplay);                    // Register the display callback function
    glutMouseFunc(myMouse);                        // Register the mouse callback function
    glutKeyboardFunc(myKeys);                      // Register the keyboard callback function
    glutMotionFunc(mouseMove);                     // Register the mouse motion callback function
    glutMainLoop();                                // Start the GUI event loop
    return 0;                                      // Return success
}
