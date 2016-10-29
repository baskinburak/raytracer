#ifndef ODEV_COLOR
#define ODEV_COLOR

#include <iostream>

class Color {
    public:
        int r;
        int g;
        int b;
        Color(): r(0), g(0), b(0) {};
        Color(int rr, int gg, int bb): r(rr), g(gg), b(bb) {}
        int R() const { return r; }
        int G() const { return g; }
        int B() const { return b; }
        friend std::istream& operator>>(std::istream& stream, Color& color);
};



#endif
