#ifndef COUNTING_H
#define COUNTING_H
#include <QHash>
#include <QDir>
#include <QFileInfo>
#include <QDebug>

class Counting
{
public:
    virtual QHash<QString, double> Calculate(QDir) =0;
};

#endif // COUNTING_H
