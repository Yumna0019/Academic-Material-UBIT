#include <iostream>
#include <Windows.h>
#include <gl/glut.h>
#include "math.h"
#include "pixMap.h"
#include "Spider.h"
#include "vector"

int width = 680;
int height = 440;

void myinit(void);
void draw_bullet(float x, float y);

void pressKeySpecial(int key, int x, int y);
void releaseKeySpecial(int key, int x, int y);

// Global variables for sprite SPIDER
float posx = 0.0f;
float posy = 0.0f;

bool isMoving = true; // indicate the spider is still alive 
float s1 = 400.0f;
RGBApixmap pix[3];
bool gameOver = false;  // New game over variable

Spider spider(Point2(0.0, 0.0));

// Global variables for sprite BULLET
float bullet_posx = 0.0f;	// center
float bullet_posy = -height / 2 + 25;   	// bottom
float bullet_horizontal_velocity = 50.0f; // does not move
float bullet_speed = 1000.0f;
bool isFiring = false;	// true when firing
static int K = 0;

int random(int min, int max) //range : (min, max)
{
	static bool first = true;
	if (first)
	{
		srand(static_cast<unsigned int>(time(nullptr))); //seeding for the first time only!
		first = false;
	}
	return min + rand() % (max - min);
}

void myinit()
{
    glClearColor(1, 1, 1, 0);  // Set the clear color to white
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-width / 2, width / 2, -height / 2, height / 2);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_ALPHA_TEST);
    glAlphaFunc(GL_EQUAL, 1.0);
    pix[0].readBMPFile("spider.bmp", 1.0f);
    pix[1].readBMPFile("splash.bmp", 1.0f);
    pix[2].readBMPFile("background.bmp", 1.0f); // Load background image
}

void pressKeySpecial(int key, int x, int y) {

	if (key == GLUT_KEY_LEFT)
	{
		bullet_horizontal_velocity = -200.0f;
		K = 1;
	}
	// Move right
	if (key == GLUT_KEY_RIGHT)
	{
		bullet_horizontal_velocity = 200.0f;
		K = 1;
	}
	if (key == GLUT_KEY_UP) 
	{
		isFiring = true;
		// PlaySound("shoot.wav", NULL, SND_ASYNC | SND_FILENAME);  // Optional shooting sound
	}
	glutPostRedisplay();
}

// Stop moving when release key
void releaseKeySpecial(int key, int x, int y) {

	if (key == GLUT_KEY_LEFT) {
		bullet_horizontal_velocity = .0f;
	}

	if (key == GLUT_KEY_RIGHT) {
		bullet_horizontal_velocity = .0f;
	}
	glutPostRedisplay();
}

void draw_bullet(float x, float y)
{
	glPushMatrix();

	glColor3f(.5, .4, .0);	// the head
	glBegin(GL_TRIANGLES);
	glVertex2f(x, y);
	glVertex2f(x - 3, y - 5);
	glVertex2f(x + 3, y - 5);
	glEnd();

	glBegin(GL_POLYGON);	// the shell
	glVertex2f(x + 3, y - 5);
	glVertex2f(x - 3, y - 5);
	glVertex2f(x - 3, y - 15);
	glVertex2f(x + 3, y - 15);
	glEnd();
	glPopMatrix();
}

void drawTrajectory(float x, float y) {
	// static std::vector<std::pair<float, float>> trajectoryPoints; // Store trajectory points

	// // Store current position in the trajectoryPoints vector
	// trajectoryPoints.push_back(std::make_pair(x, y));

	// // Limit the number of points to prevent excessive memory usage
	// if (trajectoryPoints.size() > 5000) {
	// 	trajectoryPoints.erase(trajectoryPoints.begin());
	// }

	// if (!isMoving) {
	// 	trajectoryPoints.clear();
	// }

	// // Draw the trajectory as a line
	// glColor3f(0.5, 0.5, 1.0);
	// glBegin(GL_LINE_STRIP);
	// for (const auto& point : trajectoryPoints) {
	// 	glVertex2f(point.first, point.second);
	// }
	// glEnd();
	// glLineWidth(2.0);
}

void drawSpider(float posx, float posy)
{
	glRasterPos2f(posx, posy);
	pix[0].mDraw();
}

