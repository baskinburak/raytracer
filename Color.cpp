#include "Color.h"

std::istream &operator>>(std::istream &stream, Color &color) {
    return stream >> color.R >> color.G >> color.B;
}


