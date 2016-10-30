#include "BoundingBox.h"
#include <algorithm>
bool BoundingBox::hit(Ray& ray) {

    Vector3 a = topright;
    Vector3 b = bottomleft;
    b.Z = a.Z;
    Vector3 c = a;
    c.X = b.X;

    Vector3 normal = (a-b).cross(c-b);

    double dn = normal.dot(ray.direction);
    if(dn != 0) {
        double t = (normal.dot(a) - normal.dot(ray.origin))/dn;
        if(t > 0) {
            Vector3 point = ray.origin + ray.direction * t;
            if(point.X <= a.X && point.X >= c.X && point.Y <= c.Y && point.Y >= b.Y)
                return true;
        }
    }
    
    a = topright;
    b = bottomleft;
    b.Y = a.Y;
    c = b;
    c.Z = a.Z;

    normal = (a-b).cross(c-b);

    dn = normal.dot(ray.direction);
    if(dn != 0) {
        double t = (normal.dot(a) - normal.dot(ray.origin))/dn;
        if(t > 0) {
            Vector3 point = ray.origin + ray.direction * t;
            if(point.X <= a.X && point.X >= c.X && point.Z <=a.Z && point.Z >= b.Z)
                return true;
        }
    }

    a = topright;
    b = bottomleft;
    b.X = a.X;
    c = b;
    c.Z = a.Z;

    normal = (a-b).cross(c-b);

    dn = normal.dot(ray.direction);
    if(dn != 0) {
        double t = (normal.dot(a) - normal.dot(ray.origin))/dn;
        if(t > 0) {
            Vector3 point = ray.origin + ray.direction * t;
            if(point.Y <= a.Y && point.Y >= b.Y && point.Z <=a.Z && point.Z >= b.Z)
                return true;
        }
    }

    a = bottomleft;
    b = topright;
    b.Z = a.Z;
    c = b;
    c.Y = a.Y;

    normal = (a-b).cross(c-b);

    dn = normal.dot(ray.direction);
    if(dn != 0) {
        double t = (normal.dot(a) - normal.dot(ray.origin))/dn;
        if(t > 0) {
            Vector3 point = ray.origin + ray.direction * t;
            if(point.Y <= b.Y && point.Y >= a.Y && point.X <= c.X && point.X >= a.X)
                return true;
        }
    }


    a = bottomleft;
    b = topright;
    b.X = a.X;
    c = b;
    c.Z = a.Z;


    normal = (a-b).cross(c-b);

    dn = normal.dot(ray.direction);
    if(dn != 0) {
        double t = (normal.dot(a) - normal.dot(ray.origin))/dn;
        if(t > 0) {
            Vector3 point = ray.origin + ray.direction * t;
            if(point.Z <= b.Z && point.Z >= a.Z && point.Y <= c.Y && point.Y >= a.Y)
                return true;
        }
    }


    a = bottomleft;
    b = topright;
    b.Y = a.Y;
    c = b;
    c.X = a.X;


    normal = (a-b).cross(c-b);

    dn = normal.dot(ray.direction);
    if(dn != 0) {
        double t = (normal.dot(a) - normal.dot(ray.origin))/dn;
        if(t > 0) {
            Vector3 point = ray.origin + ray.direction * t;
            if(point.X <= b.X && point.X >= a.X && point.Z <= c.Z && point.Z >= a.Z)
                return true;
        }
    }
    
    return false;
}
