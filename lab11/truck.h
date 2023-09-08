#ifndef TRUCK_H
# define TRUCK_H

#include "vehicle.h"

class Truck : public Vehicle
{
    public:
        Truck(Engine eng, std::string cmp, std::string model, int price, int weight, int maxV, int yr, int cap, float currentLoad);
        ~Truck();
        std::string	printTruck();
        void    draw();
        void    start() override;
        void	accelerate(double tillVelocity) override;
		void	stop() override;
        void    set_cap(int cap);
        void    setCurrentLoad(float curLoad);
        float   getCurrentLoad();
        int     get_cap();
    private:
        int _capacity;
        float   _currentLoad;
        friend std::ostream& operator<<(std::ostream&, Truck&);
		friend std::istream& operator>>(std::istream&, Truck&);
};

#endif