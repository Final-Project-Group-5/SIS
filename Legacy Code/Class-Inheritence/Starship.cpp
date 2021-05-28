#include "Circle.h"
#include "Cylinder.h"
#include "Starship.h"

Starship::Starship(double radius, double length, double height) {
    this->radius = radius;
    this->length = length;
    this->height = height;
}

double Starship::calculateValue() {
    double coneVolume = Circle::calculateValue() * height / 3;
    return coneVolume + Cylinder::calculateValue();
}