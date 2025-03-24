#include <iostream>
#include <fstream>
#include <GL/glut.h>


// Function to display the house
void DisplayHouse(void)
{
    glClear(GL_COLOR_BUFFER_BIT);         // Clears fb with bg color
    glClearColor(0.9f, 0.9f, 0.9f, 0.0f); // Set background color
    glColor3f(1, 0, 0);                   // Set foreground color

    // Main body of the house
    glColor3f(1.0f, 0.8f, 0.6f);
    glBegin(GL_POLYGON);
    glVertex2f(10, 40);
    glVertex2f(20, 40);
    glVertex2f(20, 10);
    glVertex2f(10, 10);
    glEnd();

    glColor3f(1.0f, 0.9f, 0.6f);
    glBegin(GL_POLYGON);
    glVertex2f(20, 40);
    glVertex2f(50, 40);
    glVertex2f(50, 10);
    glVertex2f(20, 10);
    glEnd();

    // Roof
    glColor3f(0.6f, 0.4f, 0.2f);
    glBegin(GL_TRIANGLES);
    glVertex2f(10, 40);
    glVertex2f(15, 50);
    glVertex2f(20, 40);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.6f, 0.8f, 1.0f);
    glVertex2f(20, 40);
    glVertex2f(15, 50);
    glVertex2f(50, 50);
    glVertex2f(50, 40);
    glEnd();

    // Door
    glColor3f(0.8f, 0.5f, 0.2f);
    glBegin(GL_POLYGON);
    glVertex2f(12, 10);
    glVertex2f(12, 20);
    glVertex2f(18, 20);
    glVertex2f(18, 10);
    glEnd();

    // Left window
    glColor3f(0.6f, 0.8f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(25, 30);
    glVertex2f(25, 35);
    glVertex2f(30, 35);
    glVertex2f(30, 30);
    glEnd();

    // Right window
    glBegin(GL_POLYGON);
    glVertex2f(35, 30);
    glVertex2f(35, 35);
    glVertex2f(40, 35);
    glVertex2f(40, 30);
    glEnd();

    // Chimney
    glColor3f(0.6f, 0.2f, 0.2f);
    glBegin(GL_POLYGON);
    glVertex2f(40, 50);
    glVertex2f(40, 55);
    glVertex2f(45, 55);
    glVertex2f(45, 50);
    glEnd();

    glColor3f(0.6f, 0.9f, 0.2f);
    glBegin(GL_POLYGON);
    glVertex2f(40, 55);
    glVertex2f(40, 57);
    glVertex2f(45, 57);
    glVertex2f(45, 55);
    glEnd();

    glFlush();
}

int screenWidth = 640, screenHeight = 480;

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(screenWidth, screenHeight);
    glutInitWindowPosition(30, 30);
    glutCreateWindow("House Drawing");

    gluOrtho2D(0, 70, 0, 90);           // Set the coordinate system
    glutDisplayFunc(DisplayHouse); // Register display function
    glutMainLoop();                     // Main loop that waits for events

    return 0;
}