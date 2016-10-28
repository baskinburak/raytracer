#ifndef ODEV_MATERIAL
#define ODEV_MATERIAL

#include "LightProperty.h"

class Scene;

class Material {
public:
	LightProperty ambient;
	LightProperty diffuse;
	LightProperty spec;
	double specexp;
	LightProperty reflectance;

    friend std::istream& operator>>(std::istream& stream, Material& mat);
};

#endif
