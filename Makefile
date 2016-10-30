SRC = main.cpp \
    BoundingBox.cpp \
    Color.cpp \
    Intensity.cpp \
    KDNode.cpp \
    KDTree.cpp \
    LightProperty.cpp \
    Material.cpp \
    Scene.cpp \
    Sphere.cpp \
    Surface.cpp \
    Triangle.cpp \
    Vector3.cpp \
    Camera.cpp \
    Image.cpp \
    PointLight.cpp

OBJ = $(SRC:.cpp=.o)
CFLAGS = -std=c++11 -O3

.cpp.o:
	g++ -c $< $(CFLAGS)

all: test

test: $(OBJ)
	g++ $(OBJ) -o raytracer $(CFLAGS)

clean:
	rm -f *.o raytracer *.ppm
