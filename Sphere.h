#ifndef ODEV_SPHERE
#define ODEV_SPHERE


class Sphere : public Surface{

public:
    int center;
    int radius;
    Sphere():center(-1), radius(-1), type(false), material(-1) {}
    Sphere(int c, int r, int m): center(c), radius(r), type(false), material(m) {}
    bool Intersect(const Ray& ray, RayHitInfo& hitInfo) const;
};


#endif 
