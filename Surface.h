#ifndef ODEV_SURFACE
#define ODEV_SURFACE

#include "BoundingBox.h"

class Surface {
    public:
        bool type; // type0 = sphere, type1 = triangle
        int material;
        BoundingBox* bbox;

        BoundingBox* getBoundingBox();

        Vector3 center(); // returns the center of mass
}

#endif
