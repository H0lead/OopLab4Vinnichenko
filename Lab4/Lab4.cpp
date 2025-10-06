#include <iostream>
#include "money.h"
#include <string>
using namespace std;

int main()
{
	money a, b, c;
	a = a.init(100, 6);
	cout << "a = ";
	a.display();
	b.read();
	cout << "b = ";
	b.display();
	cout << endl;
	string test = "";
	test = a.tostring();
	cout << "To string a test: " << test << endl;
	a = a.add(100, 45);
	cout << "a after add = ";
	a.display();
	a = a.sub(42, 90);
	cout << "a after sub = ";
	a.display();
	a = a.divide(6);
	cout << "a after divide = ";
	a.display();
	a = a.dividefloat(2.4);
	cout << "a after float divide = ";
	a.display();
	a = a.multiplyfloat(4.7);
	cout << "a after multiply float = ";
	a.display();
	cout << endl;
	cout << "c = ";
	c.display();
	money d(51, 37);
	cout << "D = ";
	d.display();
	money e(31);
	cout << "e = ";
	e.display();
	cout << endl;
	a.compare(b);
	a.compare(c);
	a.compare(d);
	a.compare(e);
	cout << endl;
	money f;
	f = a + b;
	cout << "a + b = ";
	f.display();
	cout << "b - a = ";
	f = b - a;
	f.display();
	if (a > b)
	{
		cout << "a > b";
	}
	else if(a < b)
	{
		cout << "a < b";
	}
	else 
	{
		cout << "a == b";
	}
}