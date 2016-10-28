#include "Material.h"


std::istream& operator>>(std::istream& stream, Material& mat) {
    return stream >> mat.ambient >> mat.diffuse >> mat.specular  >> mat.specexp >> mat.reflectance;
}
