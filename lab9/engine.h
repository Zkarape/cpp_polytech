#ifndef ENGINE_H
# define ENGINE_H

#include <iostream>
#include <sstream>

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
		Engine();
		Engine(std::string model, int year, int power, type t);
		~Engine();
		std::string	printEngine();
		void    set_model(std::string);
		void    set_year(int);
		void    set_power(int);
		void    set_type(type);
        std::string     get_model();
        int     get_year();
        int     get_power();
    	int     get_type();
	private:
		std::string _engModel;
		int			_prodYear;
		int			_horsepower;
		type		_type;
		friend std::ostream& operator<<(std::ostream&, const Engine&);
		friend std::istream& operator>>(std::istream&, Engine&);
};

#endif