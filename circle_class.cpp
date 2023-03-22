#include <cmath>
#include <iostream>
#include <cstring>
#define PHI 3.14

class Circle
{
	private:
		double	_r;
		double	_x0;
		double	_y0;
	public:
		void	setRadius(double);
		void	setCenterx(double);
		void	setCentery(double);
		double	getRadius() const;
		double	getCenterx() const;
		double	getCentery() const;
		Circle(double r = 1, double x0 = 2, double y0 = 2)
		{
			setRadius(r);
			setCenterx(x0);
			setCentery(y0);
		}
		~Circle()
		{
			std::cout << "Object is deleted" << std::endl;
		}
};

void	Circle::setRadius(double radius)
{
	if (radius > 0)
		_r = radius;
}

void	Circle::setCenterx(double x0)
{
	if (_x0 + _r > 0)
		_x0 = x0;
}

void	Circle::setCentery(double y0)
{
	if (_y0 + _r > 0)
		_y0 = y0;
}

double	Circle::getRadius() const
{
	return (_r);
}

double	Circle::getCenterx() const
{
	return (_x0);
}

double	Circle::getCentery() const
{
	return (_y0);
}

int	belongs_circle(const double x, const double y, const Circle &C) const
{
	double x0 = C.getCenterx();
	double y0 = C.getCentery();
	double r = C.getRadius();
	if (pow(x - x0) + pow(y - y0) <= r * r)
		return (1);
	return (0);
}

int	num_of_intersections(const Circle &C1, const Circle &C2) const
{
	double x01 = C1.getCenterx();
	double y01 = C1.getCentery();
	double r1 = C1.getRadius();
	double x02 = C2.getCenterx();
	double y02 = C2.getCentery();
	double r2 = C2.getRadius();
	double	D = 0;

	D = (2 * pow((x2 - x1), 2) + (2 * pow((y2 - y1), 2) - 4 * (r1 * r1 - r2 * r2 + x1 * x1 - x2 * x2 + y1 * y1 - y2 * y2);
	if (r1 == r2 && x01 == x02 && y01 == y02)
		return (-1);
	if (D == 0)
		return (1);
	if (D > 0)
		return (2);
	if (D < 0)
		return (0);
}

void	length_calc(const Circle &C) const
{
	double r = C.getRadius();
	
	std::cout << "The length of circle is: " << 2 * PHI * r << std::endl;
}

void	area(const Circle &C) const
{
	double r = C.getRadius();

	std::cout << "Are of circle is: " << PHI * r * r << std::endl;
}

void	distance_of_centers(const Circle &C1, const Circle &C2) const
{
	double x01 = C1.getCenterx();
	double y01 = C1.getCentery();
	double x02 = C2.getCenterx();
	double y02 = C2.getCentery();
	double	D = 0;

	D = pow((x01 - x02), 2) + pow((y01 - y02), 2);
	std::cout << "Distance between centers is: " << D << std::endl;
}

void	move_horizontally(const Circle &C, double move_length) const
{
	std::cout << "The new x_0 is: " << C.getCenterx() + move_lenght << std::endl;
	std::cout << "The new y_0 is: " << C.getCentery() + move_lenght << std::endl;
}
