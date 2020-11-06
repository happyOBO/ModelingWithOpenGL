#ifndef EVERGREEN_H_INCLUDED
#define EVERGREEN_H_INCLUDED

#include <GL/glut.h>
#include <iostream>

using namespace std;

static GLfloat tree_ring_size = 15.0;
static GLfloat branch_ring_size = 5.0;
static GLfloat top_branch_length = 50.0;
static GLfloat branch_term = 30.0;
static GLfloat leaf_term = 4.0;
static GLfloat leaf_length = 15.0;


void draw_evergreen();

#endif // EVERGREEN_H_INCLUDED
