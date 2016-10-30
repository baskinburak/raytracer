#include "PointLight.h"
#include <cmath>

double PointLight::illumination(const Vector3& pos, char type) const {
    double distance = (pos.X - position.X) * (pos.X - position.X) + (pos.Y - position.Y) * (pos.Y - position.Y) + (pos.Z - position.Z) * (pos.Z - position.Z);
    if(type == 'R') {
        return intensity.R / (12.566370614359172 * distance);
    } else if(type == 'G') {
        return intensity.G / (12.566370614359172 * distance);
    } else if(type == 'B') {
        return intensity.B / (12.566370614359172 * distance);
    }
    return 0;
}
