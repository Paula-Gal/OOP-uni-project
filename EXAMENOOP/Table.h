#pragma once
#include "Service.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QVBoxLayout>

//public Obsserver
class Table : public QWidget{
public:
	Service& srv;
	QTableWidget* table;
	QVBoxLayout* layout;

	//functie pt initializarea campurilor clasei
	void initGUI();
	//incarcare elemente in tabel
	void load_task_into_table();
	

	//constructor
	Table(Service& srv) : srv{ srv } {
		//srv.addObserver();
		initGUI();
	};

	//suprascriera metodei de update cand au loc modificar asupra listei de taskuri
	void update() /*override*/;
};