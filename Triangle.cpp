#include "Triangle.h"

BoundingBox* Triangle::getBoundingBox() {
    if(bbox != NULL) return bbox;

    Vector3 tr;
    Vector3 bl;
    double max_x, max_y, max_z;
    double min_x, min_y, min_z;
    Vector3& ver1 = (*vertices)[v1];
    Vector3& ver2 = (*vertices)[v2];
    Vector3& ver3 =  (*vertices)[v3];
    max_x = ver1.X;
    max_y = ver1.Y;
    max_z = ver1.Z;
    min_x = ver1.X;
    min_y = ver1.Y;
    min_z = ver1.Z;

    if(ver2.X > max_x) max_x = ver2.X;
    if(ver2.X < min_x) min_x = ver2.X;

    if(ver3.X > max_x) max_x = ver3.X;
    if(ver3.X < min_x) min_x = ver3.X;


    if(ver2.Y > max_y) max_y = ver2.Y;
    if(ver2.Y < min_y) min_y = ver2.Y;

    if(ver3.Y > max_y) max_y = ver3.Y;
    if(ver3.Y < min_y) min_y = ver3.Y;

    if(ver2.Z > max_z) max_z = ver2.Z;
    if(ver2.Z < min_z) min_z = ver2.Z;

    if(ver3.Z > max_z) max_z = ver3.Z;
    if(ver3.Z < min_z) min_z = ver3.Z;

    bbox = new BoundingBox(Vector3(min_x, min_y, min_z), Vector3(max_x, max_y, max_z));
    return bbox;
}

Vector3 Triangle::center() {
    if(com != NULL) return *com;
    Vector3& ver1 = (*vertices)[v1];
    Vector3& ver2 = (*vertices)[v2];
    Vector3& ver3 = (*vertices)[v3];

    com = new Vector3((ver1.X + ver2.X + ver3.X)/3, (ver1.Y + ver2.Y + ver3.Y)/3, (ver1.Z + ver2.Z + ver3.Z)/3);
    return *com;
}


bool Triangle::hit(Ray& ray, struct RayHitInfo& hitinfo) {
    return false;
}
