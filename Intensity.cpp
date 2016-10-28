#include "Intensity.h"

std::istream& operator>>(std::istream& stream, Intensity& intensity) {
    return stream >> intensity.R >> intensity.G >> intensity.B;
}
