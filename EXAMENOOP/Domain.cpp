#include "Domain.h"

#include <iostream>

//definesc metoda validate din Validator
void Validator::validate(Task task) {
	string errors = "";
	if (task.getDesc() == "")
		errors += "Descriere vida!\n";
	if (task.getStare() != "open" && task.getStare() != "inprogress" && task.getStare() != "close")
		errors += "Starea nu este valida!Introduceti una dintre: open/inprogress/close\n";
	if (task.getPr().size() < 1 || task.getPr().size() > 4)
		errors += "Lista de programatori nu are minim 1 - maxim 4 programatori!\n";
	if (errors != "")
		throw errors;
}