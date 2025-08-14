#include <iostream>
class Reader{
private:
    string name;
    string id;
public:
    Reader(string n, string id) : name(n), id(id){}

     // Функция за извеждане на информация за читателя (опционално)
    void displayReaderInfo() const {
        cout << "Reader Name: " << name << ", Number: " << number << endl;
    }
};


