#include <iostream>
#include <math.h>

using namespace std;

class Coord{
    private:
        double xval,
            yval;
    public:
        Coord(double = 0, double = 0);
        void dispCoord();
    friend void convPol(Coord&);

};

Coord::Coord(double x, double y){
    xval = x;
    yval = y;
};

void Coord::dispCoord(){
    cout << "x is: " << xval << endl;
    cout << "y is: " << yval << endl;
};

void convPol(Coord& c){
    double r,
        theta;
    cout << "Please enter the radius" << endl;
    cin >> r;
    cout << "Please enter the angle Theta (in radians)" << endl;
    cin >> theta;

    c.xval = r * cos(theta);
    c.yval = r * sin(theta);
};

int main(){
    Coord c;
    convPol(c);
    cout << "The new Rectangular coordinates are: " << endl;
    c.dispCoord();
}