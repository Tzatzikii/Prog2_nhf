#ifndef K2_ENGINE_VERTEX_HPP_
#define K2_ENGINE_VERTEX_HPP_

#include "mat4.hpp"
#include "vec4.hpp"
#include "lightsource.hpp"
#include <cmath>
#include <cstring>
#include <iostream>

namespace k2_engine{

extern const char GRAYSCALE[];

class Vertex2{
    double x, y;
    char lumin_txtr;

    public:
    Vertex2(double x, double y, char lumin_txtr):x(x),y(y),lumin_txtr(lumin_txtr){}
    double getX(){return x;}
    double getY(){return y;}
    char gettxtr(){return lumin_txtr;}
    static void rasterize(Vertex2& v0, Vertex2& v1, Vertex2& v2);
    static void interpolate(Vertex2& v0, Vertex2& v1);
    static void interpolate(double x, double y, double lumin1, double lumin2);
};

class Vertex3{
    double x, y, z, luminosity;
    char grayscale;
    char calculate_grayscale();

public:
    double getX() const{return x;}
    double getY() const{return y;}
    double getZ() const{return z;}
    double getluminosity(){return luminosity;}
    double getgrayscale(){return grayscale;}
    Vertex3(const Vec4&, double lumin);

    
};

} // namespace k2_engine

#endif // K2_ENGINE_VERTEX_HPP_