#include <iostream> // Include standard input/output stream library
#include <fstream>  // Include file stream library
#include <string>   // Include string library
#include <GL/glut.h> // Include OpenGL Utility Toolkit (GLUT) library

using namespace std; // Use the standard namespace

int screenWidth = 640, screenHeight = 480; // Define screen width and height

// User-defined display function
void myDisplay(void)
{                                       
    glClear(GL_COLOR_BUFFER_BIT);        // Clears the framebuffer with the background color
    glFlush();                           // Sends buffer pixels to the display screen
}

// Function to draw a dot at given coordinates
void drawDot(int xx, int yy) {
    glBegin(GL_POINTS); // Begin drawing points
    glVertex2i(xx, yy); // Specify the vertex position for the dot
    glEnd(); // End drawing points
}

// Mouse button event handler
void myMouse(int button, int state, int x, int y)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) // Check if left button is pressed
        drawDot(x, screenHeight - y); // Draw a dot at the mouse position, adjusting for window coordinate system
    
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) // Check if right button is pressed
        glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer
    
    glutPostRedisplay(); // Request a redraw of the scene
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode to single buffer and RGB color
    glutInitWindowSize(screenWidth, screenHeight); // Set the window size
    glutInitWindowPosition(30, 30); // Set the window position on the screen
    glutCreateWindow("Experiment with Images"); // Create the window with a title
    glutDisplayFunc(myDisplay); // Register the display callback function
    glutMouseFunc(myMouse); // Register the mouse callback function
    glutMainLoop(); // Start the GUI event loop
    return 0; // Return success
}
