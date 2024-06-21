#include <QCoreApplication>
#include "counter.h"
#include "groupbytype.h"
#include "groupinfolders.h"
#include <QTextStream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QDir dir("C:\\Qt\\Examples\\TRPO\\TRPO_lab3\\Test\\test4\\");
    Counter c = Counter(new(std::nothrow) GroupByType());
    QHash<QString, double>H1 = c.Calc(dir);
    for(auto h : H1.keys())
        qDebug() << h << "----" << H1[h];
    c.setStrategy(new(std::nothrow) GroupInFolders());
    qDebug() << " ";
    QHash<QString, double>H2 = c.Calc(dir);
    for(auto h : H2.keys())
        qDebug() << h << "----" << H2[h];
    return a.exec();
}
