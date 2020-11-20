#ifndef OBJLOADER_H_INCLUDED
#define OBJLOADER_H_INCLUDED

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

//GLEW
#include <GL/glew.h>

//GLFW
#include <GLFW/glfw3.h>

//OpenGL Math libs
#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


#include <GL/gl.h>
#include <GL/glu.h>

#include "Vertex.h"

static std::vector<Vertex> loadOBJ(const char* file_name)
{
    //Vertex portions
    std::vector<glm::fvec3> vertex_positions;
    std::vector<glm::fvec2> vertex_texcoords;
    std::vector<glm::fvec3> vertex_normals;

    //Face vectors
    std::vector<GLint> vertex_position_indicies;
    std::vector<GLint> vertex_texcoord_indicies;
    std::vector<GLint> vertex_normal_indicies;

    //vertex array

    std::vector<Vertex> vertices;

    std::stringstream ss;
    std::ifstream in_file(file_name);
    std::string line = "";
    std::string prefix = "";
    glm::vec3 temp_vec3;
    glm::vec2 temp_vec2;
    GLint temp_glint = 0;

    //File open error check
    if(!in_file.is_open())
    {
        throw "ERROR::OGJLOADER::Could not open file.";
    }

    //Read one line at a time
    while(std::getline(in_file,line))
    {
        //Get the prefix of the line
        ss.clear();
        ss.str(line);
        //prefix : v, vt , ...
        ss >> prefix;

        if(prefix == "#")
        {
            //do nothing
        }

        else if(prefix == "o")
        {

        }
        else if(prefix == "s")
        {

        }
        else if(prefix == "use_mtl")
        {

        }
        else if(prefix == "v") //Vertex position
        {
            ss >> temp_vec3.x >> temp_vec3.y >> temp_vec3.z;
            vertex_positions.push_back(temp_vec3);

        }
        else if(prefix == "vt")
        {
            ss >> temp_vec2.x >> temp_vec2.y;
            vertex_texcoords.push_back(temp_vec2);
        }
        else if(prefix == "vn")
        {
            ss >> temp_vec3.x >> temp_vec3.y >> temp_vec3.z;
            vertex_normals.push_back(temp_vec3);
        }
        else if(prefix == "f")
        {

        }
        else
        {

        }

        //DEBUG
        std::cout << line << "\n";
        std::cout << "Num of vertices: " << vertex_positions.size() << "\n";

    }



    //Loaded succuess
    return vertices;
}

#endif // OBJLOADER_H_INCLUDED
