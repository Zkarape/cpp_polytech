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
		Polynom(const std::array<int, size>& degree, const std::array<double, size>& coeff, char& x)
		{	
			_degree = degree;
			_coeff = coeff;
			_x = x;
			_count++;
		};
		void	printPolynom();
		const	std::array<int, size>	get();
		const	std::array<double, size>	getd();
		void	set(const std::array<int, size> degree, const std::array<double, size> coeff, char x);
};

void	Polynom::set(const std::array<int, size> degree, const std::array<double, size> coeff, char x)
{
	_degree = degree;
	_coeff = coeff;
	_x = x;
}

const	std::array<int, size>	Polynom::get()
{
	return (_degree);
}

const std::array<double, size>	Polynom::getd()
{
	return (_coeff);
}

void	Polynom::printPolynom()
{
	int i;

	i = 0;
	std::cout << _coeff[i] << _x << '^' << _degree[i];
	while (++i < 5)
		std::cout << '+' << _coeff[i] << _x << '^' << _degree[i];
	std::cout << std::endl;
}
int Polynom::_count = 0;
int main()
{
	Polynom P;
	std::array<int, size>arr{1, 2, 3, 4, 5};
	std::array<double, size>arrd{1.1, 2.2, 3.4, 4.5, 5.6};
	P.set(arr, arrd, 'x');
	P.get();
	P.getd();
	P.printPolynom();
}
