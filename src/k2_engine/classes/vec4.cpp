#include "headers/vec4.hpp"

namespace k2_engine{


Vec4::Vec4(double x, double y, double z, double w):x(x),y(y),z(z),w(w){}

Vec4& Vec4::operator*=(const Mat4& lhs_m){  //lhs_matrix, mert igazából nem definiáljuk a 
                                            //vektorok szorzását mátrixxal jobbról
    *this = lhs_m*(*this);
    return *this;
}

}