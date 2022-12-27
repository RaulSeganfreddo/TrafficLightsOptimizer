#ifndef LINECHARTMODEL_H
#define LINECHARTMODEL_H

#include "model.h"
#include "model/record.h"

#include <vector>
#include <list>

/*
 * @brief La classe LineChartModel si occupa di gestire i dati per il grafico a linee
 */
class LineChartModel : public Model
{
public:
    /*
     * @brief Costruttore della classe LineChartModel
     * @param date Data sul quale si vuole visualizzare il grafico
     */
    explicit LineChartModel(QDate date);

    /*
     * @brief Metodo che ottiene l'ottimizzazione in secondi della strada nel dato giorno
     * @param index Indice della strada, 1 per la prima strada, 2 per la seconda strada
     */
    void getOttimizzazione(int index);

    /*
     * @brief metodo getter per l'attributo ottimizzazione1
     */
    std::vector<unsigned int> getOttimizzazione1();

    /*
     * @brief metodo getter per l'attributo ottimizzazione2
     */
    std::vector<unsigned int> getOttimizzazione2();

    /*
     * @brief metodo getter per l'attributo ore
     */
    std::vector<unsigned int> getOre();

private:
    QDate date;
    std::vector<unsigned int> ottimizzazione1;
    std::vector<unsigned int> ottimizzazione2;
    std::vector<unsigned int> ore;
};

#endif // LINECHARTMODEL_H