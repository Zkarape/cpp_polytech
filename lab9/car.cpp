#include "car.h"

Car((*ctor)(Engine eng, std::string cmp, std::string model, int price, int weight, int maxV, int yr), int n)
    :  _nmbOfSeats(n) {}

std::string Car::printCar()
{
    std::ostringstream ostr;

    ostr << Vehicle::printVehicle();
    ostr << "Number of seats in car " << _nmbOfSeats << std::endl;
    return (ostr.str());
}

void    Car::set_num(int n)
{
    _nmbOfSeats = n;
}

int Car::get_num()
{
    return (_nmbOfSeats);
}

Car::~Car()
{
    std::cout << printCar();
}