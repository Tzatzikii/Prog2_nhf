#include "engine_main.hpp"

namespace k2_engine{
const double PI = 3.14159265;
const size_t TERMINAL_HEIGHT = 24;
const size_t TERMINAL_WIDTH = 80;

// void Renderer::pushvec4(Vec4 vector){
//     globalvectors.push_back(vector);
// }

void Renderer::addlsource(Lightsource lsource){
    lights.push_back(lsource);
}
void Renderer::render(){
    for(int i = 0; i < globaltriangles.size(); i++){
        Triangle& current = globaltriangles[i];
        Vertex3 v0 = set_realtive_vertex(current.getv0());
        Vertex3 v1 = set_realtive_vertex(current.getv1());
        Vertex3 v2 = set_realtive_vertex(current.getv2());
        flattriangles.push_back(RenderTriangle(project_vertex(v0), project_vertex(v1), project_vertex(v2)));
    }
    for(int i = 0; i < flattriangles.size(); i++){
        RenderTriangle& current = flattriangles[i];
        double x0 = current.getvx0().getX();
        double y0 = current.getvx0().getY();
        double x1 = current.getvx1().getX();
        double y1 = current.getvx1().getY();
        double x2 = current.getvx2().getX();
        double y2 = current.getvx2().getY();
        #ifdef DEBUG
        //std::cout << x
        #endif // DEBUG
        if(boundary(x0, 0, TERMINAL_WIDTH) && boundary(y0, 0, TERMINAL_HEIGHT)){
            outbuf.setbuffer(x0, y0, current.getvx0().gettxtr());
        }
        if(boundary(x1, 0, TERMINAL_WIDTH) && boundary(y1, 0, TERMINAL_HEIGHT)){
            outbuf.setbuffer(x1, y1, current.getvx1().gettxtr());
        }
        if(boundary(x2, 0, TERMINAL_WIDTH) && boundary(y2, 0, TERMINAL_HEIGHT)){
            outbuf.setbuffer(x2, y2, current.getvx2().gettxtr());
        }
    }
    flattriangles.clear();
    outbuf.pushtostdout();
    outbuf.clearbuffer();

}
void Renderer::addtriangle(Vec4& v0, Vec4& v1, Vec4& v2){
    globaltriangles.push_back(Triangle(v0, v1, v2));
}
void Renderer::addtriangle(Triangle t){
    #ifdef DEBUG
    std::cout << "xv0: " << t.getv0().getX() << std::endl;
    #endif //DEBUG
    
    globaltriangles.push_back(t);
}
// void Renderer::render(){
//     set_relative_vertices();
//     project_vertices();
//     for(int i = 0; i < flatvertices.size(); i++){
//         Vertex2& current = flatvertices[i];
//         if(current.getX() < TERMINAL_WIDTH && current.getY() < TERMINAL_HEIGHT && current.getX() > 0 && current.getY() > 0){
//             outbuf.setbuffer(current.getX(), current.getY(), current.gettxtr());
//         }
//     }
//     localvertices.clear();
//     flatvertices.clear();
//     outbuf.pushtostdout();
//     outbuf.clearbuffer();
    
// }
double Renderer::calculate_luminosity(Vec4& v){
    double luminosity = 0;
    for(int i = 0; i < lights.size(); i++){
        Lightsource current = lights[i];
        double vdist = pyth3d(v.getX() - current.getpos().getX(),
                              v.getY() - current.getpos().getY(),
                              v.getZ() - current.getpos().getZ());
        if(vdist > current.getdist()) luminosity += 0;
        else luminosity += (LUMINOSITY_MAX*(current.getbrightness()/vdist))/lights.size();
        luminosity = clamp<double>(luminosity, 1, LUMINOSITY_MAX);
        //else luminosity += (LUMINOSITY_MAX*(vdist/(current.getdist()*1/current.getbrightness())))/lights.size();

        #ifdef DEBUG
        std::cout << "vdist: " << vdist << " luminosity: "  << luminosity << std::endl;
        #endif //DEBUG
    }
    return luminosity;
}

Vertex3 Renderer::set_realtive_vertex(Vec4 v){
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
    return Vertex2(projected_x, projected_y, vx.getluminosity());
}

// void Renderer::project_vertices(){
//     for(int i = 0; i < localvertices.size(); i++){
//         Vertex3& current = localvertices[i];
//         flatvertices.push_back(project_vertex(current));
//     } 
// }
// void Renderer::set_relative_vertices(){
//     for(int i = 0; i < globalvectors.size(); i++){
//         Vec4& current = globalvectors[i];
//         localvertices.push_back(set_realtive_vertex(current));
//     }
// }



}