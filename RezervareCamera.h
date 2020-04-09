#pragma once
#include <iostream>
using namespace std;

class RezervareCamera {
private:
	int id;
	char* nr;
	char* tip;
	bool eliberata;
public:
	RezervareCamera();
	RezervareCamera(int id, char* nr, char* tip, bool eliberata);
	RezervareCamera(const RezervareCamera&);
	RezervareCamera& operator=(const RezervareCamera&);
	int getId();
	char* getTip();
	void setTip(char* tip);
	void setId(int id);
	char* getNr();
	void setNr(char* nr);
	bool getEliberata();
	void setEliberata(bool eliberata);
	bool operator==(const RezervareCamera&);
	friend ostream& operator<<(ostream& os, const RezervareCamera& s);
	friend istream& operator>>(istream&, RezervareCamera&);
	void afisare();
	~RezervareCamera();
};