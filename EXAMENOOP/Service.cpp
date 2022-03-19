#include "Service.h"
#include <algorithm>

using namespace std;

vector<Task> Service::getAll() {
	return this->repo.getAll();
}

vector<Task> Service::sortareDesc() {
	vector<Task> sortt = this->repo.getAll();

	sort(sortt.begin(), sortt.end(), [](Task t1, Task t2)
		{
			return t1.getDesc() < t2.getDesc();
		});

	return sortt;
}

void Service::adauga(int id, string desc, vector<string> list, string stare) {
	Task task{ id, desc, list, stare };
	//validez taskul de adaugat
	this->valid.validate(task);
	repo.addTask(task);
	//notify();
}