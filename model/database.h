#ifndef DATABASE_H
#define DATABASE_H

#include "model/record.h"

#include <QCoreApplication>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QDebug>

/*
 * @brief La classe Database si occupa di gestire il database
 */
class Database
{

public:
    /*
     * @brief Costruttore della classe Database
     */
    Database();

    /*
     * @brief Costruttore di copia profonda della classe Database
     */
    Database(const Database& other);

    /*
     * @brief Metodo che carica il database dal file .csv e lo trasforma in una lista di Record
     */
    void load();

    /*
     * @brief Metodo che salva il database su file .csv a partire dalla lista di Record
     */
    void save();

    /*
     * @brief Metodo che elimina tutti i record dalla lista di Record
     */
    void clearRecords();

    /*
     * @brief Metodo che aggiunge un Record alla lista di Record
     * @param record Record da aggiungere
     */
    void addRecord(Record *record);

    /*
     * @brief Metodo che rimuove un Record dalla lista di Record. Il record in se non viene rimosso, ma autoStrada1 e autoStrada2 vengono settate a 0
     * @param record Record da rimuovere
     */
    void removeRecord(Record *record);

    /*
     * @brief Metodo che restituisce la lista di Record
     * @return Lista di Record
     */
    std::list<Record*> getRecords();

    /*
     * @brief Metodo che copia la lista di Records e la salva con il metodo save()
     * @param records Lista di Record da settare
     */
    void setRecords(std::list<Record*> records);

    /*
     * @brief Metodo che restituisce il path del database
     * @return Path del database
     */
    std::string getDatabasePath();

private:
    std::string databasePath = QCoreApplication::applicationDirPath().toStdString() + "/db/database.csv";
    std::list<Record*> records;
};

#endif // DATABASE_H