#ifndef ODEV_KAMERA
#define ODEV_KAMERA

#include "Vector3.h"
#include "Image.h"

class Camera {
    public:
        Vector3 position;
        Vector3 gaze;
        Vector3 up;
        
        struct {
            float left, right, bottom, top;
            float distance;

            int width;
            int height;

        } imagePlane;

        std::string outputFile;
        Image Render(Scene* currentScene) const;

        friend std::istream& operator>>(std::istream& stream, Camera& camera);


};

#endif
