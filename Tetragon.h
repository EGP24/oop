#pragma once
#include "Polygon.h"


class Tetragon : public Polygon {
public:
    Tetragon(int *xs, int *ys, std::string name);
    ~Tetragon();

    double area() override;
};
