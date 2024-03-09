#include "output.hpp"

namespace outp{

#ifdef __linux__



static struct termios original;
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
int kbhit(){

        int count = 0;
        ioctl(STDIN_FILENO, FIONREAD, &count);
        return count;
}

#endif //__linux__

void Cursor::hide(){ std::cout << "\x1B[?25l"; atexit(show);}
void Cursor::show(){ std::cout << "\x1B[?25h";}
void Cursor::move(size_t x, size_t y){ std::cout << "\x1B[" << y << ';' << x << 'H'; }
void Cursor::reset(){move(0, 0); show();}

OutputBuffer::OutputBuffer(size_t bufferwidth, size_t bufferheight):bufferwidth(bufferwidth),bufferheight(bufferheight){

        for(int i = 0; i < bufferwidth; i++){

                std::vector<char> column;
                buffer.push_back(column);
                for(int j = 0; j < bufferheight; j++){
                buffer[i].push_back(' ');
                }
        }
}
void OutputBuffer::set_buffer(size_t i, size_t j, char c){

        assert(i >= 0 && i < bufferwidth);
        assert(j >= 0 && j < bufferheight);
        buffer[i][j] = c;
}
void OutputBuffer::push_to_stdout(){

        for(int i = 0; i < bufferwidth; i++){
                for(int j = 0; j < bufferheight; j++){

                        cout_xy<char>(i, j, buffer[i][j]);
                }
        }
}
void OutputBuffer::clear_buffer(){

        for(int i = 0; i < bufferwidth; i++){
                for(int j = 0; j < bufferheight; j++){

                        buffer[i][j] = ' ';

                }
        }
}

} //namespace outp