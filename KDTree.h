#ifndef ODEV_KDTREE
#define ODEV_KDTREE

#include "KDNode.h"

class KDTree {
    private:        
        void extendBoundingBox(BoundingBox* target, BoundingBox* source);
        void divide(root);
    public:
        KDNode *root;
        void generateTree(std::vector<Vector3>& vertices, std::vector<Surface*> surfaces);
}

#endif
