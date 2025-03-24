#include <GL/glut.h> // Include OpenGL Utility Toolkit library
#include <cmath>     // Include cmath for mathematical functions

// Structure to represent a point in 2D space
struct Point2
{
    float x, y;                              // Coordinates of the point
    Point2(float x, float y) : x(x), y(y) {} // Constructor to initialize point coordinates
};

// Function to draw an arc
void drawArc(Point2 center, float radius, float startAngle, float sweep)
{
    // startAngle and sweep are in degrees
    const int n = 30;                             // Number of intermediate segments to approximate the arc
    float angle = startAngle * M_PI / 180.0f;     // Convert initial angle from degrees to radians
    float angleInc = sweep * M_PI / (180.0f * n); // Calculate the angle increment for each segment
    float cx = center.x, cy = center.y;           // Extract the center coordinates

    glBegin(GL_LINE_STRIP); // Begin drawing the arc as a series of connected line segments
    for (int k = 0; k <= n; k++, angle += angleInc)
    {
        // Calculate the vertex position for the current angle and add it to the arc
        glVertex2f(cx + radius * cos(angle), cy + radius * sin(angle));
    }
    glEnd(); // End drawing the arc
}

// Display function for rendering the scene
void display()
{
    // Clear the screen with a white background
    glClear(GL_COLOR_BUFFER_BIT);

    // Set the arc color to red
    glColor3f(1.0, 0.0, 0.0);
    // Draw a quarter-circle arc centered at (0, 0) with a radius of 50
    drawArc(Point2(0.0f, 0.0f), 50.0f, 0.0f, 90.0f); // Start at 0 degrees, end at 90 degrees

    // Flush the drawing to the screen
    glFlush();
}

// Initialization function to set up the OpenGL environment
void init()
{
    // Set the background color to white
    glClearColor(1.0, 1.0, 1.0, 1.0);

    // Set up the projection (orthographic projection in this case)
    glMatrixMode(GL_PROJECTION);              // Switch to projection matrix mode
    glLoadIdentity();                         // Load the identity matrix to reset transformations
    gluOrtho2D(-100.0, 100.0, -100.0, 100.0); // Set the visible area (2D orthographic projection)

    // Switch to model view matrix for subsequent transformations
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity(); // Load the identity matrix to reset transformations
}

int main(int argc, char **argv)
{
    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode to single-buffered and RGB color mode
    glutInitWindowSize(500, 500);                // Set the window size
    glutCreateWindow("Draw Arc");                // Create the window with a title

    // Call the initialization function to set up OpenGL
    init();

    // Register the display callback function to render the scene
    glutDisplayFunc(display);

    // Enter the GLUT main loop to handle events and render continuously
    glutMainLoop();
    return 0; // Exit the program
}
