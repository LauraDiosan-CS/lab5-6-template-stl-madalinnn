#include "Service.h"
#include "UI.h"
#include "RezervareCamera.h"
#include <iostream>
using namespace std;


void UI::add_ui() {
	RezervareCamera r;
	cout << "Dati rezervarea: ";
	cin >> r;
	serv.add(r);
	cout << "Rezervarea a fost adaugata cu succes!" << endl;
}

void UI::del_ui() {
	int id;
	cout << "Dati id-ul rezervarii de sters: ";
	cin >> id;
	serv.del(id);
	cout << "Rezervarea a fost  stearsa cu succes!" << endl;
}

void UI::update_ui() {
	int id;
	char* new_nr = new char[10];
	char* new_tip = new char[10];
	bool new_el;
	cout << "Dati id-ul rezervarii de modificat: "; cin >> id;
	cout << "Dati noul numar al rezervarii: "; cin >> new_nr;
	cout << "Dati noul tip al rezervarii: "; cin >> new_tip;
	cout << "Dati noua stare a rezervarii: "; cin >> new_el;
	serv.update(id, new_nr, new_tip, new_el);
	cout << " Rezervarea a fost modificata cu succes!" << endl;
}

void UI::show_all() {
	cout << "TOATE CHELTUIELILE:" << endl;
	cout << "---------------" << endl;
	vector<RezervareCamera> rez = serv.getAll();
	for (RezervareCamera r : rez)
		cout << r;
	cout << "| ----------------------------|" << endl;
}

UI::UI() {
}

UI::UI(ServiceRepoTemplate& s) {
	serv = s;
}

void UI::showUI() {
	bool gata = false;
	while (!gata) {
		cout << endl;
		cout << "OPTIUNI: " << endl;
		cout << "	1. Adauga rezervare " << endl;
		cout << "	2. Modifica rezervare " << endl;
		cout << "	3. Sterge rezervare " << endl;
		cout << "	4. Afiseaza toate rezervarile " << endl;
		cout << "	0. EXIT!" << endl;
		cout << "Introduceti optiunea (prin numarul ei): " << endl;
		int opt;
		cin >> opt;
		switch (opt) {
		case 1: {add_ui(); break; }
		//case 2: {update_ui(); break; }
		//case 3: {del_ui(); break; }
		case 4: {show_all(); break; }
		case 0: {gata = true; cout << "LA REVEDERE!" << endl; }
		default: {cout << "OPTIUNEA NU EXISTA! VA RUGAM SELECTATI UNA DIN OPTIUNILE EXISTENTE:" << endl; }
		}
	}
}

UI::~UI() {
	//destructorul
}

