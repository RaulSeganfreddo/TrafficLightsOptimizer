#include "barchartmodel.h"

BarChartModel::BarChartModel(QDate date1, QDate date2)
{
    this->date1 = date1;
    this->date2 = date2;
    setDays();
    setStrada1();
    setStrada2();
}

void BarChartModel::setDays()
{
    QDate date = date1;
    while (date <= date2)
    {
        days << date.toString("dd/MM/yyyy");
        date = date.addDays(1);
    }
}

void BarChartModel::setStrada1()
{
    QDate date = date1;
    while (date <= date2)
    {
        strada1.push_back(autoGiorno(1, date, 0, 23));
        date = date.addDays(1);
    }
}

void BarChartModel::setStrada2()
{
    QDate date = date1;
    while (date <= date2)
    {
        strada2.push_back(autoGiorno(2, date, 0, 23));
        date = date.addDays(1);
    }
}

QStringList BarChartModel::getDays() const
{
    return days;
}

std::vector<unsigned int> BarChartModel::getStrada1() const
{
    return strada1;
}

std::vector<unsigned int> BarChartModel::getStrada2() const
{
    return strada2;
}

QDate BarChartModel::getDate1() const
{
    return date1;
}

QDate BarChartModel::getDate2() const
{
    return date2;
}