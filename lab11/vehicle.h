#ifndef VEHICLE_H
# define VEHICLE_H

#include "engine.h"

class Engine;

class Vehicle
{
	public:
		Vehicle(Engine eng, std::string cmp, std::string model, int price, int weight, float maxV, int yr);
		std::string	printVehicle();
		virtual	~Vehicle();
		virtual void	draw();
		virtual float   getCurrentLoad();//experiment//need to be overrided
		void	run(double tillVelocity);
		void	set_engine(Engine);
		void	set_cmp(std::string);
		void	set_model(std::string);
		void	set_price(int);
		void	set_weight(int);
		void	set_year(int);
		Engine	get_engine();
		std::string     get_comp();
		std::string     get_model();
        int     get_price();
        int     get_weight();
        int     get_maxv();
        int     get_year();
	private:
		Engine		_engine;
		std::string _company;
		std::string _model;
		int			_price;
		int			_weight;
		int			_year;
		float		_velocity;
		float		_maxVelocity;
		bool		_isRunning;
		friend std::ostream& operator<<(std::ostream&, Vehicle&);
		friend std::istream& operator>>(std::istream&, Vehicle&);
	private:
		virtual void	start() = 0;
		virtual void	accelerate(double tillVelocity) = 0;
		virtual void	stop() = 0;
	protected:
		void	setVelocity(float velo);
		void	setMaxVelocity(float maxV);
		void	setIsRunning(bool run);
		float	getVelocity();
		float	getMaxVelocity();
		bool	getIsRunning();
};

#endif