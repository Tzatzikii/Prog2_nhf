#include "headers/vertex.hpp"

namespace k2_engine{

const char GRAYSCALE[] = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'.";

Vertex2::Vertex2(double x, double y, double flatlumin):x(x),y(y),flatlumin(flatlumin){}
char calculate_grayscale(double luminosity){
    if(luminosity == 0) return 0;
    int scale = std::strlen(GRAYSCALE);
    double ratio = (int)scale / LUMINOSITY_MAX;
    int index = scale - (int)(ratio * luminosity);
    #ifdef DEBUG
    std::cout << "glum: "<< luminosity << " gscale: " << scale << " gratio: " << ratio << " gindex: " << index << std::endl;
    #endif //DEBUG
    return GRAYSCALE[index];
}

Vertex3::Vertex3(const Vec4& v, double lumin):x(v.getX()),y(v.getY()),z(v.getZ()),luminosity(lumin){
    //grayscale = calculate_grayscale();
}


void RenderTriangle::rasterize(){
    
}



} // namespace k2_engine