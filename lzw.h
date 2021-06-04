#ifndef LZW_H
#define LZW_H
#include <QString>
#include "algorithmencoding.h"
#include "codeword.h"
#include "vector"
#include "datadict.h"
#include <QList>
#include <statelzw.h>
#include "statedata.h"

class LZW: public AlgorithmEncoding

{
public:
    LZW();
    void nextStep();
    void setData(QString data);
    QString getName();
    void start();
    void prevStep();
    QList <CodeWord> getResult() ;
    Dictionary getDictionary();
    int getPost();
    void setPost(int i);
    QString getTextRezult();
    CodeWord getCode() {return code_word;}
    QString getOneDict();
    QString getDescription();
    ~LZW();

    QString in;
    int post;
    int prev;
    QString word;
    CodeWord code_word;
    QList <CodeWord> out;
    QString outStr;
    QList <DataDict> dict;
    bool error;
    QString one_dict;
    QString description;
    bool out_flag;
    bool dict_flag;
    QString code_res;
    QString dict_prev;
    QList <StateLZW> states;
    //QList <StateData> states;


    bool getOutFlag();
    QString getDictPrev();
    QString getOneCodeRes();
    bool getDictFlag();
    QString getOneDictWord();
    void initDict();
    bool errorFlag();

};

#endif // LZW_H
