#ifndef K2_ENGINE_LIGHTSOURCE_HPP_
#define K2_ENGINE_LIGHTSOURCE_HPP_

#include "mat4.hpp"
#include "vec4.hpp"

namespace k2_engine{

class Lightsource{
    Vec4 pos;
    double lightdistance;

    public:
    Lightsource(Vec4& pos, double dist);
    double getDist(){return lightdistance;}
    void setDist(double dist){lightdistance = dist;}

};


} // namespace k2_engine

#endif // K2_ENGINE_LIGHTSOURCE_HPP_