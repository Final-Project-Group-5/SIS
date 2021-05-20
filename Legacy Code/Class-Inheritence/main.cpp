#include <iostream>
#include "Circle.h"
#include "Cylinder.h"
#include "Starship.h"

using namespace std;

int main() {
    Circle c(5);
    Cylinder y(5, 10);
    Starship s(5, 10, 2);

    std::cout << "Circle Area: " << c.calculateValue() 
              << "\tCylinder Volume:" << y.calculateValue() 
              << "\t\tStarship Volume:" << s.calculateValue() 
              << endl;
}