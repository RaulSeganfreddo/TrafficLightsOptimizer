#include "model/piechartmodel.h"

PieChartModel::PieChartModel(QDate date1, QDate date2)
{
    this->date1 = date1;
    this->date2 = date2;
    ottimizzazione1 = getOttimizzazione(1);
    ottimizzazione2 = getOttimizzazione(2);
};

unsigned int PieChartModel::getOttimizzazione(unsigned int index)
{
    float autoGiorni1 = autoGiorni(1, date1, date2, 0, 23);
    float autoGiorni2 = autoGiorni(2, date1, date2, 0, 23);
    unsigned int ottimizzazione = 0;
    float percentuale = 0;
    if (index == 1)
    {
        percentuale = autoGiorni1 / (autoGiorni1 + autoGiorni2);
        if (percentuale > 0.95)
            percentuale = 0.95;
        if (percentuale < 0.05)
            percentuale = 0.05;
        ottimizzazione = percentuale * 300.0;
        return ottimizzazione;
    }
    if (index == 2)
    {
        percentuale = autoGiorni2 / (autoGiorni1 + autoGiorni2);

        if (percentuale > 0.95)
            percentuale = 0.95;
        if (percentuale < 0.05)
            percentuale = 0.05;
        ottimizzazione = percentuale * 300.0;
        return ottimizzazione;
    }
}

unsigned int PieChartModel::getOttimizzazione1() const
{
    return ottimizzazione1;
}

unsigned int PieChartModel::getOttimizzazione2() const
{
    return ottimizzazione2;
}