#ifndef VEHICLE_H
# define VEHICLE_H

#include <iostream>
#include "engine.h"

class Engine;

class Vehicle
{
	public:
		Vehicle(Engine eng, std::string name, std::string cmp, std::string model, int price, int weight, int maxV, int yr);
		~Vehicle();
		void	printinf();
	private:
		Engine		_engine;
		std::string _name;
		std::string _company;
		std::string _model;
		int			_price;
		int			_weight;
		int			_maxV;
		int			_year;
};

#endif