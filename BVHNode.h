#ifndef ODEV_BVHNODE
#define ODEV_BVHNODE

#include "Surface.h"
#include "BoundingBox.h"
#include <vector>

class BVHNode {
    public:
        BVHNode* left;
        BVHNode* right;
        std::vector<Surface*> surfaces;
        BoundingBox box;
        BVHNode(BoundingBox bb, std::vector<Surface*> sf): box(bb), surfaces(sf), left(NULL), right(NULL) {}
        BVHNode() : left(NULL), right(NULL) {}
};

#endif
