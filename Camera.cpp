#include "Camera.h"
#include "Scene.h"
#include <iostream>
std::istream& operator>>(std::istream& stream, Camera& camera) {
    std::string empty;
    int id;
    stream >> empty >> id >> camera.position >> camera.gaze >> camera.up >> camera.imagePlane.left >> camera.imagePlane.right >> camera.imagePlane.bottom >> camera.imagePlane.top >> camera.imagePlane.distance >> camera.imagePlane.width >> camera.imagePlane.height >> camera.outputFile;

   // std::cout << camera.up.X << " " << camera.up.Y << " " << camera.up.Z  << std::endl;

    camera.gaze.normalize();
    //std::cout << "gaze:" << camera.gaze.X << " " << camera.gaze.Y << " " << camera.gaze.Z << std::endl;
    camera.up.normalize();
   // std::cout << "up: " << camera.up.X << " " <<camera.up.Y << " " << camera.up.Z << std::endl;
    camera.calculateRight();
    //std::cout << "right: " << camera.right.X << " " << camera.right.Y << " " << camera.right.Z << std::endl;
    return stream;
}

void Camera::calculateRight() {
    right = gaze.cross(up);
}

Ray Camera::calculateRay(int px_x, int px_y) const {
    double u = imagePlane.left + ((imagePlane.right - imagePlane.left) * (0.5 + px_y)) / imagePlane.width;
    double v = imagePlane.top - ((imagePlane.top - imagePlane.bottom) * (0.5 + px_x)) / imagePlane.height;
    Vector3 direction(right * u + up * v + gaze * imagePlane.distance);
    return Ray(position, direction);
}

Image Camera::Render(Scene* currentScene) const {
    //std::cout << imagePlane.width << " " << imagePlane.height << std::endl;
    Image img(imagePlane.width, imagePlane.height, currentScene->backgroundColor);
    for(int i=0; i < imagePlane.height; i++) {
        //std::cout << i << std::endl;
        for(int j=0; j < imagePlane.width; j++) {
            Ray ray = calculateRay(i,j);
            ray.direction.normalize();
            (currentScene->tree).rayTrace(ray, currentScene->reflectDepth, *currentScene, img.Pixel(i,j), 0.0);
        }
    }
    return img;
}
