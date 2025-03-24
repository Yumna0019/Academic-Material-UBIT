#include <GL/glut.h> // Include the GLUT library for OpenGL utilities
#include <cmath>     // Include cmath library for mathematical functions

// Global Variables
float carPosition = -1.0f; // Initial car position on the screen
float carSpeed = 0.0f;     // Initial speed of the car, set to 0 for now

// Function to draw buildings in the background
void drawBuildings()
{
    // Draw big building on the left
    glColor3f(0.5f, 0.5f, 0.5f); // Set color to gray
    glBegin(GL_POLYGON);         // Begin drawing a polygon
    glVertex2f(-0.8f, -0.5f);    // Bottom-left corner
    glVertex2f(-0.5f, -0.5f);    // Bottom-right corner
    glVertex2f(-0.5f, 0.2f);     // Top-right corner
    glVertex2f(-0.8f, 0.2f);     // Top-left corner
    glEnd();                     // End drawing

    // Draw big building on the right
    glBegin(GL_POLYGON);
    glVertex2f(0.3f, -0.5f);
    glVertex2f(0.6f, -0.5f);
    glVertex2f(0.6f, 0.3f);
    glVertex2f(0.3f, 0.3f);
    glEnd();

    // Draw small building in the center
    glColor3f(0.7f, 0.7f, 0.7f); // Lighter gray color
    glBegin(GL_POLYGON);
    glVertex2f(-0.2f, -0.5f);
    glVertex2f(0.1f, -0.5f);
    glVertex2f(0.1f, 0.1f);
    glVertex2f(-0.2f, 0.1f);
    glEnd();

    // Draw another small building on the far right
    glBegin(GL_POLYGON);
    glVertex2f(0.7f, -0.5f);
    glVertex2f(0.9f, -0.5f);
    glVertex2f(0.9f, 0.2f);
    glVertex2f(0.7f, 0.2f);
    glEnd();
}

// Function to draw the road
void drawRoad()
{
    glColor3f(0.3f, 0.3f, 0.3f); // Set color to dark gray
    glBegin(GL_POLYGON);         // Begin drawing the road polygon
    glVertex2f(-1.0f, -0.9f);    // Bottom-left corner
    glVertex2f(1.0f, -0.9f);     // Bottom-right corner
    glVertex2f(1.0f, -0.5f);     // Top-right corner
    glVertex2f(-1.0f, -0.5f);    // Top-left corner
    glEnd();

    // Draw white road divider lines
    glColor3f(1.0f, 1.0f, 1.0f); // Set color to white
    for (float i = -1.0f; i < 1.0f; i += 0.3f)
    { // Loop for multiple lines
        glBegin(GL_POLYGON);
        glVertex2f(i, -0.7f);
        glVertex2f(i + 0.15f, -0.7f);
        glVertex2f(i + 0.15f, -0.71f);
        glVertex2f(i, -0.71f);
        glEnd();
    }
}

// Function to draw the main body of the car
void drawBody()
{
    glColor3f(1.0f, 0.0f, 0.0f); // Set color to red
    glBegin(GL_POLYGON);
    glVertex2f(-0.1f, 0.0f);  // Bottom-left corner of the body
    glVertex2f(0.1f, 0.0f);   // Bottom-right corner
    glVertex2f(0.1f, 0.05f);  // Top-right corner
    glVertex2f(-0.1f, 0.05f); // Top-left corner
    glEnd();
}

// Function to draw the roof of the car
void drawRoof()
{
    glBegin(GL_POLYGON);
    glVertex2f(-0.05f, 0.05f); // Bottom-left corner of the roof
    glVertex2f(0.05f, 0.05f);  // Bottom-right corner
    glVertex2f(0.03f, 0.1f);   // Top-right corner
    glVertex2f(-0.03f, 0.1f);  // Top-left corner
    glEnd();
}

// Function to draw the door handles on the car
void drawHandles()
{
    glColor3f(0.0f, 0.0f, 0.0f); // Set color to black for handles
    glBegin(GL_POLYGON);
    glVertex2f(-0.04f, 0.02f); // Bottom-left corner of the handle
    glVertex2f(0.04f, 0.02f);  // Bottom-right corner
    glVertex2f(0.04f, 0.04f);  // Top-right corner
    glVertex2f(-0.04f, 0.04f); // Top-left corner
    glEnd();
}

// Function to draw a single tyre at given position and radius
void drawTyre(float x, float y, float radius)
{
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {                                                                 // Loop to create circular shape
        float theta = i * 3.14159f / 180.0f;                          // Convert angle to radians
        glVertex2f(radius * cos(theta) + x, radius * sin(theta) + y); // Calculate x, y
    }
    glEnd();
}

// Function to draw the entire car
void drawCar()
{
    glPushMatrix();                         // Save the current matrix
    glTranslatef(carPosition, -0.7f, 0.0f); // Move car to initial position on the road
    glPushMatrix();                         // Save the car's position

    drawBody(); // Draw car body
    drawRoof(); // Draw car roof

    glPushMatrix();
    glTranslatef(0, 0.05f, 0); // Move up for door handles
    drawHandles();             // Draw door handles
    glPopMatrix();             // Restore to car roof position

    glPushMatrix();
    glTranslatef(-0.07f, -0.02f, 0); // Move to left tyre position
    drawTyre(0.0f, 0.0f, 0.05f);     // Draw left tyre
    glPopMatrix();                   // Restore to car body position

    glPushMatrix();
    glTranslatef(0.07f, -0.02f, 0); // Move to right tyre position
    drawTyre(0.0f, 0.0f, 0.05f);    // Draw right tyre
    glPopMatrix();                  // Restore to car body position

    glPopMatrix(); // Restore to original position
}

// Display function to render objects on the screen
void display()
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear the screen
    glLoadIdentity();             // Reset transformations

    drawBuildings(); // Draw the buildings in the background
    drawRoad();      // Draw the road in front of buildings
    drawCar();       // Draw the car on the road

    glutSwapBuffers(); // Swap buffers to display the scene
}

// Update function to animate car movement
void update(int value)
{
    carPosition += carSpeed; // Update car position by speed

    if (carPosition > 1.2f)
    { // Reset car position if it goes off screen
        carPosition = -1.2f;
    }

    glutPostRedisplay();          // Request a redisplay to animate
    glutTimerFunc(16, update, 0); // Set update to be called again after 16 ms
}

// Menu function to handle menu options
void menu(int option)
{
    switch (option)
    {
    case 1:                // Start car movement
        carSpeed = 0.005f; // Set speed to start moving
        break;
    case 2: // Restart car position
        carPosition = -1.0f;
        carSpeed = 0.005f;
        break;
    case 3: // Exit the program
        exit(0);
        break;
    }
}

// Initialize OpenGL settings
void init()
{
    glClearColor(0.529f, 0.808f, 0.922f, 1.0f); // Set background color to sky blue
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // Set up orthographic projection
}

// Main function to start GLUT application
int main(int argc, char **argv)
{
    glutInit(&argc, argv);                       // Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // Use double buffering and RGB mode
    glutInitWindowSize(800, 600);                // Set window size
    glutCreateWindow("Moving Car");              // Create a window with title

    init(); // Call init function for settings

    glutCreateMenu(menu); // Create right-click menu
    glutAddMenuEntry("Start", 1);
    glutAddMenuEntry("Restart", 2);
    glutAddMenuEntry("Exit", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON); // Attach menu to right mouse button

    glutDisplayFunc(display);     // Set display callback
    glutTimerFunc(16, update, 0); // Set timer for animation

    glutMainLoop(); // Start the main loop
    return 0;
}
