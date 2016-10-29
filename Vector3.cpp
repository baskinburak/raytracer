#include "Vector3.h"
#include <cmath>

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

Vector3 Vector3::operator+(const Vector3& vect) const {
    Vector3 vec = *this;
    vec.X += vect.X;
    vec.Y += vect.Y;
    vec.Z += vect.Z;
    return vec;
}

Vector3 Vector3::operator-(const Vector3& vect) const {
    Vector3 vec = *this;
    vec.X -= vect.X;
    vec.Y -= vect.Y;
    vec.Z -= vect.Z;
    return vec;
}


Vector3 Vector3::operator*(const double& val) const {
    Vector3 vec = *this;
    vec.X *= val;
    vec.Y *= val;
    vec.Z *= val;
    return vec;
}

Vector3 Vector3::cross(const Vector3& vec) const {
    Vector3 res;
    res.X = Y * vec.Z - Z * vec.Y;
    res.Y = Z * vec.Y - X * vec.Z;
    res.Z = X * vec.Y - Y * vec.X;
    return res;
}

void Vector3::normalize() {
    double inv_sqrt = 1.0 / sqrt(X * X + Y * Y + Z * Z);
    X = X * inv_sqrt;
    Y = Y * inv_sqrt;
    Z = Z * inv_sqrt;
}

double Vector3::dot(const Vector3& vec) const {
    return X * vec.X + Y * vec.Y + Z * vec.Z;
}
