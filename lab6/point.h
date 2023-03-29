#ifndef POINT_H
#define POINT_H

class Point
{
	private:
		double _x0;
		double _y0;
	public:
		Point(double, double);
		void	setCenterx(double);
		void	setCentery(double);
		double	getCenterx() const;
		double	getCentery() const;
};

#endif
