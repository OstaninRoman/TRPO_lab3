#ifndef GROUPBYTYPE_H
#define GROUPBYTYPE_H
#include "counting.h"

class GroupByType : public Counting
{
public:
    GroupByType(){};
private:
    QHash<QString, double> Calculate(QDir) override;
};

#endif // GROUPBYTYPE_H
