#ifndef ODEV_BOUNDING_BOX
#define ODEV_BOUNDING_BOX

#include "Vector3.h"
class BoundingBox {
    public:
        Vector3 bottomleft;
        Vector3 topright;
        BoundingBox(): bottomleft(), topright() {}
        BoundingBox(Vector3 bl, Vector3 tr): bottomleft(bl), topright(tr) {}
}

#endif