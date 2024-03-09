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
        std::vector<Raster> rasters;

        std::vector<Vec4> globalvectors;
        std::vector<Lightsource> lightsources;
        int screenoffset_x;
        int screenoffset_y;

        outp::OutputBuffer outbuf{TERMINAL_WIDTH, TERMINAL_HEIGHT};

        Vertex3 set_realtive_vertex(Vec4 v);
        Px project_vertex(Vertex3& vx);

        double calculate_luminosity(Vec4& v);

        void plothigh_interp(const Px& v0, const Px& v1, std::vector<Px>& vertexarray);
        void plotlow_inpterp(const Px& v0, const Px& v1, std::vector<Px>& vertexarray);

public:

        Camera camera;
        Renderer()
                :screenoffset_x(TERMINAL_WIDTH/2),screenoffset_y(TERMINAL_HEIGHT/2){}
        
        void add_triangle(Triangle triangle);
        void add_triangle(Vec4& v0, Vec4& v1, Vec4& v2);
        void add_lightsource(Lightsource lightsource);

        void render();
        void rasterize(Raster& t);

        void bresenham(const Px& v0, const Px& v1, std::vector<Px>& edge);
        
        }; 
}

#endif // K2_ENGINE_ENGINE_MAIN_HPP_