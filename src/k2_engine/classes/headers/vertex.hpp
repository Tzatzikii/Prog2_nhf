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
#include "../../../../dep/output.hpp"

namespace k2_engine{

extern const char GRAYSCALE[];

class Vertex2{
    double x, y;
    double flatlumin;
    char texture;

    char calculate_grayscale();
    void plothigh_interp(Vertex2& v0, Vertex2& v1, std::vector<Vertex2>& vertexarray);
    void plotlow_inpterp(Vertex2& v0, Vertex2& v1, std::vector<Vertex2>& vertexarray);

    public:
    Vertex2(double x, double y, char lumin_txtr);
    double getX(){return x;}
    double getY(){return y;}
    double getluminosity(){return flatlumin;}
    char gettxtr(){return texture;}
    static void bresenham(const Vertex2& v0, const Vertex2& v1, std::vector<Vertex2>& vertexarray);
    static double interpolate(double n0, double n1, double diff);
};

class Vertex3{
    double x, y, z, luminosity;
    char grayscale;

public:
    double getX() const{return x;}
    double getY() const{return y;}
    double getZ() const{return z;}
    double getluminosity(){return luminosity;}
    double getgrayscale(){return grayscale;}
    Vertex3(const Vec4&, double lumin);

    
};

class Triangle{
    Vec4 v0;
    Vec4 v1;
    Vec4 v2;

    public:

    Triangle(Vec4 v0, Vec4 v1, Vec4 v2):v0(v0),v1(v1),v2(v2){}
    Vec4 getv0(){return v0;}
    Vec4 getv1(){return v1;}
    Vec4 getv2(){return v2;}
};

class RenderTriangle{
    Vertex2 vx0;
    Vertex2 vx1;
    Vertex2 vx2;

    public: 

    RenderTriangle(Vertex2 vx0, Vertex2 vx1, Vertex2 vx2):vx0(vx0),vx1(vx1),vx2(vx2){}
    Vertex2 getvx0(){return vx0;}
    Vertex2 getvx1(){return vx1;}
    Vertex2 getvx2(){return vx2;}
    void rasterize();
};

} // namespace k2_engine

#endif // K2_ENGINE_VERTEX_HPP_