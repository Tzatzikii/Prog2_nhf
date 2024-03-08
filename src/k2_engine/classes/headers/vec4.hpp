/**
 * @file vec4.hpp
 * @author Klemm Gábor - Neptun: H8XK58
 * @brief A vektor modul megvalósítása, a mátrix "párja"
 * @version 0.1
 * @date 2024-03-08
 * 
 * 
 */
#ifndef K2_ENGINE_VEC4_HPP_
#define K2_ENGINE_VEC4_HPP_

#include <cmath>
#include "mat4.hpp"
namespace k2_engine{

class Mat4;
/**
 * @brief Osztály egy négy dimenzióra kiterjesztett vektorhoz
 * @param x
 * @param y
 * @param z
 * @param w - ált. nincs használva és az értéke 1, de van eset amikor kell
 * @note A konstruktort, setter/gettereket nem fogom részletezni, mert magától értetődőek
 */
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
        /**
         * @brief *= Operátor mátrixra és vektorra
         *           habár a kódban jobb oldalon van,
         *           a paraméter bal oldali mátrixként szerepel,
         *           hiszen jobb oldalról nincs definiálva
         * 
         * @param lhs_m 
         * @return Vec4& 
         */
        Vec4& operator*=(const Mat4& lhs_m);
        Vec4 operator-(const Vec4& rhs_v) const;

}; //class Vec4


} //namespace k2_engine

#endif //K2_ENGINE_MAT4_HPP