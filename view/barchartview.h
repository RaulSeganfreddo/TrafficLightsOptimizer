#ifndef BARCHARTVIEW_H
#define BARCHARTVIEW_H

#include "view.h"

#include "model/barchartmodel.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QLegend>
#include <QScrollBar>
#include <vector>
#include <QDate>
#include <QMessageBox>

QT_CHARTS_USE_NAMESPACE // come "using namespace QtCharts"

/*
 * @brief La classe BarChartView mostra attraverso un BarChart il numero di auto passate nelle due strade (al giorno) in un dato range di date
 */
class BarChartView : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Costruttore della classe BarChartView
     * @param m Puntatore al modello
     * @param parent Puntatore al QWidget padre
     */
    explicit BarChartView(BarChartModel* m, QWidget *parent = nullptr);

    /**
     * @brief Distruttore della classe BarChartView
     */
    ~BarChartView();

    /*
     * @brief Metodo che crea i set di dati per il grafico
     * @param auto1 Numero di auto passate nella prima strada
     * @param auto2 Numero di auto passate nella seconda strada
     */
    void createSets(std::vector<unsigned int> strada1, std::vector<unsigned int> strada2);

    /*
     * @brief Metodo che applica i set di dati al grafico
     */
    void applySets();

    /*
     * @brief Metodo che imposta gli assi del grafico
     * @param date Date da applicare all'asse x
     */
    void applyAxis(QStringList days);

private:
    QChart *chart = new QChart();
    std::vector<QBarSet *> setList;
    // QBarSeries *series;
    QScrollBar *scrollBar;
    QPushButton *backArrow;

signals:
    /*
     * @brief Segnale per tornare alla view OptimizerView
     */
    void toOptimizerView();

public slots:
    /*
     * @brief Slot per mostrare la view OptimizerView
     */
    void showOptimizerView();
};

#endif // BARCHARTVIEW_H