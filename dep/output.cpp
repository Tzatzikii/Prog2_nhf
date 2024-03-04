#include "output.hpp"

namespace outp{

#ifdef __linux__
struct termios original;
void Rawmode::disable(){
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &original);
}

void Rawmode::enable(){
    tcgetattr(STDIN_FILENO, &original);
    struct termios raw = original;
    atexit(disable);
    raw.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

#endif //__linux__

void Cursor::hide(){ std::cout << "\x1B[?25l";}
void Cursor::show(){ std::cout << "\x1B[?25h";}
void Cursor::move(int x, int y){ std::cout << "\x1B[" << y << ';' << x << 'H'; }

char keystroke(){
    Rawmode().enable();
    char c;
    return std::getchar();
}

} //namespace outp