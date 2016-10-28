#ifndef ODEV_COLOR
#define ODEV_COLOR

#include <iostream>

class Color {
    public:
        int R;
        int G;
        int B;
        Color(): R(0), G(0), B(0) {};
        Color(int r, int g, int b): R(r), G(g), B(b) {}

        friend std::istream& operator>>(std::istream& stream, Color& color);
};



#endif
