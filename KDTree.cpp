#include "KDTree.h"

void KDTree::extendBoundingBox(BoundingBox* target, BoundingBox* source) {
    if((source->tr).X > (target->tr).X) (target->tr).X = (source->tr).X;
    if((source->tr).Y > (target->tr).Y) (target->tr).Y = (source->tr).Y;
    if((source->tr).Z > (target->tr).Z) (target->tr).Z = (source->tr).Z;

    if((source->bl).X < (target->bl).X) (target->bl).X = (source->bl).X;
    if((source->bl).Y < (target->bl).Y) (target->bl).Y = (source->bl).Y;
    if((source->bl).Z < (target->bl).Z) (target->bl).Z = (source->bl).Z;
}

Vector3 centerOfMass(std::vector<Surface*>& surfaces) {
    int weight = 0;
    Vector3 com;
    for(int i=0; i<surfaces.size(); i++) {
        com += surfaces[i]->center();
        weight++;
    }

    com.X /= weight;
    com.Y /= weight;
    com.Z /= weight;

    return com;
}

void KDTree::divide(KDNode* node) {
    Vector3 center = centerOfMass(node->surfaces);
    
}

void KDTree::generateTree(std::vector<Vector3>& vertices, std::vector<Surface*>& surfaces) {
    if(surfaces.size() == 0) return;
    BoundingBox bb = surfaces[0]->getBoundingBox();

    for(int i=1; i<surfaces.size(); i++) {
        Surface* surf = surfaces[i];
        BoundingBox* bbox = surf->getBoundingBox();
        extendBoundingBox(&bb, bbox);
    }

    root = new KDNode(bb, surfaces);

    divide(root);

}
