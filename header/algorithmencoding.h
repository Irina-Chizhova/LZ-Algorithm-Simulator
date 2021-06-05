#ifndef ALGORITHMENCODING_H
#define ALGORITHMENCODING_H
#include "header/algorithm.h"
#include "header/codeword.h"


class AlgorithmEncoding: public Algorithm
{
public:    
    virtual void setData(QString data) =0; //устанавливает данные
    virtual QString getTextRezult() =0;
    virtual CodeWord getCode()=0;
    virtual bool getOutFlag() =0;
    virtual QString getOneCodeRes() =0;
    virtual bool getDictFlag() =0;
    virtual bool errorFlag() =0;
};

#endif // ALGORITHMENCODING_H
