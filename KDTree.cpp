#include "KDTree.h"
#include <iostream>
#include <stack>
#include "Sphere.h"

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

void KDTree::divide(KDNode* root) {

    std::stack<KDNode*> stk;
    stk.push(root);
    while(!stk.empty()) {
        KDNode* node = stk.top();
        stk.pop();
        Vector3 center = centerOfMass(node->surfaces);
        KDNode* left = new KDNode();
        KDNode* right = new KDNode();

        Vector3& tr = (node->box).topright;
        Vector3& bl = (node->box).bottomleft;

        BoundingBox left_box = (node->box);
        BoundingBox right_box = (node->box);

        double x_diff = tr.X - bl.X;
        double y_diff = tr.Y - bl.Y;
        double z_diff = tr.Z - bl.Z;

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
        if(extend_count * 2 > (node->surfaces).size() || (left->surfaces).size() < 5 || (right->surfaces).size() < 5) continue;
        stk.push(left);
        stk.push(right);
    }

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

Color KDTree::rayTrace(Ray& ray, int depth) {
    std::stack<KDNode*> stk;
    stk.push(root);
    double min_t = 0;
    bool t_changed = false;
    struct RayHitInfo hitinfo;
    while(!stk.empty()) {
        KDNode* node = stk.top();
        stk.pop();
        if((node->box).hit(ray)) {
            if(node->left != NULL) {
                stk.push(node->left);
                stk.push(node->right);
            } else { // this is a leaf node. do the thing.
                for(int i=0; i < (node->surfaces).size() ; i++) {
                    Surface* surf = (node->surfaces)[i];
                    if(surf->hit(ray, hitinfo)) {
                        return Color(255,255,255);
                    }
                }
            }
        }
    }
    return Color(0,0,0);
}
