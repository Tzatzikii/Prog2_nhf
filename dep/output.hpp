#ifndef OUTPUT_HPP_
#define OUTPUT_HPP_

#include "utils.hpp"
#include <iostream>
#include <cassert>
#include <vector>

#define ARROW_LEFT 37
#define ARROW_UP 38
#define ARROW_RIGHT 39
#define ARROW_DOWN 40

namespace outp{

#ifdef __linux__
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>

struct Rawmode{
    static void disable();
    static void enable();
};

int kbhit();
#endif //__linux__

struct Cursor{
    static void hide();
    static void show();
    static void move(size_t x, size_t y);
    static void reset();
};
inline void clrscrn(){ std::cout << "\x1B[2J"; }

template <typename T>
inline void coutXY(size_t x, size_t y, const T c, bool duplicate = true, bool stretch = true){
    if(stretch) x*=2;
    Cursor().move(x, y);
    std::cout << c;
    if(duplicate) std::cout << c;
}

class OutputBuffer{
    size_t bufferwidth;
    size_t bufferheight;
    std::vector<std::vector<char>> buffer;

    public:

    OutputBuffer(size_t bufferwidth, size_t bufferheight);
    void clearbuffer();
    void setbuffer(size_t i, size_t j, char c);
    void pushtostdout();
};

} //namespace outp

#endif //OUTPUT_HPP_