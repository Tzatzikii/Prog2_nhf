#include "headers/camera.hpp"

namespace k2_engine{

void Camera::offsetpos(double xmod, double ymod, double zmod){
    pos.set_x(pos.get_x()+xmod);
    pos.set_y(pos.get_y()+ymod);
    pos.set_z(pos.get_z()+zmod);
}

void Camera::rotate(double dx, double dy, double dz){
    rot_x += dx;
    rot_y += dy;
    rot_z += dz;
}

}