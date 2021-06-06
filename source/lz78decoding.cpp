#include "header/lz78decoding.h"

LZ78Decoding::LZ78Decoding()
{

}

LZ78Decoding::~LZ78Decoding()
{

}

void LZ78Decoding::doCodeToText(CodeWord code)
{
    in_for_text+="<";
    in_for_text+=QString::number(code.index);
    in_for_text+=",";
    in_for_text+=code.letter;
    in_for_text+=">";
}

void LZ78Decoding::setOneCode(CodeWord code)
{
    CodeWord buf;
    if (code.flag)
    {
        buf.index=code.index;
        buf.letter=code.letter;
        in.push_back(buf);
        doCodeToText(buf);
    }
}

void LZ78Decoding::nextStep()
{
    DataDict buf;
    if (in[post].index==0)
    {
        description=" ";
        descr.push_back(description);
        buf.word.clear();
        in_dict.clear();
        buf.id=dictionary.size()+1;
        buf.word=in[post].letter;
        dictionary.push_back(buf);
        out+=in[post].letter;
        one_word=in[post].letter;
        in_dict+=QString::number(buf.id);
        in_dict+=": ";
        in_dict+=buf.word;
        one_dict=buf.word;
        words.push_back(buf.word);
        description.clear();
        description+="Добавить в словарь: ";
        description+=word;
        description+="\n\nДобавить в результат: ";
        description+=in[post].letter;

    }
    else
    {
        buf.word.clear();
        word.clear();
        in_dict.clear();
        buf.id=dictionary.size()+1;
        word+=dictionary[in[post].index-1].word;
        word+=in[post].letter;
        buf.word=word;
        dictionary.push_back(buf);
        out+=word;
        in_dict+=QString::number(buf.id);
        in_dict+=": ";
        in_dict+=word;
        one_dict=word;
        one_word=word;
        words.push_back(word);
        description.clear();
        description+="Добавить в словарь: ";
        description+=word;
        description+="\n\nДобавить в результат: ";
        description+=in[post].letter;
    }
    descr.push_back(description);
}

void LZ78Decoding::prevStep()
{
    if(post>0)
    {
        dictionary.pop_back();
        dict_prev.clear();
        for(int b=0;b<dictionary.size();b++)
        {
            dict_prev+=QString::number(dictionary[b].id);
            dict_prev+=": ";
            dict_prev+=dictionary[b].word;
            dict_prev+="\n";
        }
        dict_prev.chop(1);
        out.chop(words.back().length());
        words.pop_back();
        descr.pop_back();
        description=descr.back();
        post--;
    }
}

int LZ78Decoding::getPosition()
{
    return post;
}

void LZ78Decoding::setPosition(int i)
{
    post=i;
}

QString LZ78Decoding::getResult()
{
    return out;
}

QString LZ78Decoding::setIn()
{
    return in_for_text;
}

QString LZ78Decoding::getOneDict()
{
    return in_dict;
}

void LZ78Decoding::start()
{
    in_for_text.clear();
    out.clear();
    word.clear();
    in_dict.clear();
    dictionary.clear();
    post=0;
    in.clear();
}

void LZ78Decoding::doClearInForPrevStepEnc()
{
    while (in_for_text[in_for_text.length()-1]!='<')
        in_for_text.chop(1);
    in_for_text.chop(1);

    in.pop_back();
}

QString LZ78Decoding::getDictPrev()
{
    return dict_prev;
}

QString LZ78Decoding::getOneDictWord()
{
    return one_dict;
}

QString LZ78Decoding::getOneWord()
{
    return one_word;
}
