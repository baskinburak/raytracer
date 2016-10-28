#ifndef ODEV_KDNODE
#define ODEV_KDNODE

class KDNode {
    public:
        KDNode* left;
        KDNode* right;
        std::vector<Surface*> surfaces;
        BoundingBox box;
        KDNode(BoundingBox bb, std::vector<Surface*> sf): box(bb), surfaces(sf) {}
}

#endif

