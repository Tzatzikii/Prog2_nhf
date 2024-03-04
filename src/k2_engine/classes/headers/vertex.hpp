#ifndef K2_ENGINE_VERTEX_HPP_
#define K2_ENGINE_VERTEX_HPP_

#include "mat4.hpp"
#include "vec4.hpp"
#include <cmath>

namespace k2_engine{

extern char GRAYSCALE[];

class Vertex2{
    double x, y;
    char lumin_txtr;

    public:
    static void rasterize(Vertex2& v0, Vertex2& v1, Vertex2& v2);
    static void interpolate(Vertex2& v0, Vertex2& v1);
    static void interpolate(double x, double y, double lumin1, double lumin2);
};

class Vertex3{
    double x, y, z, luminosity;
    char greyscale;
    public:
    

    
};

} // namespace k2_engine

#endif // K2_ENGINE_VERTEX_HPP_