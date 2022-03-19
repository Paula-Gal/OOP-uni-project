#pragma once
#include <QtWidgets/QWidget>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QTableWidgetItem>
#include <QPushButton>
#include <QMessageBox>
#include <QLabel>
#include <QLineEdit>

#include "Service.h"
#include "Table.h"


//clasa responsabila de interfata aplicatiei
class GUI: public QWidget {
private:
	Service& srv;
	Table* table;

	QLabel* id_label;
	QLineEdit* id_line_edit;

	QLabel* desc_label;
	QLineEdit* desc_line_edit;

	QLabel* progr_label;
	QLineEdit* progr_line_edit;

	QLabel* stare_label;
	QLineEdit* stare_line_edit;

	QPushButton* add_btn;

	//metoda care initializeaza campurile clasei tabel
	void initGUI();

	//metoda care conecteaza butoanele la actiuni
	void connectBtn();

	//metoda care initializeaza app inainte ca aceasta sa porneasca
	void initStateGUI();

public:
	//constructorul clasei
	GUI(Service& srv) : srv{ srv } {
		initGUI();
		connectBtn();
		initStateGUI();
	}
};