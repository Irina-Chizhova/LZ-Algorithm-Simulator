#ifndef LZ78_H
#define LZ78_H
#include <QString>
#include "algorithmencoding.h"
#include "codeword.h" //как именно я должна сделать сеттер если параметры разные без парсинга!
#include "QList"
#include "QString"
#include "datadict.h"
#include "statedata.h"

class LZ78: public AlgorithmEncoding
{
public:
    QString in;
    QList <CodeWord> out;
    QList <DataDict> dictionary;
    CodeWord code;
    QString rezult_for_text;
    int post;
    int post_dict;
    int code_size;
    bool flag;
    bool dict_flag;
    bool out_flag;
    QString word;
    QString in_dict;
    QString description;
    QList <StateData> state;
    QString dictPrev;
    QString code_res;

    LZ78(){}
    ~LZ78(){}

    void nextStep();
    void setData(QString data);
    QString getName(){return "LZ78";}
    void setPost(int i);
    int getPost();
    QString getTextRezult();
    void start();
    CodeWord getCode();
    void prevStep();
    QString getOneDict();
    QString getDescription();
    bool getOutFlag();
    QString getDictPrev();
    QString getOneCodeRes();
    bool getDictFlag();
    QString getOneDictWord();
    void initDict() {}
    bool errorFlag() {return false;}


};

#endif // LZ78_H
