#include "Triangle.h"

Triangle::Triangle(int *xs, int *ys, std::string name) : Polygon(3, xs, ys, name) {}

Triangle::~Triangle() = default;

double Triangle::area() {
    return 0.5 * abs(
        xs[0] * (ys[1] - ys[2]) +
        xs[1] * (ys[2] - ys[0]) +
        xs[2] * (ys[0] - ys[1])
    );
}
