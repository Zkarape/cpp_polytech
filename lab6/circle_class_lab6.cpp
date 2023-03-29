#include <cmath>
#include <iostream>
#include <cstring>
#include <sstream>
#include "point.hpp"

#define PHI 3.14

Circle::Circle(double r = 1, Point& P)
{
	if (r > 0)
		_r = r;
	_P = P;
}

void	Circle::setRadius(double radius)
{
	if (radius > 0)
		_r = radius;
	else
		throw std::invalid_argument("Invalid radius");
}

double	Circle::getRadius() const
{
	return (_r);
}

double	area(const Circle &C)
{
	double r = C.getRadius();
	double area = PHI * r * r;

	std::cout << "Are of circle is: " << area << std::endl;
	return (area);
}

void	area_check(Circle &C, double k)
{
	double x0 = C.getCenterx();
	double y0 = C.getCentery();
	double r = C.getRadius();

	if (x0 + sqrt(k) * r > 0 && y0 + sqrt(k) * r > 0)
	{
		C.setRadius(sqrt(k) * r);
		std::cout << "The new area is: " << area(C) << std::endl;
	}
	std::cout << "The area is: " << area(C) << std::endl;
}

int	belongs_circle(double x, double y, const Circle &C)
{
	double x0 = C.getCenterx();
	double y0 = C.getCentery();
	double r = C.getRadius();

	if (pow(x - x0, 2) + pow(y - y0, 2) <= r * r)
		return (1);
	return (0);
}

double	distance_of_centers(const Circle& C1, const Circle& C2)
{
	double x01 = C1.getCenterx();
	double y01 = C1.getCentery();
	double x02 = C2.getCenterx();
	double y02 = C2.getCentery();
	double	D = 0;

	D = sqrt(pow((x01 - x02), 2) + pow((y01 - y02), 2));
	return (D);
}

int	num_of_intersections(const Circle &C1, Circle const &C2)
{
	double x1 = C1.getCenterx();
	double y1 = C1.getCentery();
	double r1 = C1.getRadius();
	double x2 = C2.getCenterx();
	double y2 = C2.getCentery();
	double r2 = C2.getRadius();
	double	D = 0;

	D = distance_of_centers(C1, C2);
	if (r1 == r2 && x1 == x2 && y1 == y2)
		return (-1);
	if (D > r1 + r2)
		return (0);
	if (D < r1 + r2)
		return (2);
	if (D == abs(r1 - r2))
		return (1);
	return (8);
}

void	length_calc(const Circle &C)
{
	double r = C.getRadius();
	
	std::cout << "The length of circle is: " << 2 * M_PI * r << std::endl;
}

void	move_horizontally(Circle& C, double move_step)
{
	C.setCenterx(C.getCenterx() + move_step); 
	std::cout << "The new x_0 is: " << C.getCenterx() << std::endl;
}

void	move_vertically(Circle& C, double move_step)
{
	C.setCentery(C.getCentery() + move_step);
	std::cout << "The new y_0 is: " << C.getCentery() << std::endl;
}

std::string	Circle::info()
{
	std::ostringstream ostr;

	ostr << "x0 is: " << _x0 << ", \n" << "y0 is: " << _y0 << ", \n" << "radius is: " << _r << std::endl;
	return (ostr.str());
}

int main()
{
	try 
	{
		Circle C(3, 5, 8);
		Circle C1(4, 2, 2);
		std::cout << C.info() << std::endl;
		std::cout << C1.info() << std::endl;
		length_calc(C);
		std::cout << "Distance between centers is: " << distance_of_centers(C, C1) << std::endl;
		std::cout << "number of intersections is: " << num_of_intersections(C, C1) << std::endl;
	}
	catch (std::invalid_argument& e)
	{
		std::cerr << "Exception caught" << e.what() << std::endl;
	}
}
