#include <GL/glut.h> // Include OpenGL Utility Toolkit library
#include <cmath>     // Include cmath for mathematical functions

const int NUMPOINTS = 200; // The number of sample points to use for the parametric function

#define CIRCLE 1 // Define a constant for circle type
#define ROSE 4   // Define a constant for rose curve type

float xmin, xmax, ymin, ymax;               // Variables to store the limits of the curve
float tmin = 0.0, tmax = 2 * M_PI;          // Range of t for the parametric equations
float xArray[NUMPOINTS], yArray[NUMPOINTS]; // Arrays to store x and y coordinates of the curve

// Parametric equation for x(t)
float x(float t)
{
    // Example: Rose curve with 4 petals
    return cos(4 * t) * cos(t);
}

// Parametric equation for y(t)
float y(float t)
{
    // Example: Rose curve with 4 petals
    return cos(4 * t) * sin(t);
}

// Function to compute the points on the curve
void computeCurve()
{
    float dt = (tmax - tmin) / (NUMPOINTS - 1); // Calculate the increment in t

    for (int i = 0; i < NUMPOINTS; i++)
    {                            // Loop to compute points
        float t = tmin + i * dt; // Calculate current t value
        xArray[i] = x(t);        // Compute x-coordinate and store it in xArray
        yArray[i] = y(t);        // Compute y-coordinate and store it in yArray
    }
}

// Function to plot the computed curve
void plotCurve()
{
    glBegin(GL_LINE_STRIP); // Begin drawing a line strip
    for (int i = 0; i < NUMPOINTS; i++)
    {                                     // Loop through all computed points
        glVertex2f(xArray[i], yArray[i]); // Specify the vertex position
    }
    glEnd(); // End drawing the line strip
}

// Display function for rendering the scene
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

    // Set color for drawing the curve
    glColor3f(1.0f, 0.75f, 0.8f); // Set to pink color

    glLineWidth(5.0f); // Set line width for the curve

    // Calculate and store points on curve in an array
    computeCurve();

    // Determine the window limits based on the curve
    xmin = xmax = xArray[0]; // Initialize xmin and xmax with the first x value
    ymin = ymax = yArray[0]; // Initialize ymin and ymax with the first y value
    for (int i = 1; i < NUMPOINTS; i++)
    { // Loop through all points to find limits
        if (xArray[i] < xmin)
            xmin = xArray[i]; // Update xmin if current x is smaller
        if (xArray[i] > xmax)
            xmax = xArray[i]; // Update xmax if current x is larger
        if (yArray[i] < ymin)
            ymin = yArray[i]; // Update ymin if current y is smaller
        if (yArray[i] > ymax)
            ymax = yArray[i]; // Update ymax if current y is larger
    }

    // Set the window limits for the projection
    glMatrixMode(GL_PROJECTION);        // Switch to projection matrix mode
    glLoadIdentity();                   // Load the identity matrix to reset transformations
    gluOrtho2D(xmin, xmax, ymin, ymax); // Set the visible area for 2D orthographic projection

    // Plot the computed curve
    plotCurve();

    glFlush(); // Force drawing to the screen
}

// Function to set the background color
void setBackgroundColor(float r, float g, float b)
{
    glClearColor(r, g, b, 1.0); // Set the clear color for the background
}

// Function to clear the screen
void clearScreen()
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);                       // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode to single-buffered and RGB color mode
    glutInitWindowSize(500, 500);                // Set the window size
    glutCreateWindow("Parametric Curve");        // Create the window with a title
    glutDisplayFunc(display);                    // Register the display callback function
    setBackgroundColor(1, 1, 1);                 // Set background color to white
    glutMainLoop();                              // Enter the GLUT main loop to handle events and render continuously
    return 0;                                    // Exit the program
}
