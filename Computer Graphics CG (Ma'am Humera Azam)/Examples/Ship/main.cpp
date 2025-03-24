#include <iostream>
#include <fstream>
#include <string>
#include <GL/glut.h>

using namespace std;

void myDisplay(void) {
    glClear(GL_COLOR_BUFFER_BIT);        // Clears framebuffer with background color
    glClearColor(0.9f, 0.9f, 0.9f, 0.0); // Set background color

    // Drawing the first filled shape
    glColor3f(0.5, 0.5, 0.5); // Grey color
    glBegin(GL_POLYGON);
    glVertex2f(-0.2f, 0.6f);
    glVertex2f(-0.1f, 0.6f);
    glVertex2f(-0.1f, 0.35f);
    glVertex2f(-0.2f, 0.35f);
    glEnd();

    // Drawing the second filled shape
    glBegin(GL_POLYGON);
    glVertex2f(0.2f, 0.48f);
    glVertex2f(0.1f, 0.48f);
    glVertex2f(0.1f, 0.35f);
    glVertex2f(0.2f, 0.35f);
    glEnd();

    // Drawing the third filled shape
    glColor3f (1, 0, 0);                  // Set foreground color to red
    glBegin(GL_POLYGON);
    glVertex2f(0.35f, 0.35f);
    glVertex2f(-0.35f, 0.35f);
    glVertex2f(-0.35f, 0.0f);
    glVertex2f(0.35f, 0.0f);
    glEnd();

    // Drawing the fourth filled shape
    glBegin(GL_POLYGON);
    glVertex2f(0.35f, 0.15f);
    glVertex2f(0.5f, 0.15f);
    glVertex2f(0.5f, 0.0f);
    glVertex2f(0.35f, 0.0f);
    glEnd();

    // Drawing the fifth filled shape
    glColor3f(0, 0, 1); // Blue color
    glBegin(GL_POLYGON);
    glVertex2f(-0.75f, 0.0f);
    glVertex2f(0.75f, 0.0f);
    glVertex2f(0.65f, -0.25f);
    glVertex2f(-0.65f, -0.25f);
    glEnd();

    // Drawing the sixth filled shape
    glColor3f(0.6, 0.3, 0.0);  //brown color
    glBegin(GL_POLYGON);
    glVertex2f(-0.65f, -0.25f);
    glVertex2f(0.65f, -0.25f);
    glVertex2f(0.65f, -0.35f);
    glVertex2f(-0.62f, -0.35f);
    glEnd();

    glFlush(); // Sends buffer pixels to display screen
}

int screenWidth = 640, screenHeight = 480;

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(screenWidth, screenHeight);
    glutInitWindowPosition(30, 30);
    glutCreateWindow("MY First 2D Picture");

    glutDisplayFunc(myDisplay); // Register display func. as callback
    glutMainLoop();             // GUI loop that waits for events to occur
    return 0;
}
