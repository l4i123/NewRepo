// home.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;/*
int chancheValue(int x)
{
	x = 20; // This will not change the original value of x in main
	return x;
}

int main()
{
	int x = 10;//
	int* ptr = &x;
	std::cout << "Value of x: " << x << std::endl;
	std::cout << "Address of x: " << &x << std::endl;
	std::cout << "Value of ptr: " << ptr << std::endl;
	std::cout << "Value pointed to by ptr: " << *ptr << std::endl;
	std::cout << "Address of ptr: " << &ptr << std::endl;
	x = 0;
	std::cout << "Value of x after modification: " << x << std::endl;
	std::cout << "Value pointed to by ptr after modification: " << *ptr << std::endl;
	std::cout << "Value returned by chancheValue: " << chancheValue(x) << std::endl;
	std::cout << "Value of x after chancheValue: " << x << std::endl; // x remains unchanged

	
}
*/
void changeValue(int* ptr1) {
	*ptr1 = 10;  // Промени стойността, към която сочи ptr
}
void changeValue2(int ptr2) {
	ptr2 = 10;  // Промени стойността, към която сочи ptr
}

int main() {
	int a = 5;
	changeValue(&a);  // Подаваме адреса на a
	cout << a << endl;  // Ще отпечата 10
	a = 5;
	changeValue2(a);  // Подаваме стойността на a
	cout << a << endl;  // Ще отпечата 10, защото changeValue2 не променя оригиналната стойност на a
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
