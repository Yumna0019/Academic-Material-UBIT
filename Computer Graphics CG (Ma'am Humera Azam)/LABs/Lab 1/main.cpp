#include <iostream>
#include <fstream>
#include <string>
#include <GL/glut.h>

using namespace std;

void myDisplay(void)
{                                        // user defined display function
    glClear(GL_COLOR_BUFFER_BIT);        // clears fb with bg color
    glClearColor(0.3f, 0.3f, 0.3f, 0.0); // set background color
    glColor3f(1, 0, 0);                  // set foreground color
    glFlush();                           // sends buffer pixels to display screen
}

int screenWidth = 640, screenHeight = 480;

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(screenWidth, screenHeight);
    glutInitWindowPosition(30, 30);
    glutCreateWindow("HT First OGL Program");

    glutDisplayFunc(myDisplay); // register display func. as callback
    glutMainLoop();             // gui loop that waits for events to occur
    return 0;
}