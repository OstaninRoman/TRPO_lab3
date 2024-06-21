#include "counter.h"

QHash<QString, double> Counter::Calc(QDir d)
{
    if(m_strategy)
        return m_strategy->Calculate(d);
    qWarning("strategy == nullptr");
    return QHash<QString, double>{} ;
}
