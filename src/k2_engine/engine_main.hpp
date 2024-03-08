/**
 * @file engine_main.hpp
 * @author Klemm Gábor - H8XK58
 * @brief fiujhsdfhodsjfosdjfds
 * @version 0.1
 * @date 2024-03-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */
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

double interpolate(double n0, double n1, double diff);

class Renderer{
        std::vector<Triangle> globaltriangles;
        std::vector<RenderTriangle> flattriangles;

        std::vector<Vec4> globalvectors;
        std::vector<Lightsource> lights;
        int flatscreenoffsetX;
        int flatscreenoffsetY;

        outp::OutputBuffer outbuf{TERMINAL_WIDTH, TERMINAL_HEIGHT};

        Vertex3 set_realtive_vertex(Vec4 v);
        Vertex2 project_vertex(Vertex3& vx);

        void set_relative_vertices();
        void project_vertices();
        double calculate_luminosity(Vec4& v);


        void plothigh_interp(const Vertex2& v0, const Vertex2& v1, std::vector<Ept>& vertexarray);
        void plotlow_inpterp(const Vertex2& v0, const Vertex2& v1, std::vector<Ept>& vertexarray);

public:
        Camera camera;
        Renderer():flatscreenoffsetX(TERMINAL_WIDTH/2),flatscreenoffsetY(TERMINAL_HEIGHT/2){}
        
        void addtriangle(Triangle triangle);
        void addtriangle(Vec4& v0, Vec4& v1, Vec4& v2);
        void addlsource(Lightsource lsource);

        void render();
        void rasterize(RenderTriangle& t);

        void bresenham(const Vertex2& v0, const Vertex2& v1, std::vector<Ept>& edge);
        

        }; 
}

#endif // K2_ENGINE_ENGINE_MAIN_HPP_