#include <QCoreApplication>
#include "counter.h"
#include "groupbytype.h"
#include "groupinfolders.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QDir dir("C:\\Test\\");
    Counter c = Counter(new GroupByType());
    qDebug() << c.Calc(dir);
    c.setStrategy(new GroupInFolders());
    qDebug() << c.Calc(dir);
    return a.exec();
}
