#include <GL/glut.h> // Include OpenGL Utility Toolkit (GLUT) library for OpenGL functions
#include <vector>    // Include vector library for dynamic arrays
#include <cmath>     // Include math library for mathematical functions
#include <iostream>  // Include standard input/output stream library

using namespace std; // Use standard namespace to avoid prefixing standard functions

// Structure to represent a point in 2D space
struct Point
{
    float x, y; // Coordinates of the point
};

// List of polylines where each polyline is a vector of points
vector<vector<Point>> polylines; // Vector to hold multiple polylines
int currentPolyline = -1;        // Index of the currently active polyline
bool dragging = false;           // Flag to check if a point is being dragged
int dragIndex = -1;              // Index of the point being dragged

// Screen dimensions
const int WINDOW_WIDTH = 800;  // Width of the window
const int WINDOW_HEIGHT = 600; // Height of the window

// Function to draw a polyline
void drawPolyline(const vector<Point> &polyline)
{
    glBegin(GL_LINE_STRIP); // Begin drawing a series of connected lines
    for (const auto &p : polyline)
    {                         // Loop through each point in the polyline
        glVertex2f(p.x, p.y); // Specify the vertex at the point's coordinates
    }
    glEnd(); // End drawing
}

// Function to display the scene
void display()
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer to prepare for drawing

    // Draw all polylines
    for (const auto &polyline : polylines)
    {
        drawPolyline(polyline); // Draw each polyline in the list
    }

    glutSwapBuffers(); // Swap the front and back buffers to display the rendered scene
}

// Function to handle mouse input
void mouse(int button, int state, int x, int y)
{
    // Convert mouse coordinates from pixel to normalized device coordinates
    float mx = (x - WINDOW_WIDTH / 2.0f) / (WINDOW_WIDTH / 2.0f);
    float my = (WINDOW_HEIGHT / 2.0f - y) / (WINDOW_HEIGHT / 2.0f);

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    { // If the left mouse button is pressed
        if (dragging)
        { // If currently dragging a point
            // Check if clicking on an existing point
            float minDist = 0.05f; // Minimum distance to consider for dragging
            for (size_t i = 0; i < polylines[currentPolyline].size(); ++i)
            {                                                                    // Loop through points
                float dist = sqrt(pow(polylines[currentPolyline][i].x - mx, 2) + // Calculate distance
                                  pow(polylines[currentPolyline][i].y - my, 2));
                if (dist < minDist)
                {                  // If the distance is within the minimum distance
                    dragIndex = i; // Set the index of the dragged point
                    break;         // Exit the loop
                }
            }
        }
        else
        { // If not currently dragging
            if (currentPolyline == -1)
            { // If no polyline is active
                // Start a new polyline
                polylines.push_back(vector<Point>{{mx, my}}); // Create a new polyline with the starting point
                currentPolyline = polylines.size() - 1;       // Set current polyline to the new one
            }
            else
            { // If an active polyline exists
                // Add a point to the current polyline
                polylines[currentPolyline].push_back({mx, my}); // Add the new point to the current polyline
            }
        }
    }

    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && dragging)
    {                     // If the left button is released while dragging
        dragging = false; // Stop dragging
        dragIndex = -1;   // Reset drag index
    }

    glutPostRedisplay(); // Request a redraw of the scene
}

// Function to handle mouse motion while dragging
void motion(int x, int y)
{
    if (dragging && dragIndex != -1 && currentPolyline != -1)
    { // If dragging is active and a valid point is selected
        // Convert mouse coordinates from pixel to normalized device coordinates
        float mx = (x - WINDOW_WIDTH / 2.0f) / (WINDOW_WIDTH / 2.0f);
        float my = (WINDOW_HEIGHT / 2.0f - y) / (WINDOW_HEIGHT / 2.0f);

        // Update the position of the dragged point
        polylines[currentPolyline][dragIndex].x = mx; // Update x coordinate of the dragged point
        polylines[currentPolyline][dragIndex].y = my; // Update y coordinate of the dragged point

        glutPostRedisplay(); // Request a redraw of the scene
    }
}

// Function to handle keyboard input
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'b': // If 'b' is pressed
        // Begin a new polyline
        currentPolyline = -1; // Reset current polyline index
        break;
    case 'd': // If 'd' is pressed
        if (currentPolyline != -1 && !polylines[currentPolyline].empty())
        {                            // If there is an active polyline
            float minDist = 0.05f;   // Minimum distance for point selection
            size_t deleteIndex = -1; // Index of the point to delete

            // Find the closest point
            float mx = (x - WINDOW_WIDTH / 2.0f) / (WINDOW_WIDTH / 2.0f);   // Convert mouse x coordinate
            float my = (WINDOW_HEIGHT / 2.0f - y) / (WINDOW_HEIGHT / 2.0f); // Convert mouse y coordinate
            for (size_t i = 0; i < polylines[currentPolyline].size(); ++i)
            {                                                                    // Loop through points in polyline
                float dist = sqrt(pow(polylines[currentPolyline][i].x - mx, 2) + // Calculate distance to each point
                                  pow(polylines[currentPolyline][i].y - my, 2));
                if (dist < minDist)
                {                    // If within minimum distance
                    minDist = dist;  // Update minimum distance
                    deleteIndex = i; // Set index to delete
                }
            }

            // Remove the point and reconnect the line
            if (deleteIndex != -1 && polylines[currentPolyline].size() > 1)
            {                                                                                       // If a valid point to delete exists
                polylines[currentPolyline].erase(polylines[currentPolyline].begin() + deleteIndex); // Remove the point from polyline
            }
        }
        break;
    case 'm': // If 'm' is pressed
        // Enable dragging
        dragging = true; // Set dragging flag to true
        break;
    case 'q':    // If 'q' is pressed
        exit(0); // Exit the program
        break;
    default:
        break; // Do nothing for other keys
    }
}

// Initialize OpenGL settings
void initGL()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);         // Set clear color to white
    glColor3f(0.0, 0.0, 0.0);                 // Set drawing color to black
    glLineWidth(2.0);                         // Set line width for drawing
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); // Set orthographic projection matrix
}

// Main function
int main(int argc, char **argv)
{
    glutInit(&argc, argv);                           // Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);     // Set display mode to double buffer and RGB color
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT); // Set the window size
    glutCreateWindow("Polyline Editor");             // Create a window with the specified title

    initGL(); // Initialize OpenGL settings

    glutDisplayFunc(display);   // Register display callback function
    glutMouseFunc(mouse);       // Register mouse callback function
    glutMotionFunc(motion);     // Register mouse motion callback function
    glutKeyboardFunc(keyboard); // Register keyboard callback function

    glutMainLoop(); // Enter the event-processing loop
    return 0;       // Return success
}
