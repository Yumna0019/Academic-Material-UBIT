#include <iostream>
#include <Windows.h>
#include <gl/glut.h>
#include "math.h"
#include "pixMap.h"
#include "Spider.h"
#include "vector"

// Window dimensions
int width = 680;
int height = 440;

// Function declarations
void myinit(void);
void draw_bullet(float x, float y);
void pressKeySpecial(int key, int x, int y);
void releaseKeySpecial(int key, int x, int y);

// Global variables for sprite SPIDER
float posx = 0.0f; // Spider's X position
float posy = 0.0f; // Spider's Y position

bool isMoving = true;  // Indicates if the spider is still alive
float s1 = 400.0f;	   // Arbitrary variable for spider sprite
RGBApixmap pix[3];	   // Array to hold pixmaps for sprites
bool gameOver = false; // Game over state

Spider spider(Point2(0.0, 0.0)); // Create spider object

// Global variables for the bullet
float bullet_posx = 0.0f;				  // Bullet's X position (center)
float bullet_posy = -height / 2 + 25;	  // Bullet's Y position (bottom)
float bullet_horizontal_velocity = 50.0f; // Initial horizontal velocity of the bullet
float bullet_speed = 1000.0f;			  // Bullet speed
bool isFiring = false;					  // Indicates if the bullet is being fired
static int K = 0;						  // Arbitrary variable for bullet movement direction

// Function to generate a random number within a specified range
int random(int min, int max) // range : (min, max)
{
	static bool first = true; // Flag to check if it's the first call
	if (first)
	{
		srand(static_cast<unsigned int>(time(nullptr))); // Seed the random number generator for the first time
		first = false;
	}
	return min + rand() % (max - min); // Return a random number in the range
}

// Initialization function
void myinit()
{
	glClearColor(1, 1, 1, 0); // Set the clear color to white
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-width / 2, width / 2, -height / 2, height / 2);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_ALPHA_TEST);	// Enable alpha testing
	glAlphaFunc(GL_EQUAL, 1.0); // Set alpha test function
								// Load sprite images
	pix[0].readBMPFile("spider.bmp", 1.0f);
	pix[1].readBMPFile("splash.bmp", 1.0f);
	pix[2].readBMPFile("background.bmp", 1.0f); // Load background image
}

// Handle special key presses (arrow keys)
void pressKeySpecial(int key, int x, int y)
{

	if (key == GLUT_KEY_LEFT)
	{
		bullet_horizontal_velocity = -200.0f; // Set velocity for left movement
		K = 1;								  // Update direction flag
	}
	// Move right
	if (key == GLUT_KEY_RIGHT)
	{
		bullet_horizontal_velocity = 200.0f; // Set velocity for right movement
		K = 1;								 // Update direction flag
	}
	if (key == GLUT_KEY_UP)
	{
		isFiring = true; // Set firing state to true
	}
	glutPostRedisplay(); // Request to redraw the scene
}

// Stop moving when release key
void releaseKeySpecial(int key, int x, int y)
{

	if (key == GLUT_KEY_LEFT)
	{
		bullet_horizontal_velocity = .0f; // Stop left movement
	}

	if (key == GLUT_KEY_RIGHT)
	{
		bullet_horizontal_velocity = .0f; // Stop right movement
	}
	glutPostRedisplay(); // Request to redraw the scene
}

// Function to draw the bullet
void draw_bullet(float x, float y)
{
	glPushMatrix(); // Save the current matrix state

	glColor3f(.5, .4, .0); // Set color for the bullet head
	glBegin(GL_TRIANGLES); // Draw the bullet head
	glVertex2f(x, y);
	glVertex2f(x - 3, y - 5);
	glVertex2f(x + 3, y - 5);
	glEnd();

	glBegin(GL_POLYGON); // Draw the bullet shell
	glVertex2f(x + 3, y - 5);
	glVertex2f(x - 3, y - 5);
	glVertex2f(x - 3, y - 15);
	glVertex2f(x + 3, y - 15);
	glEnd();
	glPopMatrix(); // Restore the previous matrix state
}

// Function to draw the trajectory of the bullet (commented out)
void drawTrajectory(float x, float y)
{
}

// Function to draw the spider sprite
void drawSpider(float posx, float posy)
{
	glRasterPos2f(posx, posy); // Set position for drawing the spider
	pix[0].mDraw();			   // Draw the spider image
}

