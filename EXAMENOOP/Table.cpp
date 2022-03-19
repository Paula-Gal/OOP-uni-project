#include "Table.h"

void Table::initGUI() {
	layout = new QVBoxLayout;
	this->setLayout(layout);

	table = new QTableWidget;
	layout->addWidget(table);

	load_task_into_table();
}

void Table::load_task_into_table() {
	vector<Task> rez;
	rez = srv.sortareDesc();

	table->setColumnCount(4);
	table->setRowCount(rez.size());

	int k = 0;
	for (auto task : rez) {
		QTableWidgetItem* t0 = new QTableWidgetItem(QString::fromStdString(to_string(task.getID())));
		table->setItem(k, 0, t0);

		QTableWidgetItem* t1 = new QTableWidgetItem(QString::fromStdString((task.getDesc())));
		table->setItem(k, 1, t1);

		QTableWidgetItem* t2 = new QTableWidgetItem(QString::fromStdString((task.getPr()[0])));
		table->setItem(k, 2, t2);

		QTableWidgetItem* t3 = new QTableWidgetItem(QString::fromStdString((task.getStare())));
		table->setItem(k, 3, t3);
		
		k++;
	}
}

void Table::update() {

	load_task_into_table();
}