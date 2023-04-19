#include "circle_class_lab8.h"
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

Point Point::operator+(const Point& P2) const
{
	return (Point(this->_x + P2._x, this->_y + P2._y));
}

Point Point::operator-(const Point& P2) const
{
	return (Point(this->_x - P2._x, this->_y - P2._y));
}

// Point Point::operator+=(const Point &P2) const//////////& with const causes error????????????
// {
// 	*this = *this + P2;
// 	//printf("x iss = %f, y is == %f\n", x, y);
// 	return (*this);
// }

// Point Point::operator-=(const Point &P2) const//////////& with const causes error????????????
// {
// 	*this = *this - P2;
// 	//printf("x iss = %f, y is == %f\n", x, y);
// 	return (*this);
// }

bool Point::operator==(const Point &P2) const
{
	return (this->getPointx() == P2.getPointx() && this->getPointy() == P2.getPointy());
}

bool Point::operator!=(const Point &P2) const
{
	return (this->getPointx() != P2.getPointx() && this->getPointy() != P2.getPointy());
}

bool Point::operator>(const Point &P2) const
{
	return (this->getPointx() > P2.getPointx() && this->getPointy() > P2.getPointy());
}

bool Point::operator>=(const Point &P2) const
{
	return (this->getPointx() >= P2.getPointx() && this->getPointy() >= P2.getPointy());
}

bool Point::operator<(const Point &P2) const
{
	return (this->getPointx() < P2.getPointx() && this->getPointy() < P2.getPointy());
}

bool Point::operator<=(const Point &P2) const
{
	return (this->getPointx() <= P2.getPointx() && this->getPointy() <= P2.getPointy());
}

/*
Point& Point::operator++()
{
	std::cout << "mtaaaaaaaa prefixxxx\n";
	_x++;
	_y++;
	return (*this);
}

Point Point::operator++(int)
{
	std::cout << "mtaaaaaaaa\n";
	Point tmp = *this;
	_x++;
	_y++;
	std::cout << "tmp x is" << tmp._x << tmp._y << std::endl; 
	return (tmp);
}
*/
