#ifndef ODEV_KAMERA
#define ODEV_KAMERA

#include "Vector3.h"
#include "Image.h"
#include "Ray.h"

class Scene;

class Camera {
    private:
        Ray calculateRay(int px_x, int px_y) const;
        void calculateRight();
    public:
        Vector3 position;
        Vector3 gaze;
        Vector3 right;
        Vector3 up;
        
        struct {
            double left, right, bottom, top;
            double distance;

            int width;
            int height;

        } imagePlane;

        std::string outputFile;
        Image Render(Scene* currentScene) const;

        friend std::istream& operator>>(std::istream& stream, Camera& camera);


};

#endif
