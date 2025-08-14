#include <iostream>
#include "Car.h"
#include "Truck.h"
int main(){
    int t;
    Car c1(6, 55), c2(2, 120);
    Truck t1(10000, 55), t2(20000, 72);

    cout << "Comparing c1 and t1:\n";
    t = c1.sp_greater(t1); // Извиква се като член-функция на car
    if (t < 0)
        cout << "Truck is faster.\n";
    else if (t == 0)
        cout << "Car and truck speed is the same.\n";
    else
        cout << "Car is faster.\n";

    cout << "\nComparing c2 and t2:\n";
    t = c2.sp_greater(t2); // Извиква се като член-функция на car
    if (t < 0)
        cout << "Truck is faster.\n";
    else if (t == 0)
        cout << "Car and truck speed is the same.\n";
    else
        cout << "Car is faster.\n";

    // Изчисляване на време за изминаване на разстояние
    double distance = 100.0; // Разстояние в километри

    try {
        cout << "\nTravel time for c1 over " << distance << " km: " << travel_time(c1, distance) << " hours\n";
        cout << "Travel time for t1 over " << distance << " km: " << travel_time(t1, distance) << " hours\n";
    } catch (const invalid_argument& e) {
        cerr << e.what() << endl;
    }

    return 0;
}
