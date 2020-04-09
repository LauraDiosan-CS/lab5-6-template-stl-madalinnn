#pragma once
#include <vector>
#include <algorithm>
#include "RezervareCamera.h"
using namespace std;

template<class T> class RepoTemplate {
private: 
	vector<T> elem;
public:
	RepoTemplate<T>();
	void add(const T&);
	void del(int);
	T getById(int);
	int size();
	void update(int, char*, char*, bool);
	vector<T> getAll();
	~RepoTemplate();
};