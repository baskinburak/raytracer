#include "Camera.h"

std::istream& operator>>(std::istream& stream, Camera& camera) {
    std::string empty;
    int id;
    return stream >> empty >> id >> camera.position >> camera.gaze >> camera.up >> camera.imagePlane.left >> camera.imagePlane.right >> camera.imagePlane.bottom >> camera.imagePlane.top >> camera.imagePlane.distance >> camera.imagePlane.width >> camera.imagePlane.height;
}

Image Camera::Render(Scene* currentScene) {
    
}
