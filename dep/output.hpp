#ifndef OUTPUT_HPP_
#define OUTPUT_HPP_

#include <iostream>
#include <cassert>

#define ARROW_LEFT 37
#define ARROW_UP 38
#define ARROW_RIGHT 39
#define ARROW_DOWN 40

namespace outp{

#ifdef __linux__
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

struct Rawmode{
    static void disable();
    static void enable();
};

char keystroke();
#endif //__linux__

struct Cursor{
    static void hide();
    static void show();
    static void move(int x, int y);
    static void reset();
};
inline void clrscrn(){ std::cout << "\x1B[2J"; }

template <typename T>
void coutXY(int x, int y, const T c, bool duplicate = true, bool stretch = true){
    if(stretch) x*=2;
    Cursor().move(x, y);
    std::cout << c;
    if(duplicate) std::cout << c;
}


} //namespace outp

#endif //OUTPUT_HPP_