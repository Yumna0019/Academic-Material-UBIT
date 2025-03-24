#include <GL/glut.h>

// Aspect ratio for the camera setup
float aspect = 1.0;

// Function to initialize OpenGL settings
void init()
{
    glClearColor(0.1, 0.1, 0.1, 1.0); // Background color (dark gray)
    glEnable(GL_DEPTH_TEST);          // Enable depth testing
}

// Function to handle the rendering of the scene
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the buffers

    // Set up orthographic projection and camera view
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-4.0 * aspect, 4.0 * aspect, -4.0, 4.0, 0.1, 100);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(4.0, 4.2, 8.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    // Draw shapes at different positions
    glPushMatrix();
    glTranslatef(-3.0, 2.0, 0.0); // Position the cube
    glutWireCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.0, 2.0, 0.0); // Position the sphere
    glutWireSphere(0.5, 16, 16);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.0, 2.0, 0.0); // Position the torus
    glutWireTorus(0.2, 0.5, 16, 16);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3.0, 2.0, 0.0); // Position the teapot
    glutWireTeapot(0.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-3.0, -1.0, 0.0); // Position the tetrahedron
    glutWireTetrahedron();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.0, -1.0, 0.0); // Position the octahedron
    glutWireOctahedron();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.0, -1.0, 0.0); // Position the dodecahedron
    glutWireDodecahedron();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3.0, -1.0, 0.0); // Position the icosahedron
    glutWireIcosahedron();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-3.0, -3.5, 0.0); // Position the cone
    glutWireCone(0.5, 1.0, 16, 16);
    glPopMatrix();

    // Draw the cylinder with a GLU quadric
    GLUquadricObj *qobj = gluNewQuadric();
    gluQuadricDrawStyle(qobj, GLU_LINE);
    glPushMatrix();
    glTranslatef(1.0, -3.5, 0.0); // Position the cylinder
    gluCylinder(qobj, 0.3, 0.3, 1.0, 16, 16);
    glPopMatrix();

    gluDeleteQuadric(qobj); // Clean up the quadric object

    // Swap buffers for smooth rendering
    glutSwapBuffers();
}

// Function to handle window resizing
void reshape(int w, int h)
{
    if (h == 0)
        h = 1; // Prevent division by zero
    aspect = (float)w / (float)h;
    glViewport(0, 0, w, h); // Set the viewport
}

// Main function to set up the OpenGL environment
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("OpenGL Shapes");

    init();                   // Initialize OpenGL settings
    glutDisplayFunc(display); // Register the display callback
    glutReshapeFunc(reshape); // Register the reshape callback

    glutMainLoop(); // Enter the main loop
    return 0;
}

//               DRY RUN:

// ### Initialization

// 1. `init` function:
//    - Sets the background color to dark gray.
//    - Enables depth testing to ensure correct 3D rendering order.

// ### Display Function

// 2. Display Setup:
//    - Clears color and depth buffers, resetting the frame for rendering.
//    - Sets up an orthographic projection with `glOrtho` so that objects closer or farther don’t scale in size.
//    - Sets up the camera view using `gluLookAt` positioned at (4, 4.2, 8), pointing toward the origin, with the 'up' direction along the y-axis.

// 3. Drawing Shapes:
//    - Cube: Translated to (-3, 2, 0), drawn using `glutWireCube(1.0)`.
//    - Sphere: Translated to (-1, 2, 0), drawn using `glutWireSphere(0.5, 16, 16)`.
//    - Torus: Translated to (1, 2, 0), drawn using `glutWireTorus(0.2, 0.5, 16, 16)`.
//    - Teapot: Translated to (3, 2, 0), drawn using `glutWireTeapot(0.5)`.
//    - Tetrahedron: Translated to (-3, -1, 0), drawn using `glutWireTetrahedron()`.
//    - Octahedron: Translated to (-1, -1, 0), drawn using `glutWireOctahedron()`.
//    - Dodecahedron: Translated to (1, -1, 0), drawn using `glutWireDodecahedron()`.
//    - Icosahedron: Translated to (3, -1, 0), drawn using `glutWireIcosahedron()`.
//    - Cone: Translated to (-3, -3.5, 0), drawn using `glutWireCone(0.5, 1.0, 16, 16)`.

//    - Cylinder: Created with a `GLUquadricObj` object and drawn using `gluCylinder` at (1, -3.5, 0). After drawing, the quadric object is deleted.

// 4. Buffer Swap:
//    - Calls `glutSwapBuffers()` for smooth rendering.

// ### Window Resizing

// 5. `reshape` function:
//    - Adjusts the `aspect` variable based on the window’s new width and height to maintain the correct aspect ratio.
//    - Sets the viewport to cover the entire window.

// ### Main Function

// 6. Setting Up GLUT:
//    - Initializes GLUT and sets the display mode to support double buffering, RGB color, and depth testing.
//    - Creates a window with the title “OpenGL Shapes” and registers the display and reshape callbacks.

// When executed, this setup will render a scene containing various wireframe 3D shapes in different positions within a single orthographic view. Adjustments like changing positions, sizes, or colors can be done by modifying `glTranslatef`, `glScalef`, or other transformations within each shape's `glPushMatrix` block.