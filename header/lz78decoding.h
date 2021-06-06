#ifndef LZ78DECODING_H
#define LZ78DECODING_H
#include "header/algorithmdecoding.h"
#include "QList"
#include "header/codeword.h"
#include "header/datadict.h"

class LZ78Decoding: public AlgorithmDecoding
{
public:
     LZ78Decoding();

    void nextStep();
    void prevStep();
    void start();
    void doCodeToText(CodeWord code);
    void setOneCode(CodeWord code);
    void setPosition(int i);
    int getPosition();
    QString getResult();
    QString setIn();
    QString getOneDict();
    void doClearInForPrevStepEnc();
    QString getDictPrev();
    QString getOneDictWord();
    QString getOneWord();
    void initDict() {}
    QString getName(){return "LZ78";}
    QString getDescription() {return description;}

    ~LZ78Decoding();

private:
    QString out;
    QList <CodeWord> in;
    QString word;
    int post;
    QString in_for_text;
    QString in_dict;
    QList <DataDict> dictionary;
    QList <QString> words;
    QString dict_prev;
    QString one_word;
    QString one_dict;
    QString description;
    QList <QString> descr;
};

#endif // LZ78DECODING_H
