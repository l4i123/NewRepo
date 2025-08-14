#include <iostream>
#include "Rectangle.h"
using namespace std;
int main() {
    // Създаване на обект от клас Rectangle
    Rectangle rect(5.0, 3.0);

    // Извеждане на информация за правоъгълника
    rect.display();

    // Използване на функцията face()
    double area, perimeter;
    rect.face(area, perimeter);
    cout << "Using face() - Area: " << area << ", Perimeter: " << perimeter << endl;

    return 0;
}
