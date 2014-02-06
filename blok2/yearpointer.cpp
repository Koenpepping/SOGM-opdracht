#include <iostream>

using namespace std;

int main()
{
unsigned short year = 2013;
unsigned short* yearpointer = &year;
short yeartijdelijk; 
	cout << "Inhoud van de variabele year: "
	<< year << endl;
	cout << "Inhoud van de pointer yearpointer: "
	<< &year << endl;
	cout << "Inhoud van waar de pointer yearpointer naar wijst: "
	<< *yearpointer << endl;
	cout << "type huidig jaar:" << endl;
	cin >> yeartijdelijk;
	cin.get();
	*yearpointer = yeartijdelijk;
	cout << "Inhoud van de variable year: "
	<< year << endl;

return 0;
}
