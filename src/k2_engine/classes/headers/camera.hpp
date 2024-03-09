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
 * @param rad_x - a kamera x tengely körüli elfordulása
 * @param rad_x - a kamera y tengely körüli elfordulása
 * @param rad_z - a kamera z tengely körüli elfordulása 
 *               (Habár ezt kétlem, hogy bármikor meg kéne változtatni, azért nem konstans)
 * @param pos - egy négy dimenziós vektor osztály (ld. vec4.hpp)
 * @param screendist - a kamera képernyőtől való távolsága
 * @note Nem mindegyik settert/gettert részletezem a dokumentációban, ha teljesen magukért beszélnek
 */
class Camera{

        double rot_x;
        double rot_y;
        double rot_z;
        Vec4 pos;
        double screendist;

public:

        /**
         * @brief Egy új kamerát hoz létre
         * @note 10 egységnyi távolságnál közelebb nem éremes
         *       hozni a képernyőhöz (főleg nem 0-ra)
         */
        Camera(Vec4 pos = Vec4(0, 0, 0), double rot_x = 0, double rot_y = 0, double rot_z = 0, double screendist = 10)
                :rot_x(rot_x), rot_y(rot_y), rot_z(rot_z), pos(pos), screendist(screendist){}

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

        double get_rot_x() const{return rot_x;}
        double get_rot_y() const{return rot_y;}
        double get_rot_z() const{return rot_z;}
        double get_screendist() const{return screendist;}
        Vec4 get_pos() const{return pos;}

}; // class Camera

} // namespace k2_engine

#endif // K2_ENGINE_CAMERA_HPP_