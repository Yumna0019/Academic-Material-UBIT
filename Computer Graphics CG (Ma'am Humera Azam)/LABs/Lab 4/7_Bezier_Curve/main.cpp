#include <GL/glut.h> // Include the GLUT header for OpenGL utilities
#include <cmath>     // Include the cmath header for mathematical functions

// Control points for the Bézier curve
float ctrlPoints[4][2] = {
    {-80.0f, -80.0f}, // Start point
    {-30.0f, 100.0f}, // Control point 1
    {30.0f, -100.0f}, // Control point 2
    {80.0f, 80.0f}    // End point
};

// Function to calculate the Bézier curve point at a given t using De Casteljau’s algorithm
void calculateBezierPoint(float t, float &x, float &y)
{
    float u = 1 - t;    // Calculate (1 - t)
    float tt = t * t;   // Calculate t^2
    float uu = u * u;   // Calculate (1 - t)^2
    float uuu = uu * u; // Calculate (1 - t)^3
    float ttt = tt * t; // Calculate t^3

    // Calculate the x-coordinate of the Bézier point using the control points
    x = uuu * ctrlPoints[0][0]          // (1 - t)^3 * P0
        + 3 * uu * t * ctrlPoints[1][0] // 3 * (1 - t)^2 * t * P1
        + 3 * u * tt * ctrlPoints[2][0] // 3 * (1 - t) * t^2 * P2
        + ttt * ctrlPoints[3][0];       // t^3 * P3

    // Calculate the y-coordinate of the Bézier point using the control points
    y = uuu * ctrlPoints[0][1] + 3 * uu * t * ctrlPoints[1][1] + 3 * u * tt * ctrlPoints[2][1] + ttt * ctrlPoints[3][1];
}

// Function to draw the Bézier curve
void drawBezierCurve()
{
    glBegin(GL_LINE_STRIP); // Use GL_LINE_STRIP to draw a continuous curve

    // Loop through values of t from 0 to 1 to draw the curve
    for (float t = 0.0f; t <= 1.0f; t += 0.01f)
    {
        float x, y;                    // Variables to hold the x and y coordinates
        calculateBezierPoint(t, x, y); // Calculate the Bézier point
        glVertex2f(x, y);              // Specify the vertex for the curve
    }

    glEnd(); // End the vertex specification
}

// Function to draw the control points and the connecting lines
void drawControlPoints()
{
    // Draw lines connecting control points
    glColor3f(0.8f, 0.8f, 0.8f); // Set color to gray
    glBegin(GL_LINE_STRIP);      // Start drawing lines
    for (int i = 0; i < 4; i++)
    {                                                   // Loop through all control points
        glVertex2f(ctrlPoints[i][0], ctrlPoints[i][1]); // Specify the vertex for each control point
    }
    glEnd(); // End the line drawing

    // Draw control points as small squares
    glColor3f(1.0f, 0.0f, 0.0f); // Set color to red
    glPointSize(5.0f);           // Set the point size for control points
    glBegin(GL_POINTS);          // Start drawing points
    for (int i = 0; i < 4; i++)
    {                                                   // Loop through all control points
        glVertex2f(ctrlPoints[i][0], ctrlPoints[i][1]); // Specify the vertex for each control point
    }
    glEnd(); // End the point drawing
}

// Display function
void display()
{
    // Clear the screen with a white background
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

    // Draw the control points and the lines connecting them
    drawControlPoints(); // Call the function to draw control points

    // Draw the Bézier curve in blue
    glColor3f(0.0f, 0.0f, 1.0f); // Set color to blue
    drawBezierCurve();           // Call the function to draw the Bézier curve

    // Flush the drawing to the screen
    glFlush(); // Ensure all OpenGL commands are executed
}

// Initialization function
void init()
{
    // Set the background color to white
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set the clear color to white

    // Set up the projection (orthographic projection in this case)
    glMatrixMode(GL_PROJECTION);              // Switch to projection matrix
    glLoadIdentity();                         // Load the identity matrix
    gluOrtho2D(-100.0, 100.0, -100.0, 100.0); // Set the visible area in 2D

    // Switch to model view matrix
    glMatrixMode(GL_MODELVIEW); // Switch to model view matrix
    glLoadIdentity();           // Load the identity matrix
}

int main(int argc, char **argv)
{
    // Initialize GLUT
    glutInit(&argc, argv);                       // Initialize GLUT with command line arguments
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set the display mode to single buffering and RGB color
    glutInitWindowSize(500, 500);                // Set the window size to 500x500 pixels
    glutCreateWindow("Bezier Curve");            // Create the window with a title

    // Call the initialization function
    init(); // Initialize the OpenGL settings

    // Register the display callback function
    glutDisplayFunc(display); // Register the display function to be called on window refresh

    // Enter the GLUT main loop
    glutMainLoop(); // Start the GLUT event processing loop
    return 0;       // Return success
}
