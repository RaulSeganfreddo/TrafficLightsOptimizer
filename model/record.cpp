#include "record.h"

Record::Record(QDate data, int ora, int autoStrada1, int autoStrada2) {
    this->data = data;
    this->ora = ora;
    this->autoStrada1 = autoStrada1;
    this->autoStrada2 = autoStrada2;
}

Record::Record() {
    this->data = QDate::currentDate();
    this->ora = QTime::currentTime().hour();
    this->autoStrada1 = 0;
    this->autoStrada2 = 0;
}

Record::~Record() = default;

const QDate &Record::getData() const {
    return data;
}

unsigned int Record::getOra() const {
    return ora;
}

QString Record::getOraString() const {
    return QString::number(ora);
}

unsigned int Record::getAutoStrada1() const {
    return autoStrada1;
}

unsigned int Record::getAutoStrada2() const {
    return autoStrada2;
}

void Record::setData(const QDate &data) {
    Record::data = data;
}

void Record::setOra(unsigned int ora) {
    Record::ora = ora;
}

void Record::setAutoStrada1(unsigned int autoStrada1) {
    Record::autoStrada1 = autoStrada1;
}

void Record::setAutoStrada2(unsigned int autoStrada2) {
    Record::autoStrada2 = autoStrada2;
}