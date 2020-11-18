#include <GL/glut.h>
#include <iostream>
//#include <stdlib.h>
static float rotAngle = 0.;
using namespace std;

/* 알파 블렌딩, 힌트, 선분 폭을 포함한,
 * RGBA 모드에 대한 안티 앨리어싱을 초기화한다.
 * 선분의 폭과 선분의 폭에대한 입도( line width granularity)에 관련된
 * OpenGL 구현에 종속적인 정보를 출력한다.
 */

void init(void)
{
    GLfloat values[2];
    glGetFloatv(GL_LINE_WIDTH_GRANULARITY, values);
    cout<<"GL_LINE_WIDTH_GRANULARITY value is "<< values[0]<<endl;
    glGetFloatv(GL_LINE_WIDTH_RANGE, values);
    cout<<"GL_LINE_WIDTH_RANGE values are "<< values[0]<<" "<< values[1]<<endl;
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glHint(GL_LINE_SMOOTH_HINT, GL_DONT_CARE);
    glLineWidth(4.0);

    glClearColor(0.0,0.0,0.0,0.0);

}


// X 모양으로 겹쳐지는 두개의 선분을 그린다.

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0,1.0,0.0);
    glPushMatrix();
    glRotatef(-rotAngle,0.0,0.0,0.1);
    glBegin(GL_LINES);
        glVertex2f(-0.5,0.5);
        glVertex2f(0.5, -0.5);
    glEnd();
    glPopMatrix();

    glColor3f(0.0,0.0,1.0);
    glPushMatrix();
    glRotatef(rotAngle,0.0,0.0,0.1);
    glBegin(GL_LINES);
        glVertex2f(0.5,0.5);
        glVertex2f(-0.5, -0.5);
    glEnd();
    glPopMatrix();

    glFlush();

}

void reshape(int w, int h)
{
    glViewport(0,0,(GLint) w, (GLint) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(w <= h)
        gluOrtho2D(-1.0,1.0, -1.0 * (GLfloat) h/ (GLfloat)w, 1.0*(GLfloat)h/ (GLfloat)w);
    else
        gluOrtho2D(-1.0*(GLfloat) w/(GLfloat)h , 1.0*(GLfloat) w/ (GLfloat)h, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

void keyboard(unsigned char key, int x , int y)
{

    switch(key)
    {
    case 'r' :
    case 'R' :
        rotAngle += 20.;
        if(rotAngle >= 360.) rotAngle = 0;
        glutPostRedisplay();
        break;
    case 27:
        exit(0);
        break;
    default:
        break;
    }
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(200, 200);
    glutCreateWindow(argv[0]);
    init();
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
