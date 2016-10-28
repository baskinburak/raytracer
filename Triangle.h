#ifndef RAYTRACER_TRIANGLE_H
#define RAYTRACER_TRIANGLE_H

#include "Surface.h"
#include "Vector3.h"

class Triangle : public Surface
{
    public:
        Vector3* com;
        int v1;
        int v2;
        int v3;
        Triangle(): v1(-1), v2(-1), v3(-1), Surface(true), com(NULL) {}
        Triangle(int a, int b, int c, int m, std::vector<Vector3>* vert) : v1(a), v2(b), v3(c), Surface(true, m, NULL, vert), com(NULL) {}
        BoundingBox* getBoundingBox();
        Vector3 center();

};

#endif //RAYTRACER_TRIANGLE_H

