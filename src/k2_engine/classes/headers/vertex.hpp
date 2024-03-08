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
 * @param flatlumin - a leképzett él "fényességét" írja le (kicsit rossz neve van, de már így marad)
 * @note Ahogy a legtöbb helyen, a metódusai ismét magától értetődnek, csak egy tároló
 * TODO Pixellé alakítani és mitigálni az EdgePoint classal, de előbb raszterizálok
 */
class Vertex2{
        double x, y;
        double flatlumin;

public:

        Vertex2(double x, double y, double flatlumin);
        double getX() const{return x;}
        double getY() const{return y;}
        double getluminosity() const{return flatlumin;}
    
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

        double getX() const {return x;}
        double getY() const {return y;}
        double getZ() const {return z;}
        double getluminosity() const {return luminosity;}
        Vertex3(const Vec4&, double lumin);

    
};

class Ept{

        int x,y;
        double luminosity;

public:

        Ept(int x, int y, double luminosity):x(x), y(y), luminosity(luminosity){}

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
        Vec4 v0;
        Vec4 v1;
        Vec4 v2;

public:

        Triangle(Vec4 v0, Vec4 v1, Vec4 v2):v0(v0),v1(v1),v2(v2){}
        Vec4 getv0() const {return v0;}
        Vec4 getv1() const {return v1;}
        Vec4 getv2() const {return v2;}
};

/**
 * @brief Render háromszög, már ki van lapítva a képernyő síkjára,
 *        tovább lehet adni raszterizációra
 *        Három két dimenziós vektor csúcsból áll
 *        Tárol továbbá három "EdgePoint" oszályt tartalmazó vektort,
 *        ami alapján zajlik a raszterizáció
 *
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
class RenderTriangle{
        Vertex2 vx0;
        Vertex2 vx1;
        Vertex2 vx2;
        std::vector<Ept> edge0;
        std::vector<Ept> edge1;
        std::vector<Ept> edge2;

public: 

        RenderTriangle(Vertex2 vx0, Vertex2 vx1, Vertex2 vx2):vx0(vx0),vx1(vx1),vx2(vx2){}
        std::vector<Ept>& edge0ref(){return edge0;};
        std::vector<Ept>& edge1ref(){return edge1;};
        std::vector<Ept>& edge2ref(){return edge2;};
        Vertex2 getvx0() const {return vx0;}
        Vertex2 getvx1() const {return vx1;}
        Vertex2 getvx2() const {return vx2;}

};

} // namespace k2_engine

#endif // K2_ENGINE_VERTEX_HPP_