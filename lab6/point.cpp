#include "circle_class_lab6.h"
#include "point.h"

Point::Point(double x = 2, double y = 2)
{
	if (x > 0 && y > 0)
	{
		setCenterx(x);
		setCentery(y);
	}
}

void	Point::setCenterx(double x0)
{
	_x0 = x0;
}

void	Point::setCentery(double y0)
{
	_y0 = y0;
}

double Point::getCenterx()
{
	return (_x0);
}

double Point::getCentery()
{
	return (_y0);
}
