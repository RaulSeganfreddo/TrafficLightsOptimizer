#ifndef EDITDBMODEL_H
#define EDITDBMODEL_H

#include "model.h"

#include <QAbstractTableModel>
#include <QDate>
#include <QMessageBox>

/*
 * @brief La classe EditDBModel si occupa di gestire i dati per la modifica del database attraverso la schermata editDBview
 */
class EditDBModel : public QAbstractTableModel, public Model
{
    Q_OBJECT

public:
    /*
     * @brief Costruttore della classe EditDBModel
     * @param data Data
     * @param parent Oggetto padre
     */
    explicit EditDBModel(QDate data, QObject *parent = nullptr);

    /*
     * @brief Distruzione della classe EditDBModel
     */
    ~EditDBModel();

    /*
     * @brief Override di headerData della classe QAbstractTableModel, gestisce gli header della tabella
     * @param section Sezione
     * @param orientation Orientamento
     * @param role Ruolo
     */
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    /*
     * @brief Override di rowCount della classe QAbstractTableModel, gestisce il numero di righe della tabella
     * @param parent Oggetto padre
     */
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    /*
     * @brief Override di columnCount della classe QAbstractTableModel, gestisce il numero di colonne della tabella
     * @param parent Oggetto padre
     */
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;


    /*
     * @brief Override di data della classe QAbstractTableModel, gestisce i dati della tabella
     * @param index Indice
     * @param role Ruolo
     */
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    /*
     * @brief Override di setData della classe QAbstractTableModel, gestisce la modifica dei dati della tabella
     * @param index Indice
     * @param value Valore
     * @param role Ruolo
     */
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    /*
     * @brief Override di flags della classe QAbstractTableModel, gestisce le flags della tabella
     * @param index Indice
     */
    Qt::ItemFlags flags(const QModelIndex& index) const override;

    /*
     * @brief Metodo che gestisce il cambio di giorno nel modello
     * @param date Data
     */
    void setNewData(QDate data);

    /*
     * @brief Metodo che salva i dati modificati nel database
     */
    void saveData(QDate data);

private:
    QStringList m_data;

};

#endif // EDITDBMODEL_H