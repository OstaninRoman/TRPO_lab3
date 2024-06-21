#include "groupinfolders.h"

QHash<QString, double> GroupInFolders::Calculate(QDir d)
{
    QHash<QString, double> Hash;
    double size = 0;
    for(QFileInfo inf : d.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot)){
        if(inf.isDir()){
            double size_t = AttahedSize(inf.absoluteFilePath());
            Hash.insert(inf.baseName(), size_t);
        }
        else if(inf.isFile()){
            size += inf.size()/1024;
        }
    }
    Hash.insert("Current Directory", size);
    return Hash;
}

double GroupInFolders::AttahedSize(QDir d)
{
    double size = 0;
    for(QFileInfo inf : d.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot)){
        if(inf.isDir()){
            double size_t = AttahedSize(inf.absoluteFilePath());
            size += size_t;
        }
        else if(inf.isFile()){
            size += inf.size()/1024;
        }
    }
    return size;
}
