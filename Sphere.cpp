#include "Sphere.h"

BoundingBox* Sphere::getBoundingBox() {
    if(bbox != NULL) return bbox;
    Vector3 cntrvec = (*vertices)[cntr];
    bbox = new BoundingBox(Vector3(cntrvec.X - radius, cntrvec.Y - radius, cntrvec.Z - radius), Vector3(cntrvec.X + radius, cntrvec.Y + radius, cntrvec.Z + radius));
    return bbox;
}

Vector3 Sphere::center() {
    return (*vertices)[cntr];
}
