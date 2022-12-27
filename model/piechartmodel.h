#ifndef PIECHARTMODEL_H
#define PIECHARTMODEL_H

#include "model.h"

#include <iostream>
#include <QDebug>

/*
 * @brief La classe PieChartModel si occupa di gestire i dati per il grafico a torta
 */
class PieChartModel : public Model
{
public:
    /*
     * @brief Costruttore della classe PieChartModel
     * @param date1 Data iniziale
     * @param date2 Data finale
     */
    explicit PieChartModel(QDate date1, QDate date2);

    /*
     * @brief Metodo che ottiene l'ottimizzazione in secondi della strada nel range di date
     * @param index Indice della strada, 1 per la prima strada, 2 per la seconda strada
     */
    unsigned int getOttimizzazione(unsigned int index);

    /*
     * @brief metodo getter per l'attributo ottimizzazione1
     */
    unsigned int getOttimizzazione1() const;

    /*
     * @brief metodo getter per l'attributo ottimizzazione2
     */
    unsigned int getOttimizzazione2() const;

private:
    QDate date1;
    QDate date2;
    unsigned int ottimizzazione1;
    unsigned int ottimizzazione2;
};

#endif // PIECHARTMODEL_H