#include <windows.h>
#include <mmsystem.h> 
#include <GL/glut.h>
#include <iostream>
#include <random>
#include <chrono>
#include <string>

// Ghost position and score
float ghostX = 0.0f, ghostY = 0.0f;
int score = 0;

// Function to generate random positions for ghost
void randomizeGhostPosition() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> disX(-0.8, 0.8); 
    std::uniform_real_distribution<> disY(-0.8, 0.8);

    ghostX = disX(gen);
    ghostY = disY(gen);
}

// Render a ghost 
void renderGhost() {
    glColor3f(1.0, 1.0, 1.0); 
    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; i++) {
        float angle = 2.0f * 3.1416f * i / 100;
        float dx = 0.1f * cos(angle);
        float dy = 0.1f * sin(angle);
        glVertex2f(ghostX + dx, ghostY + dy);
    }
    glEnd();

    // Draw ghost eyes
    glColor3f(0.0, 0.0, 0.0); 
    glBegin(GL_QUADS);
    glVertex2f(ghostX - 0.03f, ghostY + 0.05f);
    glVertex2f(ghostX - 0.02f, ghostY + 0.05f);
    glVertex2f(ghostX - 0.02f, ghostY + 0.03f);
    glVertex2f(ghostX - 0.03f, ghostY + 0.03f);

    glVertex2f(ghostX + 0.02f, ghostY + 0.05f);
    glVertex2f(ghostX + 0.03f, ghostY + 0.05f);
    glVertex2f(ghostX + 0.03f, ghostY + 0.03f);
    glVertex2f(ghostX + 0.02f, ghostY + 0.03f);
    glEnd();

    // Draw bottom part of the ghost with a wavy effect
    glBegin(GL_TRIANGLES);
    for (float i = -0.1f; i <= 0.1f; i += 0.05f) {
        glVertex2f(ghostX + i, ghostY - 0.1f);  
        glVertex2f(ghostX + i + 0.025f, ghostY); 
        glVertex2f(ghostX + i + 0.05f, ghostY - 0.1f);  
    }
    glEnd();
}

// Function to display the score on the screen
void renderScore() {
    std::string scoreText = "Score: " + std::to_string(score);
    glColor3f(1.0, 1.0, 1.0); 
    glRasterPos2f(-0.95f, 0.9f); 

    for (char c : scoreText) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c); 
    }
}

// Function to update game state
void update(int value) {
    randomizeGhostPosition();
    glutPostRedisplay();
    glutTimerFunc(1200, update, 0); 
}

// Mouse callback function to detect shooting
void mouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        float mouseX = (float)x / 500.0f * 2.0f - 1.0f;
        float mouseY = (float)(500 - y) / 500.0f * 2.0f - 1.0f;

        if (mouseX > ghostX - 0.1f && mouseX < ghostX + 0.1f &&
            mouseY > ghostY - 0.1f && mouseY < ghostY + 0.1f) {
            score++;
            std::cout << "Score: " << score << std::endl;

            PlaySound(TEXT("Jump-SoundBible.com-1007297584.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
        }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    renderGhost();

    renderScore();

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("2D Ghost Game");

    glutDisplayFunc(display);
    glutMouseFunc(mouseClick);

    glutTimerFunc(1200, update, 0);

    glutMainLoop();

    return 0;
}
