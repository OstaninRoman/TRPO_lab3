#ifndef GROUPINFOLDERS_H
#define GROUPINFOLDERS_H
#include "counting.h"

class GroupInFolders : public Counting
{
public:
    GroupInFolders(){};
    QHash<QString, double> Calculate(QDir) override;
    double AttahedSize(QDir);
};

#endif // GROUPINFOLDERS_H
