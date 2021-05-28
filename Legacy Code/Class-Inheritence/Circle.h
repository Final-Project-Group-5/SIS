#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
    protected:
        const double PI = 3.14159;
        double radius = 0.0;
    public:
        Circle(){}
        Circle(double radius) {
            this->radius = radius;
        }
        
        double calculateValue();
};

#endif