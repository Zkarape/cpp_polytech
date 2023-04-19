#include "point.h"
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>

class Circle
{
	private:
		double	_r;
		Point	*_pPtr;
	public:
		Circle &setRadius(double);
		Circle &setPoint(Point *pPtr);
		Circle &setPx(double x);
		Circle &setPy(double y);
		double	getRadius() const;
		Point	getPoint() const;
		const Circle &getter() const;
		static	int _count;
		std::string info();
		Circle();
		Circle(const Circle &);
		Circle(double, Point &);
		~Circle();
		friend double area(const Circle &C);
		friend std::ostream& operator<<(std::ostream&, const Circle&);
		friend std::istream& operator>>(std::istream& input, Circle);
		Circle& operator=(const Circle&);
};
