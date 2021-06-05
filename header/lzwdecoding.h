#ifndef LZWDECODING_H
#define LZWDECODING_H
#include <QString>
#include <QList>
#include <header/algorithmdecoding.h>
#include <header/datadict.h>
#include "header/codeword.h"

class LZWDecoding: public AlgorithmDecoding
{
public:

    void nextStep();
    void prevStep();
    QString getResult();
    //Dictionary getDictionary();
    //QString getName();
    void start();
    void doCodeToText(CodeWord code);
    void setOneCode(CodeWord code);
    void setPosition(int i){post=i;}
    int getPosition() {return post;}
    void doClearInForPrevStepEnc();
    QString setIn();
    QString getOneDict();
    QString getDictPrev() {return dict_prev;}
    QString getOneDictWord() {return dict_word;}
    QString getOneWord() {return one_word;}
    void initDict();
    QString getName(){return "LZW";}
    QString getDescription() {return description;}
    LZWDecoding();
    ~LZWDecoding();

private:
    QString out;
    QString in_str;
    QList <CodeWord> in;
    QList <DataDict> dict;
    int post;
    QString one_dict;
    QString word;
    QList <QString> words;
    QString dict_prev;
    QString one_word;
    QString dict_word;
    QString description;

};

#endif // LZWDECODING_H
