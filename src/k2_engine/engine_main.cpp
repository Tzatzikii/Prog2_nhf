#include "engine_main.hpp"

namespace k2_engine{
const double PI = 3.14159265;
const int TERMINAL_HEIGHT = 24;
const int TERMINAL_WIDTH = 80;

void Renderer::pushvec4(Vec4 vector){
    globalvectors.push_back(vector);
}
void Renderer::render(){
    set_relative_vertices();
    project_vertices();
    for(int i = 0; i < flatvertices.size(); i++){
        Vertex2& current = flatvertices[i];
        outp::coutXY((int)current.getX(), (int)current.getY(), '#');
    }
    
}

void Renderer::set_relative_vertices(){

    Mat4 rotx_m(Mat4::ROTATION_X, camera.getrotX());
    Mat4 roty_m(Mat4::ROTATION_Y, camera.getrotY());
    Mat4 rotz_m(Mat4::ROTATION_Z, camera.getrotZ());

    for(int i = 0; i < globalvectors.size(); i++){
        Vec4& current = globalvectors[i];
        Vec4 relative;
        relative = rotx_m*roty_m*rotz_m*(current - camera.getpos());
        localvertices.push_back(Vertex3(relative));
    }
}

void Renderer::project_vertices(){
    // Ez így elég csúnya lesz (as in: mátrixokkal szebb lenne),
    // de lusta vagyok újraírni.. :v)
    for(int i = 0; i < localvertices.size(); i++){
        Vertex3& current = localvertices[i];
        double projected_x = camera.getdist()/current.getZ()*current.getX() + flatscreenoffsetX;
        double projected_y = camera.getdist()/current.getZ()*current.getY() + flatscreenoffsetY;
        flatvertices.push_back(Vertex2(projected_x, projected_y));
    }
    

}

}