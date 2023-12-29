#include "Tetragon.h"

Tetragon::Tetragon(int *xs, int *ys, std::string name) : Polygon(4, xs, ys, name) {}

Tetragon::~Tetragon() = default;

double Tetragon::area() {
    return abs(
        xs[0] * (ys[1] - ys[3]) +
        xs[1] * (ys[3] - ys[0]) +
        xs[2] * (ys[0] - ys[1]) +
        xs[3] * (ys[1] - ys[2])
    );
}
