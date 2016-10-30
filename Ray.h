#ifndef ODEV_RAY
#define ODEV_RAY

#include "Material.h"
#include "Vector3.h"

class Ray {
public:
    Vector3 origin;
    Vector3 direction;
    Ray(const Vector3& o, const Vector3& d) : origin(o), direction(d) {}
    Ray() {}

};

/////////////////
// BEWARE !
// When an intersection occurs, this struct should be filled !
/////////////////

struct RayHitInfo
{
    int Material;
    Vector3 Position;
    Vector3 Normal;

    double      Parameter;
};

#endif
