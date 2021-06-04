#ifndef LZWDECODING_H
#define LZWDECODING_H
#include <QString>
#include <QList>
#include <algorithmdecoding.h>
#include <datadict.h>
#include "codeword.h"

class LZWDecoding: public AlgorithmDecoding
{
public:

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

    void nextStep();
    void prevStep();
    void setData(QList <int> data) {}
    QString getResult();
    //Dictionary getDictionary();
    //QString getName();
    void start();
    void forBetterView(CodeWord code);
    void setOneCode(CodeWord code);
    void setPost(int i){post=i;}
    int getPost() {return post;}
    void doClearInForPrevStepEnc();
    QString setIn();
    QString getOneDict();
    QString getDictPrev() {return dict_prev;}
    QString getOneDictWord() {return dict_word;}
    QString getOneWord() {return one_word;}
    void initDict();
    QString getName(){return "LZW";}
    LZWDecoding();
    ~LZWDecoding();

};

#endif // LZWDECODING_H
