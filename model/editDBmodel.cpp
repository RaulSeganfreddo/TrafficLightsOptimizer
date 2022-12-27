#include "editDBmodel.h"

EditDBModel::EditDBModel(QDate data, QObject *parent) : QAbstractTableModel(parent)
{
    m_data = getGiorno(data);
}

EditDBModel::~EditDBModel()
{
}

QVariant EditDBModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
        case 0:
            return QString("Hour");
        case 1:
            return QString("Street 1");
        case 2:
            return QString("Street 2");
        default:
            return QVariant();
        }
    }

    if (orientation == Qt::Vertical) {
        return section + 1;
    }
    return QVariant();
}

int EditDBModel::rowCount(const QModelIndex &parent) const
{
    return 24;
}

int EditDBModel::columnCount(const QModelIndex &parent) const
{
    return 3;
}

QVariant EditDBModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole) {
        if (index.column() == 0) {
            if (QString::number(index.row()) < 10)
                return "0" + QString::number(index.row());
            else
                return QString::number(index.row());
        } else {
            return m_data.at(index.row() * 3 + index.column());
        }
    }
    return QVariant();
}

Qt::ItemFlags EditDBModel::flags(const QModelIndex& index) const
{
    if (index.column() == 0)
        return Qt::ItemIsEnabled;
    else
        return (Qt::ItemIsEnabled | Qt::ItemIsEditable);
}

bool EditDBModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role == Qt::EditRole) {
        if (index.column() == 1) {
            m_data.replace(index.row() * 3 + index.column(), value.toString());
            emit dataChanged(index, index);
            return true;
        } else if (index.column() == 2) {
            m_data.replace(index.row() * 3 + index.column(), value.toString());
            emit dataChanged(index, index);
            return true;
        }
    }
    return false;
}

void EditDBModel::setNewData(QDate data)
{
    m_data = getGiorno(data);
    emit dataChanged(index(0, 0), index(23, 2));
}

void EditDBModel::saveData(QDate data)
{
    setGiorno(data, m_data);
}