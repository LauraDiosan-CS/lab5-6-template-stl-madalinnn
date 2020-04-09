#include "RezervareCamera.h"
#include <string.h>
#include <iostream>
#include <istream>
#include <cstddef>
#include <ostream>
using namespace std;


//Descr: creeaza o rezervare
//In: -
//Out: o instanta de tip RezervareCamera
RezervareCamera::RezervareCamera() {
	this->tip = NULL;
	this->nr = NULL;
	this->id = 0;
	this->eliberata = true;
}

//Descr: creeaza un obiect de tip rezervare, constructor cu parametru
//In: id, int: id-ul rezervarii;    nr, int: numarul rezervarii;    tip, char*: tipul rezervarii;   
//    el ,bool: True, daca camera a fost eliberata, False in caz contrar
//Out: o instanta de tip rezervare
RezervareCamera::RezervareCamera(int id, char* nr, char* tip, bool eliberata) {
	this->tip = new char[strlen(tip) + 1];
	strcpy_s(this->tip, strlen(tip) + 1, tip);
	this->nr = new char[strlen(nr) + 1];
	strcpy_s(this->nr, strlen(nr) + 1, nr);
	this->id = id;
	this->eliberata = eliberata;
}

//Descr: creeaza o rezervare folosind informatii din alta (constructor de copiere)
//In: rc: o rezervare data
//Out: o instanta de tip RezervareCamera cu informatii din rc
RezervareCamera::RezervareCamera(const RezervareCamera& s) {
	this->tip = new char[strlen(s.tip) + 1];
	strcpy_s(this->tip, strlen(s.tip) + 1, s.tip);
	this->nr = new char[strlen(s.nr) + 1];
	strcpy_s(this->nr, strlen(s.nr) + 1, s.nr);
	this->eliberata = s.eliberata;
	this->id = s.id;
}

//Descr: acceseaza id-ul unei rezervari
//In: o rezervare
//Out: id-ul ei
int RezervareCamera::getId() {
	return this->id;
}

//Descr: modifica id-ul unei rezervari
//In: o rezervare si un id
//Out: rezervarea cu id modificat
void RezervareCamera::setId(int i) {
	this->id = i;
}

//Descr: acceseaza starea camerei unei rezervari
//In: o rezervare
//Out: starea ei
bool RezervareCamera::getEliberata() {
	return this->eliberata;
}

//Descr: modifica starea camerei unei rezeravri
//In: o rezervare si noua stare a camerei
//Out: rezervare cu starea camerei modificata
void RezervareCamera::setEliberata(bool elib) {
	this->eliberata = elib;
}

//Descr: acceseaza tipul unei rezervari
//In: o rezervare
//Out: tipul ei
char* RezervareCamera::getTip() {
	return this->tip;
}

//Descr: modifica tipul unei rezervari
//In: o rezervare si un tip
//Out: rezervare cu tip modificat
void RezervareCamera::setTip(char* t) {
	if (tip) delete[]tip;
	tip = new char[strlen(t) + 1];
	strcpy_s(tip, strlen(t) + 1, t);
}


//Descr: acceseaza numarul unei rezervari
//In: o rezervare
//Out: numarul ei
char* RezervareCamera::getNr() {
	return this->nr;
}

//Descr: modifica numarul unei rezervari
//In: o rezervare si un numar
//Out: rezervarea cu numarul modificat
void RezervareCamera::setNr(char* t) {
	if (nr) delete[]nr;
	nr = new char[strlen(t) + 1];
	strcpy_s(nr, strlen(t) + 1, t);
}

//Descr: distruge o rezervare
//In: o rezervare 
//Out: - (destructor)
RezervareCamera::~RezervareCamera() {
	if (tip) delete[]tip;
	tip = NULL;
	if (nr) delete[]nr;
	nr = NULL;
	id = -1;
	eliberata = true;
}

//suprascrie operatorul "=" pentru un element de tip RezervareCamera
RezervareCamera& RezervareCamera::operator=(const RezervareCamera& s) {
	this->setId(s.id);
	this->setEliberata(s.eliberata);
	this->setTip(s.tip);
	this->setNr(s.nr);
	return *this;
}

//operatorul de egalitate
bool RezervareCamera::operator==(const RezervareCamera& s) {
	return (id == s.id) && eliberata == s.eliberata && (strcmp(tip, s.tip) == 0 && (strcmp(nr, s.nr) == 0));
}

//Descr: afiseaza o rezervare sub forma de string
ostream& operator<<(ostream& os, const RezervareCamera& s)
{
	os << "ID-ul: " << s.id << ", numarul: " << s.nr << ", tipul: " << s.tip << ", eliberata: " << s.eliberata << endl;
	return os;
}

//afisare2
void RezervareCamera::afisare() {
	cout << "ID: " << this->id << ", numarul: " << this->nr << ", tip: " << this->tip << ", eliberata: " << this->eliberata;

}

//Descr: citeste o rezervare
//Out: o noua rezervare
istream& operator>>(istream& is, RezervareCamera& r)
{
	cout << "Dati id-ul: ";
	int id;
	cin >> id;
	cout << "Dati numarul: ";
	char* nr = new char[10];
	is >> nr;
	cout << "Dati tipul: ";
	char* tip = new char[10];
	is >> tip;
	cout << "Dati starea camerei: ";
	bool el;
	cin >> el;
	r.setId(id);
	r.setNr(nr);
	r.setTip(tip);
	r.setEliberata(el);
	delete[] tip;
	delete[] nr;
	return is;
}
