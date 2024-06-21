#ifndef COUNTER_H
#define COUNTER_H
#include "counting.h"

class Counter
{
public:
    Counter(Counting* strategy):m_strategy(strategy){};
    QHash<QString, double> Calc(QDir );
    void setStrategy(Counting* strategy){
        m_strategy = strategy;
    };
private:
    Counting* m_strategy;
};

#endif // COUNTER_H
