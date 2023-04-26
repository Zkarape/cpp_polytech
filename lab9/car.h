#ifndef CAR_H
# define CAR_H

#include "vehicle.h"

class Car : public Vehicle
{
    public:
        Car(Engine eng, std::string name, std::string cmp, std::string model, int price, int weight, int maxV, int yr, int n);
        ~Car();
        void	print();
    private:
        int _nmbOfSeats;
};

#endif