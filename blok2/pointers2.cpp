#include <iostream>

using namespace std;

//Sogm opdracht:	pointers 2
//door:						Koen Pepping

	int x = 30;
	int * p;
	const	int VIER = 4;
	int d[VIER] = {10, 20, 30, 40};
	int zoek( int * t, int lengte); // eerste argument (pointer) gaat word later het begin adress van de array d
	int getal;

int main()
{
	p = &x;
	cout << "x is nu: " << x << endl;									// geeft waarde van x
	cout << "Adres van x is: " << p << endl;					// geeft adres van x
	*p = (x + 10);																		//x is nu x + 10 
	cout << "De waarde van x + 10 is: " << *p << endl; // geeft nieuwe waarde van x
	cout << "De waarde van x is veranderd maar het adres is nog steeds: " << p <<endl;

	cout << "typ een getal en druk op enter" << endl;
	cin >> getal;
	cin.get();

	cout << "nu ga ik checken of het getal 20 voorkomt in de array" << endl;
	zoek( d, VIER); // d is de naam en het beginadres van de array 

	int gezochteGetal = zoek( d, VIER);
	if (gezochteGetal != 0)
	{
		cout << "Het getal " << getal << " komt voor" << endl; 
	}
	else
		cout << "Het getal " << getal << " komt niet voor" << endl;
}

int zoek( int * t, int lengte) 
{
	for(int i = 0; i < lengte; i++)
	{
		if (*t == getal)
			return *t;
		t++;
	}
	return 0;
}








