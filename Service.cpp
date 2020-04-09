#include "Service.h"
using namespace std;


//Constructor implicit
//Out: o instanta de tip ServiceRepoTemplate
ServiceRepoTemplate::ServiceRepoTemplate() {
}

//Descr: creeaza un obiect de tip Service
//In: r: repositoryul de entitati de manevrat
//Out: o instanta de tip ServiceRepoTemplate
ServiceRepoTemplate::ServiceRepoTemplate(const RepoTemplate<RezervareCamera>& r) {
	repo = r;
}

//Descr: initializeaza un repository
//In: r: repository de initializat
//Out: -
void ServiceRepoTemplate::setRepo(const RepoTemplate<RezervareCamera>& r) {
	repo = r;
}

//Descr: adauga o rezervare
//In: r: rezervarea de adaugat
//Out: -
void ServiceRepoTemplate::add(RezervareCamera& r) {
	repo.add(r);
}

//Descr: Sterge o rezervare
//In: id: id-ul rezervarii de sters
//Out: -
void ServiceRepoTemplate::del(int id)
{
	repo.del(id);
}

//Descr: returneaza vectorul tuturor rezervarilor
vector<RezervareCamera> ServiceRepoTemplate::getAll()
{
	/*list<StudentBursier> rez = repo.getAll();
	vector<StudentBursier> v(rez.begin(), rez.end());
	return v;   */
	return repo.getAll();
}

//Descr: modifica o rezervare
//In: id: id-ul rezervarii de modificat;  new_nr: noul numar;  new_tip: noul tip;    new_el: noua stare a camerei
//Out: -
void ServiceRepoTemplate::update(int id, char* nr, char* tip, bool el)
{
	repo.update(id, nr, tip, el);
}

//Destructor
//Distruge un obiect de tip Service
ServiceRepoTemplate::~ServiceRepoTemplate() {
}
