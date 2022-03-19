#include "GUI.h"
#include "QDebug"

using namespace std;

void GUI::initGUI() {
	QVBoxLayout* ly = new QVBoxLayout;
	this->setLayout(ly);

	//
	table = new Table(this->srv);
	ly->addWidget(table);

	//id
	id_label = new QLabel("ID");
	ly->addWidget(id_label);
	id_line_edit = new QLineEdit;
	ly->addWidget(id_line_edit);

	//desc
	desc_label = new QLabel("Descriere");
	ly->addWidget(desc_label);
	desc_line_edit = new QLineEdit;
	ly->addWidget(desc_line_edit);


	//programatori
	progr_label = new QLabel("Programatori");
	ly->addWidget(progr_label);
	progr_line_edit = new QLineEdit;
	ly->addWidget(progr_line_edit);

	//stare
	stare_label = new QLabel("Stare");
	ly->addWidget(stare_label);
	stare_line_edit = new QLineEdit;
	ly->addWidget(stare_line_edit);

	add_btn = new QPushButton("Adauga");
	ly->addWidget(add_btn);

	//stergere dupa programator
}

void GUI::connectBtn() {
	QObject::connect(add_btn, &QPushButton::clicked, this, [this]()
		{
			vector<string> pr;
			 int id = id_line_edit->text().toInt();
			 id_line_edit->clear();

			 string desc = desc_line_edit->text().toStdString();
			 desc_line_edit->clear();

			 string progr = progr_line_edit->text().toStdString();
			 pr.push_back(progr);
			 progr_line_edit->clear();

			 string stare = stare_line_edit->text().toStdString();
			 stare_line_edit->clear();

			 try {
				 this->srv.adauga(id, desc, pr, stare);
			 }
			 catch (const string& err) {
				 QMessageBox::warning(nullptr, "Eroare", QString
					 ::fromStdString(err));
			 }

		});
}

void GUI::initStateGUI() {
	table->update();
}