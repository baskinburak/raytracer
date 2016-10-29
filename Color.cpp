#include "Color.h"

std::istream &operator>>(std::istream &stream, Color &color) {
    return stream >> color.r >> color.g >> color.b;
}
