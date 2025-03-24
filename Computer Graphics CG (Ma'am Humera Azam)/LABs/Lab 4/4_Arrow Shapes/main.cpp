#include <GL/glut.h> // Include the GLUT header for OpenGL Utility Toolkit
#include <cmath>     // Include the cmath header for mathematical functions

// Structure to represent a point
struct Point2
{
    float x, y; // Coordinates of the point
    // Constructor to initialize the point
    Point2(float x, float y) : x(x), y(y) {}
};

// Function to draw an arc
void drawArc(Point2 center, float radius, float startAngle, float sweep)
{
    const int n = 30;                             // number of intermediate segments in the arc
    float angle = startAngle * M_PI / 180.0f;     // Convert start angle to radians
    float angleInc = sweep * M_PI / (180.0f * n); // Calculate angle increment for each segment
    float cx = center.x, cy = center.y;           // Get the center coordinates

    glBegin(GL_LINE_STRIP); // Begin drawing the arc using line strips
    for (int k = 0; k <= n; k++, angle += angleInc)
    {                                                                   // Loop through segments to calculate points on the arc
        glVertex2f(cx + radius * cos(angle), cy + radius * sin(angle)); // Calculate and specify vertex position
    }
    glEnd(); // End drawing the arc
}

// Function to draw a line
void drawLine(float x1, float y1, float x2, float y2)
{
    glBegin(GL_LINES);  // Begin drawing lines
    glVertex2f(x1, y1); // Specify the first endpoint of the line
    glVertex2f(x2, y2); // Specify the second endpoint of the line
    glEnd();            // End drawing the lines
}

// Function to draw horizontal lines
void drawHorizontalLines(float y, int numLines, float lineWidth)
{
    glBegin(GL_LINES); // Begin drawing lines
    for (int i = 0; i < numLines; i++)
    {                                      // Loop to create multiple horizontal lines
        float xStart = -47.0f;             // Starting x-coordinate for each line
        glVertex2f(xStart, y);             // Specify the start point of the line
        glVertex2f(xStart + lineWidth, y); // Specify the end point of the line
        y += 45.0f;                        // Adjust y-coordinate for the next horizontal line
    }
    glEnd(); // End drawing the lines
}

// Display function
void display()
{
    // Clear the screen with a white background
    glClear(GL_COLOR_BUFFER_BIT);

    // Set color to blue
    glColor3f(0.0, 0.0, 1.0);
    // Draw an arc centered at (0, 0) with a radius of 50
    drawArc(Point2(0.0f, 0.0f), 50.0f, 20.0f, 140.0f); // Start at 20 degrees, sweep 140 degrees

    // Calculate points on the arc for vertical lines
    float endX = 50.0f * cos((20.0f + 140.0f) * M_PI / 180.0f); // Calculate x-coordinate for end point
    float endY = 50.0f * sin((20.0f + 140.0f) * M_PI / 180.0f); // Calculate y-coordinate for end point

    float startX = 50.0f * cos(20.0f * M_PI / 180.0f); // Calculate x-coordinate for start point
    float startY = 50.0f * sin(20.0f * M_PI / 180.0f); // Calculate y-coordinate for start point

    float midX = 50.0f * cos(90.0f * M_PI / 180.0f); // Calculate x-coordinate for midpoint
    float midY = 50.0f * sin(90.0f * M_PI / 180.0f); // Calculate y-coordinate for midpoint

    // Set line color to blue
    glColor3f(0.0, 0.0, 1.0);
    // Draw vertical lines from points on the arc
    drawLine(endX, endY, endX, -50.0f);       // Draw line from end point to y = -50
    drawLine(startX, startY, startX, -50.0f); // Draw line from start point to y = -50
    drawLine(midX, midY, midX, -50.0f);       // Draw line from midpoint to y = -50

    // Draw horizontal lines starting at the midX position
    drawHorizontalLines(-50.0f, 2, 94.0f); // Draw 2 horizontal lines at y = -50 with specified width

    // Flush the drawing to the screen
    glFlush();
}

// Initialization function
void init()
{
    // Set the background color to white
    glClearColor(1.0, 1.0, 1.0, 1.0);

    // Set up the projection (orthographic projection in this case)
    glMatrixMode(GL_PROJECTION);              // Switch to projection matrix
    glLoadIdentity();                         // Load the identity matrix
    gluOrtho2D(-100.0, 100.0, -100.0, 100.0); // Set the visible area for the projection

    // Switch to model view matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity(); // Load the identity matrix for model view
}

int main(int argc, char **argv)
{
    // Initialize GLUT
    glutInit(&argc, argv);                       // Initialize the GLUT library
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode to single buffer and RGB
    glutInitWindowSize(500, 500);                // Set the window size
    glutCreateWindow("Draw Horizontal Arc");     // Create the window with a title

    // Call the initialization function
    init();

    // Register the display callback function
    glutDisplayFunc(display); // Set the display function to be called when the window needs to be redrawn

    // Enter the GLUT main loop
    glutMainLoop(); // Start the main loop, awaiting events
    return 0;       // Return from main function
}
