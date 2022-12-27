#ifndef BARCHARTMODEL_H
#define BARCHARTMODEL_H

#include "model.h"
#include "model/database.h"
#include "model/record.h"

#include <vector>
#include <string>
#include <list>
#include <QDate>
#include <QStringList>
#include <QMessageBox>

/*
 * @brief La classe BarChartModel si occupa di gestire i dati per il grafico a barre
 */
class BarChartModel : public Model
{
public:
    /*
     * @brief Costruttore della classe BarChartModel
     * @param date1 Data iniziale
     * @param date2 Data finale
     */
    explicit BarChartModel(QDate date1, QDate date2);

    /*
     * @brief Metodo che assegna i giorni nel range di date alla QStringList days
     */
    void setDays();

    /*
     * @brief Metodo che assegna il numero di auto passate ogni giorno nella strada 1 al vettore strada1 per il dato range di date
     */
    void setStrada1();

    /*
     * @brief Metodo che assegna il numero di auto passate ogni giorno nella strada 2 al vettore strada2 per il dato range di date
     */
    void setStrada2();

    /*
     * @brief metodo getter per l'attributo days
     * @return QStringList days
     */
    QStringList getDays() const;

    /*
     * @brief metodo getter per l'attributo strada1
     * @return vettore di strada1
     */
    std::vector<unsigned int> getStrada1() const;

    /*
     * @brief metodo getter per l'attributo strada2
     * @return vettore di strada2
     */
    std::vector<unsigned int> getStrada2() const;

    /*
     * @brief metodo getter per l'attributo date1
     * @return data iniziale
     */
    QDate getDate1() const;

    /*
     * @brief metodo getter per l'attributo date2
     * @return data finale
     */
    QDate getDate2() const;

private:
    QStringList days;
    QDate date1;
    QDate date2;
    std::vector<unsigned int> strada1;
    std::vector<unsigned int> strada2;
};

#endif // BARCHARTMODEL_H