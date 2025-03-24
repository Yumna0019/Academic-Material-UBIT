#include <GL/glut.h>
#include <vector>

// Define the positions of the stars in the Big Dipper constellation
std::vector<std::pair<float, float>> stars = {
    {0.0f, 0.0f}, // Alpha Ursae Majoris (Dubhe)
    {0.8f, 0.2f}, // Beta Ursae Majoris (Merak)
    {1.6f, 0.3f}, // Gamma Ursae Majoris (Phecda)
    {2.0f, 0.4f}, // Delta Ursae Majoris (Megrez)
    {2.8f, 0.5f}, // Epsilon Ursae Majoris (Alioth)
    {3.0f, 0.2f}, // Zeta Ursae Majoris (Mizar)
    {3.6f, 0.1f}  // Eta Ursae Majoris (Alcor)
};

// Function to draw the Big Dipper constellation
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Set the color for the stars
    glColor3f(1.0f, 1.0f, 1.0f);

    // Draw stars as points
    glBegin(GL_POINTS);
    for (const auto &star : stars)
    {
        glVertex2f(star.first, star.second);
    }
    glEnd();

    // Draw lines between stars to form the Big Dipper
    glBegin(GL_LINES);
    glVertex2f(stars[0].first, stars[0].second); // Dubhe
    glVertex2f(stars[1].first, stars[1].second); // Merak

    glVertex2f(stars[1].first, stars[1].second); // Merak
    glVertex2f(stars[2].first, stars[2].second); // Phecda

    glVertex2f(stars[2].first, stars[2].second); // Phecda
    glVertex2f(stars[3].first, stars[3].second); // Megrez

    glVertex2f(stars[3].first, stars[3].second); // Megrez
    glVertex2f(stars[4].first, stars[4].second); // Alioth

    glVertex2f(stars[4].first, stars[4].second); // Alioth
    glVertex2f(stars[5].first, stars[5].second); // Mizar

    glVertex2f(stars[5].first, stars[5].second); // Mizar
    glVertex2f(stars[6].first, stars[6].second); // Alcor
    glEnd();

    glFlush();
}

// Function to initialize OpenGL settings
void init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black
    glColor3f(1.0f, 1.0f, 1.0f);          // Set star color to white
    glPointSize(5.0f);                    // Set the size of the points
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 5.0, -1.0, 1.0); // Set the coordinate system
}

// Main function to set up GLUT and start the rendering loop
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Big Dipper Constellation");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
