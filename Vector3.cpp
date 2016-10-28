#include "Vector3.h"

std::istream &operator>>(std::istream &stream, Vector3 &vector)
{
    return stream >> vector.X >> vector.Y >> vector.Z;
}

Vector3 Vector3::operator+=(const Vector3& vect) {
    X += vect.X;
    Y += vect.Y;
    Z += vect.Z;
    return *this; 
}

Vector3 Vector3::operator+(const Vector3& vect) {
    Vector3 vec = *this;
    vec.X += vect.X;
    vec.Y += vect.Y;
    vec.Z += vect.Z;
    return vec;
}
