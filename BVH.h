#ifndef ODEV_KDTREE
#define ODEV_KDTREE

#include "BVHNode.h"
#include "Color.h"

class BVH {
    private:
        int extendBoundingBox(BoundingBox* target, BoundingBox* source);
        void divide(BVHNode* node);
    public:
        BVHNode *root;
        void generateBVH(std::vector<Vector3>& vertices, std::vector<Surface*> surfaces);
        bool rayTrace(Ray& ray, int depth, Scene& currentScene, Color& color, double min_t);
        bool hits_before_1(Ray& ray);
        void printTree();
};

#endif
