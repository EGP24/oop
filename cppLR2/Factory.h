#pragma once
#include "Polygon.h"
#include <vector>


class Factory {
    friend class Menu;
    public:
        Factory();
        ~Factory();

        void addFigure();
        void removeFigure();
    private:
        std::vector<Polygon*> polygons;
};
