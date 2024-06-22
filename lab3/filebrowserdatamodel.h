#ifndef FILEBROWSERDATAMODEL_H
#define FILEBROWSERDATAMODEL_H
#include <QAbstractTableModel>
#include <QList>
#include "somedata.h"

class FileBrowserDataModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    FileBrowserDataModel (QObject *parent = nullptr, QList<SomeData> dt = QList<SomeData>());
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    private:
    enum NameColumn {
        NAME = 0,
        SIZE,
        PERCENT
        };
    QList<SomeData> dataModel;
};

#endif // FILEBROWSERDATAMODEL_H
