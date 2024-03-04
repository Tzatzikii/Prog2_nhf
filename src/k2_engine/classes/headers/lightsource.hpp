#ifndef K2_ENGINE_LIGHTSOURCE_HPP_
#define K2_ENGINE_LIGHTSOURCE_HPP_

#include "mat4.hpp"
#include "vec4.hpp"

namespace k2_engine{
extern const double LUMINOSITY_MAX;

class Lightsource{
    Vec4 pos;
    double brightness;
    double lightdistance;

    public:
    Lightsource(Vec4& pos, double dist, double bright):pos(pos),lightdistance(dist),brightness(bright){}
    Lightsource(Vec4 pos, double dist, double bright):pos(pos),lightdistance(dist),brightness(bright){}
    Vec4 getpos(){return pos;}
    double getdist(){return lightdistance;}
    double getbrightness(){return brightness;}
    void setdist(double dist){lightdistance = dist;}

};


} // namespace k2_engine

#endif // K2_ENGINE_LIGHTSOURCE_HPP_