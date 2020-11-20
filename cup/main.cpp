/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

//#ifdef __APPLE__
//#include <GLUT/glut.h>
//#else
//#include <GL/glut.h>
//#endif

#include <stdlib.h>

#include<stdio.h>

#include "OBJLoader.h"

//globals


GLuint car;
float carrot;
#include <direct.h>





//other functions and main
//.obj loader code


void mini_loadObj(char *fname)
{
        FILE *fp;
        int read;
        GLfloat x, y, z;
        char ch;
        car=glGenLists(1);
        fp=fopen(fname,"r");
        if (!fp)
        {
        printf("can't open file %s\n", fname);
        exit(1);
        }
        glPointSize(2.0);
        glNewList(car, GL_COMPILE);
        {
        glPushMatrix();
        glScalef(100.0,100.0,100.0);
        glBegin(GL_POINTS);
        while(!(feof(fp)))
        {
                read=fscanf(fp,"%c %f %f %f",&ch,&x,&y,&z);
                if(read==4&&ch=='v')
        {
                glVertex3f(x,y,z);
                }
        }
        glEnd();
        }
        glPopMatrix();
        glEndList();
        fclose(fp);
}
//.obj loader code ends here
void reshape(int w,int h)
{
        glViewport(0,0,w,h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective (60, (GLfloat)w / (GLfloat)h, 0.1, 1000.0);
        //glOrtho(-25,25,-2,2,0.1,100);
        glMatrixMode(GL_MODELVIEW);
}


void drawCar()
{
        glPushMatrix();
        glTranslatef(0,-40.00,-105);
        glColor3f(1.0,0.23,0.27);
        glScalef(0.1,0.1,0.1);
        glRotatef(carrot,0,1,0);
        glCallList(car);
        glPopMatrix();
        carrot=carrot+0.1;
        if(carrot>360)carrot=carrot-360;
}


void display(void)
{
//        glClearColor (0.0,0.0,0.0,1.0);
//        glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//        glLoadIdentity();
//        drawCar();
//        glutSwapBuffers(); //swap the buffers
}


int main(int argc,char **argv)
{
//     char curDir[1000];
//  _getcwd(curDir,1000);
//
//printf( "%s", curDir);
//        glutInit(&argc,argv);
//        glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
//        glutInitWindowSize(800,450);
//        glutInitWindowPosition(20,20);
//        glutCreateWindow("ObjLoader");
//        glutReshapeFunc(reshape);
//        glutDisplayFunc(display);
//        glutIdleFunc(display);
//        mini_loadObj("cup.obj");//replace porsche.obj with radar.obj or any other .obj to display it
//        glutMainLoop();
        return 0;
}
