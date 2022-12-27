#ifndef EDITDBVIEW_H
#define EDITDBVIEW_H

#include "topbar.h"
#include "model/editDBmodel.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QTableView>
#include <QCalendarWidget>
#include <QLabel>
#include <QPixmap>
#include <QCoreApplication>
#include <QDebug>

/*
 * @brief La classe EditDBView mostra la schermata per la modifica del database
 */
class EditDBView : public QWidget
{
    Q_OBJECT

public:
    /*
     * @brief Costruttore della classe EditDBView
     * @param parent Puntatore al QWidget padre
     */
    explicit EditDBView(QWidget *parent = nullptr);
    /*
     * @brief Distruttore della classe EditDBView
     */
    ~EditDBView();

private:
    QPushButton *home;
    EditDBModel *model;
    QTableView *tableView;

signals:
    /*
     * @brief Segnale per tornare alla view HomeView
     */
    void toHomeView();

public slots:
    /*
     * @brief Slot per aggiornare la view
     */
    void showHomeView();
};

#endif // EDITDBVIEW_H