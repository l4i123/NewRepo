#include <iostream>
class Line{
private :
    int len;
public:
    Line(int lenght): len(lenght){
    drawLine(); //конструктора чертае линията
    }
    void drawLine(){
        for(int i = 0; i< len; i++){
            std::cout<<"*";
        }
        std::cout<<std::endl;
    }
    ~Line(){
    clearLine();
    }

    void clearLine(){
        std::cout<<"Line of len"<<len<<"is deleted"<<std::endl;
    }
};
