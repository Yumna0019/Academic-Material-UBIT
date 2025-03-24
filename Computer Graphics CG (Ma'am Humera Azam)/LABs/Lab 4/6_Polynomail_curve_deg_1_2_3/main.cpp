#include <GL/glut.h> // Include the GLUT library for OpenGL
#include <cmath>     // Include the cmath library for mathematical functions

// Coefficients for each polynomial equation
// Degree 1: y = ax + b
float a1 = 0.5f;  // Coefficient 'a' for the linear equation
float b1 = -2.0f; // Coefficient 'b' for the linear equation

// Degree 2: y = ax^2 + bx + c
float a2 = 0.01f; // Coefficient 'a' for the quadratic equation
float b2 = -0.1f; // Coefficient 'b' for the quadratic equation
float c2 = -1.0f; // Coefficient 'c' for the quadratic equation

// Degree 3: y = ax^3 + bx^2 + cx + d
float a3 = 0.001f; // Coefficient 'a' for the cubic equation
float b3 = 0.02f;  // Coefficient 'b' for the cubic equation
float c3 = -0.1f;  // Coefficient 'c' for the cubic equation
float d3 = 0.5f;   // Coefficient 'd' for the cubic equation

// Function to calculate the y-value for a linear polynomial
float linearPolynomial(float x)
{
    return a1 * x + b1; // Calculate y using the linear polynomial formula
}

// Function to calculate the y-value for a quadratic polynomial
float quadraticPolynomial(float x)
{
    return a2 * x * x + b2 * x + c2; // Calculate y using the quadratic polynomial formula
}

// Function to calculate the y-value for a cubic polynomial
float cubicPolynomial(float x)
{
    return a3 * x * x * x + b3 * x * x + c3 * x + d3; // Calculate y using the cubic polynomial formula
}

// Function to draw the polynomial curve
void drawPolynomialCurve(float (*polynomialFunction)(float))
{
    glBegin(GL_LINE_STRIP); // Use GL_LINE_STRIP to draw a continuous curve

    // Iterate over x values from -10.0 to 10.0
    for (float x = -10.0f; x <= 10.0f; x += 0.1f)
    {
        float y = polynomialFunction(x); // Calculate y using the provided polynomial function
        glVertex2f(x, y);                // Specify the vertex at (x, y)
    }

    glEnd(); // End the drawing of the curve
}

// Function to draw reference lines (horizontal and vertical axes)
void drawReferenceLines()
{
    glBegin(GL_LINES); // Begin drawing lines

    // Draw horizontal line (x-axis)
    glVertex2f(-10.0f, 0.0f); // Starting point of x-axis
    glVertex2f(10.0f, 0.0f);  // Ending point of x-axis

    // Draw vertical line (y-axis)
    glVertex2f(0.0f, -10.0f); // Starting point of y-axis
    glVertex2f(0.0f, 10.0f);  // Ending point of y-axis

    glEnd(); // End drawing the lines
}

// Display function
void display()
{
    // Clear the screen with a white background
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw reference lines (axes) in black
    glColor3f(0.0, 0.0, 0.0); // Set color to black
    drawReferenceLines();     // Draw the axes

    // Draw the Degree 1 (Linear) curve in red
    glColor3f(1.0, 0.0, 0.0);              // Set color to red
    drawPolynomialCurve(linearPolynomial); // Draw the linear polynomial curve

    // Draw the Degree 2 (Quadratic) curve in green
    glColor3f(0.0, 1.0, 0.0);                 // Set color to green
    drawPolynomialCurve(quadraticPolynomial); // Draw the quadratic polynomial curve

    // Draw the Degree 3 (Cubic) curve in blue
    glColor3f(0.0, 0.0, 1.0);             // Set color to blue
    drawPolynomialCurve(cubicPolynomial); // Draw the cubic polynomial curve

    // Flush the drawing to the screen
    glFlush();
}

// Initialization function
void init()
{
    // Set the background color to white
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set clear color for the window

    // Set up the projection (orthographic projection in this case)
    glMatrixMode(GL_PROJECTION);          // Switch to projection matrix
    glLoadIdentity();                     // Load the identity matrix
    gluOrtho2D(-10.0, 10.0, -10.0, 10.0); // Set the visible area for the orthographic projection

    // Switch to model view matrix
    glMatrixMode(GL_MODELVIEW); // Switch to model view matrix
    glLoadIdentity();           // Load the identity matrix
}

int main(int argc, char **argv)
{
    // Initialize GLUT
    glutInit(&argc, argv);                                      // Initialize GLUT with command line arguments
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);                // Set display mode to single buffer and RGB
    glutInitWindowSize(500, 500);                               // Set the window size to 500x500 pixels
    glutCreateWindow("Polynomial Curves with Reference Lines"); // Create the window with a title

    // Call the initialization function
    init(); // Perform initialization

    // Register the display callback function
    glutDisplayFunc(display); // Set the display callback function

    // Enter the GLUT main loop
    glutMainLoop(); // Start the GLUT main loop
    return 0;       // Return 0 to indicate successful execution
}
