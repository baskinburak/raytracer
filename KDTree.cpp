#include "KDTree.h"
#include <iostream>
#include <stack>
#include "Sphere.h"
#include "Scene.h"
#include "PointLight.h"
#include <algorithm>
#include <limits>
#include <queue>

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
    std::queue<KDNode*> queue;
    queue.push(root);
    //int leaf_count = 1;
    while(!queue.empty()) {
        KDNode* node = queue.front();
        queue.pop();
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
        //leaf_count++;
        node->left = left;
        node->right = right;
        if((left->surfaces).size() < 16 || (right->surfaces).size() < 16) continue;
        queue.push(left);
        queue.push(right);
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

bool KDTree::hits_before_1(Ray& ray) {
    std::stack<KDNode*> stk;
    stk.push(root);
    struct RayHitInfo hitinfo;
    while(!stk.empty()) {
        KDNode* node = stk.top();
        stk.pop();
        if((node->box).hit(ray)) {
            if(node->left != NULL) {
                stk.push(node->left);
                stk.push(node->right);
            } else {
                for(int i=0; i < (node->surfaces).size() ; i++) {
                    Surface* surf = (node->surfaces)[i];
                    if(surf->hit(ray, hitinfo)) {
                        if(hitinfo.Parameter <= 1 && hitinfo.Parameter > 1e-10) return true;
                    }
                }
            }
        }
    }
    return false;
}

bool KDTree::rayTrace(Ray& ray, int depth, Scene& currentScene, Color& color, double min_t) {
    std::stack<KDNode*> stk;
    stk.push(root);
    struct RayHitInfo hitinfo;
    struct RayHitInfo min_hitinfo;
    min_hitinfo.Parameter = std::numeric_limits<double>::infinity();
    bool hit_occured = false;
    while(!stk.empty()) {
        KDNode* node = stk.top();
        stk.pop();
        if((node->box).hit(ray)) {
            if(node->left != NULL) {
                stk.push(node->left);
                stk.push(node->right);
            } else {
                for(int i=0; i < (node->surfaces).size() ; i++) {
                    Surface* surf = (node->surfaces)[i];
                    if(surf->hit(ray, hitinfo)) {
                        if(hitinfo.Parameter <= min_hitinfo.Parameter && hitinfo.Parameter >= min_t) {
                            min_hitinfo = hitinfo;
                            hit_occured = true;
                        }
                    }
                }
            }
        }
    }
    if(hit_occured) {
        Material& mat = currentScene.materials[min_hitinfo.Material];
        int R = mat.ambient.R * currentScene.ambientLightIntensity.R;
        int G = mat.ambient.G * currentScene.ambientLightIntensity.G;
        int B = mat.ambient.B * currentScene.ambientLightIntensity.B;
        for(int i=0; i<currentScene.lights.size(); i++) {
            PointLight& light = currentScene.lights[i];
            Vector3 l = light.position-min_hitinfo.Position;
            Ray light_ray(min_hitinfo.Position, l);
            if(hits_before_1(light_ray)) continue;
            double r_illumination = light.illumination(min_hitinfo.Position, 'R');
            double g_illumination = light.illumination(min_hitinfo.Position, 'G');
            double b_illumination = light.illumination(min_hitinfo.Position, 'B');
            l.normalize();
            double dot = std::max(0.0, min_hitinfo.Normal.dot(l));
            R += mat.diffuse.R * r_illumination * dot;
            G += mat.diffuse.G * g_illumination * dot;
            B += mat.diffuse.B * b_illumination * dot;
            
            Vector3 v = ray.origin - min_hitinfo.Position;
            v.normalize();
            Vector3 vl = (v+l);
            vl.normalize();
            double spec_dot = std::pow(std::max(0.0, min_hitinfo.Normal.dot(vl)), mat.specexp);
            R += mat.specular.R * r_illumination * spec_dot;
            G += mat.specular.G * g_illumination * spec_dot;
            B += mat.specular.B * b_illumination * spec_dot;
            
        }
        if((mat.reflectance.R != 0 || mat.reflectance.G != 0 || mat.reflectance.B != 0) && depth != 0) {
            Vector3& d = ray.direction;
            d.normalize();
            Vector3 r = d - min_hitinfo.Normal * d.dot(min_hitinfo.Normal) * 2;
            Ray refl_ray(min_hitinfo.Position, r);
            Color clr;
            if(rayTrace(refl_ray, depth-1, currentScene, clr, 1e-10)) {
                R += clr.r * mat.reflectance.R;
                G += clr.g * mat.reflectance.G;
                B += clr.b * mat.reflectance.B;
            }
        }
        color = Color(std::min(255,R), std::min(255,G), std::min(255,B));
        return true;
    }
    return false;
}

void KDTree::printTree() {
    std::stack<KDNode*> stk;
    stk.push(root);
    while(!stk.empty()) {
        KDNode* node = stk.top();
        stk.pop();
        if(node->left != NULL) {
            std::cout << "left not null" << std::endl;
            stk.push(node->left);
            stk.push(node->right);
        } else {
            std::cout << "\t";
            for(int i=0; i<node->surfaces.size(); i++) {
                Surface* srf = node->surfaces[i];
                std::cout << (srf->type?"Triangle":"Sphere") << " ";
            }
            std::cout << std::endl;
        }
    }
}
