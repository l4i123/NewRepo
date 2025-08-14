#include <iostream>
using namespace std;
/*/Задача 1: Да се дефинира клас за описание на правоъгълник (по аналог на
класа triangle) с две член-функции face(), която се отличава по наличието
на аргумент и по действие – освен лицето, тя връща и периметъра на
правоъгълника.*/
class Rectangle{
private:
    double width;
    double length;
public:
    Rectangle():width(0),length(0) {} // default constructor
    Rectangle(double w, double l) : width(w), length(l) {}

    void setDimensions(double w, double l){
        width = w;
        length = l;
    }
     // Функция за изчисляване на лицето
    double area() const {
        return width * length;
    }

    // Функция за изчисляване на периметъра
    double perimeter() const {
        return 2 * (width + length);
    }
     // Модифицирана функция face(), която връща и лицето, и периметъра
    void face(double& areaOut, double& perimeterOut) const {
        areaOut = area();
        perimeterOut = perimeter();
    }
    // Функция за извеждане на информация за правоъгълника
    void display() const {
        cout << "Width: " << width << ", Height: " << length << endl;
        cout << "Area: " << area() << ", Perimeter: " << perimeter() << endl;
    }


};
