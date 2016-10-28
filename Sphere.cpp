#include "Sphere.h"

BoundingBox* Sphere::getBoundingBox() {
    if(bbox != NULL) return bbox;
    Vector3 cntr = vertices[center];
    Vector3 tr(cntr.X + radius, cntr.Y + radius, cntr.Z + radius);
    Vector3 bl(cntr.X - radius, cntr.Y - radius, cntr.Z - radius);
    bbox = new BoundingBox(Vector3(cntr.X - radius, cntr.Y - radius, cntr.Z - radius), Vector3(cntr.X + radius, cntr.Y + radius, cntr.Z + radius));
    return bbox;
}

Vector3 Sphere::center() {
    return center;
}
