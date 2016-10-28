#include "KDTree.h"

int KDTree::extendBoundingBox(BoundingBox* target, BoundingBox* source) {
    int extend_count = 0;

    if((source->topright).X > (target->topright).X) { (target->topright).X = (source->topright).X; extend_count = 1; }
    if((source->topright).Y > (target->topright).Y) { (target->topright).Y = (source->topright).Y; extend_count = 1; }
    if((source->topright).Z > (target->topright).Z) { (target->topright).Z = (source->topright).Z; extend_count = 1; }

    if((source->bottomleft).X < (target->bottomleft).X) { (target->bottomleft).X = (source->bottomleft).X; extend_count = 1; }
    if((source->bottomleft).Y < (target->bottomleft).Y) { (target->bottomleft).Y = (source->bottomleft).Y; extend_count = 1; }
    if((source->bottomleft).Z < (target->bottomleft).Z) { (target->bottomleft).Z = (source->bottomleft).Z; extend_count = 1; }
    return extend_count;
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
    KDNode* left = new KDNode();
    KDNode* right = new KDNode();

    Vector3& tr = (node->box).topright;
    Vector3& bl = (node->box).bottomleft;

    BoundingBox left_box = (node->box);
    BoundingBox right_box = (node->box);

    int x_diff = tr.X - bl.X;
    int y_diff = tr.Y - bl.Y;
    int z_diff = tr.Z - bl.Z;

    int extend_count = 0;

    if(x_diff > y_diff && x_diff > z_diff) {
        left_box.topright.X = center.X;
        right_box.bottomleft.X = center.X;
        for(int i=0; i<(node->surfaces).size(); i++) {
            if((((node->surfaces)[i])->center()).X < center.X) {
                extend_count += extendBoundingBox(&left_box, ((node->surfaces)[i])->getBoundingBox());
                (left->surfaces).push_back((node->surfaces)[i]);
            } else {
                extend_count += extendBoundingBox(&right_box, ((node->surfaces)[i])->getBoundingBox());
                (right->surfaces).push_back((node->surfaces)[i]);
            }
        }
    } else if(y_diff > z_diff) {
        left_box.topright.Y = center.Y;
        right_box.bottomleft.Y = center.Y;
        for(int i=0; i<(node->surfaces).size(); i++) {
            if((((node->surfaces)[i])->center()).Y < center.Y) {
                extend_count += extendBoundingBox(&left_box, ((node->surfaces)[i])->getBoundingBox());
                (left->surfaces).push_back((node->surfaces)[i]);
            } else {
                extend_count += extendBoundingBox(&right_box, ((node->surfaces)[i])->getBoundingBox());
                (right->surfaces).push_back((node->surfaces)[i]);
            }
        }
    } else {
        left_box.topright.Z = center.Z;
        right_box.bottomleft.Z = center.Z;
        for(int i=0; i<(node->surfaces).size(); i++) {
            if((((node->surfaces)[i])->center()).Z < center.Z) {
                extend_count += extendBoundingBox(&left_box, ((node->surfaces)[i])->getBoundingBox());
                (left->surfaces).push_back((node->surfaces)[i]);
            } else {
                extend_count += extendBoundingBox(&right_box, ((node->surfaces)[i])->getBoundingBox());
                (right->surfaces).push_back((node->surfaces)[i]);
            }
        }
    }

    left->box = left_box;
    right->box = right_box;


    if(extend_count*2 > (node->surfaces).size()) return;

    divide(left);
    divide(right);

}

void KDTree::generateTree(std::vector<Vector3>& vertices, std::vector<Surface*> surfaces) {
    if(surfaces.size() == 0) return;
    BoundingBox *bb = surfaces[0]->getBoundingBox();

    for(int i=1; i<surfaces.size(); i++) {
        Surface* surf = surfaces[i];
        BoundingBox* bbox = surf->getBoundingBox();
        extendBoundingBox(bb, bbox);
    }

    root = new KDNode(*bb, surfaces);

    divide(root);

}
