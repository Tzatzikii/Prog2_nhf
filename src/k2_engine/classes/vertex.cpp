#include "headers/vertex.hpp"

namespace k2_engine{

const char GRAYSCALE[] = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'. ";


char Vertex3::calculate_grayscale(){
    double scale = (double)std::strlen(GRAYSCALE);
    double ratio = scale / LUMINOSITY_MAX;
    int index = (int)(ratio * luminosity);
    return GRAYSCALE[index];
}

Vertex3::Vertex3(const Vec4& v, double lumin):x(v.getX()),y(v.getY()),z(v.getZ()),luminosity(lumin){
    grayscale = calculate_grayscale();
}

} // namespace k2_engine