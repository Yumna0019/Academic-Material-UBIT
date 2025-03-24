#include <GL/glut.h>
#include <math.h>
#define PI 3.141592
#include <windows.h>
#include <mmsystem.h>

// Variables for windmill animation
float windmill_angle = 0.0f; // To rotate the windmill blades

// Variables for plane animation
float plane_x = 250.0f;     // Initial X position of the plane
float plane_y = 230.0f;     // Initial Y position of the plane
float plane_speed = -1.0f;  // Speed at which the plane moves left and down
bool plane_crashed = false; // Flag to detect crash

// Set crash position here
float crash_position_x = 125.0f; // X position where the plane will crash
float crash_position_y = 40.0f;  // Y position where the plane will crash

// Variables to keep track of the last position before crashing
float crash_last_x = plane_x;
float crash_last_y = plane_y;

void display(void);      // Draw everything
void drawWind(void);     // Draw single blade
void drawwindmill(void); // Complete this to call drawWind() multiple times and animate
void drawplane();        // Animate and crash the plane
void drawlandscape();    // Draw static landscape
void Timer(int value);   // Update variables for animation
void keyboard(unsigned char key, int x, int y);
void init(void);
void reshape(GLsizei w, GLsizei h);

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawlandscape();
    drawplane();
    drawwindmill();

    glutSwapBuffers();
}

void drawWind()
{
    // Draw single windmill blade (triangle)
    glBegin(GL_TRIANGLES);
    glColor3f(0.8, 0.8, 0.8);
    glVertex2f(0.0, 0.0);   // Center of rotation
    glVertex2f(15.0, 30.0); // Tip of the blade
    glVertex2f(30.0, 30.0); // Edge of the blade
    glEnd();
}

void drawwindmill()
{
    // Draw the windmill structure (stand)
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.0);
    glVertex2f(145.0, 50.0);
    glVertex2f(135.0, 100.0);
    glVertex2f(115.0, 100.0);
    glVertex2f(105.0, 50.0);
    glEnd();

    // Translate to windmill's center
    glPushMatrix();
    glTranslatef(125.0, 100.0, 0.0); // Move origin to the center of the windmill

    // Rotate the blades
    glRotatef(windmill_angle, 0.0, 0.0, 1.0); // Rotate around the Z-axis

    // Draw 4 blades at 90 degree angles
    for (int i = 0; i < 4; i++)
    {
        drawWind();
        glRotatef(90.0, 0.0, 0.0, 1.0); // Rotate 90 degrees to draw the next blade
    }
    glPopMatrix();
}

void Timer(int value)
{
    // Update windmill angle for rotation animation (increased speed)
    windmill_angle += 4.0f; // Adjust speed of windmill rotation (increased)
    if (windmill_angle > 360.0f)
    {
        windmill_angle -= 360.0f;
    }

    // Animate the plane
    if (!plane_crashed)
    {
        // Move the plane diagonally downwards at a 45-degree angle
        plane_x += 2 * plane_speed; // Move the plane left
        plane_y += 2 * plane_speed; // Move the plane down

        // Check if the plane has reached the crash position
        if (plane_x <= crash_position_x && plane_y <= crash_position_y)
        {
            PlaySound(TEXT("shoot.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
            plane_crashed = true;   // Stop moving the plane when it reaches crash position
            crash_last_x = plane_x; // Store last position for crashing
            crash_last_y = plane_y;
        }
    }

    display();
    glutTimerFunc(30, Timer, 1); // Call Timer every 30 ms
}

void drawplane()
{
    if (!plane_crashed)
    {
        // Draw the moving plane
        glPushMatrix();
        glTranslatef(plane_x, plane_y, 0.0); // Translate plane to current position
        glBegin(GL_TRIANGLES);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0, 10.0);
        glVertex2f(-30.0, 0.0);

        glColor3f(0.2, 0.2, 0.2);
        glVertex2f(-1.0, -2.0);
        glVertex2f(-1.0, 5.0);
        glVertex2f(-17.0, 5.0);
        glEnd();
        glPopMatrix();
    }
    else
    {
        // If crashed, break the plane into four parts
        glPushMatrix();
        glTranslatef(crash_last_x, crash_last_y, 0.0); // Translate to crash position

        // Part 1: Top-left piece
        glPushMatrix();
        glTranslatef(-10.0, 5.0, 0.0);  // Offset position
        glRotatef(30.0, 0.0, 0.0, 1.0); // Slight rotation
        glScalef(0.5, 0.5, 1.0);        // Scale down
        glBegin(GL_TRIANGLES);
        glColor3f(0.8, 0.0, 0.0); // Red color
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0, 10.0);
        glVertex2f(-30.0, 0.0);
        glEnd();
        glPopMatrix();

        // Part 2: Top-right piece
        glPushMatrix();
        glTranslatef(10.0, 5.0, 0.0);    // Offset position
        glRotatef(-20.0, 0.0, 0.0, 1.0); // Slight rotation
        glScalef(0.5, 0.5, 1.0);
        glBegin(GL_TRIANGLES);
        glColor3f(0.8, 0.0, 0.0);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0, 10.0);
        glVertex2f(-30.0, 0.0);
        glEnd();
        glPopMatrix();

        // Part 3: Bottom-left piece
        glPushMatrix();
        glTranslatef(-10.0, -5.0, 0.0); // Offset position
        glRotatef(-15.0, 0.0, 0.0, 1.0);
        glScalef(0.4, 0.4, 1.0);
        glBegin(GL_TRIANGLES);
        glColor3f(0.8, 0.0, 0.0);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0, 10.0);
        glVertex2f(-30.0, 0.0);
        glEnd();
        glPopMatrix();

        // Part 4: Bottom-right piece
        glPushMatrix();
        glTranslatef(10.0, -5.0, 0.0);
        glRotatef(25.0, 0.0, 0.0, 1.0);
        glScalef(0.4, 0.4, 1.0);
        glBegin(GL_TRIANGLES);
        glColor3f(0.8, 0.0, 0.0);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0, 10.0);
        glVertex2f(-30.0, 0.0);
        glEnd();
        glPopMatrix();
        glPopMatrix();
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Windmill");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(30, Timer, 1);
    glutMainLoop();
}

void drawlandscape()
{
    // Grass
    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(250.0, 0.0);
    glColor3f(0.0, 0.9, 0.0);
    glVertex2f(250.0, 50.0);
    glColor3f(0.0, 0.8, 0.0);
    glVertex2f(0.0, 50.0);
    glColor3f(0.0, 0.7, 0.0);
    glVertex2f(0.0, 0.0);
    glEnd();

    // Mountains
    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.0, 0.6);
    glVertex2f(250.0, 50.0);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(200.0, 150.0);
    glColor3f(0.0, 0.0, 0.5);
    glVertex2f(150.0, 50.0);

    glColor3f(0.0, 0.0, 0.5);
    glVertex2f(200.0, 50.0);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(150.0, 150.0);
    glColor3f(0.0, 0.0, 0.5);
    glVertex2f(100.0, 50.0);
    glEnd();
}

void init()
{
    glClearColor(0.8f, 0.8f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 250.0, 0.0, 250.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void reshape(GLsizei w, GLsizei h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 250.0, 0.0, 250.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:
        exit(0);
        break;
    }
}
