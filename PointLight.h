#ifndef RAYTRACER_POINTLIGHT_H
#define RAYTRACER_POINTLIGHT_H

#include "Vector3.h"
#include "Intensity.h"

class PointLight {
public:
	Vector3 position;
	Intensity intensity;
};

#endif //RAYTRACER_POINTLIGHT_H
