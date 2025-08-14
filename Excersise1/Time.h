
#include <iostream>
#include <string>
class Time{
private:
    unsigned int hours, minutes, seconds;
public:
    Time();
    void timeShow();
};
Time::Time(){
    do{
        std::cout<<"Enter hours: ";
        std::cin>>hours;
        std::cout<<"\nEnter minutes: ";
        std::cin>>minutes;
        std::cout<<"\nEnter seconds: ";
        std::cin>>seconds;
    }while(!(hours>=0 && hours<=23 && minutes >= 0 && minutes<=59 && seconds >=0 && seconds<=59));
}
void Time::timeShow(){
    std::cout<<"\n"<<hours<<":"<<minutes<<":"<<seconds;
    if(hours>11){
    std::cout<<"\n"<<hours<<":"<<minutes<<":"<<seconds<<"PM";
    }else{
    std::cout<<"\n"<<hours<<":"<<minutes<<":"<<seconds<<"AM";
    }
}
