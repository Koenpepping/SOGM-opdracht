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
	void conclusie(int s, int gezocht);
	void telOp(int gezocht, int optellen);
	int getal2;


int main()
{
	p = &x;
	cout << "x is nu: " << x << endl;									// geeft waarde van x
	cout << "Adres van x is: " << p << endl;					// geeft adres van x
	*p = (x + 10);																		//x is nu x + 10 
	cout << "De waarde van x + 10 is: " << *p << endl; // geeft nieuwe waarde van x
	cout << "De waarde van x is veranderd maar het adres is nog steeds: " << p <<endl;
	cout << " " << endl;
	cout << "typ een getal en druk op enter" << endl;
	cin >> getal;
	cin.get();

	cout << "nu ga ik checken of het getal " << getal << " voorkomt in de array" << endl;

	zoek( d, VIER); // d is de naam en het beginadres van de array 
	int gezochteGetal = zoek( d, VIER);

	void (* op)(int, int); // pointer naar een functie met 2 x int als argumenten, en void als functiewaarden
	op = conclusie;	// op krijgt adres van de functie conclusie(); 
	op(gezochteGetal, getal); 
	
	cout << " " << endl;
	cout << "typ nog een getal en druk op enter" <<endl;
	cin >> getal2;
	cout << "nu tel ik er " << getal2 << " bij op gewoon.. zomaar" <<endl;
	op = telOp;
	op(getal, getal2);
}
void conclusie(int s, int gezocht)
{
	if (s != 0)
			cout << "Het getal " << gezocht << " komt voor" << endl; 
	else
			cout << "Het getal " << gezocht << " komt niet voor" << endl;
	
}

void telOp(int gezocht, int optellen)
{
	cout << gezocht << " + " << optellen << " is: " << (gezocht + optellen) << endl;
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







