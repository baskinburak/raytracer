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
    return Vector3(X + vect.X, Y + vect.Y, Z + vect.Z);
}

Vector3 Vector3::operator-(const Vector3& vect) const {
    return Vector3(X - vect.X, Y - vect.Y, Z - vect.Z);
}


Vector3 Vector3::operator*(const double& val) const {
    return Vector3(this->X * val, this->Y * val, this->Z * val);
}

Vector3 Vector3::cross(const Vector3& vec) const {
    return Vector3(Y * vec.Z - Z * vec.Y, Z * vec.X - X * vec.Z, X * vec.Y - Y * vec.X);
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
