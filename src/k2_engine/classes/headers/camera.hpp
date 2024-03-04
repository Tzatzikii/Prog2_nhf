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

    Vec4 getpos() const{return pos;}
    void setpos(const Vec4& newpos){pos = newpos;}
    void offsetpos(double xmod, double ymod, double zmod);
};

} // namespace k2_engine

#endif // K2_ENGINE_CAMERA_HPP_