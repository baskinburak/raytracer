#ifndef ODEV_LIGHT_PROPERTY
#define ODEV_LIGHT_PROPERTY

class LightProperty {
    public:
        double R;
        double G;
        double B;
        LightProperty(): R(0), G(0), B(0);
        LightProperty(double r, double g, double b): R(r), G(g), B(b) {}
        friend std::istream& operator>>(std::istream& stream, LightProperty& lp);
}

#endif
