#include "engine_main.hpp"

namespace k2_engine{
const double PI = 3.14159265;
const int TERMINAL_HEIGHT = 24;
const int TERMINAL_WIDTH = 80;

void Renderer::pushvec4(Vec4 vector){
    globalvectors.push_back(vector);
}

void Renderer::addlsource(Lightsource lsource){
    lights.push_back(lsource);
}
void Renderer::render(){
    set_relative_vertices();
    project_vertices();
    for(int i = 0; i < flatvertices.size(); i++){
        Vertex2& current = flatvertices[i];
        int screenx = (int)current.getX();
        int screeny = (int)current.getY();
        screenx = clamp(screenx, 0, TERMINAL_WIDTH);
        screeny = clamp(screeny, 0, TERMINAL_HEIGHT);
        
        outp::coutXY<char>(screenx, screeny, current.gettxtr());
    }
    
}
double Renderer::calculate_luminosity(Vec4& v){
    double luminosity = 0;
    for(int i = 0; i < lights.size(); i++){
        Lightsource current = lights[i];
        double vdist = pyth3d(v.getX() - current.getpos().getX(),
                              v.getY() - current.getpos().getY(),
                              v.getZ() - current.getpos().getZ());
        if(vdist > current.getdist()) luminosity += 0;
        else luminosity += (LUMINOSITY_MAX*(current.getbrightness()/vdist))/lights.size();
        luminosity = clamp<double>(luminosity, 0, LUMINOSITY_MAX - 1);
        //else luminosity += (LUMINOSITY_MAX*(vdist/(current.getdist()*1/current.getbrightness())))/lights.size();

        #ifdef DEBUG
        std::cout << "vdist: " << vdist << " luminosity: "  << luminosity << std::endl;
        #endif //DEBUG
    }
    return luminosity;
}

Vertex3 Renderer::set_realtive_vertex(Vec4& v){
    Mat4 rotx_m(Mat4::ROTATION_X, camera.getrotX());
    Mat4 roty_m(Mat4::ROTATION_Y, camera.getrotY());
    Mat4 rotz_m(Mat4::ROTATION_Z, camera.getrotZ());

    Vec4 relative = rotx_m*roty_m*(v - camera.getpos());
    double luminosity = calculate_luminosity(v);
    return Vertex3(relative, luminosity);
}

Vertex2 Renderer::project_vertex(Vertex3& vx){
    // Ez így elég csúnya lesz (as in: mátrixokkal szebb lenne),
    // de lusta vagyok újraírni.. :v)
    double projected_x = camera.getdist()/vx.getZ()*vx.getX() + flatscreenoffsetX;
    double projected_y = camera.getdist()/vx.getZ()*vx.getY() + flatscreenoffsetY;
    return Vertex2(projected_x, projected_y, vx.getgrayscale());
}

void Renderer::project_vertices(){
    // Ez így elég csúnya lesz (as in: mátrixokkal szebb lenne),
    // de lusta vagyok újraírni.. :v)
    for(int i = 0; i < localvertices.size(); i++){
        Vertex3& current = localvertices[i];
        flatvertices.push_back(project_vertex(current));
    }
    

}
void Renderer::set_relative_vertices(){
    for(int i = 0; i < globalvectors.size(); i++){
        Vec4& current = globalvectors[i];
        localvertices.push_back(set_realtive_vertex(current));
    }
}

}