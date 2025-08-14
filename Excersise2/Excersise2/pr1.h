#include <iostream>
using namespace std;
class pr2;
class pr1{
    int printing;
public:
    pr1(){
        printing = 0;
    }
    void set_print(int staus){
    printing = staus;
    }
    friend bool inuse(const  pr1& obj1, const pr2& obj2);

};
