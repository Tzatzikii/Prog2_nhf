#ifndef UTILS_HPP_
#define UTILS_HPP_

#include <cmath>

namespace k2_engine{

//#define DEBUG

template <typename T>
inline void swap(T& A, T& B){
    T C = A;
    A = B;
    B = C;
}
template <typename T>
inline void clamp(T& val, T min, T max){
    if(val < min) val = min;
    else if(val > max) val = max;
}
inline bool boundary(double val, double min, double max){
    return (val > min && val < max);
}

inline double pyth2d(double a, double b){return sqrt(a*a + b*b);}
inline double pyth3d(double a, double b, double c){return sqrt(a*a + b*b + c*c);}
inline double pyth2d(int a, int b){return sqrt(a*a + b*b);}
inline double pyth3d(int a, int b, double c){return sqrt(a*a + b*b + c*c);}

} // namespace k2_engine

#endif // UTILS_HPP_