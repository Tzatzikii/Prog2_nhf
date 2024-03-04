#include "headers/camera.hpp"

namespace k2_engine{

void Camera::offsetpos(double xmod, double ymod, double zmod){
    pos.setX(pos.getX()+xmod);
    pos.setY(pos.getY()+ymod);
    pos.setZ(pos.getZ()+zmod);
}


}