#ifndef ALGORITHMENCODING_H
#define ALGORITHMENCODING_H
#include "algorithm.h"
#include "codeword.h"


class AlgorithmEncoding: public Algorithm
{
public:
   //AlgorithmEncoding();
    virtual void nextStep() =0; //делает шаг вперед
    virtual void prevStep() =0; //делает шаг назад, пока не делает
    virtual void setData(QString data) =0; //устанавливает данные
    //virtual QList <CodeWord> getResult() =0; //возвращает реультат, но пока не возвращает
    //virtual Dictionary getDictionary() =0; //возвращает словарь, но пока не возвращает
    virtual QString getName()=0; //возвращает имя алгоритма
    virtual void start()=0; //функция готовит алгоритм к работе

    virtual void setPost(int i)=0; //функция устанавливает позицию в текущей строке!
    virtual int getPost ()=0;
    virtual QString getTextRezult() =0;
    virtual CodeWord getCode()=0;
    virtual QString getOneDict() =0;
    virtual QString getDescription() =0;
    virtual bool getOutFlag() =0;
    virtual QString getDictPrev() =0;
    virtual QString getOneCodeRes() =0;
    virtual bool getDictFlag() =0;
    virtual QString getOneDictWord() =0;
    virtual void initDict() =0;
    virtual bool errorFlag() =0;
};

#endif // ALGORITHMENCODING_H
