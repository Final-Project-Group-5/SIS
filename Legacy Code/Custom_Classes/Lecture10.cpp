// Lecture10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// #include "pch.h"
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
	void setName(char n) { name = n; }
	void setReadPart(double);		//inline function declerated explicitly
	void setImaginaryPart(double i) { imaginaryPart = i;}	//inline function declared implicitly
	void assignNewValues(double, double, char n);

	void showComplexValues();
	double getReadPart();		//inline function declerated explicitly
	double getImaginaryPart() {return imaginaryPart;}	//inline function declared implicitly

	double amplitude();

	Complex multScalar(double);
};

//Implementation Section
Complex Complex::multScalar(double factor) {
	Complex m(0.0, 0.0, 'M');
	m.realPart = realPart * factor;
	m.imaginaryPart = imaginaryPart * factor;

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

	Complex x = b.multScalar(2.0);
	x.setName('X');
	x.showComplexValues();

	c.~Complex();		//Call destructor just like any other function
	c.showComplexValues();
	cout << "--- main completed ---" << endl;
}
