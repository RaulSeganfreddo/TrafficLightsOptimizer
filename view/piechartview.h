#ifndef PIECHARTVIEW_H
#define PIECHARTVIEW_H

#include "view.h"
#include "model/piechartmodel.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

QT_CHARTS_USE_NAMESPACE

/*
 * @brief La classe PieChartView mostra attraverso un PieChart l'ottimizzazione in secondi delle due strade in un dato range di date
 */
class PieChartView : public QWidget
{
    Q_OBJECT

public:
    /*
     * @brief Costruttore della classe PieChartView
     * @param m Puntatore al modello
     * @param parent Puntatore al QWidget padre
     */
    explicit PieChartView(PieChartModel* m, QWidget *parent = nullptr);

    /*
     * @brief Distruttore della classe PieChartView
     */
    ~PieChartView();

    /*
     * @brief Metodo per applicare la serie di dati al grafico
     * @param ottimizzazione1 Ottimizzazione in secondi della prima strada
     * @param ottimizzazione2 Ottimizzazione in secondi della seconda strada
     */
    void applySeries(unsigned int ottimizzazione1, unsigned int ottimizzazione2);

private:
    QChart *chart;
    QPushButton *backArrow;
    // QPieSeries *series;

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

#endif // PIECHARTVIEW_H