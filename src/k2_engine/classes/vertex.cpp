#include "headers/vertex.hpp"

namespace k2_engine{

const char GRAYSCALE[] = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'.";


char Vertex3::calculate_grayscale(){
    if(luminosity == 0) return 0;
    int scale = std::strlen(GRAYSCALE);
    double ratio = (int)scale / LUMINOSITY_MAX;
    int index = (int)(ratio * luminosity);
    return GRAYSCALE[scale - index - 1];
}

Vertex3::Vertex3(const Vec4& v, double lumin):x(v.getX()),y(v.getY()),z(v.getZ()),luminosity(lumin){
    grayscale = calculate_grayscale();
}


void RenderTriangle::rasterize(){
    
}

void Vertex2::bresenham(const Vertex2& v0, const Vertex2& v1, std::vector<Vertex2&>& vertexarray){
}

} // namespace k2_engine