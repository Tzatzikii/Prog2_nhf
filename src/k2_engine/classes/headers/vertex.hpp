#ifndef K2_ENGINE_VERTEX_HPP_
#define K2_ENGINE_VERTEX_HPP_

#include "mat4.hpp"
#include "vec4.hpp"
#include "lightsource.hpp"
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
#include "../../../../dep/utils.hpp"

namespace k2_engine{

extern const char GRAYSCALE[];

class Vertex2{
    double x, y;
    char lumin_txtr;

    void plothigh_interp(const Vertex2& v0, const Vertex2& v1, std::vector<Vertex2&>& vertexarray);
    void plotlow_inpterp(const Vertex2& v0, const Vertex2& v1, std::vector<Vertex2&>& vertexarray);

    public:
    Vertex2(double x, double y, char lumin_txtr):x(x),y(y),lumin_txtr(lumin_txtr){}
    double getX(){return x;}
    double getY(){return y;}
    char gettxtr(){return lumin_txtr;}
    static void bresenham(const Vertex2& v0, const Vertex2& v1, std::vector<Vertex2&>& vertexarray);
    static void interpolate(Vertex2& v0, Vertex2& v1);
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

class Triangle{
    Vertex3& vx0;
    Vertex3& vx1;
    Vertex3& vx2;

    public:

    Triangle(Vertex3& vx0, Vertex3& vx1, Vertex3& vx2):vx0(vx0),vx1(vx1),vx2(vx2){}
};

class RenderTriangle{
    Vertex2& vx0;
    Vertex2& vx1;
    Vertex2& vx2;

    public: 

    RenderTriangle(Vertex2& vx0, Vertex2& vx1, Vertex2& vx2):vx0(vx0),vx1(vx1),vx2(vx2){}
    void rasterize();
};

} // namespace k2_engine

#endif // K2_ENGINE_VERTEX_HPP_