#pragma once
#include "Polygon.h"


class Triangle : public Polygon {
    public:
        Triangle(int *xs, int *ys, std::string name);
        ~Triangle();

        double area() override;
};
