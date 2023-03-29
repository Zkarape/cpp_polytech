#include "circle_class_lab6.h"
#include "point.h"

Point::Point()
{
	_x = 0;
	_y = 0;
}

Point::Point(double x = 2, double y = 2)
{
	if (x > 0 && y > 0)
		setPoint(x, y);
}

void	Point::setPoint(double x = 2, double y = 2)
{
	if (x > 0 && y > 0)
	{
		_x = x;
		_y = y;
	}
}

/*
Point &Point::getPoint() const
{
	return (*this);
}
*/

double Point::getPointx() const
{
	return (_x);
}

double Point::getPointy() const
{
	return (_y);
}
