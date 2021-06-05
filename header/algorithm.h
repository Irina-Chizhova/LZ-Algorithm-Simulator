#ifndef ALGORITHM_H
#define ALGORITHM_H
#include <QString>
#include "header/dictionary.h"

class Algorithm
{
public:
    virtual void start() =0;
    virtual QString getName() =0;
    virtual void nextStep() =0;
    virtual void prevStep() =0;
    virtual void setPosition(int i) =0;
    virtual int getPosition() =0;
    virtual void initDict() =0;
    virtual QString getOneDictWord() =0;
    virtual QString getDictPrev() =0;
    virtual QString getOneDict() =0;
    virtual QString getDescription() =0;
};

#endif // ALGORITHM_H
