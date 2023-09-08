#include "engine.h"
#include "vehicle.h"
#include "truck.h"
#include "car.h"
#include <typeinfo>

bool compare(Car* a, Car* b) {
    return (a->get_engine().get_power() > b->get_engine().get_power());
}

void    sortInt(Car* C[3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            if (compare(C[j], C[i]))
                std::swap(C[j], C[i]);
        }   
    }
}

int main()
{
    // Engine E("Prado", 2020, 300, Engine::GAS);
    //Vehicle V(E, "Toyota", "Prado", 50000, 50, 200, 2020);
   // Car C(E, "Toyota", "Prado", 50000, 50, 200, 2020, 7);
    // Truck T(E, "Toyota", "Prado", 50000, 50, 200, 2020, 700, 10520);
   // std::cin >> E;
    //std::cout << E << std::endl;
    Engine E1("Prado", 2020, 300, Engine::GAS);
    Engine E2("Prado", 2020, 335, Engine::GAS);
    Engine E3("Prado", 2020, 400, Engine::GAS);
    // Car C1(E1, "Toyota", "Prado1", 50000, 50, 200, 2021, 7);
    // Car C2(E2, "Toyota", "Prado2", 50000, 50, 200, 2022, 2);
    // Car C3(E3, "Toyota", "Prado3", 50000, 50, 200, 2023, 6);
    // Car *C[3];
    // C[0] = &C1;
    // C[1] = &C2;
    // C[2] = &C3;
    // sortInt(C);
    //std::cout << E1 << std::endl << E2 << std::endl << E3 << std::endl;
    // for (int i = 0; i < 3; i++)
    // {
    //     if ((*C[i]).get_num() <= 5)//C[i]->get_num()
    //         std::cout << *C[i] << std::endl;
    // }
    //std::cout << C1 << std::endl << C2 << std::endl << C3 << std::endl;
    //lab_10
    // Vehicle *array[3];
    // array[0] = &C1;
    // array[1] = &C2;
    // array[2] = &T;
    // for (int i = 0; i < 3; i++)
    // {
    //     array[i]->draw();
    //     std::cout << std::endl;
    // }
    //
    //lab11
    Engine engArr[3];
    engArr[0] = E1;
    engArr[1] = E2;
    engArr[2] = E3;
    Vehicle *arr[3];
    for (int i = 0; i < 3; i++)
    {
        if (i % 2 == 0)
        {
            arr[i] = new Car(engArr[i], "Toyota", "Prado", 50000, 50, 200, 2020 + i, 5 + i);
            arr[i]->run(100);
        }
        else
        {
            arr[i] = new Truck(engArr[i], "Toyota", "Prado", 50000, 50, 200, 2020 + i, 700, 9999 + i);
            if (arr[i]->getCurrentLoad() >= 10000)
                std::cout << "Track's current load is >= 10000" << std::endl;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        std::cout << typeid(*arr[i]).name() << std::endl;
        delete arr[i];//how to combine delete with destructor
    }
    return (0);
}