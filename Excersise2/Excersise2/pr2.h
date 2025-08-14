#include <iostream>
using namespace std;
class pr1;
class pr2{
    int printing;
public:
    pr2(){
        int printing = 0;
    }
    void set_print(int status){
    printing = status;
    }
    friend bool inuse(const pr1& obj1, const pr2& obj2);
};
bool inuse(const pr1& obj1, const pr2& obj2){
    return obj1.printing!=0 || obj2.printing!=0;
}
