#include <iostream>
#include "kerstboomsogm.h"
#include <stdlib.h>
using namespace std;


int main()
{
int aantalkerstbomen=0;
	cout << "KERSTKORTING nu geld voor elke kerstboom 1+1 GRATIS!" <<endl;
	cout << "hoeveel kerstbomen wil je?" << endl;
	cin >> aantalkerstbomen; 
	
	cout << "aantal kerstbomen: " << (aantalkerstbomen+aantalkerstbomen) << endl;

int rnd;
srand (time(NULL));

	for(int boom=0;boom<aantalkerstbomen; ++boom) {
		for(int rij=0; rij<HOOGTE; ++rij) {    
			for(int spat=HOOGTE; spat>rij; --spat) {
				cout << " ";
			}
			for(int ster=0 ;ster<(rij*2+1); ++ster) {
				rnd = rand() % 10 + 1;
				if (rnd < 2) {
					cout << "0";
				}
				else { 
					cout << "*";
				}
			}
			for(int spat=HOOGTE; spat>rij; --spat) {
				cout << " ";
			}
			for(int spat=HOOGTE; spat>rij; --spat) {
				cout << " ";
			}
			for(int ster=0 ;ster<(rij*2+1); ++ster) {
				rnd = rand() % 10 + 1;
				if (rnd < 2) {
					cout << "0";
				}
				else { 
					cout << "*";
				}
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

