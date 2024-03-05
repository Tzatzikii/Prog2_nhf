#include "k2_engine/engine_main.hpp"

using namespace k2_engine;
int main(){
    outp::clrscrn();
    Renderer renderer;
    renderer.pushvec4(Vec4(-10, -5, 10));
    renderer.pushvec4(Vec4(10, -5, 10));
    renderer.pushvec4(Vec4(-10, -5, 30));
    renderer.pushvec4(Vec4(10, -5, 30));
    renderer.addlsource(Lightsource(Vec4(0, -100, 20), 100, 1));
    Camera& camera = renderer.camera;
    outp::Cursor().hide(); //disables on exit
    outp::Rawmode().enable(); //disables on exit
    //camera.offsetpos(0, 0, -5);
    //renderer.render();
    char c = 0;
    int count = 0;
    while(c != 'q'){
        count = outp::kbhit();
        if(!!count) c = std::getchar();
        else c = 0;
        #ifdef DEBUG
        std::cout << count << c << std::endl;
        #endif

        if(c == 'w') camera.offsetpos(0, 0, 1);
        if(c == 's') camera.offsetpos(0, 0, -1);
        if(c == 'a') camera.offsetpos(-1, 0, 0);
        if(c == 'd') camera.offsetpos(1, 0, 0);
        renderer.render();
        outp::usleep(1000*50);
    }

    outp::Cursor().reset();
    //Cursor show
    //Rawmode enable

    //outp::clrscrn();
    return 0;
}