#include <QtWidgets/QApplication>
#include "GUI.h"
#include "Teste.h"

int main(int argc, char *argv[])
{ 
    QApplication a(argc, argv);
    //teste();
    Validator val;
    Repo repo{"repo.txt"};
    Service srv(repo, val);

    GUI g(srv);
    g.show();

    return a.exec();
}
