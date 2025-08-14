#include <iostream>
using namespace std;
class Truck{
    int weight;
    int speed;
public:
    Truck ( int w, int  s) : weight(w), speed(s){}

    friend int Car::sp_greater(Truck t);
    friend double travel_time( Truck t, double distance);
};
int Car::sp_greater(Truck t) { // ako V na car e po golqma +
    return speed - t.speed;
}
/* Функция за изчисляване на времето за изминаване на разстояние от кола */
double travel_time(Car c, double distance) {
    if (c.speed <= 0) {
        throw invalid_argument("Speed must be greater than zero.");
    }
    return distance / c.speed;
}
/* Функция за изчисляване на времето за изминаване на разстояние от камион */
double travel_time(Truck t, double distance) {
    if (t.speed <= 0) {
        throw invalid_argument("Speed must be greater than zero.");
    }
    return distance / t.speed;
}
