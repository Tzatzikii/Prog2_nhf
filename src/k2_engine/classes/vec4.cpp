#include "headers/vec4.hpp"

namespace k2_engine{

Vec4& Vec4::operator*=(const Mat4& lhs_m){  //lhs_matrix, mert igazából nem definiáljuk a 
                                            //vektorok szorzását mátrixxal jobbról
        *this = lhs_m*(*this);
        return *this;
}

Vec4 Vec4::operator-(const Vec4& rhs_v) const{
        
        return Vec4(x-rhs_v.x, y-rhs_v.y, z-rhs_v.z, w-rhs_v.w);
}      

} //namespace k_engine