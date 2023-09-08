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

void    Car::draw()
{
    Vehicle::draw();
    std::cout << "Number of seats in car " << _nmbOfSeats << std::endl;
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
    c = Car(engine, company, model, price, weight, maxV, year, num);//when pure virtual is not redefined it is not allowed to call
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

void    Car::start()
{
    std::cout << "I am start() override in Car (derived) class\n";
}

void    Car::stop()
{
    std::cout << "I am stop() override in Car (derived) class\n";
    this->setVelocity(0);
}

void    Car::accelerate(double tillVelocity)
{
    std::cout << "I am accelerate() override in Car (derived) class\n";
    this->setVelocity(tillVelocity);
}

Car::~Car()
{
    std::cout << "~Car() is called" << std::endl;
  //  std::cout << printCar();
}