#ifndef OPTIMIZERVIEW_H
#define OPTIMIZERVIEW_H

#include "view.h"
#include "view/topbar.h"
#include "view/homeview.h"
#include "model/database.h"


/*
* @brief La classe OptimizerView mostra la schermata che permette di accedere ai 3 grafici
*/
class OptimizerView : public QWidget
{
    Q_OBJECT

public:
    /*
     * @brief Costruttore della classe OptimizerView
     * @param parent Puntatore al QWidget padre
     */
    explicit OptimizerView(QWidget *parent = nullptr);

    /*
     * @brief Distruttore della classe OptimizerView
     */
    ~OptimizerView();

    /*
     * @brief Metodo che aggiunge i layout alla view
     */
    void addLayouts();

private:
    QVBoxLayout *mainLayout;
    QHBoxLayout *chartsLayout;
    QPushButton *barChartButton;
    QPushButton *pieChartButton;
    QPushButton *lineChartButton;
    QPushButton *home;

signals:
    /*
     * @brief Segnale per tornare alla view HomeView
     */
    void toHomeView();

    /*
     * @brief Segnale per mostrare la view BarChartView
     */
    void toBarChartView();

    /*
     * @brief Segnale per mostrare la view PieChartView
     */
    void toPieChartView();

    /*
     * @brief Segnale per mostrare la view LineChartView
     */
    void toLineChartView();

public slots:
    /*
     * @brief Slot per mostrare la view HomeView
     */
    void showHomeView();

    /*
     * @brief Slot per mostrare la view BarChartView
     */
    void showBarChartView();

    /*
     * @brief Slot per mostrare la view PieChartView
     */
    void showPieChartView();

    /*
     * @brief Slot per mostrare la view LineChartView
     */
    void showLineChartView();
};

#endif // OPTIMIZERVIEW_H