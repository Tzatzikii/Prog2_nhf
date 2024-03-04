#include "k2_engine/engine_main.hpp"

using namespace k2_engine;
int main(){
    // outp::Cursor().hide(); //disables on exit
    // outp::Rawmode().enable(); //disables on exit
    char c;
    int x = 1;
    int y = 1;
    Mat4 m(Mat4::ROTATION_X, PI/2);
    Mat4 m2;
    Vec4 v(1, 1, 1);
    std::cout << v.getX() << std::endl;
    // while(c != 'q'){
    //     outp::coutXY<int>(x, y, m(0, 0));
    //     c = outp::keystroke();
    //     if(c == 'a') x--;
    //     if(c == 'd') x++;
    //     if(c == 'w') y--;
    //     if(c == 's') y++;
    //     outp::clrscrn();
    // }

    //outp::Cursor().reset();
    //Cursor show
    //Rawmode enable
    return 0;
}