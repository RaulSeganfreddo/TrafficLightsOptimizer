#ifndef CTRL_H
#define CTRL_H

#include "model.h"
#include "view.h"

class View;

class Ctrl : public QObject
{
    Q_OBJECT
public:
    /*
     * @brief Costruttore della classe Ctrl
     * @param m Model
     */
    Ctrl(Model *m);

    /*
     * @brief Metodo che setta la view
     * @param v View
     */
    void setView(View *v);

private:
    Model *model;
    View *view;

public slots:

};

#endif // CTRL_H