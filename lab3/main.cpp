#include <QCoreApplication>
#include "counter.h"
#include "groupbytype.h"
#include "groupinfolders.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QDir dir("..\\Test\\test3\\");
    Counting* strategyByType = new(std::nothrow) GroupByType();
    Counter c = Counter(strategyByType);
    QHash<QString, double>H1 = c.Calc(dir);
    double t = 0;
    for(auto h : H1.keys())
        t += H1[h];
    QHash<QString, double>prst1;
    for(auto h : H1.keys()){
        prst1.insert(h, (H1[h]*100/t));
        qDebug() << h << "----" << H1[h] << "----" << prst1[h];
    }
    qDebug() << " ";
    Counting* srategyInFolders = new(std::nothrow) GroupInFolders();
    c.setStrategy(srategyInFolders);
    QHash<QString, double>H2 = c.Calc(dir);
    t = 0;
    for(auto h : H2.keys())
        t += H2[h];
    QHash<QString, double>prst2;
    for(auto h : H2.keys()){
        if(t)
            prst2.insert(h, (H2[h]*100/t));
        else
            prst2.insert(h, t);
        qDebug() << h << "----" << H2[h] << "----" << prst2[h];
        }
    return a.exec();
}
