#include "groupinfolders.h"

QHash<QString, double> GroupInFolders::Calculate(QDir d)
{
    QHash<QString, double> Hash;
    double size = 0;
    for(QFileInfo inf : d.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot)){
        if(inf.isDir()){
            QHash<QString, double> H;
            H = Calculate(inf.absoluteFilePath());
            double size_t = 0;
            for(auto t : H.values())
                size_t += t;
            Hash.insert(inf.baseName(), size_t);
        }
        else if(inf.isFile()){
            size += inf.size()/1024;
        }
    }
    Hash.insert("Current Directory", size);
    return Hash;
}
