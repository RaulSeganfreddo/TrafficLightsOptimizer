#ifndef MODEL_H
#define MODEL_H

#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <list>
#include <QDebug>

#include "model/database.h"
#include "model/record.h"

/*
 * @brief La classe Model si occupa di gestire i dati
 */
class Model
{
private:
    Database *database;

public:
    /*
     * @brief Costruttore della classe Model
     */
    explicit Model();

    /*
     * @brief Distruzione della classe Model
     */
    ~Model();

    /*
     * @brief Metodo che restituisce il numero di auto passate un certo giorno da una certa ora ad una certa ora
     * @param index Indice della strada, 1 se strada1, 2 se strada2
     * @param giorno Giorno
     * @param oraInizio Ora inizio
     * @param oraFine Ora fine
     */
    unsigned int autoGiorno(unsigned int index, QDate giorno, unsigned int oraIni, unsigned int oraFin);

    /*
     * @brief Metodo che restituisce l'ottimizzazione in secondi in una certa ora
     * @param index Indice della strada, 1 se strada1, 2 se strada2
     * @param giorno Giorno
     * @param ora Ora
     */
    unsigned int ottimizzazioneOra(unsigned int index, QDate giorno, unsigned int ora);

    /*
     * @brief Metodo che restituisce l'ottimizzazione in secondi in un certo giorno
     * @param index Indice della strada, 1 se strada1, 2 se strada2
     * @param giornoIni Giorno inizio
     * @param giornoFin Giorno fine
     * @param oraIni Ora inizio
     * @param oraFin Ora fine
     */
    unsigned int autoGiorni(unsigned int index, QDate giornoIni, QDate giornoFin, unsigned int oraIni, unsigned int oraFin);

    /*
     * @brief Metodo che restitiusce i record di un giorno in formato QStringList. Se quel giorno non è nel database
     *        restituisce una lista vuota
     * @param giorno Giorno
     */
    QStringList getGiorno(QDate giorno);

    /*
     * @brief Metodo che, presa una lista di record in formato QStringList, la trasforma in una lista di Record
     *        e salva i record nel database
     */
    void setGiorno(QDate data, QStringList lista);

    /*
     * @brief Controlla se le date presenti nel range esistono nel database
     * @param data1 Data inizio
     * @param data2 Data fine
     * @return true se esistono, false altrimenti
     */
    static bool dateCheck(QDate data1, QDate data2);

    /*
     * @brief Controlla se la data è nel formato corretto
     */
    static bool formatCheck(QString data);
};

#endif // MODEL_H