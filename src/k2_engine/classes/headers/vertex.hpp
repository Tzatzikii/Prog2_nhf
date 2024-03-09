/**
 * @file vertex.hpp
 * @author Egy elég fontos modul, a Vertex oszály már a kamerához
 *         relatív leképzett 3 dimenziós csúcs, azt nem transzformálom
 *         és nem módosítom semmilyen formában a leképzés után
 *         Miután le lett képezve, 2 dimenziós csúcs lesz belőle, hogy
 *         lehessen raszterizálni
 * @brief 
 * @version 0.1
 * @date 2024-03-08
 * 
 * 
 */
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

//? Ez jó helyen van itt?
char calculate_grayscale(double luminosity);

//TODO jobb helyre átvinni a grascale-t
extern const char GRAYSCALE[];

/**
 * @brief 
 * @param x - már a terminálon lévő helye
 * @param y - már a terminálon lévő értéke
 * @param luminosity - a leképzett él "fényességét" írja le (kicsit rossz neve van, de már így marad)
 * @note Ahogy a legtöbb helyen, a metódusai ismét magától értetődnek, csak egy tároló
 */
class Px{
        double x, y;
        double luminosity;

public:

        Px(double x, double y, double luminosity);
        double get_x() const{return x;}
        double get_y() const{return y;}
        double get_luminosity() const{return luminosity;}
    
};

/**
 * @brief Kamerához relatív leképzett csúcs
 * @param x
 * @param y
 * @param z
 * @param luminosity - Az eredeti vektor fényforrástól való távolságából számított
 *                     fényességi érték
 */
class Vertex3{

        double x, y, z, luminosity;

public:

        Vertex3(const Vec4& vector, double luminosity)
                :x(vector.get_x()), y(vector.get_y()), z(vector.get_z()), luminosity(luminosity){}
        double get_x() const {return x;}
        double get_y() const {return y;}
        double get_z() const {return z;}
        double get_luminosity() const {return luminosity;}

    
};


/**
 * @brief Az egész motor háromszögekkel dolgozik, ezekből le lehet képezni kb minden polygont,
 *        a quadok és ezek is háromszögekből épülnek fel - később pedig ki vannak lapítva
 *        render háromszöggé, amin lehet futtatni egy rasztorizációs algoritmust
 * @param v0 - nulladik csúcsa egy vektor által megadva
 * @param v1 - első csúcsa vektor
 * @param v2 - egyértelműen a második csúcs vektor
 */
class Triangle{

        Vec4 vector0;
        Vec4 vector1;
        Vec4 vector2;

public:

        Triangle(Vec4 vector0, Vec4 vector1, Vec4 vector2)
                :vector0(vector0),vector1(vector1),vector2(vector2){}
        Vec4 get_vector0() const {return vector0;}
        Vec4 get_vector1() const {return vector1;}
        Vec4 get_vector2() const {return vector2;}
};

/**
 * @brief Render háromszög, már ki van lapítva a képernyő síkjára,
 *        tovább lehet adni raszterizációra
 *        Három két dimenziós vektor csúcsból áll
 *        Tárol továbbá három "EdgePoint" oszályt tartalmazó vektort,
 *        ami alapján zajlik a raszterizáció
 *!obsolete leírás !!! ^^^^^^^^^^^^^^^^^^^^^^^^
 * @param vx0
 * @param vx1
 * @param vx2
 * @param edge0
 * @param edge1
 * @param edge2 
 * @note Az élek sorszáma az a csúcs száma, amelyből egy normális koordináta-rendszerben
 *       balra jön ki az adott él. Ez elég szerencsétlen, mert balsodrású rendszert használok,
 *       és a fordított koordináta renszer miatt jobbsodrású szabály lesz belőle, de már
 *       így maradt, mert nincs túl sok jelentősége
 *? Átírni balsodrásúra
 */
class Raster{

        Px vertex0;
        Px vertex1;
        Px vertex2;
        std::vector<Px> edge0;
        std::vector<Px> edge1;
        std::vector<Px> edge2;

public: 

        Raster(Px vertex0, Px vertex1, Px vertex2)
                :vertex0(vertex0),vertex1(vertex1),vertex2(vertex2){}
        std::vector<Px>& ref_edge0(){return edge0;};
        std::vector<Px>& ref_edge1(){return edge1;};
        std::vector<Px>& ref_edge2(){return edge2;};
        Px get_vertex0() const {return vertex0;}
        Px get_vertex1() const {return vertex1;}
        Px get_vertex2() const {return vertex2;}

};

} // namespace k2_engine

#endif // K2_ENGINE_VERTEX_HPP_