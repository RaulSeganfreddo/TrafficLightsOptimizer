#ifndef HOMEVIEW_H
#define HOMEVIEW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QPixmap>
#include <QCoreApplication>
#include <QMessageBox>
#include <QCloseEvent>
#include "topbar.h"


/*
 * @brief La classe HomeView mostra la schermata principale (e iniziale) dell'applicazione
 */
class HomeView : public QWidget
{
    Q_OBJECT

public:
    /*
     * @brief Costruttore della classe HomeView
     * @param parent Puntatore al QWidget padre
     */
    explicit HomeView(QWidget *parent = nullptr);

    /*
     * @brief Distruttore della classe HomeView
     */
    ~HomeView();

    /*
     * @brief Metodo che aggiunge i layout alla view
     */
    void inizialize();

    /*
     * @brief Metodo che si occupa di settare le icone dei bottoni
     */
    static void setIcons(const QPixmap &pix, QPushButton *btn);

private:
    QVBoxLayout *mainLayout;
    QHBoxLayout *optionsLayout;
    QPushButton *HowItWorks;
    QPushButton *Optimizer;
    QPushButton *EditDB;

    // void closeEvent(QCloseEvent *event);


signals:
    /*
     * @brief Segnale per mostrare la view HowItWorksView
     */
    void toHowItWorksView();

    /*
     * @brief Segnale per mostrare la view OptimizerView
     */
    void toOptimizerView();

    /*
     * @brief Segnale per mostrare la view EditDBView
     */
    void toEditDBView();

public slots:
    /*
     * @brief Slot per mostrare la view HowItWorksView
     */
    void showHowItWorksView();

    /*
     * @brief Slot per mostrare la view OptimizerView
     */
    void showOptimizerView();

    /*
     * @brief Slot per mostrare la view EditDBView
     */
    void showEditDBView();

};

#endif // HOMEVIEW_H