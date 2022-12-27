#include <QApplication>
#include <iostream>

#include "view.h"
#include "model.h"
#include "ctrl.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Model m = Model();
    Ctrl ctrl(&m);
    View* view = new View(&ctrl);
    view->show();

    return app.exec();
}