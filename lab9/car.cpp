#include "car.h"

Car::Car(Engine eng, std::string name, std::string cmp, std::string model, int price, int weight, int maxV, int yr, int n)
    : Vehicle(eng, name, cmp, model, price, weight, maxV, yr), _nmbOfSeats(n)
{
}

void Car::print()
{
    Vehicle.printinf();
    std::cout << "Number of seats in car " << _nmbOfSeats << std::endl;
}