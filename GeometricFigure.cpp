#define _USE_MATH_DEFINES

#include "GeometricFigure.h"
#include <cmath>
#include <iostream>

const int GrPi = 180;

double GeometricFigure::checkValue(const double value) const
{
	if (value <= 0)
		throw std::out_of_range("Zero value exception");
	return value;
}

double GeometricFigure::checkAngle(double value) const {
	if ((value > 0) && (value <= GrPi / 2)) {
		return value;
	}
	else  if ((value > GrPi / 2) && (value <= GrPi)) {
		return GrPi - value;
	}
	else {
		throw std::exception("Invalid_Angle");
	}
}

Сircle::Сircle(const double R)
{
	this->R = checkValue(R);
}

Сircle::Сircle(const Сircle& circle)
{
	this->R = circle.R;
	this->perimeter = circle.perimeter;
	this->area = circle.area;
}

double Сircle::getPerimeter() {
	this->perimeter = 2 * M_PI * R;
	return this->perimeter;
}

double Сircle::getArea() {
	this->area = M_PI * pow(R, 2);
	return this->area;
}

Rectangle::Rectangle(double a, double b)
{
	this->a = checkValue(a);
	this->b = checkValue(b);
}

Rectangle::Rectangle(const Rectangle& rectangle)
{
	this->a = rectangle.a;
	this->b = rectangle.b;
	this->perimeter = rectangle.perimeter;
	this->area = rectangle.area;
}

double Rectangle::getPerimeter() {
	this->perimeter = 2 * (this->a + this->b);
	return this->perimeter;
}

double Rectangle::getArea() {
	this->area = this->a * this->b;
	return this->area;
}

Triagle::Triagle(double a, double h, double angle)
{
	this->a = checkValue(a);
	this->h = checkValue(h);
	this->angle = checkAngle(angle);
}

Triagle::Triagle(const Triagle& triagle)
{
	this->a = triagle.a;
	this->h = triagle.h;
	this->angle = triagle.angle;
	this->perimeter = triagle.perimeter;
	this->area = triagle.area;
}

double Triagle::getPerimeter() {
	this->perimeter = this->a + this->h + sqrt(pow(this->a, 2) + pow(this->h, 2) - 2 * this->a * this->h * abs(cos(this->angle*(M_PI / 180))));
	return this->perimeter;
}

double Triagle::getArea() {
	this->area = 0.5 * this->a * this->h * abs(sin(this->angle*(M_PI / 180)));
	return this->area;
}

std::ostream& operator<<(std::ostream& out, const GeometricFigure& geometricFigure)
{
	out << "Perimetr " << geometricFigure.perimeter << std::endl << "Area " << geometricFigure.area << std::endl;
	return out;
}

std::istream& operator>>(std::istream& in, Сircle& circle)
{
	double R;
	in >> R;
	circle = Сircle(R);
	return in;
}

std::istream& operator>>(std::istream& in, Rectangle& rectangle)
{
	double a, b;
	in >> a >> b;
	rectangle = Rectangle(a, b);
	return in;
}

std::istream& operator>>(std::istream& in, Triagle& triagle)
{
	double a, h, angle;
	in >> a >> h >> angle;
	triagle = Triagle(a, h, angle);
	return in;
}