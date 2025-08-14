#include <iostream>
#include "Worker.h"
int main(){

    Worker worker1;  // Въвеждане на длъжност от клавиатурата

    worker1.setId("123-45-6789");
    worker1.setWorking_years(5);
    worker1.addSalary(1500);
    worker1.addSalary(1800);
    worker1.addSalary(1700);

    worker1.showDetailsWorker();

    Worker worker2("Manager");
    worker2.setName("Robert de NIro");
    worker2.setId("987-65-4321");
    worker2.setWorking_years(10);
    worker2.addSalary(2000);
    worker2.addSalary(2200);

    worker2.showDetailsWorker();

    return 0;
}
