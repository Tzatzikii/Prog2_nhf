#ifndef OUTPUT_HPP
#define OUTPUT_HPP

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

extern struct termios original;
struct Cursor{
    static void hide();
    static void show();
    static void move(int x, int y);
};

inline void coutXY(int x, int y, const char c){
    Cursor().move(x, y);
    std::cout << c;
}

inline void clrscrn(){ std::cout << "\x1B[2J"; }

} //namespace outp

#endif //OUTPUT_HPP