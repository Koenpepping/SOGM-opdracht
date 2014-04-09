#include <iostream>

using namespace std;

//Sogm opdracht:	pointers 2
//door:						Koen Pepping

int main()
{
	int x = 30;
	int * p;

	p = &x;
	cout << "x is nu: " << x << endl;
	cout << "Adres van x is: " << p << endl;
	*p = (30 + 10);
	cout << "De waarde van x + 10 is: " << x << endl;
}
