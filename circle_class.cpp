#include <cmath>
#include <iostream>
#include <cstring>

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
		double	getRadius();
		double	getCenterx();
		double	getCentery();
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

double	Circle::getRadius()
{
	return (_r);
}

double	Circle::getCenterx()
{
	return (_x0);
}

double	Circle::getCentery()
{
	return (_y0);
}
