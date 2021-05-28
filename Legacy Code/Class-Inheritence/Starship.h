#ifndef STARSHIP_H
#define STARSHIP_H

#include "Circle.h"
#include "Cylinder.h"

class Starship : public Cylinder {
    private:
        double height = 0.0;

    public:
        Starship(){}
        Starship(double radius, double length, double height);

        double calculateValue();
};

#endif