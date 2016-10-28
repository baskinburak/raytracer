#ifndef ODEV_SPHERE
#define ODEV_SPHERE

#include "Surface.h"

class Sphere : public Surface{

public:
    int cntr;
    double radius;
    Sphere():cntr(-1), radius(-1), Surface(false) {}
    Sphere(int c, double r, int m, std::vector<Vector3>* vert): cntr(c), radius(r), Surface(false, m, NULL, vert) {}
    BoundingBox* getBoundingBox();
    Vector3 center();
};


#endif 
