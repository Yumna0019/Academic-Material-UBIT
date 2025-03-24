#pragma once		 // Ensures this header file is only included once during compilation
#include <iostream>	 // Include standard input-output library
#include <GL/glut.h> // Include OpenGL and GLUT for graphics rendering
#include "pixMap.h"	 // Include header for RGBApixmap (image handling class)

// Point2 class to represent a 2D point
class Point2
{
public:
	Point2() { x = y = 0.0f; } // Default constructor, initializes coordinates to (0, 0)
	Point2(float xx, float yy)
	{
		x = xx;
		y = yy;
	} // Constructor with custom coordinates (xx, yy)
	void set(float xx, float yy)
	{
		x = xx;
		y = yy;
	} // Set custom coordinates (xx, yy)
	float getX() { return x; } // Get the x-coordinate of the point
	float getY() { return y; } // Get the y-coordinate of the point

	// Function to draw the point using OpenGL
	void draw(void)
	{
		glPointSize(2.0);								   // Set the size of the point to 2 pixels
		glEnable(GL_BLEND);								   // Enable blending (for transparency)
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Set the blending mode
		glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);		   // Set point smoothing for better visuals
		glEnable(GL_POINT_SMOOTH);						   // Enable smooth points
		glBegin(GL_POINTS);								   // Begin drawing points
		glVertex2f((GLfloat)x, (GLfloat)y);				   // Define the position of the point (x, y)
		glEnd();										   // End drawing the point
		glDisable(GL_POINT_SMOOTH);						   // Disable point smoothing
	}

private:
	float x, y; // Private variables to store x and y coordinates of the point
}; // End class Point2

// Mario class to represent the character and its behavior
class Mario
{
public:
	RGBApixmap pix[5]; // Array to store different images for Mario's states (standing, running, jumping, etc.)
	enum State
	{
		STANDING,
		RUNNING1,
		RUNNING2,
		RUNNING3,
		JUMPING,
		DIE,
		GROUND
	} state; // Enumeration for Mario's state
	enum ModeType
	{
		STAY,
		RUN,
		JUMP,
		DEAD,
		GROUNDED
	} mode;				// Enumeration for Mario's mode
	float pos_X, pos_Y; // Coordinates to store Mario's current position

	// Constructor to initialize Mario with a given position
	Mario(Point2 pos)
	{
		// Load images for Mario's different states
		pix[0].readBMPFile("imgs\\MarioStanding.bmp", 1);
		pix[1].readBMPFile("imgs\\MarioJump.bmp", 1);
		pix[2].readBMPFile("imgs\\MarioRun1.bmp", 1);
		pix[3].readBMPFile("imgs\\MarioRun2.bmp", 1);
		pix[4].readBMPFile("imgs\\MarioRun3.bmp", 1);

		// Set chroma key for transparency (remove color with RGB values of 192, 192, 192)
		for (int i = 0; i < 5; i++)
			pix[i].setChromaKey(192, 192, 192);

		this->pos_X = pos.getX(); // Set Mario's x-coordinate from the given Point2 object
		this->pos_Y = pos.getY(); // Set Mario's y-coordinate from the given Point2 object
		state = STANDING;		  // Initialize Mario's state to STANDING
		mode = STAY;			  // Initialize Mario's mode to STAY (not moving)
	}

	// Function to change Mario's position by dx and dy
	void changePosition(float dx, float dy)
	{
		pos_X += dx; // Update Mario's x-coordinate by dx
		pos_Y += dy; // Update Mario's y-coordinate by dy
		if (pos_X > 600)
			pos_X = 0.0f; // If Mario moves off-screen to the right, reset his x position
		if (pos_Y < 0)
			pos_Y = 0; // Prevent Mario from moving below the ground (y < 0)
	}

	// Function declarations (defined elsewhere) for Mario's actions
	void render();				 // Render Mario on the screen based on the current state and mode
	void changeMode(ModeType m); // Change Mario's mode (stay, run, jump, etc.)
	void run();					 // Function to handle running state
	void stay();				 // Function to handle staying state
	void jump();				 // Function to handle jumping state
	void grounded();			 // Function to handle grounded state
}; // End class Mario
