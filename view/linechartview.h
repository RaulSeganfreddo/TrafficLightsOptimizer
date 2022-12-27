#ifndef LINECHARTVIEW_H
#define LINECHARTVIEW_H

#include "model/linechartmodel.h"
#include "view.h"

#include <QHBoxLayout>
#include <QtCharts/QChartView>
#include <QtCharts/QSplineSeries>
#include <QPushButton>

QT_CHARTS_USE_NAMESPACE

/*
 * @brief La classe LineChartView mostra il LineChart che mostra il variare dell'ottimizzazione dei secondi nelle due strade in un dato range di date
 */
class LineChartView : public QWidget
{
    Q_OBJECT

public:

    /*
     * @brief Costruttore della classe LineChartView
     * @param m Puntatore al modello
     * @param parent Puntatore al QWidget padre
     */
    explicit LineChartView(LineChartModel* m, QWidget *parent = nullptr);

    /*
     * @brief Distruttore della classe LineChartView
     */
    ~LineChartView();

    /*
     * @brief Metodo per applicare la serie di dati al grafico
     * @param ottimizzazione1 Ottimizzazione in secondi della prima strada
     * @param ottimizzazione2 Ottimizzazione in secondi della seconda strada
     */
    void applySeries(std::vector<unsigned int> ottimizzazione1, std::vector<unsigned int> ottimizzazione2, std::vector<unsigned int> ore);

private:
    QChart *chart;
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

#endif  // LINECHARTVIEW_H