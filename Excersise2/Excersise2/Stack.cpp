#include <iostream>
using namespace std;
#include "Stack.h"
int main(){
    Stack s;

    cout << "Loading stack with lowercase letters:\n";
    s.loadstack(0);
    s.display();

    cout << "Loading stack with uppercase letters:\n";
    s.loadstack(1);
    s.display();

    return 0;


}
