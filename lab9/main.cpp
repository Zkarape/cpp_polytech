#include "engine.h"
#include "vehicle.h"
#include "truck.h"
#include "car.h"

int main()
{
    Engine E("Prado", 2020, 335, Engine::GAS);
    Vehicle V(E, "Toyota", "Prado", 50000, 50, 200, 2020);
    Car C(E, "Toyota", "Prado", 50000, 50, 200, 2020, 7);
    Truck T(E, "Toyota", "Prado", 50000, 50, 200, 2020, 7);
    std::cout << E << std::endl;
    return (0);
}