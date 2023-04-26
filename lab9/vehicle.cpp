#include "vehicle.h"

Vehicle::Vehicle(Engine eng, std::string name, std::string cmp, std::string model, int price, int weight, int maxV, int yr)
    : _engine(eng),
      _name(name),
      _company(cmp),
      _model(model),
      _price(price),
      _weight(weight),
      _maxV(maxV),
      _year(yr)
{
}

void Vehicle::printinf()
{
    std::cout << "Vehicle name is " << _name << std::endl;
    std::cout << "Vehicle model is " << _model << std::endl;
    std::cout << "Vehicle company is " << _company << std::endl;
    std::cout << "Vehicle production year is " << _year << std::endl;
    std::cout << "Vehicle price is " << _price << std::endl;
    std::cout << "Vehicle weight is " << _weight << std::endl;
    std::cout << "Vehicle maximal velocity is " << _maxV << std::endl;
}

Vehicle::~Vehicle()
{
    printinf();
}