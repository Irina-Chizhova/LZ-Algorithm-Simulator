#ifndef LZ77DECODING_H
#define LZ77DECODING_H
#include <algorithmdecoding.h>
#include "QList"
#include "codeword.h"

class LZ77Decoding: public AlgorithmDecoding
{
public:
   QString out;
   QList <CodeWord> in; //это вообще очень спорный момент только потому что кодовое слово это номер в словаре
   QString word;
   int post;

   LZ77Decoding();
   void nextStep(){}
   void prevStep(){}

   void setData(QList <int> data) {}
   QString getResult() {return "result";}
   //Dictionary getDictionary();
   //QString getName();
   void start() {}
   void forBetterView(CodeWord code){}
   void setOneCode(CodeWord code){}
   void setPost(int i){post=i;}
   int getPost() {return post;}
   QString setIn() {return "LZ77";}
   QString getOneDict() {return "LZ77Dict";}
   void doClearInForPrevStepEnc(){}
   QString getDictPrev() {return "dictPrev";}
   QString getOneDictWord() {return "dictWord";}
   QString getOneWord() {return "word";}
   void initDict() {}
   QString getName(){return "LZ77";}
   ~LZ77Decoding();
};

#endif // LZ77DECODING_H
