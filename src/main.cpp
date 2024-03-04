#include "k2_engine/engine_main.hpp"

using namespace k2_engine;

int main(){
    outp::Cursor().hide();
    char c;
    int x = 1;
    int y = 1;
    while(c != 'q'){
        outp::coutXY(x, y, '#');
        c = outp::keystroke();
        if(c == 'a') x--;
        if(c == 'd') x++;
        if(c == 'w') y--;
        if(c == 's') y++;
        outp::clrscrn();
    }
    outp::Cursor().show();
    outp::Rawmode().disable();
    return 0;
}