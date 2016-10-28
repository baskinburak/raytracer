#include <iostream>
#include <fstream>
#include "Scene.h"

int main(int argc, char** argv)
{
    if (argc < 3)
    {
        std::cerr << "Please provide scene and camera files" << std::endl;
        return 1;
    }

    Scene CurrentScene;

    CurrentScene.ReadScene(argc, argv);

    /*for (const auto& camera : CurrentScene->Cameras())
    {
        Image img = camera.Render();

        std::ofstream out(camera.OutputFile());

        out << img;
    }*/

    return 0;
}
