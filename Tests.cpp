#include "Tests.h"
#include "RezervareCamera.h"
#include "Service.h"
#include <assert.h>
#include "RepoTemplate.h"
#include <iostream>
#include <cassert>
using namespace std;


//test pentru getteri entitate
void test1()
{
	RezervareCamera t(1, "T17", "simpla", true);
	assert(strcmp(t.getTip(), "simpla") == 0);
	assert(t.getId() == 1);
	assert(t.getEliberata() == true);
	RezervareCamera t2(3, "P19", "dubla", false);
	assert(!(t == t2));
	t2 = t;
	assert(t2 == t);
}

//test pentru constructor implicit
void test2()
{
	RezervareCamera t3;
	assert(t3.getId() == 0);
	assert(t3.getEliberata() == true);
	assert(t3.getTip() == NULL);
	assert(t3.getNr() == NULL);
}

//test pentru egalitate
void test3()
{
	RezervareCamera t(1, "T17", "simpla", true);
	RezervareCamera t2(3, "P19", "dubla", false);
	assert(!(t == t2));
	t2 = t;
	assert(t2 == t);
}

//test pentru repo
void test4()
{
	RezervareCamera t(1, "A23", "simpla", true);
	RezervareCamera t1(2, "C2", "simpla", false);
	RezervareCamera t2(3, "P19", "dubla", false);
	RezervareCamera t3(4, "T17", "simpla", true);
	RepoTemplate<RezervareCamera> repo;
	repo.add(t);
	repo.add(t1);
	repo.add(t2);
	repo.add(t3);
	assert(repo.size() == 4);
	assert(repo.getAll()[0] == t);
	assert(repo.getAll()[1] == t1);
	assert(repo.getAll()[2] == t2);
	assert(repo.getAll()[3] == t3);
	repo.del(t3);
	assert(repo.size() == 3);
	assert(strcmp(t.getNr(), "A23") == 0);
}