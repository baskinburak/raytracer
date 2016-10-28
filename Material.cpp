#include "Material.h"


friend std::istream& operator>>(std::istream& stream, Material& mat) {
    stream >> ambient >> diffuse >> specular  >> specexp >> reflectance;
}
