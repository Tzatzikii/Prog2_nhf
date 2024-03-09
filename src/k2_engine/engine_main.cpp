#include "engine_main.hpp"

namespace k2_engine{

const double PI = 3.14159265;
const size_t TERMINAL_HEIGHT = 40;
const size_t TERMINAL_WIDTH = 80;



void Renderer::add_lightsource(Lightsource lightsource){
        lightsources.push_back(lightsource);
}
void Renderer::render(){

        for(int i = 0; i < globaltriangles.size(); i++){

                Triangle& current = globaltriangles[i];
                Vertex3 v0 = set_realtive_vertex(current.get_vector0());
                Vertex3 v1 = set_realtive_vertex(current.get_vector1());
                Vertex3 v2 = set_realtive_vertex(current.get_vector2());
                rasters.push_back(Raster(project_vertex(v0), project_vertex(v1), project_vertex(v2)));
        }

        for(int i = 0; i < rasters.size(); i++){

                Raster& current = rasters[i];
                rasterize(current);

        }

        rasters.clear();
        #ifndef DEBUG
        outbuf.push_to_stdout();
        #endif //DEBUG
        outbuf.clear_buffer();

}

//!not used vvvvvvvvvvvv
void Renderer::add_triangle(Vec4& v0, Vec4& v1, Vec4& v2){

        globaltriangles.push_back(Triangle(v0, v1, v2));

}

void Renderer::add_triangle(Triangle t){

        globaltriangles.push_back(t);
}

double Renderer::calculate_luminosity(Vec4& v){

        double luminosity = 0;

        for(int i = 0; i < lightsources.size(); i++){

                Lightsource current = lightsources[i];
                double dist = pyth3d(v.get_x() - current.get_pos().get_x(),
                                v.get_y() - current.get_pos().get_y(),
                                v.get_z() - current.get_pos().get_z());

                if(dist > current.get_range()) luminosity += 0;
                else luminosity += (LUMINOSITY_MAX*(current.get_brightness()/dist))/lightsources.size();

                clamp<double>(luminosity, 1, LUMINOSITY_MAX);

        }

        return luminosity;

}

Vertex3 Renderer::set_realtive_vertex(Vec4 v){

        Mat4 rotx_m(Mat4::ROTATION_X, camera.get_rot_x());
        Mat4 roty_m(Mat4::ROTATION_Y, camera.get_rot_y());
        Mat4 rotz_m(Mat4::ROTATION_Z, camera.get_rot_z());

        Vec4 relative = rotx_m*roty_m*(v - camera.get_pos());
        double luminosity = calculate_luminosity(v);
        return Vertex3(relative, luminosity);

}

Px Renderer::project_vertex(Vertex3& vx){

        // Ez így elég csúnya lesz (as in: mátrixokkal szebb lenne),
        // de lusta vagyok újraírni.. :v)
        double projected_x = camera.get_screendist()/vx.get_z()*vx.get_x() + screenoffset_x;
        double projected_y = camera.get_screendist()/vx.get_z()*vx.get_y() + screenoffset_y;
        return Px(projected_x, projected_y, vx.get_luminosity());

}

//muh
double interpolate(double n0, double n1, double diff){

        double dn = fabs(n1 - n0);
        return n0 + dn*diff;

}

void Renderer::plothigh_interp(const Px& v0, const Px& v1, std::vector<Px>& edge){

        int dx = round(v1.get_x() - v0.get_x());
        int dy = round(v1.get_y() - v0.get_y());
        int xi = 1;

        if(dx < 0){

                xi = -1;
                dx = -dx;

        }

        int D = (2 * dx) - dy;
        int x = round(v0.get_x());

        for(int y = (int)v0.get_y(); y < (int)v1.get_y(); y++){
                
                double diff = (double)y/(double)dy;
                double interpolated_luminosity = interpolate(v0.get_luminosity(), v1.get_luminosity(), diff);
                edge.push_back(Px(x, y, interpolated_luminosity));

                if(boundary(x, 0, TERMINAL_WIDTH) && boundary(y, 0, TERMINAL_HEIGHT)){

                        outbuf.set_buffer(x, y, calculate_grayscale(interpolated_luminosity));

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

void Renderer::plotlow_inpterp(const Px& v0, const Px& v1, std::vector<Px>& edge){

        int dx = round(v1.get_x() - v0.get_x());
        int dy = round(v1.get_y() - v0.get_y());
        int yi = 1;
        #ifdef DEBUG
        std::cout << "v0 luminosity: " << v0.get_luminosity() << "\nv1 luminosity: " << v0.get_luminosity() << std::endl; 
        #endif //DEBUG
        if(dy < 0){

                yi = -1;
                dy = -dy;

        }

        int D = (2*dy) - dx;
        int y = round(v0.get_y());

        for(int x = round(v0.get_x()); x < round(v1.get_x()); x++){
                
                double diff = (double)x/(double)dx;
                char interpolated_luminosity = interpolate(v0.get_luminosity(), v1.get_luminosity(), diff);
                edge.push_back(Px(x, y, interpolated_luminosity));

                if(boundary(x, 0, TERMINAL_WIDTH) && boundary(y, 0, TERMINAL_HEIGHT)){

                        outbuf.set_buffer(x, y, calculate_grayscale(interpolated_luminosity)); 

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

void Renderer::bresenham(const Px& v0, const Px& v1, std::vector<Px>& edge){

        int dx = round(v1.get_x() - v0.get_x());
        int dy = round(v1.get_y() - v0.get_y());

        if(abs(dy) < abs(dx)){

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

void Renderer::rasterize(Raster& r){

        std::vector<Px> edge0 = r.ref_edge0();
        std::vector<Px> edge1 = r.ref_edge1();
        std::vector<Px> edge2 = r.ref_edge2();
        //wireframe elkészítése Bresemham-algoritmussal
        bresenham(r.get_vertex0(), r.get_vertex1(), edge0);
        bresenham(r.get_vertex1(), r.get_vertex2(), edge1);
        bresenham(r.get_vertex2(), r.get_vertex0(), edge2);
        
        
}

} //namespace k_engine