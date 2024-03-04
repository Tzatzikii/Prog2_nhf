#include "k2_engine/engine_main.hpp"

using namespace k2_engine;
int main(){
    outp::clrscrn();
    Renderer renderer;
    renderer.pushvec4(Vec4(10, 10, 10));
    renderer.pushvec4(Vec4(10, 10, 20));
    renderer.pushvec4(Vec4(0, 10, 50));
    renderer.addlsource(Lightsource(Vec4(10, 30, 30), 30, 10));
    renderer.render();
    std::cout<<std::endl;

    // outp::Cursor().hide(); //disables on exit
    // outp::Rawmode().enable(); //disables on exit
    // while(c != 'q'){
    //     outp::coutXY<int>(x, y, m(0, 0));
    //     c = outp::keystroke();
    //     if(c == 'a') x--;
    //     if(c == 'd') x++;
    //     if(c == 'w') y--;
    //     if(c == 's') y++;
    //     outp::clrscrn();
    // }

    outp::Cursor().reset();
    //Cursor show
    //Rawmode enable

    //outp::clrscrn();
    return 0;
}