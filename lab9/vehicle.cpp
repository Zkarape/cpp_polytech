#include "vehicle.h"

Vehicle::Vehicle(Engine eng, std::string cmp, std::string model, int price, int weight, int maxV, int yr)
    : _engine(eng),
      _company(cmp),
      _model(model),
      _price(price),
      _weight(weight),
      _maxV(maxV),
      _year(yr)
{}

std::string Vehicle::printVehicle()
{
    std::ostringstream ostr;

    ostr << "Vehicle model is " << _model << std::endl;
    ostr << "Vehicle company is " << _company << std::endl;
    ostr << "Vehicle production year is " << _year << std::endl;
    ostr << "Vehicle price is " << _price << std::endl;
    ostr << "Vehicle weight is " << _weight << std::endl;
    ostr << "Vehicle maximal velocity is " << _maxV << std::endl;
    return (ostr.str());
}

void	Vehicle::set_engine(Engine e)
{
    _engine = e;
}

void	Vehicle::set_cmp(std::string c)
{
    _company = c;
}

void	Vehicle::set_model(std::string m)
{
    _model = m;
}

void    Vehicle::set_price(int p)
{
    _price = p;
}

void    Vehicle::set_weight(int w)
{
    _weight = w;
}

void    Vehicle::set_maxv(int v)
{
    _maxV = v;
}

void    Vehicle::set_year(int y)
{
    _year = y;
}

Engine  Vehicle::get_engine()
{
    return (_engine);
}

std::string  Vehicle::get_comp()
{
    return (_company);
}

std::string  Vehicle::get_model()
{
    return (_model);
}

int Vehicle::get_price()
{
    return (_price);
}

int Vehicle::get_weight()
{
    return (_weight);
}

int Vehicle::get_maxv()
{
    return (_maxV);
}

int Vehicle::get_year()
{
    return (_year);
}

Vehicle::~Vehicle()
{
    std::cout << printVehicle();
}