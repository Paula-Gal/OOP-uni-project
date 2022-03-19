#include "Repo.h"
#include <fstream>
#include<iostream>

using namespace std;

void Repo::load_from_file() {
	ifstream f(this->fileN);

	if (!f.is_open())
		return;

	while (!f.eof())
	{
		int ID;
		vector<string> p;
		string desc, stare, program = "";
		f >> ID >> desc;
		f >> program;
		p.push_back(program);
		//if (program == "") return;
		f >> stare;
		//stare = program;
		Task task{ ID, desc, p, stare };
		this->all.push_back(task);
	}
	f.close();
}

void Repo::write_to_file() {
	int k = 0;
	ofstream g(this->fileN);
	if (!g.is_open()) return;

	for (auto t : this->all) {
		g << t.getID() << " " << t.getDesc() << " " << t.getPr()[0] << " " << t.getStare() << " ";
		g << endl;
	}
		/*for (auto i : t.getPr())
		{
			g << i << ";";
		}
		if (k != this->all.size() - 1)
			g << '\n';
		k++;
	}*/
	load_from_file();
	g.close();
}

vector<Task> Repo::getAll() {
	return this->all;
}

void Repo::addTask(Task task) {
	for (auto t : this->all) {
		if (t.getID() == task.getID())
			throw string("Task deja existent!\n");
		this->all.push_back(task);
	//	write_to_file();
	}
}

void Repo::remove(int id) {
	vector<Task>::iterator it;
	for(auto itr = this->all.begin(); itr != this->all.end();itr++)
		if ((*itr).getID() == id) {
			it = itr;
			break;
		}
	this->all.erase(it);
	write_to_file();
}