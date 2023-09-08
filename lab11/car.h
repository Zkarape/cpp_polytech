#ifndef CAR_H
# define CAR_H

#include "vehicle.h"

class Car : public Vehicle
{
    public:
        Car(Engine eng, std::string cmp, std::string model, int price, int weight, int maxV, int yr, int n);
        ~Car();
        std::string	printCar();
        void    draw();
        void    start() override;
        void	accelerate(double tillVelocity) override;
		void	stop() override;
        void    set_num(int);
        int     get_num();
    private:
        int _nmbOfSeats;
		friend std::ostream& operator<<(std::ostream&, Car&);
		friend std::istream& operator>>(std::istream&, Car&);
};

#endif