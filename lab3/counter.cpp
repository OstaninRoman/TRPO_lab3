#include "counter.h"

QHash<QString, int> Counter::Calc(QDir d)
{
     return m_strategy->Calculate(d);
}
