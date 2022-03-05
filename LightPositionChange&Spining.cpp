#include <windows.h>
#include "GL/glut.h"
#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

GLuint colorCounter = 0, angle=0;
GLfloat lightXPos = 0.0f;
GLfloat lightYPos = 0.0f;

void keyboardFunc( unsigned char key, int x, int y )
{
    switch ( key )
    {
    case 27:
        exit(0);
        break;
    case 'c':

		cout << "Unhandled key press " << key << "." << endl;
    case 'r':
        cout << "Unhandled key press " << key << "." << endl;
    default:
        cout << "Unhandled key press " << key << "." << endl;
    }

    glutPostRedisplay();
}

void specialFunc( int key, int x, int y )
{
    switch ( key )
    {
    case GLUT_KEY_UP:

		lightYPos += 0.5f;
		break;
    case GLUT_KEY_DOWN:

		lightYPos += -0.5f;
		break;
    case GLUT_KEY_LEFT:

		lightXPos += -0.5f;
		break;
    case GLUT_KEY_RIGHT:

		lightXPos += 0.5f;
		break;
    }

    glutPostRedisplay();
}

void drawScene(void)
{
    int i;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    gluLookAt(0.0, 0.0, 5.0,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);

    GLfloat diffColors[4][4] = { {0.5, 0.5, 0.9, 1.0},
                                 {0.9, 0.5, 0.5, 1.0},
                                 {0.5, 0.9, 0.3, 1.0},
                                 {0.3, 0.8, 0.9, 1.0} };

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, diffColors[colorCounter]);

    GLfloat specColor[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat shininess[] = {100.0};

    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specColor);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);

    GLfloat Lt0diff[] = {1.0,1.0,1.0,1.0};
    // Light position
	GLfloat Lt0pos[] = {1.0f + lightXPos, 1.0f + lightYPos, 5.0f, 1.0f};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, Lt0diff);
    glLightfv(GL_LIGHT0, GL_POSITION, Lt0pos);
    glRotatef(angle,0,1,0);
	glutSolidTeapot(1.0);
    glutSwapBuffers();

}

void initRendering()
{
    glEnable(GL_DEPTH_TEST);   // Depth testing must be turned on
    glEnable(GL_LIGHTING);     // Enable lighting calculations
    glEnable(GL_LIGHT0);       // Turn on light #0.
}

void reshapeFunc(int w, int h)
{

    if (w > h) {
        glViewport((w - h) / 2, 0, h, h);
    } else {
        glViewport(0, (h - w) / 2, w, w);
    }
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, 1.0, 1.0, 100.0);
}
void loadInput()
{
	// load the OBJ file here
}

int main( int argc, char** argv )
{
    loadInput();
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );

    glutInitWindowPosition( 50, 50 );
    glutInitWindowSize( 300, 300 );
    glutCreateWindow("Assignment 1");

    initRendering();

    glutKeyboardFunc(keyboardFunc);
    glutSpecialFunc(specialFunc);
    glutReshapeFunc( reshapeFunc );
    glutDisplayFunc( drawScene );
    glutMainLoop( );
    return 0;
}
