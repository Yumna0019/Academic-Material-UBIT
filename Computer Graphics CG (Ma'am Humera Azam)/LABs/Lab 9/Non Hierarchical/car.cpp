#include <GL/glut.h> // Include the GLUT library
#include <cmath>     // Include the cmath library for mathematical functions

float carPosition = -1.0f; // Initial horizontal position of the car on the screen
float carSpeed = 0.0f;     // Car speed, initially set to 0 for stationary state

// Function to draw buildings in the background
void drawBuildings()
{
    // Draw the first big building
    glColor3f(0.5f, 0.5f, 0.5f); // Set color to gray for building
    glBegin(GL_POLYGON);         // Begin polygon drawing for building shape
    glVertex2f(-0.8f, -0.5f);    // Bottom-left vertex of the building
    glVertex2f(-0.5f, -0.5f);    // Bottom-right vertex
    glVertex2f(-0.5f, 0.2f);     // Top-right vertex
    glVertex2f(-0.8f, 0.2f);     // Top-left vertex
    glEnd();                     // End polygon drawing

    // Draw the second big building
    glBegin(GL_POLYGON);
    glVertex2f(0.3f, -0.5f); // Bottom-left vertex of the building
    glVertex2f(0.6f, -0.5f); // Bottom-right vertex
    glVertex2f(0.6f, 0.3f);  // Top-right vertex
    glVertex2f(0.3f, 0.3f);  // Top-left vertex
    glEnd();

    // Draw the first small building
    glColor3f(0.7f, 0.7f, 0.7f); // Set color to a lighter gray for smaller buildings
    glBegin(GL_POLYGON);
    glVertex2f(-0.2f, -0.5f); // Bottom-left vertex of the building
    glVertex2f(0.1f, -0.5f);  // Bottom-right vertex
    glVertex2f(0.1f, 0.1f);   // Top-right vertex
    glVertex2f(-0.2f, 0.1f);  // Top-left vertex
    glEnd();

    // Draw the second small building
    glBegin(GL_POLYGON);
    glVertex2f(0.7f, -0.5f); // Bottom-left vertex of the building
    glVertex2f(0.9f, -0.5f); // Bottom-right vertex
    glVertex2f(0.9f, 0.2f);  // Top-right vertex
    glVertex2f(0.7f, 0.2f);  // Top-left vertex
    glEnd();
}

// Function to draw the road in the scene
void drawRoad()
{
    glColor3f(0.3f, 0.3f, 0.3f); // Set color to dark gray for the road
    glBegin(GL_POLYGON);         // Begin polygon drawing for the road
    glVertex2f(-1.0f, -0.9f);    // Bottom-left vertex of the road
    glVertex2f(1.0f, -0.9f);     // Bottom-right vertex
    glVertex2f(1.0f, -0.5f);     // Top-right vertex
    glVertex2f(-1.0f, -0.5f);    // Top-left vertex
    glEnd();

    // Draw white road divider lines
    glColor3f(1.0f, 1.0f, 1.0f);               // Set color to white for dividers
    for (float i = -1.0f; i < 1.0f; i += 0.3f) // Loop to draw multiple dividers
    {
        glBegin(GL_POLYGON);           // Begin polygon drawing for each divider line
        glVertex2f(i, -0.7f);          // Bottom-left vertex of divider
        glVertex2f(i + 0.15f, -0.7f);  // Bottom-right vertex of divider
        glVertex2f(i + 0.15f, -0.71f); // Top-right vertex
        glVertex2f(i, -0.71f);         // Top-left vertex
        glEnd();                       // End polygon drawing
    }
}

// Function to draw the moving car
void drawCar()
{
    glPushMatrix();                         // Save the current matrix state
    glTranslatef(carPosition, -0.7f, 0.0f); // Move car horizontally

    // Draw the body of the car
    glColor3f(1.0f, 0.0f, 0.0f); // Set color to red for car body
    glBegin(GL_POLYGON);         // Begin polygon drawing for car body
    glVertex2f(-0.1f, 0.0f);     // Bottom-left vertex of car body
    glVertex2f(0.1f, 0.0f);      // Bottom-right vertex
    glVertex2f(0.1f, 0.05f);     // Top-right vertex
    glVertex2f(-0.1f, 0.05f);    // Top-left vertex
    glEnd();

    // Draw the top part of the car
    glBegin(GL_POLYGON);       // Begin polygon drawing for car top
    glVertex2f(-0.05f, 0.05f); // Bottom-left vertex of car top
    glVertex2f(0.05f, 0.05f);  // Bottom-right vertex
    glVertex2f(0.03f, 0.1f);   // Top-right vertex
    glVertex2f(-0.03f, 0.1f);  // Top-left vertex
    glEnd();

    // Draw the car wheels
    glColor3f(0.0f, 0.0f, 0.0f);  // Set color to black for wheels
    glBegin(GL_POLYGON);          // Begin polygon drawing for left wheel
    for (int i = 0; i < 360; i++) // Loop to create circular shape
    {
        float theta = i * 3.14159f / 180.0f;                                // Convert degrees to radians
        glVertex2f(0.05f * cos(theta) - 0.07f, 0.05f * sin(theta) - 0.02f); // Left wheel position
    }
    glEnd();

    glBegin(GL_POLYGON); // Begin polygon drawing for right wheel
    for (int i = 0; i < 360; i++)
    {
        float theta = i * 3.14159f / 180.0f;
        glVertex2f(0.05f * cos(theta) + 0.07f, 0.05f * sin(theta) - 0.02f); // Right wheel position
    }
    glEnd();

    glPopMatrix(); // Restore the previous matrix state
}

// Display function to render the scene
void display()
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear the screen
    glLoadIdentity();             // Reset transformations

    drawBuildings(); // Draw buildings in the background
    drawRoad();      // Draw the road in front of buildings
    drawCar();       // Draw the car on the road

    glutSwapBuffers(); // Swap buffers to display the updated frame
}

