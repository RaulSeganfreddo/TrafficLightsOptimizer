#include "model.h"

Model::Model()
{
    database = new Database();
    database->load();
}

Model::~Model()
{
    delete database;
}

unsigned int Model::autoGiorno(unsigned int index, QDate giorno, unsigned int oraIni, unsigned int oraFin)
{
    unsigned int autoTot = 0;
    std::list<Record*> records = database->getRecords();
    for (auto it = records.begin(); it != records.end(); ++it)
    {
        if ((*it)->getData() == giorno && (*it)->getOra() >= oraIni && (*it)->getOra() <= oraFin)
        {
            if (index == 1)
            {
                autoTot += (*it)->getAutoStrada1();
            }
            if (index == 2)
            {
                autoTot += (*it)->getAutoStrada2();
            }
        }
    }
    records.clear();
    return autoTot;
}

unsigned int Model::ottimizzazioneOra(unsigned int index, QDate giorno, unsigned int ora)
{
    unsigned int ottimizzazione = 0;
    float percentuale = 0;
    unsigned int somma = 0;
    std::list<Record*> records = database->getRecords();
    for (auto it = records.begin(); it != records.end(); ++it)
    {
        if ((*it)->getData() == giorno && (*it)->getOra() == ora)
        {
            somma = (*it)->getAutoStrada1() + (*it)->getAutoStrada2();
            if (index == 1)
            {
                percentuale = (float)(*it)->getAutoStrada1() / somma;
                if (percentuale > 0.95)
                    percentuale = 0.95;
                if (percentuale < 0.05)
                    percentuale = 0.05;
                ottimizzazione = percentuale * 300;
                return ottimizzazione;
            }
            if (index == 2)
            {
                percentuale = (float)(*it)->getAutoStrada2() / somma;
                if (percentuale > 0.95)
                    percentuale = 0.95;
                if (percentuale < 0.05)
                    percentuale = 0.05;
                ottimizzazione = percentuale * 300;
                return ottimizzazione;
            }
        }
    }
}

#if 0

unsigned int Model::autoGiorni(unsigned int index, QDate giornoIni, QDate giornoFin, unsigned int oraIni, unsigned int oraFin)
{
    unsigned int autoTot = 0;
    std::list<Record*> records = database->getRecords();
    for (auto it = records.begin(); it != records.end(); ++it)
    {
        if ((*it)->getData() >= giornoIni && (*it)->getData() <= giornoFin && (*it)->getOra() >= oraIni && (*it)->getOra() <= oraFin)
        {
            if (index == 1)
            {
                autoTot += (*it)->getAutoStrada1();
            }
            if (index == 2)
            {
                autoTot += (*it)->getAutoStrada2();
            }
        }
    }
    records.clear();
    return autoTot;
}

#endif

unsigned int Model::autoGiorni(unsigned int index, QDate giornoIni, QDate giornoFin, unsigned int oraIni, unsigned int oraFin) {
    unsigned int autoTot = 0;
    QDate dataIni = giornoIni;
    while (dataIni <= giornoFin)
    {
        autoTot += autoGiorno(index, dataIni, oraIni, oraFin);
        dataIni = dataIni.addDays(1);
    }
    return autoTot;
}

QStringList Model::getGiorno(QDate giorno)
{
    QStringList list;
    bool trovato = false;
    std::list<Record*> records = database->getRecords();
    for (auto it = records.begin(); it != records.end(); ++it)
    {
        if ((*it)->getData() == giorno)
        {
            trovato = true;
            list.append((*it)->getOraString());
            list.append(QString::number((*it)->getAutoStrada1()));
            list.append(QString::number((*it)->getAutoStrada2()));
        }
    }
    if (!trovato)
    {
        for (int i = 0; i < 24*3; i++)
        {
            list.append("");
        }
    }
    records.clear();
    return list;
}

void Model::setGiorno(QDate data, QStringList lista)
{
    std::list<Record*> records = database->getRecords();
    for (auto it = records.begin(); it != records.end(); ++it)
    {
        if ((*it)->getData() == data)
        {
            database->removeRecord(*it);
        }
    }
    records.clear();

    QString zero = "0";
    QString ora;
    unsigned int lenght = lista.length();

    for (int j = 0; j<24*3; j+=3){
        ora = QString::number(j/3);
        if (lista.at(j) == "")
            lista.replace(j, ora);
        if (lista.at(j+1) == "")
            lista.replace(j+1, zero);
        if (lista.at(j+2) == "")
            lista.replace(j+2, zero);
        if (j >= lenght/3)
        {
            lista.append(ora);
            lista.append(zero);
            lista.append(zero);
        }
    }

    for (int i = 0; i < 24; i++)
    {
        Record* record = new Record(data, lista.at(i*3).toInt(), lista.at(i*3+1).toInt(), lista.at(i*3+2).toInt());
        database->addRecord(record);
    }
    database->save();
}


bool Model::dateCheck(QDate data1, QDate data2)
{
    // controllo nel database se esistono le date comprese tra data1 e data2
    // se esistono ritorno true altrimenti false
    Database* db = new Database();
    db->load();
    std::list<Record*> records = db->getRecords();
    bool ok = false;
    QDate temp = data1;

    if (data1 > data2)
    {
        QMessageBox::warning(nullptr, "Errore", "La data di inizio deve essere precedente alla data di fine");
        db->clearRecords();
        return false;
    }

    while (temp <= data2)
    {
        for (auto it = records.begin(); it != records.end(); ++it)
        {
            if ((*it)->getData() == temp)
            {
                ok = true;
                break;
            }
        }
        if (!ok)
        {
            if (data1 == data2)
            {
                QMessageBox::warning(nullptr, "Errore", "Non esiste nessun dato per la data selezionata");
                db->clearRecords();
                return false;
            }
            QMessageBox::warning(nullptr, "Errore", "Non esiste nessun dato per una o più date nel range di date selezionate");
            db->clearRecords();
            return false;

        }
        temp = temp.addDays(1);
        ok = false;
    }
    db->clearRecords();
    return true;
}

bool Model::formatCheck(QString data)
{
    // controllo che la data sia nel formato gg/mm/aaaa
    // se è nel formato corretto ritorno true altrimenti false
    if (data.length() != 10)
        return false;
    if (data.at(2) != '/' || data.at(5) != '/')
        return false;
    if (data.at(0).isDigit() && data.at(1).isDigit() && data.at(3).isDigit() && data.at(4).isDigit() && data.at(6).isDigit() && data.at(7).isDigit() && data.at(8).isDigit() && data.at(9).isDigit())
        return true;
    return false;
}