#include <GL/glut.h>  // Include OpenGL Utility Toolkit (GLUT) library
#include <windows.h>  // Include Windows API library for Windows-specific functions
#include <mmsystem.h> // Include Multimedia System library for sound functions
#include <iostream>   // Include standard input/output stream library

#pragma comment(lib, "winmm.lib") // Link with the winmm library for sound support

float color[3] = {1.0, 0.0, 0.0}; // Initial color is red (RGB)

// Display function to render graphics
void display()
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

    // Set the current color for drawing
    glColor3fv(color); // Use the RGB color defined in the color array

    // Draw a square
    glBegin(GL_POLYGON);    // Begin drawing a polygon
    glVertex2f(-0.5, -0.5); // Specify the first vertex of the square
    glVertex2f(0.5, -0.5);  // Specify the second vertex of the square
    glVertex2f(0.5, 0.5);   // Specify the third vertex of the square
    glVertex2f(-0.5, 0.5);  // Specify the fourth vertex of the square
    glEnd();                // End drawing the polygon

    glFlush(); // Force execution of OpenGL commands and display the result
}

// Keyboard event handler
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'r': // If 'r' is pressed, change color to red
        color[0] = 1.0;
        color[1] = 0.0;
        color[2] = 0.0; // Set RGB values for red
        break;

    case 'g': // If 'g' is pressed, change color to green
        color[0] = 0.0;
        color[1] = 1.0;
        color[2] = 0.0; // Set RGB values for green
        break;

    case 'b': // If 'b' is pressed, change color to blue
        color[0] = 0.0;
        color[1] = 0.0;
        color[2] = 1.0; // Set RGB values for blue
        break;

    case 'p':                                                        // If 'p' is pressed, play a sound
        PlaySound(TEXT("ouch.wav"), NULL, SND_FILENAME | SND_ASYNC); // Play the sound asynchronously
        break;
    }
    glutPostRedisplay(); // Request a redraw of the screen after key press
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);                       // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode to single buffer and RGB color
    glutInitWindowSize(500, 500);                // Set the window size
    glutCreateWindow("Keyboard Interaction");    // Create the window with a title

    // Register display and keyboard callback functions
    glutDisplayFunc(display);   // Register the display callback function
    glutKeyboardFunc(keyboard); // Register the keyboard callback function

    glutMainLoop(); // Enter the GLUT event loop
    return 0;       // Return success
}
