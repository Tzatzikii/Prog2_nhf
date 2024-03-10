#include "headers/vertex.hpp"

namespace k2_engine{

const char GRAYSCALE[] = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'.";

char calculate_grayscale(double luminosity){

        if(luminosity == 0) return 0;

        int scale = std::strlen(GRAYSCALE);
        double ratio = scale / LUMINOSITY_MAX;
        int index = scale - (int)(ratio * luminosity);

        clamp(index, 0, scale);

        return GRAYSCALE[index];

}

} // namespace k2_engine