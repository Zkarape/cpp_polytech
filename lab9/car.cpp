#include "car.h"

Car::Car(Engine eng, std::string cmp, std::string model, int price, int weight, int maxV, int yr, int n)
    : Vehicle(eng, cmp, model, price, weight, maxV, yr), _nmbOfSeats(n) {}

std::string Car::printCar()
{
    std::ostringstream ostr;

    ostr << Vehicle::printVehicle();
    ostr << "Number of seats in car " << _nmbOfSeats << std::endl;
    return (ostr.str());
}

std::ostream& operator<<(std::ostream& o, Car& c)
{
    o << c.printCar();
    return (o);
}

std::istream& operator>>(std::istream& is, Car& c)
{
    Engine engine;
    is >> engine;
    std::string company, model;
    int price, weight, maxV, year, num;
    is >> company >> model >> price >> weight >> maxV >> year >> num;
    c = Car(engine, company, model, price, weight, maxV, year, num);
    return (is);
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
  //  std::cout << printCar();
}