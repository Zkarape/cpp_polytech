#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <cstdbool>

class Point
{
	private:
		double _x;
		double _y;
	public:
		Point();
		Point(double, double);
		void	setPoint(double x, double y);
		double	getPointx() const;
		double	getPointy() const;
//		Point& operator++();
//		Point operator++(int);
		Point operator+(const Point &P2) const;
		Point operator-(const Point &P2) const;
		Point operator+=(const Point &P2) const;
		Point operator-=(const Point &P2) const;
		bool operator==(const Point &P2) const;
		bool operator!=(const Point &P2) const;
		bool operator>(const Point &P2) const;
		bool operator>=(const Point &P2) const;
		bool operator<(const Point &P2) const;
		bool operator<=(const Point &P2) const;
		friend Point& operator++(Point&);
		friend Point operator++(Point&, int);
		friend std::ostream& operator<<(std::ostream&, const Point&);
		friend std::istream& operator<<(std::istream&, Point&);
		~Point();
		//void	*getPoint() const;
};

#endif