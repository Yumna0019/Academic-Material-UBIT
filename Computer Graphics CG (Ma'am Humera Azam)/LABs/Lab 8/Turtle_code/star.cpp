#include <GL/glut.h>  // Include the GLUT library
#include <cmath>      // Include cmath for trigonometric functions

float x = 0.0f, y = 0.0f;  // Starting position of the "turtle"
float angle = 0.0f;        // Starting angle (facing right initially)

// Convert degrees to radians
float toRadians(float degrees) {
    return degrees * (M_PI / 180.0f);  // Convert degrees to radians for angle calculations
}

// Move forward in the current direction
void forward(float distance) {
    x += distance * cos(toRadians(angle));  // Update x position based on angle and distance
    y += distance * sin(toRadians(angle));  // Update y position based on angle and distance
    glVertex2f(x, y);  // Plot the point at the new (x, y) coordinates
}

// Turn right by a specific angle
void right(float turnAngle) {
    angle -= turnAngle;  // Decrease the angle for a right turn
}

// Turn left by a specific angle
void left(float turnAngle) {
    angle += turnAngle;  // Increase the angle for a left turn
}

// Draw a star using "forward" and "right" commands
void drawStar(float size) {
    glBegin(GL_LINE_LOOP);  // Begin drawing a line loop for the star's outline
    glColor3f(1.0f, 1.0f, 0.0f);  // Set color to yellow for the star

    for (int i = 0; i < 5; ++i) {  // Loop through 5 points to create the star shape
        forward(size);  // Move forward by size distance
        right(144);     // Turn right by 144 degrees to create star points
    }

    glEnd();  // End drawing
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);  // Clear the display
    glLoadIdentity();              // Reset transformations

    x = 0.0f;  // Reset position to the center
    y = 0.0f;  // Reset y position
    angle = 0.0f;  // Reset angle to initial direction (facing right)

    drawStar(0.5f);  // Draw star with specific size

    glFlush();  // Flush the buffer to display the star
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);                          // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);    // Set single buffering and RGB color mode
    glutInitWindowSize(500, 500);                   // Set window size to 500x500 pixels
    glutCreateWindow("OpenGL Star Drawing");        // Create a window with title

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);           // Set background to black
    glMatrixMode(GL_PROJECTION);                    // Set up projection matrix
    glLoadIdentity();                               // Reset projection matrix
    gluOrtho2D(-1, 1, -1, 1);                       // Set coordinate system

    glutDisplayFunc(display);                       // Register display callback function
    glutMainLoop();                                 // Enter the main event loop
    return 0;                                       // End of program
}
