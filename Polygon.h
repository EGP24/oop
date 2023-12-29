#pragma once
#include <string>


class Polygon {
    protected:
        int n;
        int *xs;
        int *ys;
        std::string name;

    public:
        Polygon(int n, int *xs, int *ys, std::string name);
        ~Polygon();

        void move(int dx, int dy);
        std::string getName() const;
        int* getXs() const;
        int* getYs() const;

        bool isIntersect(Polygon& other);
        bool isPointInPolygon(int x, int y);

        virtual double area() = 0;
};
