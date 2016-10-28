#ifndef ODEV_INTENSITY
#define ODEV_INTENSITY

#include <iostream>

class Intensity {
    public:
        double R;
        double G;
        double B;
        Intensity():R(0), G(0), B(0) {}
        friend std::istream& operator>>(std::istream& stream, Intensity& intensity);
};

#endif
