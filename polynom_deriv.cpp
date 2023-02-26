#include <iostream>
#include <array>

const size_t	size = 5;

class 	Polynom
{
	private:
		std::array<double, size> _coeff;
		std::array<int, size> _degree;
		char _x;
		static int _count;
	public:
		Polynom()
		{
			_coeff.fill(0);
			_degree.fill(0);
			_count++;
		};
		Polynom(const std::array<double, size>& coeff)
		{
			_degree.fill(1);
			_coeff = coeff;
			_count++;
		};
		Polynom(const std::array<int, size>& degree)
		{
			_coeff.fill(1);
			_degree = degree;
			_count++;
		};
		Polynom(std::array<int, size>& degree, std::array<double, size>& coeff,const char& x)
		{	
			_degree = degree;
			_coeff = coeff;
			_x = x;
			_count++;
		};
		void	printPolynom() const;
		const	std::array<int, size>&		getdegree() const;
		const	std::array<double, size>&	getcoeff() const;
		void	set(const std::array<int, size> degree, const std::array<double, size> coeff,const char x);
};

void	Polynom::set(const std::array<int, size> degree, const std::array<double, size> coeff, const char x)
{
	_degree = degree;
	_coeff = coeff;
	_x = x;
}

const	std::array<int, size>&	Polynom::getdegree() const//const, & is for not copying and sending, but sending the reference
{
	return (_degree);
}

const	std::array<double, size>&	Polynom::getcoeff() const
{
	return (_coeff);
}

void	Polynom::printPolynom() const
{
	int i;

	i = 0;
	std::cout << _coeff[i] << _x << '^' << _degree[i];
	while (++i < 5)
		std::cout << '+' << _coeff[i] << _x << '^' << _degree[i];
	std::cout << std::endl;
}

Polynom calc_derivative(int order, const Polynom &P)
{
	std::array<double, size>	dcoeff = P.getcoeff();
	std::array<int, size>		ddegree = P.getdegree();
	int				i;
	int				j;

	i = -1;
	j = -1;
	while (++j < order)
	{
		while (++i < size)
		{
			dcoeff[i] = dcoeff[i] * ddegree[i];
			ddegree[i] =  ddegree[i] - 1;
		}
	}
	Polynom deriv(ddegree, dcoeff, 'x');
	return (deriv);
}

#include <cmath>

int	calc_res_of_deriv(Polynom P, int x)
{
	const std::array<double, size>&		dcoeff = P.getcoeff();
	const std::array<int, size>&		ddegree = P.getdegree();
	int					res;
	int					i;

	res = 0;
	i = -1;
	while (++i < size)
		res = res + dcoeff[i] * pow(x, ddegree[i]);
	return (res);
}

int Polynom::_count = 0;

int main()
{
	Polynom P;
	Polynom D;
	std::array<int, size>arr{1, 2, 3, 4, 5};
	std::array<double, size>arrd{1, 2, 3, 4, 5};
	P.set(arr, arrd, 'x');
	P.getdegree();
	P.getcoeff();
	std::cout << "Polynom is" << std::endl;
	P.printPolynom();
	D = calc_derivative(1, P);
	D.printPolynom();
	std::cout << "Res is\n" << calc_res_of_deriv(D, 1) << std::endl;
}
