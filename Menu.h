#pragma once
#include "Polygon.h"
#include "Factory.h"


typedef enum { AddObj, DelObj, WorkWithObj, JobExit} JobMode;
typedef enum { GetArea, IsIntersect, Move, ActionExit } FigureAction;

class Menu {
public:
    Menu() {};
    ~Menu() {};

    JobMode selectJob() const;
    FigureAction selectAction() const;
    Polygon* selectObject(const Factory&) const;
    static int selectItem(int);
};



