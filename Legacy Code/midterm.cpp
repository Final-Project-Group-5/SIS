#include <iostream>
#include<vector>

using namespace std;

class Rectangle{
    public:
        Rectangle(float, float, float);
        double get_volume();
        bool is_cube();
        bool operator==(const Rectangle&);
    private:
        float length,
            height,
            width;
};

Rectangle::Rectangle(float x, float y, float z){
    length = y;
    width = x;
    height = z;
};

double Rectangle::get_volume(){
    return height * width * length;
};

bool Rectangle::is_cube(){
    return width == height && height == length;
};

// This wont work since data members are private and I have not time to write in access functions it would seem
bool Rectangle::operator==(const Rectangle& r2) {
	return (this->length == r2.length) && (this->width == r2.width) && (this->height == r2.height);
}

int main(){
    Rectangle r = Rectangle(2,2,2);
    Rectangle r2 = Rectangle(2,2,2);
    cout << r.get_volume() <<" " <<  r.is_cube() << endl;
    cout << (r==r2) << endl;
    return 1;
}