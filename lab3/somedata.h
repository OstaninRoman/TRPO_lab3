#ifndef SOMEDATA_H
#define SOMEDATA_H
#include <QString>

class SomeData
{
public:
    SomeData(QString nm = "SomeName",
             QString sz = "SomeSize",
             QString prc = "SomePercent")
    {
        name = nm;
        size = sz;
        prcent = prc;
    };
    QString name, size, prcent;
};

#endif // SOMEDATA_H
