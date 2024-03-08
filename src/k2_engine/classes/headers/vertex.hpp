
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

char calculate_grayscale(double luminosity);

extern const char GRAYSCALE[];
class Vertex2{
        double x, y;
        double flatlumin;

public:

        Vertex2(double x, double y, double flatlumin);
        double getX() const{return x;}
        double getY() const{return y;}
        double getluminosity() const{return flatlumin;}
    
};

class Vertex3{

        double x, y, z, luminosity;

public:

        double getX() const {return x;}
        double getY() const {return y;}
        double getZ() const {return z;}
        double getluminosity() const {return luminosity;}
        Vertex3(const Vec4&, double lumin);

    
};

class Ept{

        int x,y;
        double luminosity;

public:

        Ept(int x, int y, double luminosity):x(x), y(y), luminosity(luminosity){}

};

class Triangle{
        Vec4 v0;
        Vec4 v1;
        Vec4 v2;

public:

        Triangle(Vec4 v0, Vec4 v1, Vec4 v2):v0(v0),v1(v1),v2(v2){}
        Vec4 getv0() const {return v0;}
        Vec4 getv1() const {return v1;}
        Vec4 getv2() const {return v2;}
};

class RenderTriangle{
        Vertex2 vx0;
        Vertex2 vx1;
        Vertex2 vx2;
        std::vector<Ept> edge0;
        std::vector<Ept> edge1;
        std::vector<Ept> edge2;

public: 

        RenderTriangle(Vertex2 vx0, Vertex2 vx1, Vertex2 vx2):vx0(vx0),vx1(vx1),vx2(vx2){}
        std::vector<Ept>& edge0ref(){return edge0;};
        std::vector<Ept>& edge1ref(){return edge1;};
        std::vector<Ept>& edge2ref(){return edge2;};
        Vertex2 getvx0() const {return vx0;}
        Vertex2 getvx1() const {return vx1;}
        Vertex2 getvx2() const {return vx2;}
        void rasterize();

};

} // namespace k2_engine

#endif // K2_ENGINE_VERTEX_HPP_