#include "engine.h"

Engine::Engine(std::string model, int year, int power, type t)
    : _type(t),
      _engModel(model),
      _horsepower(power),
      _prodYear(year)
{}

std::string Engine::printEngine()
{
    std::ostringstream ostr;
    
    ostr << "Engine type is " << _type << std::endl;
    ostr << "Engine model is " << _engModel << std::endl;
    ostr << "Engine power is " << _horsepower << std::endl;
    ostr << "Engine production year is " << _prodYear << std::endl;
    return (ostr.str());
}

std::ostream& operator<<(std::ostream& o, Engine& E)
{
    o << E.printEngine() << std::endl;
    return (o);
}

Engine::~Engine()
{
    std::cout << printEngine();
}

void    Engine::set_model(std::string m)
{
    _engModel = m;
}

void    Engine::set_year(int y)
{
    _prodYear = y;
}

void    Engine::set_power(int p)
{
    _horsepower = p;
}

void    Engine::set_type(type t)
{
    _type = t;
}

std::string     Engine::get_model()
{
    return (_engModel);
}

int Engine::get_year()
{
    return (_prodYear);
}

int Engine::get_power()
{
    return (_horsepower);
}

int Engine::get_type()
{
    return (_type);
}