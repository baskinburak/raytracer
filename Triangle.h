#ifndef RAYTRACER_TRIANGLE_H
#define RAYTRACER_TRIANGLE_H

#include "Ray.h"

class Triangle : public Surface
{
    public:
        int v1;
        int v2;
        int v3;
        Triangle(): v1(-1), v2(-1), v3(-1), type(true), material(-1) {}
        Triangle(int a, int b, int c, int d) : v1(a), v2(b), v3(c), type(true), material(d) {}

};

#endif //RAYTRACER_TRIANGLE_H

