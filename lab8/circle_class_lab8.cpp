#include "point.h"
#include "circle_class_lab8.h"

class Point;

Circle::~Circle() {};
Point::~Point() {};

Circle::Circle(double r, Point& P)
{
	if (r > 0)
		_r = r;
	_P = P;
	_count++;
}

Circle &Circle::setRadius(double radius)
{
	if (radius > 0)
	{
		_r = radius;
		return (*this);
	}
	else
		throw std::invalid_argument("Invalid radius");
}

Circle &Circle::setPx(double x)
{
	if (x - _r > 0)
	{
		_P.setPoint(x, _P.getPointy());
		return (*this);
	}
	else
		throw std::invalid_argument("Out from XOY");
}

Circle &Circle::setPy(double y)
{
	if (y - _r > 0)
	{
		_P.setPoint(_P.getPointx(), y);
		return (*this);
	}
	else
		throw std::invalid_argument("Out from XOY");
}

Point	Circle::getPoint() const
{
	return (_P);
}

const Circle &Circle::getter() const
{
	return (*this);
}

double	Circle::getRadius() const
{
	return (_r);
}

double	area(const Circle &C)
{
	double r = C._r;
	double area = M_PI * r * r;

	std::cout << "Are of circle is: " << area << std::endl;
	return (area);
}

void	area_check(Circle &C, double k)
{
	double x0 = C.getPoint().getPointx();
	double y0 = C.getPoint().getPointy();
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
	double x0 = C.getPoint().getPointx();
	double y0 = C.getPoint().getPointy();
	double r = C.getRadius();

	if (pow(x - x0, 2) + pow(y - y0, 2) <= r * r)
		return (1);
	return (0);
}

double	distance_of_centers(const Circle& C1, const Circle& C2)
{
	double x01 = C1.getPoint().getPointx();
	double x02 = C2.getPoint().getPointx();
	double y01 = C1.getPoint().getPointy();
	double y02 = C2.getPoint().getPointy();
	double	D = 0;

	std::cout << "x0 y0 " << x01 << " " << x02 << " " << y01 << " " << y02 << std::endl; 
	D = sqrt(pow((x01 - x02), 2) + pow((y01 - y02), 2));
	return (D);
}

int	num_of_intersections(const Circle &C1, Circle const &C2)
{
	double x1 = C1.getPoint().getPointx();
	double x2 = C1.getPoint().getPointx();
	double y1 = C2.getPoint().getPointy();
	double y2 = C2.getPoint().getPointy();
	double r1 = C1.getRadius();
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
	C.setPx((C.getPoint().getPointx() + move_step));
	std::cout << "The new x_0 is: " << C.getPoint().getPointx() << std::endl;
}

void	move_vertically(Circle& C, double move_step)
{
	C.setPy((C.getPoint().getPointy() + move_step));
	std::cout << "The new y_0 is: " << C.getPoint().getPointy() << std::endl;
}

std::string	Circle::info()
{
	std::ostringstream ostr;

	ostr << "x0 is: " << getPoint().getPointx() << ", \n" << "y0 is: " << getPoint().getPointy() << ", \n" << "radius is: " << _r << std::endl;
	return (ostr.str());
}

//lab7
Point& operator++(Point& p)
{
	p._x++;
	p._y++;
	return (p);
}

Point operator++(Point& p, int)
{
	Point tmp = p;
	(p._x)++;
	(p._y)++;
	return (tmp);
}

std::ostream& operator<<(std::ostream& output, const Circle& C)
{
	// output << C.info();
	output << "Center is " << C.getPoint().getPointx() << "," << C.getPoint().getPointy() << " Radius is " << C.getRadius() <<std::endl;
	return (output);
}

std::istream& operator>>(std::istream& input, Circle &c)
{
	double x, y, r;
	input >> x >> y >> r;
	c.setRadius(r);
	c.getPoint().setPoint(x, y);
	return (input);
}

std::ostream& operator<<(std::ostream& output, const Point& P)
{
	output << "Center is " << P.getPointx() << "," << P.getPointy() << std::endl;
	return (output);
}

std::istream& operator>>(std::istream& input, Point &P)
{
	double x, y;
	input >> x >> y;
	P.setPoint(x, y);
	return (input);
}
//lab8

int Circle::_count = 0;

int main()
{
	try 
	{
		Point P(3, 5);
		Point tmp;
		//P++;
		Circle C(8, P);
		Point  P1(4, 2);
		Circle C1(2, P1);
		std::cout << P << std::endl;
		//
		//+ overload test
		// tmp = P + P1;
		// std::cout << tmp << std::endl;
		//
		
		//C1.setPx(3).setPy(2).setRadius(4);
		std::cout << C << std::endl;
		std::cout << C1 << std::endl;
		length_calc(C);
		std::cout << "Distance between centers is: " << distance_of_centers(C, C1) << std::endl;
		std::cout << "number of intersections is: " << num_of_intersections(C, C1) << std::endl;
	}
	catch (std::invalid_argument& e)
	{
		std::cerr << "Exception caught" << e.what() << std::endl;
	}
}