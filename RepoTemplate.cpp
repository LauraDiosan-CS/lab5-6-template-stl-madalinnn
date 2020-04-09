#include "RepoTemplate.h"
using namespace std;

//Descr: creeaza un Repository de entitati
//In: -
//Out: o instanta de tip RepoTemplate
template <class T> RepoTemplate<T>::RepoTemplate() {}

/* Descr: Adauga o noua entitate in vectorul Repository
   Input: e: entitatea de adaugat
   Output:-            */
template<class T>
void RepoTemplate<T>::add(const T &e)
{
	elem.push_back(e);
}

// Descr: Obtine o entitate dupa id
// In: id:id-ul entitatii de cautat
// Out: entitatea cu id-ul dat
template<class T>
 T RepoTemplate<T>::getById(int id) {
	typename vector<T>::iterator it;
	for (it = elem.begin(); it <= elem.end(); it++) {
		if ((*it).getId() == id)
			return *it;
	}
}  
 
//Descr: Sterge o entitate
//In: id: id-ul entitatii de sters
//Out: -
 template <class T>
 void RepoTemplate<T>::del(int id)
 {
	 typename vector<T>::iterator it;
	 T e = getById(id);
	 it = find(elem.begin(), elem.end(), e);
	 if (it != elem.end()) {
		 elem.erase(it);
	 }
 }
 
/*descr:  Acceseaza dimensiunea vectorului de entitati
  Output: numarul de entitati	*/
template<class T>
int RepoTemplate<T>::size() {
	return elem.size();
}

//Descr: modifica o entitate
//In: id: id-ul entitatii de modificat;  new_nr: noul numar;  new_tip: noul tip;    new_el: noua stare a camerei(eliberata sau nu)
//Out: -
template <class T>
void RepoTemplate<T>::update(int id, char* new_nr, char* new_tip, bool new_el) {
	typename vector<T>::iterator it;
	T e = getById(id);
	it = find(elem.begin(), elem.end(), e);
	if (it != elem.end()) {
		(*it).setNr(new_nr);
		(*it).setTip(new_tip);
		(*it).setEliberata(new_el);
	}

}

/*Descr: Acceseaza toate entitatile din repository
  Output: vectorul de entitati   	*/
template<class T>
vector<T> RepoTemplate<T>::getAll(){
	return elem;
}

template <class T> RepoTemplate<T>::~RepoTemplate(){
	//destructorul
}
