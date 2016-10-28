#include "LightProperty.h"

std::istream& operator>>(std::istream& stream, LightProperty& lp) {
    return stream >> lp.R >> lp.G >> lp.B;
}
