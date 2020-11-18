#include "tree.h"
static GLfloat tree_ring_size = 15.0;
static GLfloat tree_head_size = 100.0;

GLfloat tree_head_vertices[6][3] = {{0. , -tree_head_size, 0.} ,{0. , tree_head_size, 0.},{0.,0., -tree_head_size}, {- tree_head_size , 0. ,0.},{0.,0.,tree_head_size} };
GLfloat tree_head_vertexlist[24] = {1,4,5, 1,5,2, 1,3,2, 1,4,3, 5,4,0, 2,5,0, 2,3,0, 3,4,0};
GLfloat tree_head_color[6][3] = {{0. , -1, 0.} ,{0. , 1, 0.},{0.,0., -1}, {- 1 , 0. ,0.},{0.,0.,1} };

GLfloat MyVertices[8][3] = { {-100,-100,100}, {-100,100,100}, {100,100,100}, {100,-100,100},
                            {-100,-100,-100}, {-100,100,-100}, {100,100,-100}, {100,-100,-100}
};
GLfloat MyColors[8][3] = { {0.2,0.2,0.2}, {1.0,0.0,0.0}, {1.0,1.0,0.0}, {0.0,1.0,0.0},
                            {0.0,0.0,1.0}, {1.0,0.0,1.0}, {1.0,1.0,1.0}, {0.0,1.0,1.0}
};
GLubyte MyVertexList[24] = {0,3,2,1 ,0,1,5,4, 5,6,7,4 ,7,3,0,4 ,3,7,6,2 ,6,5,1,2};

void line()
{
    glPushMatrix();
    glBegin(GL_LINES);
    glColor3f(1.0,0.0,0.0);
    glVertex3f(-100.0,0.0,0.0);
    glVertex3f(150.0,0.0,0.0);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0,1.0,0.0);
    glVertex3f(0.0,150.0,0.0);
    glVertex3f(0.0,-100.0,0.0);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,1.0);
    glVertex3f(0.0,0.0,150.0);
    glVertex3f(0.0,0,-100.0);
    glEnd();
    glPopMatrix();
}

void draw_tree_head()
{
//    glFrontFace(GL_CCW);
//    glEnable(GL_CULL_FACE);
//    glEnableClientState(GL_COLOR_ARRAY);
//    glEnableClientState(GL_VERTEX_ARRAY);
//    glColorPointer(3,GL_FLOAT,0,tree_head_color);
//    glVertexPointer(3,GL_FLOAT,0,tree_head_vertices);
//    for(GLint i = 0; i<8
//    ;i++){
//        glDrawElements(GL_TRIANGLE_STRIP,3,GL_UNSIGNED_BYTE, &tree_head_vertexlist[i*3]);
//    }
//    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);
//    glColorPointer(3,GL_FLOAT,0,MyColors);
    glVertexPointer(3,GL_FLOAT,0,MyVertices);
    for(GLint i = 0; i<6
    ;i++){
        glDrawElements(GL_POLYGON,4,GL_UNSIGNED_BYTE, &MyVertexList[i*4]);
    }
}


void draw_apple_tree()
{
    line();
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
    glPushMatrix();
        draw_tree_head();
    glPopMatrix();
}
