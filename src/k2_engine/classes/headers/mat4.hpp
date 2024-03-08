/**
 * @file mat4.hpp
 * @author Klemm Gábor - H8XK58
 * @brief Mátrixok megvalósítása, hogy könnyebb legyen műveleteket végezni
 *        lineáris transzformációkhoz
 * @version 0.1
 * @date 2024-03-08
 * 
 */
#ifndef K2_ENGINE_MAT4_HPP_
#define K2_ENGINE_MAT4_HPP_

#include "vec4.hpp"
#include <cstring>
#include <cmath>

namespace k2_engine{

class Vec4;

/**
 * @brief Egy 4x4-es mátrix osztály
 * @param type - nem nagyon használom, de jó, ha eltárolja milyen típusú
 * @param theta - ha forgatásmátrix, ennyi fokkal forgat
 * @param body - 4x4-es mátrix tömb
 * @param enum - a mátrix létrehozásakor létrehozható felsorolás, inkább nem globálisan adtam meg
 */
class Mat4{
        int type;
        int theta;
        double body[4][4];

public:

        enum { IDENTITY = 0, EMPTY = 1, ROTATION_X = 2, ROTATION_Y = 3, ROTATION_Z = 4 };
        /**
         * @brief Egy új 4x4-es mátrixot hoz létre, paraméter nélkül egységmátrixot
         * 
         * @param type - a mátrix típusa, ezt egyértelműen Mat4::<MATRIXTYPE> alakban kell megadni
         * @param theta - abban az esetben, ha forgatásmátrixról van szó, kell mennyivel forgat
         */
        Mat4(int type = 0, double theta = 0);
        /**
         * @brief Mátrix indexelő operátor, valszeg le fogom cserélni setter/getterekre
         *        az átláthatóság érdekében
         * 
         * @param i - sor
         * @param j - oszlop
         * @note Hű a tradicionális mátrix notációhoz
         * @return double& 
         */
        double& operator()(int i, int j){return body[i][j];};
        /**
         * @brief Mateimatikai definíció szerint szoroz össze két mátrixot
         * 
         * @param rhs_m - jobb oldali mátrix paraméter
         * @return Mat4 
         */
        Mat4 operator*(const Mat4& rhs_m) const;
        Mat4& operator*=(const Mat4& rhs_m);
        /**
         * @brief Vektor szorzása balról mátrixxal
         * 
         * @param rhs_v - jobb oldali vektor paraméter
         * @return Vec4 
         */
        Vec4 operator*(const Vec4& rhs_v) const;
    

}; //class Mat4

} //namespace k2_engine

#endif //K2_ENGINE_MAT4_HPP_