#ifndef DATA_H
#define DATA_H

#include <iostream>
using namespace std;

class Data {
private:
    int day;
    int month;
    int year;

public:
    Data(int d, int m, int y) : day(d), month(m), year(y) {}
    Data(const Data& other) : day(other.day), month(other.month), year(other.year) {}

    void print() const {
        cout << day << "/" << month << "/" << year;
    }
};
