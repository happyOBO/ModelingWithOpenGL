#include <GL/glut.h>
#include <iostream>
#include "tf.h"
using namespace std;

void draw_tf()
{
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

    GLfloat horizon_bar_down = -30.0;
    glPushMatrix();
        glColor3f(0.74,0.74,0.74);
        glTranslatef(0.0,horizon_bar_down,0);
        gluDisk(quadratic,0.0,disksize,30,15);
        glColor3f(0.74,0.74,0.74);
        glRotatef(270.0,0.0,1.0,0.0);
        gluCylinder(quadratic,disksize,disksize,300.0,32,32);
    glPopMatrix();

    GLfloat Light_cube_size = 50.0;
    GLfloat pallet[3] = {0,0,0};
    for(int i = 0; i<3; i++)
    {
        glPushMatrix();
            glTranslatef(-150.0 - i * Light_cube_size,horizon_bar_down - Light_cube_size / 2,0);
            glColor3f(0.4,0.4,0.4);
            glutSolidCube(Light_cube_size);

            if(i == 2) pallet[0] = 0.0;
            else pallet[i] = 1.0;

            glTranslatef(0.0,0.0,15);
            glColor3f(pallet[0],pallet[1],pallet[2]);
            glutSolidSphere(Light_cube_size * 0.5, 30, 15);
        glPopMatrix();
    }
}
