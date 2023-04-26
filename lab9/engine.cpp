#include "engine.h"

Engine::Engine(std::string model, int year, int power, type t)
    : _type(t),
      _engModel(model),
      _horsepower(power),
      _prodYear(year)
{
}

void Engine::printInfo()
{
    std::cout << "Engine type is " << _type << std::endl;
    std::cout << "Engine model is " << _engModel << std::endl;
    std::cout << "Engine power is " << _horsepower << std::endl;
    std::cout << "Engine production year is " << _prodYear << std::endl;
}

Engine::~Engine()
{
    printInfo();
}