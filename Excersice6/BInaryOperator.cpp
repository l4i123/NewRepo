#include<iostream>
using namespace std;
class coord {
int x, y; //кординатни стойности
public:
coord() {x=0; y=0;}
coord(int i, int j) { x=i; y=j; }
void get_xy(int &i, int &j) { i=x; j=y; }
coord operator+(coord ob2);
coord operator-(coord ob2);
coord operator=(coord ob2);
};
coord coord::operator+(coord ob2) //Предефинира + за класа coord.
{
coord temp;
temp.x = x+ob2.x;// "x" тук е x на текущия обект, т.е. на "this" (o1)
temp.y = y+ob2.y;// "y" тук е y на текущия обект, т.е. на "this" (o1)
return temp;
}
coord coord::operator-(coord ob2) //Предефинира – за класа coord.
{
coord temp;
temp.x = x-ob2.x;
temp.y = y-ob2.y;
return temp;
}
coord coord::operator=(coord ob2) //Предефинира = за класа coord.

2

{
x = ob2.x;
y = ob2.y;
return *this;
}
int main()
{ coord o1(10,10), o2(5,3), o3;
int x, y;
o3 = o1 + o2; //добавя два обекта – извиква се operator+()
o3.get_xy(x, y);
cout << "(o1+o2) X:" << x << ", Y " << y << '\n';
o3 = o1 - o2; //изважда два обекта – извиква се operator-()
o3.get_xy(x, y);
cout << "(o1-o2) X:" << x << ", Y:" << y << '\n';
o3 = o1; //присвоява обект - извиква се operator=()
o3.get_xy(x, y);
cout << "(o3=o1) X:" << x << ", Y:" << y << '\n';
return 0;
}
/*Резултати:
(o1+o2) x:15, y:13
(o1-o2) x:5, y:7
(o3=o1) x:10, y:10
*/
