#ifndef RAYTRACER_SCENE_H
#define RAYTRACER_SCENE_H

#include <vector>
#include "Camera.h"
#include "Surface.h"
#include "Color.h"
#include "PointLight.h"
#include "Vector3.h"
#include "Material.h"
#include "KDTree.h"

class Scene {

public:
    std::vector<Vector3> vertices;
    std::vector<Camera> cameras;
    std::vector<Material> materials;
    std::vector<PointLight> lights;
    std::vector<Surface*> surfaces;

    int reflectDepth;
    Color backgroundColor;
    Intensity ambientLightIntensity;

    KDTree tree;

    void ReadScene(int argc, char** argv);

    void GenerateKDTree();
};

#endif //RAYTRACER_SCENE_H
