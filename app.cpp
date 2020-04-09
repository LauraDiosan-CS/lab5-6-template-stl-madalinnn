#include "RepoTemplate.h"
#include "UI.h"
#include "Service.h"
#include "Tests.h"
#include <iostream>
using namespace std;


int main() {
	test1();
	test2();
	test3();
	test4();
	cout << "Good job!" << endl;
	RepoTemplate<RezervareCamera> r;
	ServiceRepoTemplate serv(r);
	UI ui(serv);
	ui.showUI();
	return 0;
}