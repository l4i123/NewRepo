#include <iostream>
using namespace std;
class Truck;

class Car{
    int passengers;
    int speed;
public:
    Car(int p, int s):passengers(p), speed(s){}

    int sp_greater(Truck t);
    friend double travel_time(Car c, double distance);
};
/*Задача 2: Разширете функционалността на задачи 2 и 3, като имплементирате
друга приятелска функция, която да изчислява времето за изминаване на
зададени километри (S = V * T)*/
