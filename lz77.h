#ifndef LZ77_H
#define LZ77_H
#include <QString>
#include "algorithmencoding.h"
#include "codeword.h"

class LZ77: public AlgorithmEncoding
{
public:
    QString in;
    QString out;
    CodeWord code_word;
    LZ77() {}
    ~LZ77(){}

    void nextStep(){}
    void setData(QString data){}
    QString getName(){return "LZ77";}
    void start(){}
    void prevStep() {}

    //QList <CodeWord> getResult() ;
    //Dictionary getDictionary();

    int getPost() {return 0;}
    void setPost(int i){}
    CodeWord getCode () {return code_word;}
    QString getTextRezult(){return "Rezult";}
    QString getOneDict() {return "dict";}
    QString getDescription() {return "desc";}
    bool getOutFlag() {return false;}
    QString getDictPrev() {return "dictPrev";}
    QString getOneCodeRes() {return "code";}
    bool getDictFlag() {return true;}
    QString getOneDictWord() {return "word";}
    void initDict() {}
    bool errorFlag() {return false;}

};

#endif // LZ77_H
