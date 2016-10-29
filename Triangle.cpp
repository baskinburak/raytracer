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
    Vector3& a = (*vertices)[v1];
    Vector3& b = (*vertices)[v2];
    Vector3& c = (*vertices)[v3];
    Vector3& d = ray.direction;
    Vector3& e = ray.origin;

    double eihf = (a.Y - c.Y) * (d.Z) - (d.Y) * (a.Z - c.Z);
    double gfdi = (d.X) * (a.Z - c.Z) - (a.X - c.X) * (d.Z);
    double dheg = (a.X - c.X) * (d.Y) - (d.X) * (a.Y - c.Y);
    double akjb = (a.X - b.X) * (a.Y - e.Y) - (a.X - e.X) * (a.Y - b.Y);
    double jcal = (a.X - e.X) * (a.Z - b.Z) - (a.X - b.X) * (a.Z - e.Z);
    double blkc = (a.Y - b.Y) * (a.Z - e.Z) - (a.Y - e.Y) * (a.Z - b.Z);

    double M = (a.X - b.X) * eihf + (a.Y - b.Y) * gfdi + (a.Z - b.Z) * dheg;

    double t = ((a.Z - c.Z) * akjb + (a.Y - c.Y) * jcal + (a.X - c.X) * blkc) / -M;

    if(t<=0) return false;

    double gamma = ((d.Z) * akjb + (d.Y) * jcal + (d.X) * blkc) / M;

    if(gamma < 0 || gamma > 1) return false;

    double beta = ((a.X - e.X) * eihf + (a.Y - e.Y) * gfdi + (a.Z - e.Z) * dheg) / M;

    if(beta < 0 or beta > 1-gamma) return false;

    hitinfo.Parameter = t;
    hitinfo.Material = material;
    hitinfo.Position = ray.origin + ray.direction * t;
    hitinfo.Normal = (b-a).cross(c-a);
    hitinfo.Normal.normalize();
    return true;
}
