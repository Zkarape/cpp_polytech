#include "pont.hpp"

class Circle
{
	private:
		double	_r;
		Point	_P;
	public:
		void	setRadius(double);
		double	getRadius() const;
		Point	getPoint();
		static 
		std::string info();
		Circle(double r, Point &P);
		~Circle();
};
