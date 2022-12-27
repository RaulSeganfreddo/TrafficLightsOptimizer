#include "database.h"

Database::Database()
{
}

Database::Database(const Database &other)
{
    // copia profonda di records
    for (auto it = other.records.begin(); it != other.records.end(); ++it)
    {
        records.push_back(new Record(**it));
    }
}

void Database::addRecord(Record *record)
{
    // se data e ora sono uguali cambio solo autoStrada1 e autoStrada2
    for (auto it = records.begin(); it != records.end(); ++it)
    {
        if ((*it)->getData() == record->getData() && (*it)->getOra() == record->getOra())
        {
            (*it)->setAutoStrada1(record->getAutoStrada1());
            (*it)->setAutoStrada2(record->getAutoStrada2());
            return;
        }
    }
    // altrimenti aggiungo il record in ordine di data e ora
    for (auto it = records.begin(); it != records.end(); ++it)
    {
        if ((*it)->getData() > record->getData() || ((*it)->getData() == record->getData() && (*it)->getOra() > record->getOra()))
        {
            records.insert(it, record);
            return;
        }
    }
    records.push_back(record);
}

void Database::removeRecord(Record *record)
{
    for (auto it = records.begin(); it != records.end(); ++it)
    {
        if ((*it)->getData() == record->getData() && (*it)->getOra() == record->getOra())
        {
            (*it)->setAutoStrada1(0);
            (*it)->setAutoStrada2(0);
        }
    }
}

void Database::load()
{
    // svota la lista records
    clearRecords();

    QFile file(QString::fromStdString(databasePath));
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(0, "Warning", "Database file not found!");
        return;
    }
    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        // trasforma il fields[0] in una data
        QDate date = QDate::fromString(fields[0], "dd/MM/yyyy");
        // trasforma il fields[1] in un int
        int ora = fields[1].toInt();
        // trasforma il fields[2] in un int
        int auto1 = fields[2].toInt();
        // trasforma il fields[3] in un int
        int auto2 = fields[3].toInt();
        // crea un nuovo record
        Record* record = new Record(date, ora, auto1, auto2);
        // aggiunge il record alla lista
        records.push_back(record);
    }
    file.close();
}

void Database::save()
{
    std::string databasePath = QCoreApplication::applicationDirPath().toStdString() + "/db/database.csv";
    // elimina il file .csv se esiste
    QFile::remove(databasePath.c_str());
    // crea un nuovo file .csv
    QFile file(databasePath.c_str());
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::warning(0, "Warning", "Database file not found!");
        return;
    }
    // salva i record nel file .csv
    QTextStream out(&file);
    for (Record* record : Database::records)
    {
        out << record->getData().toString("dd/MM/yyyy") << "," 
            << record->getOra() << "," 
            << record->getAutoStrada1() << "," 
            << record->getAutoStrada2() << endl;
    }
    file.close();
}

void Database::clearRecords()
{
    // cicla la lista records e elimina ogni record
    for (auto it = records.begin(); it != records.end(); ++it)
    {
        delete *it;
    }
}

std::string Database::getDatabasePath()
{
    return databasePath;
}

std::list<Record*> Database::getRecords()
{
    std::list<Record*> recordsCopy;
    // copia profonda di records
    for (auto it = records.begin(); it != records.end(); ++it)
    {
        recordsCopy.push_back(new Record(**it));
    }
    return recordsCopy;
}

void Database::setRecords(std::list<Record*> records)
{
    // svota la lista records
    clearRecords();
    // copia profonda di records
    for (auto it = records.begin(); it != records.end(); ++it)
    {
        this->records.push_back(new Record(**it));
    }
    save();
}