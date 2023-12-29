#include "Polygon.h"

Polygon::Polygon(int n, int *xs, int *ys, std::string name) {
    this->n = n;
    this->xs = xs;
    this->ys = ys;
    this->name = name;
}

Polygon::~Polygon() = default;

void Polygon::move(int dx, int dy) {
    for (int i = 0; i < n; i++) {
        xs[i] += dx;
        ys[i] += dy;
    }
}

bool Polygon::isPointInPolygon(int x, int y) {
    int i, j;
    bool c = false;
    for (i = 0, j = n - 1; i < n; j = i++) {
        if (
           ((ys[i] > y) != (ys[j] > y))
           && (x < (xs[j] - xs[i]) * (y - ys[i]) / (ys[j] - ys[i]) + xs[i])
        )
            c = !c;
    }
    return c;
}

bool Polygon::isIntersect(Polygon &other) {
    for (int i = 0; i < n; i++) {
        if (other.isPointInPolygon(xs[i], ys[i])) {
            return true;
        }
    }
    return false;
}

std::string Polygon::getName() const{
    return this->name;
}

int *Polygon::getXs() const {
    return this->xs;
}

int *Polygon::getYs() const {
    return this->ys;
}
