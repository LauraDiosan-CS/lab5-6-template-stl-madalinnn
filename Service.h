#pragma once
#include "RepoTemplate.h"
#include "RezervareCamera.h"
#include <vector>
using namespace std;


class ServiceRepoTemplate {
private:
	RepoTemplate<RezervareCamera> repo;
public:
	ServiceRepoTemplate();
	ServiceRepoTemplate(const RepoTemplate<RezervareCamera>&);
	void setRepo(const RepoTemplate<RezervareCamera>&);
	void add(RezervareCamera&);
	void del(int);
	vector<RezervareCamera> getAll();
	void update(int, char*, char*, bool);
	~ServiceRepoTemplate();
};
