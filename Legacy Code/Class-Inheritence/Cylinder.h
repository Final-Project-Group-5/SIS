#ifndef CYLINDER_H
#define CYLINDER_H

#include "Circle.h"

class Cylinder : public Circle {
    protected:
        double length = 0.0;
    
    public:
        Cylinder() {}
        Cylinder(double radius, double length);

        double calculateValue();
};

#endif