/**
 * @file lightsource.hpp
 * @author Klemm Gábor - H8XK58
 * @brief A fényforrás(ok)ért felelős modul
 * ? Későbbiekben talán mehet directional light meg egyébb fancy cuccok
 * @version 0.1
 * @date 2024-03-08
 * 
 * 
 */
#ifndef K2_ENGINE_LIGHTSOURCE_HPP_
#define K2_ENGINE_LIGHTSOURCE_HPP_

#include "mat4.hpp"
#include "vec4.hpp"

namespace k2_engine{

extern const double LUMINOSITY_MAX;

/**
 * @brief Egy gömbszerű fényforrás
 * ? Bővíteni több fajtára (?)
 * @param pos - egy vektor típus pizíciónak, ld. vec4.hpp
 * @param brightness - milyen erős a fénye
 * @param lightdistance - milyen messzire megy el a fénye
 * @note Egyértelmű setter/gettereket nem fogom részletezni
 */
class Lightsource{

        Vec4 pos;
        double brightness;
        double range;

public:

        /**
         * @brief Csinál egy új fényforrást
         * 
         * @param pos
         * @param dist 
         * @param bright 
         */
        Lightsource(Vec4 pos, double range, double brightness)
                :pos(pos),range(range),brightness(brightness){}
        Vec4 get_pos(){return pos;}
        double get_range(){return range;}
        double get_brightness(){return brightness;}
        void set_range(double new_range){range = new_range;}

}; // class Lightsource

} // namespace k2_engine

#endif // K2_ENGINE_LIGHTSOURCE_HPP_