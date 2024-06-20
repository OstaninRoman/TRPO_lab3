#include "groupinfolders.h"

QHash<QString, int> GroupInFolders::Calculate(QDir d)
{
    QHash<QString, int> Hash;
    int size = 0;
    for(QFileInfo inf : d.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot)){
        if(inf.isDir()){
            QHash<QString, int> H;
            H = Calculate(inf.absoluteFilePath());
            Hash.insert(H);
        }
        else if(inf.isFile()){
            size += inf.size()/1024;
        }
    }
    Hash.insert(d.dirName(), size);
    return Hash;
}
