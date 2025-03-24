#include <windows.h>  // Include Windows API header
#include <mmsystem.h> // Include Multimedia System header for sound playback
#include <GL/glut.h>  // Include GLUT header for OpenGL utility toolkit
#include <iostream>   // Include header for input/output stream
#include <random>     // Include header for random number generation
#include <chrono>     // Include header for time utilities
#include <string>     // Include header for string manipulation

// Ghost position and score
float ghostX = 0.0f, ghostY = 0.0f; // Initialize ghost's position at the center
int score = 0;                      // Initialize score to 0

// Function to generate random positions for the ghost
void randomizeGhostPosition()
{
    std::random_device rd;                            // Obtain a random number from hardware
    std::mt19937 gen(rd());                           // Seed the generator
    std::uniform_real_distribution<> disX(-0.8, 0.8); // Distribution for ghost's X position
    std::uniform_real_distribution<> disY(-0.8, 0.8); // Distribution for ghost's Y position

    ghostX = disX(gen); // Assign a random X position
    ghostY = disY(gen); // Assign a random Y position
}

// Render a ghost
void renderGhost()
{
    glColor3f(1.0, 1.0, 1.0); // Set ghost color to white
    glBegin(GL_POLYGON);      // Begin drawing a polygon for the ghost shape
    for (int i = 0; i < 100; i++)
    {                                           // Loop to create a circle for the ghost
        float angle = 2.0f * 3.1416f * i / 100; // Calculate angle for each vertex
        float dx = 0.1f * cos(angle);           // Calculate x offset
        float dy = 0.1f * sin(angle);           // Calculate y offset
        glVertex2f(ghostX + dx, ghostY + dy);   // Specify vertex position
    }
    glEnd(); // End the polygon

    // Draw ghost eyes
    glColor3f(0.0, 0.0, 0.0);                   // Set eye color to black
    glBegin(GL_QUADS);                          // Begin drawing quadrilaterals for eyes
    glVertex2f(ghostX - 0.03f, ghostY + 0.05f); // Left eye top left
    glVertex2f(ghostX - 0.02f, ghostY + 0.05f); // Left eye top right
    glVertex2f(ghostX - 0.02f, ghostY + 0.03f); // Left eye bottom right
    glVertex2f(ghostX - 0.03f, ghostY + 0.03f); // Left eye bottom left

    glVertex2f(ghostX + 0.02f, ghostY + 0.05f); // Right eye top left
    glVertex2f(ghostX + 0.03f, ghostY + 0.05f); // Right eye top right
    glVertex2f(ghostX + 0.03f, ghostY + 0.03f); // Right eye bottom right
    glVertex2f(ghostX + 0.02f, ghostY + 0.03f); // Right eye bottom left
    glEnd();                                    // End the quadrilaterals

    // Draw bottom part of the ghost with a wavy effect
    glBegin(GL_TRIANGLES); // Begin drawing triangles for wavy bottom
    for (float i = -0.1f; i <= 0.1f; i += 0.05f)
    {                                                  // Loop to create waves
        glVertex2f(ghostX + i, ghostY - 0.1f);         // Bottom vertex of triangle
        glVertex2f(ghostX + i + 0.025f, ghostY);       // Middle vertex of triangle
        glVertex2f(ghostX + i + 0.05f, ghostY - 0.1f); // Bottom right vertex of triangle
    }
    glEnd(); // End the triangles
}

// Function to display the score on the screen
void renderScore()
{
    std::string scoreText = "Score: " + std::to_string(score); // Create score string
    glColor3f(1.0, 1.0, 1.0);                                  // Set score color to white
    glRasterPos2f(-0.95f, 0.9f);                               // Position the score on the screen

    for (char c : scoreText)
    {                                                     // Loop through each character in the score string
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c); // Render each character
    }
}

// Function to update game state
void update(int value)
{
    randomizeGhostPosition();       // Randomize the ghost's position
    glutPostRedisplay();            // Request a redraw
    glutTimerFunc(1200, update, 0); // Call update again after 1200 milliseconds
}

// Mouse callback function to detect shooting
void mouseClick(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {                                                           // Check for left mouse click
        float mouseX = (float)x / 500.0f * 2.0f - 1.0f;         // Convert mouse X position to OpenGL coordinates
        float mouseY = (float)(500 - y) / 500.0f * 2.0f - 1.0f; // Convert mouse Y position to OpenGL coordinates

        // Check if the mouse click is within the ghost's bounds
        if (mouseX > ghostX - 0.1f && mouseX < ghostX + 0.1f &&
            mouseY > ghostY - 0.1f && mouseY < ghostY + 0.1f)
        {
            score++;                                      // Increase the score
            std::cout << "Score: " << score << std::endl; // Print score to console

            PlaySound(TEXT("Jump-SoundBible.com-1007297584.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_NODEFAULT); // Play sound
        }
    }
}

// Display function
void display()
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

    renderGhost(); // Render the ghost

    renderScore(); // Render the score

    glutSwapBuffers(); // Swap the front and back buffers
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);                       // Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // Set display mode to double buffering and RGB color
    glutInitWindowSize(500, 500);                // Set window size
    glutCreateWindow("2D Ghost Game");           // Create a window with the specified title

    glutDisplayFunc(display);  // Register display callback function
    glutMouseFunc(mouseClick); // Register mouse click callback function

    glutTimerFunc(1200, update, 0); // Set the timer function to update the game state

    glutMainLoop(); // Enter the GLUT main loop

    return 0; // Return success
}
