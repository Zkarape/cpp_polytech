#ifndef ENGINE_H
# define ENGINE_H

#include <iostream>

class Engine
{
	public:
		enum type
		{
			DIESEL,
			PETROL,
			GAS,
			ELECTRIC,
		};
		Engine(std::string model, int year, int power, type t);
		~Engine();
		void	printInfo();
	private:
		std::string _engModel;
		int			_prodYear;
		int			_horsepower;
		type		_type;
};

#endif