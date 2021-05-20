// Lecture11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// #include "PCH.h"
#include <iostream>
#include <math.h>

using namespace std;

//Decleration Section
class Complex {
public:						//members could be either public or private. Could be borken in different groups. Could be listed in any order
	Complex(double = 0.0, double = 0.0, char n = ' ');
	~Complex();

private:
	char name;
	double realPart;	//Data members
	double imaginaryPart;

public:
	char showName();
	void setName(char n) { name = n; }
	void setReadPart(double);		//inline function declerated explicitly
	void setImaginaryPart(double i) { imaginaryPart = i; }	//inline function declared implicitly
	void assignNewValues(double, double, char n);

	void showComplexValues();
	double getReadPart();		//inline function declerated explicitly
	double getImaginaryPart() { return imaginaryPart; }	//inline function declared implicitly

	double amplitude();

	Complex multScalar(double);

	Complex operator+(const Complex&);
	Complex operator*(const Complex&);
	void swap(Complex&);
	bool operator==(const Complex&);
};

//Implementation Section
bool Complex::operator==(const Complex& complex2) {
	return (this->realPart == complex2.realPart) && (this->imaginaryPart == complex2.imaginaryPart);
}

Complex Complex::operator+(const Complex& complex2) {
	Complex temp;
	temp.realPart = this->realPart + complex2.realPart;
	temp.imaginaryPart = this->imaginaryPart + complex2.imaginaryPart;
	return temp;
}

Complex Complex::operator*(const Complex& complex2) {
	Complex temp;
	temp.realPart = realPart * complex2.realPart - imaginaryPart * complex2.imaginaryPart;
	temp.imaginaryPart = realPart * complex2.imaginaryPart + imaginaryPart * complex2.realPart;
	return temp;
}
// I already know what the error will be if we attempt to declare b as a const it will fail, as const forces that particular referenced object to
// to be immutable as to preserve the integritity of the arguments data. This would mean that we would not be able to modify or reassign the data
// as is required to swap the data between our objects.
void Complex::swap(Complex& b) {
	double tempReal = b.getReadPart(),
		tempImaginary = b.getImaginaryPart();
	b.assignNewValues(realPart, imaginaryPart, b.showName());
	realPart = tempReal;
	imaginaryPart = tempImaginary;
	cout << "Swap successful!"<< endl;
}	

char Complex::showName(){
	return name;
}
Complex Complex::multScalar(double factor) {		// "this" pointer 
	Complex m(0.0, 0.0, 'M');
	//m.realPart = realPart * factor;
	m.realPart = (*this).realPart * factor;		// (*this). is equivalent to this->
	m.imaginaryPart = this->imaginaryPart * factor;

	return m;
}

double Complex::amplitude() {
	double a = sqrt(pow(realPart, 2) + pow(imaginaryPart, 2));
	return a;
}

Complex::Complex(double a, double b, char n) {
	realPart = a;
	imaginaryPart = b;
	name = n;
	cout << name << " Constructor called!" << endl;
}

Complex::~Complex() {
	cout << name << " Destructor called!" << endl;
	realPart = 0.0;
}

void Complex::assignNewValues(double a, double b, char n) {
	realPart = a;
	imaginaryPart = b;
	name = n;
}

void Complex::showComplexValues() {
	char sign = '+';
	if (imaginaryPart < 0) sign = '-';

	cout << name << ", Value is: " << realPart << " " << sign << " " << abs(imaginaryPart) << "i" << endl;
}

inline void Complex::setReadPart(double r) {
	realPart = r;
}

inline double Complex::getReadPart() {
	return realPart;
}

int main()
{
	Complex a, b, c(4.5, 8.9, 'C');	//Various ways of instaniating
	b.assignNewValues(3.3, 9.9, 'B');	//Use member function

	a.showComplexValues();	//Call member function to see what stored in data members of each object
	b.showComplexValues();
	c.showComplexValues();

	cout << "Amplitude of C: " << c.amplitude() << endl;
	b.swap(c);

	Complex x = b.multScalar(2.0);
	x.setName('X');
	x.showComplexValues();

	Complex z;
	z.setName('Z');
	z.setReadPart(b.getReadPart() + c.getReadPart());
	z.setImaginaryPart(b.getImaginaryPart() + c.getImaginaryPart());
	z.showComplexValues();

	//Complex r = b + c;	// This is equivalent to call below
	Complex r = b.operator+(c);
	r.setName('R');
	r.showComplexValues();

	cout << "Are B & C equal? " << (b == c) << endl;
	cout << "Are R & Z equal? " << (r == z) << endl;

	Complex s(b);		//Copy Constructor - created automatically by compiler. This is equivalent to below
	//Complex s = b;	// Complier automatically adds the assignment operator for every class you create
	s.setName('S');
	s.showComplexValues();


	c.~Complex();		//Call destructor just like any other function
	c.showComplexValues();
	cout << "--- main completed ---" << endl;
}
