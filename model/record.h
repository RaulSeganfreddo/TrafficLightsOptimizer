#ifndef RECORD_H
#define RECORD_H

#include <QDate>
#include <QString>

/*
 * @brief La classe Record rappresenta un record del database
 */
class Record {
private:
    QDate data;
    unsigned int ora;
    unsigned int autoStrada1;
    unsigned int autoStrada2;

public:
    /*
    * @brief Costruttore
    * @param data Data
    * @param ora Ora
    * @param autoStrada1 Numero di auto che hanno percorso la prima strada
    * @param autoStrada2 Numero di auto che hanno percorso la seconda strada
    */
    explicit Record(QDate data, int ora, int autoStrada1, int autoStrada2);

    /*
    * @brief Costruttore di default
    */
    explicit Record();

    /*
    * @brief Distruttore
    */
    ~Record();

    /*
    * @brief Metodo che restituisce la data
    * @return data
    */
    const QDate &getData() const;

    /*
    * @brief Metodo che restituisce l'ora
    * @return ora
    */
    unsigned int getOra() const;

    /*
     * @brief Metodo che restituisce l'ora in formato stringa
     * @return ora in formato stringa
     */
    QString getOraString() const;

    /*
    * @brief Metodo che restituisce il numero di auto che hanno percorso la prima strada
    * @return numero di auto che hanno percorso la prima strada
    */
    unsigned int getAutoStrada1() const;

    /*
    * @brief Metodo che restituisce il numero di auto che hanno percorso la seconda strada
    * @return numero di auto che hanno percorso la seconda strada
    */
    unsigned int getAutoStrada2() const;

    /*
    * @brief Metodo che permette di settare la data
    * @param data data
    */
    void setData(const QDate &data);

    /*
    * @brief Metodo che permette di settare l'ora
    * @param ora ora
    */
    void setOra(unsigned int ora);

    /*
    * @brief Metodo che permette di settare il numero di auto che hanno percorso la prima strada
    * @param autoStrada1 numero di auto che hanno percorso la prima strada
    */
    void setAutoStrada1(unsigned int autoStrada1);

    /*
    * @brief Metodo che permette di settare il numero di auto che hanno percorso la seconda strada
    * @param autoStrada2 numero di auto che hanno percorso la seconda strada
    */
    void setAutoStrada2(unsigned int autoStrada2);


};

#endif // RECORD_H