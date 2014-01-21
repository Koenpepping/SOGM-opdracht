#include <iostream>
#include "kerstboomsogm.h"

using namespace std;


int main()
{
int aantalkerstbomen=0;
	cout << "KERSTKORTING nu geld voor elke kerstboom 1+1 GRATIS!" <<endl;
	cout << "hoeveel kerstbomen wil je?" << endl;
	cin >> aantalkerstbomen; 
	
	cout << "aantal kerstbomen: " << (aantalkerstbomen+aantalkerstbomen) << endl;

	for(int boom=0;boom<aantalkerstbomen; ++boom) {
		for(int rij=0; rij<HOOGTE; ++rij) {    
			for(int spat=HOOGTE; spat>rij; --spat) {
				cout << " ";
			}
			for(int ster=0 ;ster<(rij*2+1); ++ster) {
				cout << "*";
			}
			for(int spat=HOOGTE; spat>rij; --spat) {
				cout << " ";
			}
			for(int spat=HOOGTE; spat>rij; --spat) {
				cout << " ";
			}
			for(int ster=0 ;ster<(rij*2+1); ++ster) {
				cout << "*";
			}
			for(int spat=HOOGTE; spat>rij; --spat) {
				cout << " ";
			}
			cout << endl;
		}

		for(int stam=0; stam<(HOOGTE/3); ++stam) {
			for(int spatie=0; spatie<(HOOGTE-1); ++spatie) {
				cout << " ";
			}
			for(int streep=0; streep<(HOOGTE/3); ++streep) {
				cout << "|";
			}
			for(int spatie=0; spatie<(HOOGTE-1); ++spatie) {
				cout << " ";
			}
			for(int spatie=0; spatie<(HOOGTE-1); ++spatie) {
				cout << " ";
			}
			for(int streep=0; streep<(HOOGTE/3); ++streep) {
				cout << "|";
			}
			for(int spatie=0; spatie<(HOOGTE-1); ++spatie) {
				cout << " ";
			}

			cout << endl;
		}
	}

return 0;
} 

