#include "headers/mat4.hpp"

namespace k2_engine{

Mat4::Mat4(int type, double theta)
        :type(type), theta(theta){

        for(int i = 0; i < 4; i++){
                for(int j = 0; j < 4; j++){
                if(i == j) body[i][j] = 1;
                else body[i][j] = 0;
                }
        }

        double pc = cos(theta);
        double ps = sin(theta);
        double mc = -cos(theta);
        double ms = -sin(theta);

        switch(type){

                case IDENTITY:
                break;
                case EMPTY:
                        for(int i = 0; i < 4; i++){
                                body[i][i] = 0;
                        }
                break;
                case ROTATION_X:
                        body[1][1] = pc;
                        body[1][2] = ps;
                        body[2][1] = ms;
                        body[2][2] = pc;
                break;
                case ROTATION_Y:
                        body[0][0] = pc;
                        body[0][2] = ms;
                        body[2][0] = ps;
                        body[2][2] = pc;
                
                break;
                case ROTATION_Z:
                        body[0][0] = pc;
                        body[0][1] = ps;
                        body[1][0] = ms;
                        body[1][1] = pc;
                break;
                
        }
        
}

Vec4 Mat4::operator*(const Vec4& rhs_v) const{
    double x, y, z, w;
    x = y = z = w = 0;
    for(int j = 0; j < 4; j++){
        x += rhs_v.get_x()*body[0][j];
        y += rhs_v.get_y()*body[1][j];
        z += rhs_v.get_z()*body[2][j];
        w += rhs_v.get_w()*body[3][j];
        //std::cout << "x: " << x << " y: " << y << " z: " << z << std::endl;
    }
    return Vec4(x, y, z, w);
}

Mat4 Mat4::operator*(const Mat4& rhs_m) const{

        Mat4 prod(EMPTY);

        for(int i = 0; i < 4; i++){

                for(int j = 0; j < 4; j++){

                        for(int k = 0; k < 4; k++){

                                prod.body[i][j] += body[i][k]*rhs_m.body[k][j];

                        }
                }
        }

        return prod;

}

Mat4& Mat4::operator*=(const Mat4& rhs_m){

        *this = *this*rhs_m;
        return *this;

}

} //namespace k2_engine