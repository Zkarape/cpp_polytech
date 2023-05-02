#ifndef TRUCK_H
# define TRUCK_H

#include "vehicle.h"

class Truck : public Vehicle
{
    public:
        Truck(Engine eng, std::string cmp, std::string model, int price, int weight, int maxV, int yr, int cap);
        ~Truck();
        std::string	printTruck();
        void    set_cap(int cap);
        int     get_cap();
    private:
        int _capacity;
        friend std::ostream& operator<<(std::ostream&, const Truck&);
		friend std::istream& operator>>(std::istream&, Truck&);
};

#endif