// Update function to animate the car movement
void update(int value)
{
    carPosition += carSpeed; // Update car position based on speed

    // Reset car position to loop back from the start when it goes off-screen
    if (carPosition > 1.2f)
    {
        carPosition = -1.2f; // Reset position to re-enter screen from left
    }

    glutPostRedisplay();          // Request a screen redraw
    glutTimerFunc(16, update, 0); // Call update again after 16 ms (~60 FPS)
}

// Menu handler function to control car speed and state
void menu(int option)
{
    switch (option)
    {
    case 1:                // Start option selected
        carSpeed = 0.005f; // Set car speed to move it
        break;
    case 2:                  // Restart option selected
        carPosition = -1.0f; // Reset car position
        carSpeed = 0.005f;   // Set speed to restart car movement
        break;
    case 3:      // Exit option selected
        exit(0); // Exit the program
        break;
    }
}

// Initialization function to set up OpenGL settings
void init()
{
    glClearColor(0.529f, 0.808f, 0.922f, 1.0f); // Set sky blue background color
    glMatrixMode(GL_PROJECTION);                // Set projection mode
    glLoadIdentity();                           // Reset projection matrix
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);           // Set orthogonal view
}

// Main function to set up the window and event loop
int main(int argc, char **argv)
{
    glutInit(&argc, argv);                       // Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // Set display mode
    glutInitWindowSize(600, 600);                // Set window size
    glutCreateWindow("Moving Car Animation");    // Create window with title

    init(); // Call initialization function

    glutCreateMenu(menu);              // Create menu
    glutAddMenuEntry("Start", 1);      // Add start option to menu
    glutAddMenuEntry("Restart", 2);    // Add restart option to menu
    glutAddMenuEntry("Exit", 3);       // Add exit option to menu
    glutAttachMenu(GLUT_RIGHT_BUTTON); // Attach menu to right mouse button

    glutDisplayFunc(display);     // Set display callback
    glutTimerFunc(16, update, 0); // Set update callback for animation

    glutMainLoop(); // Start the main event loop
    return 0;
}
