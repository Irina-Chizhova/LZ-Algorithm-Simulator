#ifndef LZ78DECODING_H
#define LZ78DECODING_H
#include "algorithmdecoding.h"
#include "QList"
#include "codeword.h"
#include "datadict.h"

class LZ78Decoding: public AlgorithmDecoding
{
public:
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

    LZ78Decoding();

    void nextStep();
    void prevStep();
    void setData(QList <int> data) {}
    //QList <int> getResult();
    //Dictionary getDictionary();
    //QString getName();
    void start();
    void forBetterView(CodeWord code);
    void setOneCode(CodeWord code);
    void setPost(int i);
    int getPost();
    QString getResult();
    QString setIn();
    QString getOneDict();
    void doClearInForPrevStepEnc();
    QString getDictPrev();
    QString getOneDictWord();
    QString getOneWord();
    void initDict() {}
    QString getName(){return "LZ78";}

    ~LZ78Decoding();
};

#endif // LZ78DECODING_H
