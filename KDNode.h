#ifndef ODEV_KDNODE
#define ODEV_KDNODE

#include "Surface.h"
#include "BoundingBox.h"
#include <vector>

class KDNode {
    public:
        KDNode* left;
        KDNode* right;
        std::vector<Surface*> surfaces;
        BoundingBox box;
        KDNode(BoundingBox bb, std::vector<Surface*> sf): box(bb), surfaces(sf), left(NULL), right(NULL) {}
        KDNode() : left(NULL), right(NULL) {}
};

#endif

