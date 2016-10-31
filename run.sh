echo "att_test_scene";
time ./raytracer scenes/att_test_scene.txt cameras/att_test_camera.txt;
echo "bunny_scene";
time ./raytracer scenes/bunny_scene.txt cameras/bunny_camera.txt;
echo "spheres_scene";
time ./raytracer scenes/spheres_scene.txt cameras/spheres_camera.txt;
echo "teapot_scene";
time ./raytracer scenes/teapot_scene.txt cameras/teapot_camera.txt;
echo "cornell_scene";
time ./raytracer extra_inputs/scene/cornell_scene.txt extra_inputs/camera/cornell_camera.txt;
echo "horse_and_mug_highres_scene";
time ./raytracer extra_inputs/scene/horse_and_mug_highres_scene.txt extra_inputs/camera/horse_and_mug_highres_camera.txt;
echo "simple_scene";
time ./raytracer extra_inputs/scene/simple_scene.txt extra_inputs/camera/simple_camera.txt;
echo "sphere_shadow_scene";
time ./raytracer extra_inputs/scene/sphere_shadow_scene.txt extra_inputs/camera/sphere_shadow_camera.txt;
echo "cube_and_sphere_scene";
time ./raytracer extra_inputs/scene/cube_and_sphere_scene.txt extra_inputs/camera/cube_and_sphere_camera.txt;
echo "horse_and_mug_scene";
time ./raytracer extra_inputs/scene/horse_and_mug_scene.txt extra_inputs/camera/horse_and_mug_camera.txt;
echo "single_sphere_scene";
time ./raytracer extra_inputs/scene/single_sphere_scene.txt extra_inputs/camera/single_sphere_camera.txt;
