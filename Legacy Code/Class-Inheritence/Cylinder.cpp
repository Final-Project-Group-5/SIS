#include <cmath>
#include "Cylinder.h"
#include <iostream>

using namespace std;

Cylinder::Cylinder(double radius, double length) {
    this->radius = radius;
    this->length = length;
}

double Cylinder::calculateValue() {
    //cout << length << " " << radius << endl;
    return PI * length * pow(radius, 2);

    //return length * Circle::calcualteValue();
}