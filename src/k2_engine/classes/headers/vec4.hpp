#ifndef K2_ENGINE_VEC4_HPP_
#define K2_ENGINE_VEC4_HPP_

#include <cmath>
#include "mat4.hpp"
namespace k2_engine{
class Mat4;

class Vec4{

    double x, y, z, w;

public:
    Vec4(double x = 0, double y = 0, double z = 0, double w = 1);
    double getX() const {return x;}
    double getY() const {return y;}
    double getZ() const {return z;}
    double getW() const {return w;}
    void setX(int n){x = n;}
    void setY(int n){y = n;}
    void setZ(int n){z = n;}
    void setW(int n){w = n;}

    Vec4& operator*=(const Mat4& lhs_m);

}; //class Vec4


} //namespace k2_engine

#endif //K2_ENGINE_MAT4_HPP