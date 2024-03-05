#ifndef K2_ENGINE_ENGINE_MAIN_HPP_
#define K2_ENGINE_ENGINE_MAIN_HPP_

#include "../../dep/output.hpp"
#include "../../dep/utils.hpp"
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


namespace k2_engine{

extern const double PI;
extern const size_t TERMINAL_WIDTH;
extern const size_t TERMINAL_HEIGHT;


class Renderer{
    std::vector<Triangle> globaltriangles;
    std::vector<RenderTriangle> flattriangles;

    std::vector<Vec4> globalvectors;
    std::vector<Vertex3> localvertices;
    std::vector<Vertex2> flatvertices;
    std::vector<Lightsource> lights;
    int flatscreenoffsetX;
    int flatscreenoffsetY;

    outp::OutputBuffer outbuf{TERMINAL_WIDTH, TERMINAL_HEIGHT};

    Vertex3 set_realtive_vertex(Vec4& v);
    Vertex2 project_vertex(Vertex3& vx);

    void set_relative_vertices();
    void project_vertices();
    double calculate_luminosity(Vec4& v);

    public:
    Camera camera;

    Renderer():flatscreenoffsetX(TERMINAL_WIDTH/2),flatscreenoffsetY(TERMINAL_HEIGHT/2){};
    void pushvec4(Vec4 vector);
    void addlsource(Lightsource lsource);

    void render();
    void rasterize();
    

}; 
}

#endif // K2_ENGINE_ENGINE_MAIN_HPP_