#ifndef K2_ENGINE_CAMERA_HPP_
#define K2_ENGINE_CAMERA_HPP_

#include "mat4.hpp"
#include "vec4.hpp"

namespace k2_engine{

class Camera{
    double rotX;
    double rotY;
    double rotZ;
    Vec4 pos;
    double screendist;

    public:
    Camera():rotX(0),rotY(0),rotZ(0),pos(Vec4(0, 0, 0)),screendist(10){}
    void rotate(double dx, double dy, double dz);
    double getrotX() const{return rotX;}
    double getrotY() const{return rotY;}
    double getrotZ() const{return rotZ;}
    double getdist() const{return screendist;}
    Vec4 getpos() const{return pos;}
    void setpos(const Vec4& newpos){pos = newpos;}
    void offsetpos(double xmod, double ymod, double zmod);
};

} // namespace k2_engine

#endif // K2_ENGINE_CAMERA_HPP_