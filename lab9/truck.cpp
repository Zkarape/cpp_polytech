#include "truck.h"

Truck::Truck(Engine eng, std::string cmp, std::string model, int price, int weight, int maxV, int yr, int cap)
    : Vehicle(eng, cmp, model, price, weight, maxV, yr), _capacity(cap) {}

std::string Truck::printTruck()
{
    std::ostringstream ostr;

    ostr << Vehicle::printVehicle();
    ostr << "Capacity of truck is " << _capacity << std::endl;
    return (ostr.str());
}

void    Truck::set_cap(int cap)
{
    _capacity = cap;
}

int Truck::get_cap()
{
    return (_capacity);
}

Truck::~Truck()
{
  //  std::cout << printTruck();
}

std::ostream& operator<<(std::ostream& o, Truck& T)
{
    o << T.printTruck();
    return (o);
}

std::istream& operator>>(std::istream& is, Truck& T)
{
    Engine engine;
    is >> engine;
    std::string company, model;
    int price, weight, maxV, year, capacity;
    is >> company >> model >> price >> weight >> maxV >> year >> capacity;
    T = Truck(engine, company, model, price, weight, maxV, year, capacity);
    return (is);
}