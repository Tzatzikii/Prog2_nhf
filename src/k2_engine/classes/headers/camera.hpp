/**
 * @file camera.hpp
 * @author Klemm Gábor - Neptun: H8XK58
 * @brief A kamera osztályért felelős modul, ez szolgál alapul a
 *        perspektivikus vetítéshez
 * @version 0.1
 * @date 2024-03-08
 * 
 * 
 */
#ifndef K2_ENGINE_CAMERA_HPP_
#define K2_ENGINE_CAMERA_HPP_

#include "mat4.hpp"
#include "vec4.hpp"

namespace k2_engine{

/**
 * @brief Eddig az egyetlen osztály a modulban, egy nagyon triviális
 *        osztály, triviális változókkal, tulajdonképpen csak változók
 *        tárolására van létrehozva
 * @param rotX - a kamera x tengely körüli elfordulása
 * @param rotY - a kamera y tengely körüli elfordulása
 * @param rotZ - a kamera z tengely körüli elfordulása 
 *               (Habár ezt kétlem, hogy bármikor meg kéne változtatni, azért nem konstans)
 * @param pos - egy négy dimenziós vektor osztály (ld. vec4.hpp)
 * @param screendist - a kamera képernyőtől való távolsága
 * @note Nem mindegyik settert/gettert részletezem a dokumentációban, ha teljesen magukért beszélnek
 */
class Camera{

        double rotX;
        double rotY;
        double rotZ;
        Vec4 pos;
        double screendist;

public:

        /**
         * @brief Egy új kamerát hoz létre
         * @note 10 egységnyi távolságnál közelebb nem éremes
         *       hozni a képernyőhöz (főleg nem 0-ra)
         */
        Camera(Vec4 pos = Vec4(0, 0, 0), double rotX = 0, double rotY = 0, double rotZ = 0, double screendist = 10)
                :rotX(rotX),rotY(rotY),rotZ(rotZ),pos(pos),screendist(screendist){}
                
        /**
         * @brief Megadott vektorértékre állítja a pozíciót
         * 
         * @param newpos 
         */
        void setpos(const Vec4& newpos){pos = newpos;}

        /**
         * @brief Elforgatja a kamerát megadott paraméterekkel
         * TODO forgatás budos asf valami miatt
         * @param dx 
         * @param dy 
         * @param dz 
         */
        void rotate(double dx, double dy, double dz);

        /**
         * @brief Eltolja megadott modifikációs értékkekel (NEM modulus)
         * ? Mátrixokkal szebb lenne talán (?)
         * @param xmod 
         * @param ymod 
         * @param zmod 
         */
        void offsetpos(double xmod, double ymod, double zmod);

        double getrotX() const{return rotX;}
        double getrotY() const{return rotY;}
        double getrotZ() const{return rotZ;}
        double getdist() const{return screendist;}
        Vec4 getpos() const{return pos;}

}; // class Camera

} // namespace k2_engine

#endif // K2_ENGINE_CAMERA_HPP_