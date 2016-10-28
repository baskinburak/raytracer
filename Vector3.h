#ifndef ODEV_VECTOR3
#define ODEV_VECTOR3

#include <iostream>

class Vector3
{
    public:
        double X;
        double Y;
        double Z;

        friend std::istream &operator>>(std::istream &stream, Vector3 &vertex);
};

#endif
