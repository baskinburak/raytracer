#include "Sphere.h"
#include <cmath>

BoundingBox* Sphere::getBoundingBox() {
    if(bbox != NULL) return bbox;
    Vector3 cntrvec = (*vertices)[cntr];
    bbox = new BoundingBox(Vector3(cntrvec.X - radius, cntrvec.Y - radius, cntrvec.Z - radius), Vector3(cntrvec.X + radius, cntrvec.Y + radius, cntrvec.Z + radius));
    return bbox;
}

Vector3 Sphere::center() {
    return (*vertices)[cntr];
}

bool Sphere::hit(Ray& ray, struct RayHitInfo& hitinfo) {
    Vector3 center = (*vertices)[cntr];
    Vector3 ec = ray.origin - center;
    double dec = ray.direction.dot(ec);
    double dd = ray.direction.dot(ray.direction);
    double disc = dec*dec  - dd * (ec.dot(ec) - radius*radius);
    if(disc<=0) return false;
    double t = (-dec - sqrt(disc)) / dd;
    if(t<0) t = (-dec + sqrt(disc)) / dd;
    if(t<0) return false;
    hitinfo.Parameter = t;
    hitinfo.Material = material;
    hitinfo.Position = ray.origin + ray.direction * t;
    hitinfo.Normal = Vector3(2*(hitinfo.Position.X - center.X), 2*(hitinfo.Position.Y - center.Y), 2*(hitinfo.Position.Z - center.Z));
    hitinfo.Normal.normalize();
    return true;
}
