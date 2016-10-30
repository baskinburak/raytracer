#ifndef ODEV_KDTREE
#define ODEV_KDTREE

#include "KDNode.h"
#include "Color.h"

class KDTree {
    private:        
        int extendBoundingBox(BoundingBox* target, BoundingBox* source);
        void divide(KDNode* node);
    public:
        KDNode *root;
        void generateTree(std::vector<Vector3>& vertices, std::vector<Surface*> surfaces);
        bool rayTrace(Ray& ray, int depth, Scene& currentScene, Color& color, double min_t);
        bool hits_before_1(Ray& ray);
};

#endif
