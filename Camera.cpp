#include "Camera.h"
#include "Scene.h"

std::istream& operator>>(std::istream& stream, Camera& camera) {
    std::string empty;
    int id;
    stream >> empty >> id >> camera.position >> camera.gaze >> camera.up >> camera.imagePlane.left >> camera.imagePlane.right >> camera.imagePlane.bottom >> camera.imagePlane.top >> camera.imagePlane.distance >> camera.imagePlane.width >> camera.imagePlane.height;
    camera.gaze.normalize();
    camera.up.normalize();
    camera.calculateRight();
    return stream;
}

void Camera::calculateRight() {
    right = gaze.cross(up);
}

Ray Camera::calculateRay(int px_x, int px_y) const {
    double u = imagePlane.left + ((imagePlane.right - imagePlane.left) * (0.5 + px_x)) / imagePlane.width;
    double v = imagePlane.top - ((imagePlane.top - imagePlane.bottom) * (0.5 + px_y)) / imagePlane.height;
    Vector3 direction(right * u + up * v + gaze * imagePlane.distance);
    return Ray(position + direction, direction);
}

Image Camera::Render(Scene* currentScene) const {
    Image img(imagePlane.width, imagePlane.height, currentScene->backgroundColor);
    for(int i=0; i < imagePlane.width; i++) {
        for(int j=0; j < imagePlane.height; j++) {
            Ray ray = calculateRay(i,j);
            ray.direction.normalize();
            img.Pixel(i,j) = (currentScene->tree).rayTrace(ray, currentScene->reflectDepth);
        }
    }
    return img;
}
