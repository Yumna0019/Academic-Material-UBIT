#include <GL/glut.h> // Include the GLUT library for OpenGL
#include <iostream>  // Include iostream for console output
#include <fstream>   // Include fstream for file operations
#include <cmath>     // Include cmath for mathematical functions
using namespace std;

const int screenwidth = 650;                                  // Define screen width
const int screenheight = 450;                                 // Define screen height
const int numdinosaurs = 15;                                  // Set the number of dinosaurs in the circle
const float circleradius = (screenwidth, screenheight) * 0.2; // Define radius of the circle

void drawdinosaur(string filename)
{                                     // Function to draw a dinosaur from a data file
    fstream instream;                 // Create fstream object for file reading
    instream.open(filename, ios::in); // Open the file in read mode

    if (instream.fail())
    {                                              // Check if file failed to open
        cout << "can't open " << filename << endl; // Print error message if file can't be opened
        return;                                    // Exit function if file cannot be opened
    }

    GLfloat numpolys, numpoints, x, y; // Declare variables for number of polylines, points, and coordinates
    instream >> numpolys;              // Read the number of polylines from the file

    for (int j = 0; j < numpolys; j++)
    {                           // Loop through each polyline
        instream >> numpoints;  // Read the number of points in the polyline
        glBegin(GL_LINE_STRIP); // Begin drawing a line strip
        for (int i = 0; i < numpoints; i++)
        {                       // Loop through each point in the polyline
            instream >> x >> y; // Read x and y coordinates
            glVertex2f(x, y);   // Set vertex for the line strip
        }
        glEnd(); // End the line strip
    }

    instream.close(); // Close the file after reading
}

void myinit(void)
{                                                                        // Initialization function for OpenGL
    glClearColor(1.0, 1.0, 1.0, 0.0);                                    // Set background color to white
    glColor3f(0.0f, 0.0f, 0.0f);                                         // Set drawing color to black
    glPointSize(2.0);                                                    // Set point size
    glMatrixMode(GL_PROJECTION);                                         // Set projection matrix mode
    glLoadIdentity();                                                    // Load the identity matrix
    gluOrtho2D(0.0, (GLdouble)screenwidth, 0.0, (GLdouble)screenheight); // Set up 2D orthographic viewing
    glViewport(0, 0, screenwidth, screenheight);                         // Set the viewport to screen dimensions
}

void mydisplay(void)
{                                 // Display function to render the scene
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer
    glColor3f(0.0f, 0.0f, 0.0f);  // Set drawing color to black

    for (int i = 0; i < numdinosaurs; i++)
    {                   // Loop through to position and draw each dinosaur in the circle
        glPushMatrix(); // Save the current transformation matrix

        float angle = (360.0 / numdinosaurs) * i; // Calculate angle for each dinosaur
        glTranslatef(screenwidth / 2.0 + circleradius * cos(angle * 3.142 / 180.0),
                     screenheight / 2.0 + circleradius * sin(angle * 3.142 / 180.0), 0); // Translate to circle position
        glScalef(0.1, 0.1, 0.1);                                                         // Scale down the dinosaur

        glRotatef(angle - 90, 0, 0, 1);    // Rotate dinosaur to align towards circle center
        glTranslatef(0, 50, 0);            // Translate dinosaur along Y-axis to adjust position
        glRotatef(-(angle - 90), 0, 0, 1); // Rotate back to align with the circle's tangent

        drawdinosaur("dino.dat"); // Call function to draw the dinosaur
        glPopMatrix();            // Restore the previous transformation matrix
    }

    glutSwapBuffers(); // Swap buffers to display the rendered scene
}

int main(int argc, char **argv)
{                                                  // Main function
    glutInit(&argc, argv);                         // Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);   // Set display mode to double buffer and RGB
    glutInitWindowSize(screenwidth, screenheight); // Set initial window size
    glutInitWindowPosition(10, 10);                // Set initial window position
    glutCreateWindow("dinosaur circle");           // Create window with title
    glutDisplayFunc(mydisplay);                    // Set display callback function
    myinit();                                      // Call initialization function
    glutMainLoop();                                // Enter GLUT main loop
    return 1;                                      // Return with exit status 1
}
