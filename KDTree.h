#ifndef ODEV_KDTREE
#define ODEV_KDTREE

#include "KDNode.h"

class KDTree {
    private:        
        int extendBoundingBox(BoundingBox* target, BoundingBox* source);
        void divide(KDNode* node);
    public:
        KDNode *root;
        void generateTree(std::vector<Vector3>& vertices, std::vector<Surface*> surfaces);
};

#endif
