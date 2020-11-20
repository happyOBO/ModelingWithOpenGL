#ifndef VERTEX_H_INCLUDED
#define VERTEX_H_INCLUDED

#include <glm/glm.hpp>

// YouTube suraj Sharma OpenGL Tutorial 25


struct Vertex
{
	glm::vec3 position;
	glm::vec3 color;
	glm::vec2 texcoord;
	glm::vec3 normal;
};
#endif // VERTEX_H_INCLUDED
