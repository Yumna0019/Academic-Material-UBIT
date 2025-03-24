#include <GL/glut.h> // Include the GLUT library for OpenGL functions
#include <cmath>     // Include cmath for mathematical calculations

float turtle_x = 0.0f;     // Initialize turtle's x position
float turtle_y = 0.0f;     // Initialize turtle's y position
float turtle_angle = 0.0f; // Initialize turtle's angle (direction)

void forward(float length, int draw) // Function to move turtle forward by a specified length
{
    float angle_radians = turtle_angle * (M_PI / 180.0f); // Convert angle to radians
    float delta_x = length * cos(angle_radians);          // Calculate x displacement
    float delta_y = length * sin(angle_radians);          // Calculate y displacement

    float new_x = turtle_x + delta_x; // Calculate new x position
    float new_y = turtle_y + delta_y; // Calculate new y position

    if (draw) // If drawing is enabled
    {
        glBegin(GL_LINES);              // Start drawing a line
        glVertex2f(turtle_x, turtle_y); // Set starting point of line
        glVertex2f(new_x, new_y);       // Set ending point of line
        glEnd();                        // End line drawing
    }

    turtle_x = new_x; // Update turtle's x position
    turtle_y = new_y; // Update turtle's y position
}

void moveTo(float x, float y) // Function to move turtle to a specified location
{
    turtle_x = x; // Set turtle's x position
    turtle_y = y; // Set turtle's y position
}

void turn(float angle) // Function to turn turtle by a specified angle
{
    turtle_angle += angle; // Adjust turtle's angle by the specified amount
}

void flakeMotif(float L) // Function to draw a motif of the snowflake
{
    glPushMatrix();       // Save the current transformation matrix
    moveTo(0.0, 0.1 * L); // Move turtle to starting position
    turn(0);              // Set initial angle to 0
    forward(2 * L, 1);    // Move forward and draw a line of length 2 * L
    turn(60);             // Turn turtle by 60 degrees
    forward(1 * L, 1);    // Draw a line of length L
    turn(270);            // Turn turtle by 270 degrees
    forward(0.2 * L, 1);  // Draw a short line
    turn(270);            // Turn turtle by 270 degrees
    forward(0.9 * L, 1);  // Draw a line of length 0.9 * L
    turn(120);            // Turn turtle by 120 degrees
    forward(1 * L, 1);    // Draw a line of length L
    turn(60);             // Turn turtle by 60 degrees
    forward(0.9 * L, 1);  // Draw a line of length 0.9 * L
    turn(270);            // Turn turtle by 270 degrees
    forward(0.2 * L, 1);  // Draw a short line
    turn(270);            // Turn turtle by 270 degrees
    forward(0.8 * L, 1);  // Draw a line of length 0.8 * L
    turn(120);            // Turn turtle by 120 degrees
    forward(1 * L, 1);    // Draw a line of length L
    turn(330);            // Turn turtle by 330 degrees
    forward(0.2 * L, 1);  // Draw a short line
    turn(30);             // Turn turtle by 30 degrees
    glPopMatrix();        // Restore the previous transformation matrix
}

void drawFlake() // Function to draw the complete snowflake by repeating motifs
{
    for (int i = 0; i < 6; i++) // Loop to create six arms of the flake
    {
        flakeMotif(10);                 // Draw one motif
        glPushMatrix();                 // Save the current transformation matrix
        glScalef(1.0, -1.0, 1.0);       // Flip the motif vertically
        flakeMotif(10);                 // Draw the flipped motif
        glPopMatrix();                  // Restore the transformation matrix
        glRotatef(60.0, 0.0, 0.0, 1.0); // Rotate by 60 degrees for the next arm
    }
}

void display() // Display callback function to render the scene
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
    glColor3f(1, 1, 1);                                 // Set drawing color to white
    drawFlake();                                        // Draw the snowflake
    glutSwapBuffers();                                  // Swap the buffers for double buffering
}

const int screenWidth = 640;  // Set screen width
const int screenHeight = 480; // Set screen height
void myInit(void)             // Initialization function
{
    glViewport(0, 0, screenWidth, screenHeight);                                        // Set viewport to match window size
    glMatrixMode(GL_PROJECTION);                                                        // Switch to projection matrix mode
    glPointSize(2.0);                                                                   // Set point size
    glLoadIdentity();                                                                   // Reset projection matrix
    gluOrtho2D(-screenWidth / 2, screenWidth / 2, -screenHeight / 2, screenHeight / 2); // Set orthographic projection
    glMatrixMode(GL_MODELVIEW);                                                         // Switch to modelview matrix mode
}

int main(int argc, char **argv) // Main function
{
    glutInit(&argc, argv);                             // Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);       // Set display mode to double buffer and RGB color
    glutInitWindowSize(800, 600);                      // Set initial window size
    glutCreateWindow("Drawing Turtle Figures part a"); // Create window with title
    glutDisplayFunc(display);                          // Register display callback function
    myInit();                                          // Call initialization function
    glutMainLoop();                                    // Enter the GLUT main loop
    return 0;                                          // Exit program
}
