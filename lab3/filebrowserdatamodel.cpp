#include "filebrowserdatamodel.h"

FileBrowserDataModel::FileBrowserDataModel(QObject *parent, QList<SomeData> dt):
    QAbstractTableModel(parent), dataModel(dt){}

int FileBrowserDataModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return dataModel.count();
}

int FileBrowserDataModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return PERCENT + 1;
}

QVariant FileBrowserDataModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || dataModel.count() <= index.row() ||
            (role != Qt::DisplayRole && role !=Qt::EditRole)){
        return QVariant ();
    }
    if (index.column () == 0) {
        return dataModel [index.row()].name;
    } else if (index.column () == 1) {
        return dataModel [index.row()].size;
    } else if (index.column() == 2) {
        return dataModel [index.row ()].prcent;
    }
}

QVariant FileBrowserDataModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt:: DisplayRole) {
        return QVariant ();
    }

    if (orientation == Qt::Vertical) {
        return section;
    }
    switch (section) {
        case NAME:
            return trUtf8 ("название");
        case SIZE:
            return trUtf8 ("Pазмеp");
        case PERCENT:
            return trUtf8 ("В продентаx");
    }

    return QVariant ();
}
