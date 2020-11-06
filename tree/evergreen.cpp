#include "evergreen.h"

void line()
{
    glPushMatrix();
    glBegin(GL_LINES);
    glColor3f(1.0,0.0,0.0);
    glVertex3f(-100.0,0.0,0.0);
    glVertex3f(100.0,0.0,0.0);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0,1.0,0.0);
    glVertex3f(0.0,100.0,0.0);
    glVertex3f(0.0,-100.0,0.0);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,1.0);
    glVertex3f(0.0,0.0,100.0);
    glVertex3f(0.0,0,-100.0);
    glEnd();
    glPopMatrix();
}

void draw_leaf(int j , int i)
{
    GLUquadricObj *quadratic;
    quadratic = gluNewQuadric();
    for(float k = 0; k < top_branch_length + 6* j; k += leaf_term)
    {
        glPushMatrix();
            glColor3f(0.5,0.5,0.37);
            glTranslatef(0.0,0,k);
            glRotatef(90,1.0,0.0,1.0);
            gluCylinder(quadratic,1,1,leaf_length +j -(k / leaf_term),32,32);

        glPopMatrix();
        glPushMatrix();
            glColor3f(0.26,0.33,0.25);
            glTranslatef(0.0,0,k);
            glRotatef(90,1.0,0.0,1.0);
            glRotatef(180,1.0,0.0,0.0);
            gluCylinder(quadratic,1,1,leaf_length +j -(0.2 * k / leaf_term),32,32);

        glPopMatrix();
    }
}



void draw_branch()
{
    GLUquadricObj *quadratic;
    quadratic = gluNewQuadric();
    glPushMatrix();
        glColor3f(0.72,0.66,0.59);
        glRotatef(90.0 ,1.0,0.0,0.0);
        gluCylinder(quadratic,tree_ring_size,tree_ring_size* 1.5,500.0,32,32);
    glPopMatrix();
    glPushMatrix();
        glColor3f(0.72,0.66,0.59);
        glRotatef(-90.0,1.0,0.0,0.0);
        gluDisk(quadratic,0.0,tree_ring_size,30,15);
    glPopMatrix();

    for(int j = 0; j < 13; j ++)
    {
        for(int i = 0; i < 360; i += 40)
        {
            glPushMatrix();
                glColor3f(0.72,0.66,0.59);
                glTranslatef(0.0,-branch_term * j,0);
                glRotatef(float(i),0.0,1.0,0.0);
                glRotatef(150.0,1.0,0.0,0.0);
                gluCylinder(quadratic,branch_ring_size,0,top_branch_length + 6* j,32,32);
                draw_leaf(j ,i);
                //line();
            glPopMatrix();
        }
    }
}


void draw_evergreen()
{
    draw_branch();
}
