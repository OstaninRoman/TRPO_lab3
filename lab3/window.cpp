#include "window.h"

Window::Window(QWidget *parent):QMainWindow(parent)
{

    QList<SomeData> someDataModel;
    QDir dir("C:\\Qt\\Examples\\TRPO_lab3\\Test\\");
    Counting* strategyByType = new(std::nothrow) GroupByType();
    Counter c = Counter(strategyByType);
    QHash<QString, double>H1 = c.Calc(dir);
    for(auto h : H1.keys()){
        QString str;
        str.setNum(H1[h]);
        someDataModel.append(SomeData(h, str, "%?"));
    }

    fileDataModel = new(std::nothrow) FileBrowserDataModel(nullptr, someDataModel);
    tableView = new QTableView;
    tableView->setModel(fileDataModel);

    dirModel = new QFileSystemModel(this);
    dirModel->setRootPath(dir.absolutePath());
    treeView = new QTreeView;
    treeView->setModel(dirModel);
    treeView->show();

    /*
    Counting* srategyInFolders = new(std::nothrow) GroupInFolders();
    c.setStrategy(srategyInFolders);
    qDebug() << " ";
    QHash<QString, double>H2 = c.Calc(dir);
    for(auto h : H2.keys())
        qDebug() << h << "----" << H2[h];
    */
}
