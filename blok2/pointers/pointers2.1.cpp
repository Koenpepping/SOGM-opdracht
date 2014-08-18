#include <iostream>

using namespace std;

/*

SOGM opdract pointers2.1 
om het verschil te laten zien tussen het doorgeven van variabelen aan een functie 
"by value" en d.m.v. pointers

*/

const int VIER = 4;
int e[VIER] = {10, 20, 30, 40};


void argumentByValue(int a, int b);
void argumentByPointer(int * c, int d);

int main()
{
	argumentByValue(0, VIER);
	cout << " " << endl;
	argumentByPointer(e, VIER);
	cout << " " << endl;
	cout << "zie code voor uitgebreide uitleg" << endl;
}

void argumentByValue(int a, int b) 
{
	for(int x = 0; x < b; x++)
	{
		cout << e[a] << " " << a <<endl; 
		a++; 
	}
cout << " " <<endl;
cout << "a = 0; links e[a], rechts a" <<endl;

/* "bij het aanroepen van deze funtie zeg ik: a = 0; a++ telt telkens 1 op bij a wat in dit geval de index is van de array e[0]. Links in de uitvoer zie je dat a het element van de array e terug geeft. Rechts zie je dat a++ dus echt telkens wanneer a++ aangeroepen word 1 optelt bij a." */

}

void argumentByPointer(int * c,int d)
{
		for(int x = 0; x < d; x++)
	{
		cout << *c << " " << c <<endl;
		c++; //(c++ jeej!) 
	}
cout << " " <<endl;
cout << "*c = e[0]. links *c, rechts c" <<endl;

/* "c++ verschuift het adres telkens met het aantal bytes van in dit geval een int. c is het beginadres van de array dus: e[0]. Elke keer wanneer c++ word aangeroepen zal naar de volgende index worden gesprongen en zal de uitvoer dat getal laten zien (links). Rechts zie je het adres van waar c naar wijst. Dat laat inderdaad zien dat het adres veranderd en c alleen wijst naar een plek in het geheugen." */

}
