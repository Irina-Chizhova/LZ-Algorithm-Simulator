#ifndef ALGORITHMDECODING_H
#define ALGORITHMDECODING_H
#include "algorithm.h"
#include "codeword.h"
#include "QString"



class AlgorithmDecoding: public Algorithm
{
public:
    virtual void nextStep() =0;
    virtual void prevStep() =0;
    virtual void setData(QList <int> data) =0; //эту функцию удалить
    //virtual QList <int> getResult() =0;
    //virtual Dictionary getDictionary() =0;
    //virtual QString getName()=0;
    virtual void start() =0;
    virtual void forBetterView(CodeWord code) =0;
    virtual void setOneCode(CodeWord code) =0;
    virtual QString getResult() =0;
    virtual void setPost(int i) =0;
    virtual int getPost() =0;
    virtual QString setIn() =0;
    virtual QString getOneDict() =0;
    virtual void doClearInForPrevStepEnc() =0;
    virtual QString getDictPrev() =0;
    virtual QString getName() =0;
    virtual QString getOneDictWord() =0;
    virtual QString getOneWord() =0;

    virtual void initDict() =0;

};

#endif // ALGORITHMDECODING_H
