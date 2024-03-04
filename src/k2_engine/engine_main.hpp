#ifndef K2_ENGINE_ENGINE_MAIN_HPP_
#define K2_ENGINE_ENGINE_MAIN_HPP_

#include "../../dep/output.hpp"
#include "classes/headers/mat4.hpp"
#include "classes/headers/vec4.hpp"
#include "classes/headers/vertex.hpp"
#include "classes/headers/lightsource.hpp"
#include "classes/headers/camera.hpp"
#include <cassert>
#include <cmath>
#include <cstring>
#include <numbers>
#include <limits>
#include <vector>

extern const double PI;

namespace k2_engine{

class Renderer{
    std::vector<Vec4> globalvectors;
    std::vector<Vertex3> localvertices;
    std::vector<Vertex2> flatvertices;
    std::vector<Lightsource> lights;
    Camera camera;

    void set_relative_vertices();
    void project_verices();
    public:

    void render();
    void rasterize();
    

}; 
}

#endif // K2_ENGINE_ENGINE_MAIN_HPP_