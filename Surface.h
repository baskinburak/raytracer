#ifndef ODEV_SURFACE
#define ODEV_SURFACE

#include "BoundingBox.h"
#include <vector>

class Surface {
    public:
        std::vector<Vector3>* vertices;
        bool type; // type0 = sphere, type1 = triangle
        int material;
        BoundingBox* bbox;

        Surface(bool t): type(t), material(-1), bbox(NULL), vertices(NULL) {}
        Surface(bool t, int m, BoundingBox* bb, std::vector<Vector3>* vert) : type(t), material(m), bbox(bb), vertices(vert) {}
        virtual BoundingBox* getBoundingBox() = 0;
        virtual Vector3 center() = 0; // returns the center of mass
};

#endif
