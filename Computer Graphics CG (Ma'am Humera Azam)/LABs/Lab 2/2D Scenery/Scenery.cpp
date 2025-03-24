#include <iostream>
#include <fstream>
#include <string>
#include <GL/glut.h>

using namespace std;

// Function to draw the chair
void Chair(void)
{
    // Clear the framebuffer with the background color
    glClear(GL_COLOR_BUFFER_BIT);
    // Set the background color to a light gray
    glClearColor(0.9f, 0.9f, 0.9f, 0.0);

    // Drawing the seat of the chair (orange color)
    glColor3f(1.0f, 0.5f, 0.0f); // Set color to orange
    glBegin(GL_POLYGON);
    glVertex2i(29, 30); // Top-left corner of the seat
    glVertex2i(47, 30); // Top-right corner of the seat
    glVertex2i(40, 25); // Bottom-right corner of the seat
    glVertex2i(22, 25); // Bottom-left corner of the seat
    glEnd();

    // Drawing the left chair leg (orange color)
    glColor3f(1.0f, 0.5f, 0.0f); // Set color to orange
    glBegin(GL_POLYGON);
    glVertex2i(29, 30); // Bottom-left corner of the leg
    glVertex2i(29, 44); // Top-left corner of the leg
    glVertex2i(31, 44); // Top-right corner of the leg
    glVertex2i(31, 30); // Bottom-right corner of the leg
    glEnd();

    // Drawing the right chair leg (orange color)
    glColor3f(1.0f, 0.5f, 0.0f); // Set color to orange
    glBegin(GL_POLYGON);
    glVertex2i(45, 44); // Top-left corner of the leg
    glVertex2i(47, 44); // Top-right corner of the leg
    glVertex2i(47, 30); // Bottom-right corner of the leg
    glVertex2i(45, 30); // Bottom-left corner of the leg
    glEnd();

    // Drawing the backrest of the chair (orange color)
    glColor3f(1.0f, 0.5f, 0.0f); // Set color to orange
    glBegin(GL_POLYGON);
    glVertex2i(31, 41); // Bottom-left corner of the backrest
    glVertex2i(45, 41); // Bottom-right corner of the backrest
    glVertex2i(45, 39); // Top-right corner of the backrest
    glVertex2i(31, 39); // Top-left corner of the backrest
    glEnd();

    // Drawing the middle part of the backrest (orange color)
    glColor3f(1.0f, 0.5f, 0.0f); // Set color to orange
    glBegin(GL_POLYGON);
    glVertex2i(31, 36); // Bottom-left corner of the middle part
    glVertex2i(45, 36); // Bottom-right corner of the middle part
    glVertex2i(45, 34); // Top-right corner of the middle part
    glVertex2i(31, 34); // Top-left corner of the middle part
    glEnd();

    // Drawing the left armrest support (brown color)
    glColor3f(0.6f, 0.3f, 0.0f); // Set color to brown
    glBegin(GL_POLYGON);
    glVertex2i(22, 25); // Top-left corner of the support
    glVertex2i(22, 12); // Bottom-left corner of the support
    glVertex2i(24, 12); // Bottom-right corner of the support
    glVertex2i(24, 25); // Top-right corner of the support
    glEnd();

    // Drawing the left armrest (brown color)
    glColor3f(0.6f, 0.3f, 0.0f); // Set color to brown
    glBegin(GL_POLYGON);
    glVertex2i(22, 25); // Bottom-left corner of the armrest
    glVertex2i(24, 23); // Bottom-right corner of the armrest
    glVertex2i(40, 23); // Top-right corner of the armrest
    glVertex2i(40, 25); // Top-left corner of the armrest
    glEnd();

    // Drawing the left lower support of the armrest (brown color)
    glColor3f(0.6f, 0.3f, 0.0f); // Set color to brown
    glBegin(GL_POLYGON);
    glVertex2i(24, 17); // Bottom-left corner of the support
    glVertex2i(29, 19); // Bottom-right corner of the support
    glVertex2i(29, 21); // Top-right corner of the support
    glVertex2i(24, 19); // Top-left corner of the support
    glEnd();

    // Drawing the right armrest support (brown color)
    glColor3f(0.6f, 0.3f, 0.0f); // Set color to brown
    glBegin(GL_POLYGON);
    glVertex2i(47, 30); // Top-right corner of the support
    glVertex2i(47, 17); // Bottom-right corner of the support
    glVertex2i(45, 17); // Bottom-left corner of the support
    glVertex2i(45, 28); // Top-left corner of the support
    glEnd();

    // Drawing the right lower support of the armrest (brown color)
    glColor3f(0.6f, 0.3f, 0.0f); // Set color to brown
    glBegin(GL_POLYGON);
    glVertex2i(38, 12); // Bottom-left corner of the support
    glVertex2i(40, 12); // Bottom-right corner of the support
    glVertex2i(40, 23); // Top-right corner of the support
    glVertex2i(38, 23); // Top-left corner of the support
    glEnd();

    // Drawing the right armrest (brown color)
    glColor3f(0.6f, 0.3f, 0.0f); // Set color to brown
    glBegin(GL_POLYGON);
    glVertex2i(40, 19); // Bottom-left corner of the armrest
    glVertex2i(45, 21); // Bottom-right corner of the armrest
    glVertex2i(45, 19); // Top-right corner of the armrest
    glVertex2i(40, 17); // Top-left corner of the armrest
    glEnd();

    // Drawing the right upper support of the armrest (brown color)
    glColor3f(0.6f, 0.3f, 0.0f); // Set color to brown
    glBegin(GL_POLYGON);
    glVertex2i(40, 25); // Bottom-left corner of the support
    glVertex2i(40, 23); // Bottom-right corner of the support
    glVertex2i(47, 28); // Top-right corner of the support
    glVertex2i(47, 30); // Top-left corner of the support
    glEnd();

    // Drawing the lower part of the left chair leg (brown color)
    glColor3f(0.6f, 0.3f, 0.0f); // Set color to brown
    glBegin(GL_POLYGON);
    glVertex2i(29, 23); // Bottom-left corner of the leg
    glVertex2i(31, 23); // Bottom-right corner of the leg
    glVertex2i(31, 17); // Top-right corner of the leg
    glVertex2i(29, 17); // Top-left corner of the leg
    glEnd();

    glFlush(); // Sends the drawing to the display screen
}

int screenWidth = 640, screenHeight = 480; // Window size

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Initialize display mode with single buffering and RGB color
    glutInitWindowSize(screenWidth, screenHeight); // Set the window size
    glutInitWindowPosition(30, 30); // Set the window position
    glutCreateWindow("CHAIR"); // Create the window with a title
    gluOrtho2D(0, 100, 0, 100); // Set the orthographic projection to map the 2D space (0,0) to (100,100)
    glutDisplayFunc(Chair); // Register the Chair function as the display callback
    glutMainLoop(); // Enter the GLUT event processing loop
    return 0;
}
