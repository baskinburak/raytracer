#include "Scene.h"
#include <map>
#include <fstream>
#include "Triangle.h"
#include "Sphere.h"
#include <iostream>
#include "Vector3.h"

void Scene::ReadScene(int argc, char** argv) {
    // start readin scene
    std::ifstream str(argv[1]);

    int N;
    std::string empty;
    int a, b, c;
    double d;
    int vid1, vid2, vid3;

    // read reflect depth
    str >> reflectDepth;


    // read background color
    str >> backgroundColor;

    // read ambient light instensity
    str >> ambientLightIntensity;

    // read point lights
    str >> N;
    lights.resize(N);
    for(int i=0; i < N; i++) {
        str >> lights[i].position >> lights[i].intensity;
    }

    // read materials
    str >> N;
    std::map<int, int> material_id_to_idx;
    materials.resize(N);
    for(int i=0; i < N; i++) {
        str >> empty;
        str >> a;
        material_id_to_idx[a] = i;
        str >> materials[i];
    }

    // read vertices
    str >> N;
    vertices.resize(N);
    str >> empty >> empty;
    for(int i=0; i < N; i++) {
        str >> vertices[i];
    }

    //read models
    str >> N;
    for(int i=0; i < N; i++) {
        str >> empty;
        str >> a;
        if(empty == "#Mesh") {
            str >> b; // triangle count
            str >> c; // material id;
            c = material_id_to_idx[c]; // material idx
            for(int j = 0; j < b; j++) {
                str >> vid1 >> vid2 >> vid3;
                surfaces.push_back((Surface*)(new Triangle(vid1-1, vid2-1, vid3-1, c, &vertices)));
            }
        } else if (empty == "#Sphere") {
            str >> b; //material id;
            b = material_id_to_idx[b]; // material idx
            str >> d; //radius
            str >> vid1; // center
            surfaces.push_back((Surface*)(new Sphere(vid1-1, d, b, &vertices)));
        }
    }
    GenerateKDTree();


    // start reading cameras
    std::ifstream sstr = std::ifstream(argv[2]);
    
    sstr >> N;
    std::cout << N << std::endl;
    cameras.resize(N);
    for(int i=0; i < N; i++) {
        Camera* camera = new Camera();
        sstr >> *camera;
        cameras[i] = camera;
    }
}

void Scene::GenerateKDTree() {
    tree.generateTree(vertices, surfaces);
}


