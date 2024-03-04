#include "headers/vertex.hpp"

namespace k2_engine{

const char GRAYSCALE[] = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'. ";

Vertex3::Vertex3(const Vec4& v):x(v.getX()),y(v.getY()),z(v.getZ()){}

} // namespace k2_engine