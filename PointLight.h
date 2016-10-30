#ifndef RAYTRACER_POINTLIGHT_H
#define RAYTRACER_POINTLIGHT_H

#include "Vector3.h"
#include "Intensity.h"

class PointLight {
public:
	Vector3 position;
	Intensity intensity;
    double illumination(const Vector3& pos, char type) const;
};

#endif //RAYTRACER_POINTLIGHT_H
