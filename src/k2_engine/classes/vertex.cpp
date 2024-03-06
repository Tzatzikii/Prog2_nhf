#include "headers/vertex.hpp"

namespace k2_engine{

const char GRAYSCALE[] = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'.";

Vertex2::Vertex2(double x, double y, char lumin_txtr):x(x),y(y),flatlumin(flatlumin){
    texture = calculate_grayscale();
}
char Vertex2::calculate_grayscale(){
    if(flatlumin == 0) return 0;
    int scale = std::strlen(GRAYSCALE);
    double ratio = (int)scale / LUMINOSITY_MAX;
    int index = scale - (int)(ratio * flatlumin);
    #ifdef DEBUG
    std::cout << "glum: "<< flatlumin << " gscale: " << scale << " gratio: " << ratio << " gindex: " << index << std::endl;
    #endif //DEBUG
    return GRAYSCALE[index];
}

Vertex3::Vertex3(const Vec4& v, double lumin):x(v.getX()),y(v.getY()),z(v.getZ()),luminosity(lumin){
    //grayscale = calculate_grayscale();
}


void RenderTriangle::rasterize(){
    
}

double Vertex2::interpolate(double n0, double n1, double diff){
    
    return 0;
}

void Vertex2::plothigh_interp(Vertex2& v0, Vertex2& v1, std::vector<Vertex2>& vertexarray){
    int dx = (int)(v1.getX() - v0.getX());
    int dy = (int)(v1.getX() - v0.getY());
    int xi = 1;
    if(dx < 0){
        xi = -1;
        dx = -dx;
    }
    int D = (2 * dx) - dy;
    int x = (int)(v0.getX());
    for(int y = (int)v0.getY(); y < (int)v1.getY(); y++){
        double diff = (double)y/(double)dy;
        double interpolated_lumin = interpolate(v0.getluminosity(), v1.getluminosity(), diff);
        vertexarray.push_back(Vertex2(x, y, interpolated_lumin));
        outp::coutXY<char>(x, y, vertexarray.back().gettxtr());
        if(D > 0){
            x += xi;
            D += 2*(dx - dy);
        }
        else{
            D += 2*dx;
        } 
    }
}
void Vertex2::plotlow_inpterp(Vertex2& v0, Vertex2& v1, std::vector<Vertex2>& vertexarray){
    int dx = (int)(v1.getX() - v0.getX());
    int dy = (int)(v1.getX() - v0.getY());
    int yi = 1;
    if(dy < 0){
        yi = -1;
        dy = -dy;
    }
    int D = (2*dy) - dx;
    int y = (int)v0.getY();
    for(int x = (int)v0.getX(); x < (int)v1.getX(); x++){
        double diff = (double)x/(double)dx;
        char interpolated_lumin = interpolate(v0.getluminosity(), v1.getluminosity(), diff);
        vertexarray.push_back(Vertex2(x, y, interpolated_lumin));
        outp::coutXY<char>(x, y, vertexarray.back().gettxtr());
        if(D > 0){
            y += yi;
            D += 2*(dy - dx);
        }
        else{
            D+= 2*dy;
        }
    }
}

void Vertex2::bresenham(const Vertex2& v0, const Vertex2& v1, std::vector<Vertex2>& vertexarray){

}

} // namespace k2_engine