#include "model/linechartmodel.h"

LineChartModel::LineChartModel(QDate date)
{
    this->date = date;
    getOttimizzazione(1);
    getOttimizzazione(2);
}

void LineChartModel::getOttimizzazione(int index)
{
    for (int i = 0; i < 24; i++)
    {
        if (index == 1)
        {
            ottimizzazione1.push_back(ottimizzazioneOra(index, date, i));
            ore.push_back(i);
        }
        if (index == 2)
        {
            ottimizzazione2.push_back(ottimizzazioneOra(index, date, i));
        }
    }
}

std::vector<unsigned int> LineChartModel::getOttimizzazione1()
{
    std::vector<unsigned int> ott1;
    for (auto it = ottimizzazione1.begin(); it != ottimizzazione1.end(); ++it)
    {
        ott1.push_back(*it);
    }
    return ott1;
}

std::vector<unsigned int> LineChartModel::getOttimizzazione2()
{
    std::vector<unsigned int> ott2;
    for (auto it = ottimizzazione2.begin(); it != ottimizzazione2.end(); ++it)
    {
        ott2.push_back(*it);
    }
    return ott2;
}

std::vector<unsigned int> LineChartModel::getOre()
{
    std::vector<unsigned int> ore1;
    for (auto it = ore.begin(); it != ore.end(); ++it)
    {
        ore1.push_back(*it);
    }
    return ore1;
}