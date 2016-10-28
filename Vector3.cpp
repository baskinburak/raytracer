#include "Vector3.h"

std::istream &operator>>(std::istream &stream, Vector3 &vector)
{
    return stream >> vector.X >> vector.Y >> vector.Z;
}