float gettime()
{
	static __int64 i64Frequency = 0;
	static __int64 i64BeginCount = 0;
	if (i64Frequency == 0) {	// do this only for the first time
		QueryPerformanceFrequency((LARGE_INTEGER*)&i64Frequency);
		QueryPerformanceCounter((LARGE_INTEGER*)&i64BeginCount); //retrieve the number of ticks since system start (64bit int).
	}
	__int64 i64CurrentCount;
	QueryPerformanceCounter((LARGE_INTEGER*)&i64CurrentCount);
	return  (float)(i64CurrentCount - i64BeginCount) / i64Frequency;
}

void move()
{
	static float prevtime = 0.0f;	// previous frame’s time
	float currtime = gettime();		// current frame’s time
	float elapsedtime = currtime - prevtime;	// elapsed time
	static float Ф = 0;
	float speed = 250.0f;
	static float movebearing = 0.0f;
	float dx = speed * cosf(Ф) * elapsedtime;
	float dy = speed * sinf(Ф) * elapsedtime;

	if (isMoving == true)
	{
		posx += dx;
		posy += dy;
		if (posx < -width / 2)
		{
			posx = -width / 2;
			Ф = Ф + 180;// (to Reverse moving Direction)
		}
		if (posx > width / 2 - 32)
		{
			posx = width / 2 - 32;
			Ф = Ф + 180;
		}
		if (posy < -height / 2)
		{
			posy = -height / 2;
			Ф = Ф + 180;// (to Reverse moving Direction)
		}
		if (posy > height / 2 - 32)
		{
			posy = height / 2 - 32;
			Ф = Ф + 180;
		}
	}

	if (isFiring == true)
	{
		float bullet_speed = 4.0f;
		bullet_posy = bullet_posy + bullet_speed;

		if (bullet_posy > height / 2 + 15)
		{
			glutSwapBuffers();
			Sleep(500);
			bullet_posy = -height / 2 + 15;
			isFiring = false;
		}

		// Check collision with the spider
		if (abs(bullet_posx - (posx + 34)) < 34 && abs((bullet_posy - 20) - (64 + posy)) < 64)
		{
			isMoving = false;
			PlaySound("shoot.wav", NULL, SND_ASYNC | SND_FILENAME);  // Play sound upon hit
			gameOver = true;  // Trigger game over
		}
	}

	if (gameOver)
	{
		isMoving = false;
		isFiring = false;
	}
	else if (isMoving == true)
	{
		glutPostRedisplay();
	}
	prevtime = currtime;
}

void reshape(int w, int h)
{
	width = w;
	height = h;
	bullet_posy = -(height / 2) + 13; //update bullet y position upon reshape

	glViewport(0, 0, w, h);			// use the entire window
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-w / 2, w / 2, -h / 2, h / 2);	// maintain unit-pixel proj.
	glMatrixMode(GL_MODELVIEW);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

    if (!gameOver) {
        // Draw the background
        glRasterPos2f(-width / 2, -height / 2);
        pix[2].mDraw();

        // Draw other elements
        drawTrajectory(posx, posy);
        drawSpider(posx, posy);
        draw_bullet(bullet_posx, bullet_posy);
    } else {
        // Game Over state
        glColor3f(1.0, 0.0, 0.0); // Red color for the game over message
        glRasterPos2f(-50, 0);    // Positioning the message in the center
        const char* message = "GAME OVER";
        for (const char* c = message; *c != '\0'; c++) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
        }
    }

    glutSwapBuffers();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);	//initialize the toolkit
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);	//set display mode
	glutInitWindowSize(680, 480);	//set window size
	glutInitWindowPosition(200, 200);	// set window position on screen
	glutCreateWindow(argv[0]);	// open the screen window

	glutSpecialFunc(pressKeySpecial);	// Detect arrow keys for bullet movement
	glutSpecialUpFunc(releaseKeySpecial);
	glutDisplayFunc(display);	//register redraw function
	glutReshapeFunc(reshape);
	glutIdleFunc(move);	// idle func for running move
	myinit();	//additional initializations as needed
	glutMainLoop();	// go into a perpetual loop
	return 0;
}
