#pragma once

#include "Repo.h"
//observer

//clasa Service va fi intermediarul dintre GUI si Repo

class Service {
private:
	Repo& repo;
	Validator& valid;

public:
	//constructorul
	Service(Repo& repo, Validator& valid) : repo{ repo }, valid{ valid }{};

	//functia care returneaza lista de taskuri
	vector<Task> getAll();

	//sortare crescator dupa descriere
	vector<Task> sortareDesc();

	//functia care adauga un nou task
	void adauga(int id, string desc, vector<string> list, string stare);

	//modifca starea

	//filtrare dupa stare
};