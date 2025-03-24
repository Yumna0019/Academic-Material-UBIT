// #include <iostream>
// #include <fstream>
// #include <string>
// #include <GL/glut.h>

// using namespace std;

// void myDisplay(void)
// {                                        // user defined display function
//     glClear(GL_COLOR_BUFFER_BIT);        // clears fb with bg color
//     glClearColor(0.9f, 0.9f, 0.9f, 0.0); // set background color
//     glColor3f(1, 0, 0);                  // set foreground color

//     glBegin(GL_LINE_LOOP);
//     glVertex2f(15,50);
//     glVertex2f(25,35);
//     glVertex2f(30,45);
//     glVertex2f(22,45);
//     glVertex2f(17,55);
//     glVertex2f(27,60);
//     glEnd();

//     glBegin(GL_TRIANGLES);
//     glVertex2f(55,50);
//     glVertex2f(60,55);
//     glVertex2f(30,60);
//     glEnd();

//     glFlush();                           // sends buffer pixels to display screen
// }
// void Initialize() {
//     gluOrtho2D(0.0, 100.0, 0.0, 100.0); // Set up a 2D orthographic viewing region
// }
// int screenWidth = 640, screenHeight = 480;

// int main(int argc, char **argv)
// {
//     glutInit(&argc, argv);
//     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//     glutInitWindowSize(screenWidth, screenHeight);
//     glutInitWindowPosition(30, 30);
//     glutCreateWindow("HT First OGL Program");
//     Initialize();
//     glutDisplayFunc(myDisplay); // register display func. as callback
//     glutMainLoop(); // gui loop that waits for events to occur
//     return 0;
// }

#include <iostream>  // For standard input/output operations
#include <fstream>   // For file handling operations
#include <string>    // For handling string objects
#include <GL/glut.h> // For OpenGL and GLUT functions

using namespace std;

// Function to display graphics on the screen
void myDisplay(void)
{                                        // User-defined display function
    glClear(GL_COLOR_BUFFER_BIT);        // Clear framebuffer with background color
    glClearColor(0.9f, 0.9f, 0.9f, 0.0); // Set background color to light grey
    glColor3f(1, 0, 0);                  // Set foreground color to red

    // Begin drawing a polygon in a continuous loop around vertices
    glBegin(GL_LINE_LOOP);
    glVertex2f(15, 50); // First vertex
    glVertex2f(25, 35); // Second vertex
    glVertex2f(30, 45); // Third vertex
    glVertex2f(22, 45); // Fourth vertex
    glVertex2f(17, 55); // Fifth vertex
    glVertex2f(27, 60); // Sixth vertex
    glEnd();            // End of line loop drawing

    // Begin drawing a triangle
    glBegin(GL_TRIANGLES);
    glVertex2f(55, 50); // First vertex of triangle
    glVertex2f(60, 55); // Second vertex of triangle
    glVertex2f(30, 60); // Third vertex of triangle
    glEnd();            // End of triangle drawing

    glFlush(); // Sends buffer pixels to the display screen
}

// Function to set up a 2D orthographic viewing region
void Initialize()
{
    gluOrtho2D(0.0, 100.0, 0.0, 100.0); // Define a 2D orthographic projection
}

int screenWidth = 640, screenHeight = 480; // Set window dimensions for display

// Main function
int main(int argc, char **argv)
{
    glutInit(&argc, argv);                         // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);   // Set display mode to single buffering and RGB color
    glutInitWindowSize(screenWidth, screenHeight); // Set initial window size
    glutInitWindowPosition(30, 30);                // Set initial window position on screen
    glutCreateWindow("HT First OGL Program");      // Create a window with a title

    Initialize();               // Initialize projection matrix
    glutDisplayFunc(myDisplay); // Register display function as callback
    glutMainLoop();             // Enter the GUI loop that waits for events
    return 0;                   // Exit program
}
