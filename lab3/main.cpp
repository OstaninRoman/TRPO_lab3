#include <QCoreApplication>
#include "counter.h"
#include "groupbytype.h"
#include "groupinfolders.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QDir dir("..\\Test\\test4\\");
    Counting* strategyByType = new(std::nothrow) GroupByType();
    Counter c = Counter(strategyByType);
    QHash<QString, double>H1 = c.Calc(dir);
    for(auto h : H1.keys())
        qDebug() << h << "----" << H1[h];
    Counting* srategyInFolders = new(std::nothrow) GroupInFolders();
    c.setStrategy(srategyInFolders);
    qDebug() << " ";
    QHash<QString, double>H2 = c.Calc(dir);
    for(auto h : H2.keys())
        qDebug() << h << "----" << H2[h];
    return a.exec();
}
