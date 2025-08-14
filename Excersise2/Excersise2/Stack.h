#include <iostream>
#include <stack>
using namespace std;
class Stack{
    stack<char> st;// стек от char
public:
    void loadstack(int upper){
        while(!st.empty()){
            st.pop();
        }
        if(upper == 1){
            for(char i = 'A'; i<='Z'; i++){
                st.push(i);
            }
        }else{
            for(char j = 'a'; j<= 'z'; j++){
                st.push(j);
            }
        }
    }
    void display(){
        stack<char> temp = st; //Копие на стека, за да не се губят елементи

        while(!temp.empty()){
            cout<<temp.top()<<" ";
            temp.pop();
        }
        cout<<endl;
    }
};
/*#include <iostream>
#include <stack>
using namespace std;

// Базов клас
class BaseStack {
protected:
    stack<char> st; // Стек от символи
public:
    virtual void loadstack(int upper) = 0; // Чист виртуален метод
    virtual void display() const = 0;     // Чист виртуален метод
};

// Наследен клас
class Stack : public BaseStack {
public:
    void loadstack(int upper) override {
        while (!st.empty()) {
            st.pop();
        }
        if (upper == 1) {
            for (char i = 'A'; i <= 'Z'; i++) {
                st.push(i);
            }
        } else {
            for (char j = 'a'; j <= 'z'; j++) {
                st.push(j);
            }
        }
    }

    void display() const override {
        stack<char> temp = st; // Копие на стека
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    BaseStack* stack = new Stack(); // Полиморфизъм
    stack->loadstack(0); // Малки букви
    cout << "Lowercase stack: ";
    stack->display();

    stack->loadstack(1); // Главни букви
    cout << "Uppercase stack: ";
    stack->display();

    delete stack;
    return 0;
}*/
