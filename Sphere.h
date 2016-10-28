#ifndef ODEV_SPHERE
#define ODEV_SPHERE

#include "Surface.h"

class Sphere : public Surface{

public:
    std::vector<Vector3>* vertices;
    int center;
    double radius;
    Sphere():center(-1), radius(-1), type(false), material(-1), vertices(NULL), bbox(NULL) {}
    Sphere(int c, double r, int m, std::vector<Vector3>* vert): center(c), radius(r), type(false), material(m), vertices(vert), bbox(NULL) {}
};


#endif 
