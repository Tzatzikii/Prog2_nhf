#ifndef K2_ENGINE_MAT4_HPP_
#define K2_ENGINE_MAT4_HPP_

#include "vec4.hpp"
#include <cstring>
#include <cmath>

namespace k2_engine{

class Vec4;

class Mat4{
    int type;
    int theta;
    double body[4][4];

public:
    enum { IDENTITY = 0, EMPTY = 1, ROTATION_X = 2, ROTATION_Y = 3, ROTATION_Z = 4 };
    Mat4(int type = 0, double theta = 0);

    //operatorok
    double& operator()(int i, int j){return body[i][j];};
    Mat4 operator*(const Mat4& rhs_m) const;
    Mat4& operator*=(const Mat4& rhs_m);
    Vec4 operator*(const Vec4& rhs_v) const;
    

}; //class Mat4

} //namespace k2_engine

#endif //K2_ENGINE_MAT4_HPP_