// Function to get the current time
float gettime()
{
	static __int64 i64Frequency = 0;  // Frequency of the high-resolution performance counter
	static __int64 i64BeginCount = 0; // Start count
	if (i64Frequency == 0)
	{															   // Initialize on the first call
		QueryPerformanceFrequency((LARGE_INTEGER *)&i64Frequency); // Get the frequency
		QueryPerformanceCounter((LARGE_INTEGER *)&i64BeginCount);  // Get the start count
	}
	__int64 i64CurrentCount;
	QueryPerformanceCounter((LARGE_INTEGER *)&i64CurrentCount);		// Get the current count
	return (float)(i64CurrentCount - i64BeginCount) / i64Frequency; // Return elapsed time
}

// Function to move the spider and bullet
void move()
{
	static float prevtime = 0.0f;			  // previous frame’s time
	float currtime = gettime();				  // Current frame’s time
	float elapsedtime = currtime - prevtime;  // Calculate elapsed time
	static float Ф = 0;						  // Angle of movement direction
	float speed = 250.0f;					  // Speed of movement
	static float movebearing = 0.0f;		  // Arbitrary variable for movement direction
	float dx = speed * cosf(Ф) * elapsedtime; // Calculate change in x
	float dy = speed * sinf(Ф) * elapsedtime; // Calculate change in y

	if (isMoving == true) // Move if the spider is alive
	{
		posx += dx; // Update spider's x position
		posy += dy; // Update spider's y position
		// Boundary checks for spider movement
		if (posx < -width / 2)
		{
			posx = -width / 2; // Keep within left boundary
			Ф = Ф + 180;	   // Reverse direction
		}
		if (posx > width / 2 - 32)
		{
			posx = width / 2 - 32; // Keep within right boundary
			Ф = Ф + 180;		   // Reverse direction
		}
		if (posy < -height / 2)
		{
			posy = -height / 2; // Keep within bottom boundary
			Ф = Ф + 180;		// Reverse direction
		}
		if (posy > height / 2 - 32)
		{
			posy = height / 2 - 32; // Keep within top boundary
			Ф = Ф + 180;			// Reverse direction
		}
	}

	if (isFiring == true) // If the bullet is firing
	{
		float bullet_speed = 4.0f;				  // Speed of bullet movement
		bullet_posy = bullet_posy + bullet_speed; // Update bullet's y position

		// Check if the bullet is off the top of the screen
		if (bullet_posy > height / 2 + 15)
		{
			glutSwapBuffers();				// Swap buffers
			Sleep(500);						// Pause for half a second
			bullet_posy = -height / 2 + 15; // Reset bullet position
			isFiring = false;				// Reset firing state
		}

		// Check collision with the spider
		if (abs(bullet_posx - (posx + 34)) < 34 && abs((bullet_posy - 20) - (64 + posy)) < 64)
		{
			isMoving = false;
			PlaySound("shoot.wav", NULL, SND_ASYNC | SND_FILENAME); // Play sound upon hit
			gameOver = true;										// Trigger game over
		}
	}

	if (gameOver) // Draw game elements if gameover
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
	bullet_posy = -(height / 2) + 13; // update bullet y position upon reshape

	glViewport(0, 0, w, h); // use the entire window
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-w / 2, w / 2, -h / 2, h / 2); // maintain unit-pixel proj.
	glMatrixMode(GL_MODELVIEW);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

	if (!gameOver)
	{
		// Draw the background
		glRasterPos2f(-width / 2, -height / 2);
		pix[2].mDraw();

		// Draw other elements
		drawTrajectory(posx, posy);
		drawSpider(posx, posy);
		draw_bullet(bullet_posx, bullet_posy);
	}
	else
	{
		// Game Over state
		glColor3f(1.0, 0.0, 0.0); // Red color for the game over message
		glRasterPos2f(-50, 0);	  // Positioning the message in the center
		const char *message = "GAME OVER";
		for (const char *c = message; *c != '\0'; c++)
		{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
		}
	}

	glutSwapBuffers();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);						 // initialize the toolkit
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // set display mode
	glutInitWindowSize(680, 480);				 // set window size
	glutInitWindowPosition(200, 200);			 // set window position on screen
	glutCreateWindow(argv[0]);					 // open the screen window

	glutSpecialFunc(pressKeySpecial); // Detect arrow keys for bullet movement
	glutSpecialUpFunc(releaseKeySpecial);
	glutDisplayFunc(display); // register redraw function
	glutReshapeFunc(reshape);
	glutIdleFunc(move); // idle func for running move
	myinit();			// additional initializations as needed
	glutMainLoop();		// go into a perpetual loop
	return 0;
}
