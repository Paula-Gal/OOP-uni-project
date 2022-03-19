#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//clasa Task
class Task {
private:
	int id;
	string descriere;
	vector<string> programatori;
	string stare;//open, inprogress,closed

public:
	//constructorul clasei, primeste cele 4 atribute id, descriere, programatori, stare
	Task(int id, string desc, vector<string> progr, string stare) : id{ id }, descriere{ desc }, programatori{ progr }, stare{ stare }{};

	//getters
	
	//functia returneaza id-ul unui task
	int getID() {
		return id;
	}

	//functia returneaza descrierea unui task
	string getDesc() {
		return descriere;
	}

	//functia returneaza lista de programatori a unui task
	vector<string> getPr() {
		return programatori;
	}

	//functia returneaza starea unui task
	string getStare() {
		return stare;
	}

	//setters
	//functia seteaza o noua stare unui task
	string setStare(string stareNoua) {
		stare = stareNoua;
	}
};

//creez o clasa Validator care se va asigura ca un task este valid
class Validator {
private:

public:
	//metoda ce va valida un task
	//verifica daca campurile taskului respecta conditiile impuse
	//Date de intrare: task  - obiect de tipul Task
	void validate(Task task);
};