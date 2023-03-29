#ifndef POINT_H
#define POINT_H

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
		~Point();
		//void	*getPoint() const;
};

#endif
