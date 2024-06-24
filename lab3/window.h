#ifndef WINDOW_H
#define WINDOW_H
#include <QMainWindow>
#include <QtWidgets>
#include "counter.h"
#include "groupbytype.h"
#include "groupinfolders.h"
#include "filebrowserdatamodel.h"

class Window : public QMainWindow
{
public:
    Window(QWidget *parent = 0);
    QAbstractTableModel* fileDataModel;
    QFileSystemModel* dirModel;
    QTreeView* treeView;
    QTableView* tableView;
};

#endif // WINDOW_H
