#ifndef CAR_H
# define CAR_H

#include "vehicle.h"

class Car : public Vehicle
{
    public:
        Car(void (*ctor)(Engine eng, std::string cmp, std::string model, int price, int weight, int maxV, int yr), int n);
        ~Car();
        std::string	printCar();
        void    set_num(int);
        int     get_num();
    private:
        int _nmbOfSeats;
		friend std::ostream& operator<<(std::ostream&, const Car&);
		friend std::istream& operator>>(std::istream&, Car&);
};
// class Car : public Vehicle
// {
//     public:
//         Car(Engine eng, std::string cmp, std::string model, int price, int weight, int maxV, int yr, int n);
//         ~Car();
//         std::string	printCar();
//         void    set_num(int);
//         int     get_num();
//     private:
//         int _nmbOfSeats;
// 		friend std::ostream& operator<<(std::ostream&, const Car&);
// 		friend std::istream& operator>>(std::istream&, Car&);
// };

#endif