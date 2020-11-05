

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <iostream>

using namespace std;
static GLfloat disksize = 15.0;
/* GLUT callback Handlers */

static void display(void)
{


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1,1,0);

    glPushMatrix();
        glRotatef(30.0,1.0,1.0,0.0);
        GLUquadricObj *quadratic;
        quadratic = gluNewQuadric();
        glPushMatrix();
            glColor3f(0.74,0.74,0.74);
            glRotatef(90.0 ,1.0,0.0,0.0);
            gluCylinder(quadratic,disksize,disksize,500.0,32,32);
        glPopMatrix();
        glPushMatrix();
            glColor3f(0.74,0.74,0.74);
            glRotatef(-90.0,1.0,0.0,0.0);
            gluDisk(quadratic,0.0,disksize,30,15);
        glPopMatrix();

        glPushMatrix();
            glColor3f(0.74,0.74,0.74);
            glTranslatef(0.0,-30.0,0);
            gluDisk(quadratic,0.0,disksize,30,15);
            glColor3f(0.74,0.74,0.74);
            glRotatef(180.0,0.0,1.0,0.0);
            gluCylinder(quadratic,disksize,disksize,400.0,32,32);
            glColor3f(1.0,0.0,0.0);
            glTranslatef(0.0,0.0,50.0);
            //gluCylinder(quadratic,50.0,50.0,700.0,32,32);
        glPopMatrix();


    glPopMatrix();


    glutSwapBuffers();
}

static void idle(void)
{
    glutPostRedisplay();
}

const GLfloat light_ambient[]  = { 0.3f, 0.3f, 0.3f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1000,600);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT Shapes");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1000.0,1000.0,-600.0,600.0,-1000.0,1000.0);
    //glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutIdleFunc(idle);

    glClearColor(1,1,1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);


    glutMainLoop();

    return EXIT_SUCCESS;
}
