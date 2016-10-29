#ifndef ODEV_VECTOR3
#define ODEV_VECTOR3

#include <iostream>

class Vector3
{
    public:
        double X;
        double Y;
        double Z;
        Vector3():X(0), Y(0), Z(0) {}
        Vector3(double x, double y, double z): X(x), Y(y), Z(z) {}
        friend std::istream &operator>>(std::istream &stream, Vector3 &vertex);
        Vector3 operator+=(const Vector3& vect);
        Vector3 operator+(const Vector3& vect) const;
        Vector3 operator-(const Vector3& vect) const;
        Vector3 operator*(const double& val) const;
        Vector3 cross(const Vector3& vec) const;
        double dot(const Vector3& vec) const;
        void normalize();
};

#endif
