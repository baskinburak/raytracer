#ifndef RAYTRACER_TRIANGLE_H
#define RAYTRACER_TRIANGLE_H

#include "Surface.h"
#include "Vector3.h"

class Triangle : public Surface
{
    public:
        std::vector<Vector3>* vertices;
        int v1;
        int v2;
        int v3;
        Triangle(): v1(-1), v2(-1), v3(-1), type(true), material(-1), bbox(NULL); {}
        Triangle(int a, int b, int c, int d, std::vector<Vector3>* vert) : v1(a), v2(b), v3(c), type(true), material(d), vertices(vert), bbox(NULL) {}

};

#endif //RAYTRACER_TRIANGLE_H

