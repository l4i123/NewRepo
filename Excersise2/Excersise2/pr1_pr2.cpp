#include <iostream>
using namespace std;
#include "pr1.h"
#include "pr2.h"
int main(){
    pr1 printing1;
    pr2 printing2;

    printing1.set_print(1);
    printing1.set_print(0);

     if (inuse(printing1, printing2)) {
        cout << "Printer in use." << endl;
    } else {
        cout << "printer is not being used." << endl;
    }


}
