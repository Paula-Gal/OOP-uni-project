#include <iostream>
#include <vector>
#include <fstream>
#include "Domain.h"

using namespace std;

//clasa Repo ce va fi responsabila cu operatiile efectuaste asupra listei de taskuri
class Repo {
private:
	string fileN;//numele fisierului
	vector<Task> all;//lista de taskuri

public:
	//constructorul clasei
	//are ca parametru numele fisierului (string) de unde incarca datele
	//si apeleaza metoda de incarcare a datelor din acel fisier
	Repo(string file) : fileN{ file } {
		load_from_file();
	}

	//functia care incarca datele din fisier
	void load_from_file();

	//functia care scrie date in fisier
	void write_to_file();

	//functia care returneaza lista de taskuri 
	vector<Task> getAll();

	//functia care adauga un nou task in lista 
	void addTask(Task task);

	//functia care sterge un nou task in lista 
	void remove(int id);


	//modifica starea unui task cu id ul dat ca param

};