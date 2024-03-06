#include "engine_main.hpp"

namespace k2_engine{
const double PI = 3.14159265;
const size_t TERMINAL_HEIGHT = 40;
const size_t TERMINAL_WIDTH = 80;



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
        bresenham(current.getvx0(), current.getvx1(), current.edge0ref());
        bresenham(current.getvx1(), current.getvx2(), current.edge1ref());
        bresenham(current.getvx2(), current.getvx0(), current.edge2ref());
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


double interpolate(double n0, double n1, double diff){
    double dn = fabs(n1 - n0);
    return n0 + dn*diff;
}

void Renderer::plothigh_interp(const Vertex2& v0, const Vertex2& v1, std::vector<Ept>& edge){
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
        edge.push_back(Ept(x, y, interpolated_lumin));
        if(boundary(x, 0, TERMINAL_WIDTH) && boundary(y, 0, TERMINAL_HEIGHT)){
            outbuf.setbuffer(x, y, calculate_grayscale(interpolated_lumin));
        }
        if(D > 0){
            x += xi;
            D += 2*(dx - dy);
        }
        else{
            D += 2*dx;
        } 
    }
}
void Renderer::plotlow_inpterp(const Vertex2& v0, const Vertex2& v1, std::vector<Ept>& edge){
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
        edge.push_back(Ept(x, y, interpolated_lumin));
        if(boundary(x, 0, TERMINAL_WIDTH) && boundary(y, 0, TERMINAL_HEIGHT)){
            outbuf.setbuffer(x, y, calculate_grayscale(interpolated_lumin));   
        }
        if(D > 0){
            y += yi;
            D += 2*(dy - dx);
        }
        else{
            D+= 2*dy;
        }
    }
}

void Renderer::bresenham(const Vertex2& v0, const Vertex2& v1, std::vector<Ept>& edge){
    double dx = v1.getX() - v0.getX();
    double dy = v1.getY() - v0.getY();
    if(fabs(dy) < fabs(dx)){
        if(dx < 0){
            plotlow_inpterp(v1, v0, edge);
        }
        else{
            plotlow_inpterp(v0, v1, edge);
        }
    }else{
        if(dy < 0){
            plothigh_interp(v1, v0, edge);
        }
        else{
            plothigh_interp(v0, v1, edge);
        }
    }
}

}