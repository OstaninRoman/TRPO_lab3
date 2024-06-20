#include "groupbytype.h"

QHash<QString, int> GroupByType::Calculate(QDir d)
{
    QHash<QString, int> Hash;
    for(QFileInfo inf : d.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot)){
        if(inf.isDir()){
            QHash<QString, int> H;
            H = Calculate(inf.absoluteFilePath());
            Hash.insert(H);
        }
        else if(inf.isFile()){
            if(inf.size()/1024 < 30){
                Hash["others"] += inf.size()/1024;
            }
            else{
                if(Hash.contains(inf.suffix()))
                    Hash[inf.suffix()] += inf.size()/1024;
                else
                    Hash[inf.suffix()] = inf.size()/1024;
            }
        }
    }
    return Hash;
}
