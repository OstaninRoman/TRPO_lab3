#ifndef GROUPBYTYPE_H
#define GROUPBYTYPE_H
#include "counting.h"

class GroupByType : public Counting
{
public:
    GroupByType(){};
    QHash<QString, int> Calculate(QDir) override;
};

#endif // GROUPBYTYPE_H
