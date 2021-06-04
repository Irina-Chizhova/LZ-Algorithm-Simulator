#ifndef ALGORITHM_H
#define ALGORITHM_H
#include <QString>
#include "dictionary.h"

class Algorithm
{
public:

    //virtual void stop() =0;
    virtual void start() =0;
    virtual QString getName() =0;
    //Функция декодинга?
    //virtual void decoding() =0;
    //virtual void setNewStepInTable()=0;
};

#endif // ALGORITHM_H
