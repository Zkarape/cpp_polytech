#include "truck.h"

Truck::Truck(Engine eng, std::string cmp, std::string model, int price, int weight, int maxV, int yr, int cap, float currentLoad)
    : Vehicle(eng, cmp, model, price, weight, maxV, yr), _capacity(cap), _currentLoad(currentLoad) {}

std::string Truck::printTruck()
{
    std::ostringstream ostr;

    ostr << Vehicle::printVehicle();
    ostr << "Capacity of truck is " << _capacity << std::endl;
    return (ostr.str());
}

void    Truck::draw()
{
    Vehicle::draw();
    std::cout << "Capacity of truck " << _capacity << std::endl;
}

void    Truck::set_cap(int cap)
{
    _capacity = cap;
}

void    Truck::setCurrentLoad(float curload)
{
    _currentLoad = curload;
}

void    Truck::start()
{
    std::cout << "I am start() override in Truck derived class\n";
}

void    Truck::stop()
{
    std::cout << "I am stop() override in Truck derived class\n";
    this->setVelocity(0);
}

void    Truck::accelerate(double tillVelocity)
{
    std::cout << "I am accelerate() override in Truck derived class\n";
    this->setVelocity(tillVelocity);
}

int Truck::get_cap()
{
    return (_capacity);
}

float Truck::getCurrentLoad()
{
    return (_currentLoad);
}

Truck::~Truck()
{
    std::cout << "~Truck() is called" << std::endl;
}

std::ostream& operator<<(std::ostream& o, Truck& T)
{
    o << T.printTruck();
    return (o);
}

std::istream& operator>>(std::istream& is, Truck& T)
{
    is >> static_cast<Vehicle&>(T);
    int capacity;
    is >> capacity;
    // Engine engine;
    // is >> engine;
    // std::string company, model;
    // int price, weight, maxV, year, capacity;
    // is >> company >> model >> price >> weight >> maxV >> year >> capacity;
    // T = Truck(engine, company, model, price, weight, maxV, year, capacity);
    return (is);
}