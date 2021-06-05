#ifndef ALGORITHMDECODING_H
#define ALGORITHMDECODING_H
#include "header/algorithm.h"
#include "header/codeword.h"
#include "QString"



class AlgorithmDecoding: public Algorithm
{
public:

    virtual void start() =0;
    virtual void doCodeToText(CodeWord code) =0;
    virtual void setOneCode(CodeWord code) =0;
    virtual QString getResult() =0;
    virtual QString setIn() =0;
    virtual void doClearInForPrevStepEnc() =0;
    virtual QString getOneWord() =0;

};

#endif // ALGORITHMDECODING_H
