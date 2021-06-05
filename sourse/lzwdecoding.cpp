#include "header/lzwdecoding.h"
#include "QString"

LZWDecoding::LZWDecoding()
{

}

LZWDecoding::~LZWDecoding()
{

}

void LZWDecoding::doCodeToText(CodeWord code)
{
    in_str+=QString::number(code.index);
    in_str+=" ";
}

void LZWDecoding::setOneCode(CodeWord code)
{
    CodeWord buf;
    if (code.flag)
    {
        buf.index=code.index;
        in.push_back(buf);
        doCodeToText(buf);
    }
}

void LZWDecoding::nextStep()
{
    DataDict buf;

    if(post==0)
    {
        word+=dict[in[post].index-1].word;
        out += dict[in[post].index-1].word;
        one_word = dict[in[post].index-1].word;
        words.push_back(word);
    }
    else

    {
        out += dict[in[post].index-1].word;
        if (dict[in[post].index-1].word.length()>1)
        {
           word+=dict[in[post].index-1].word[0];
        }
        else
        {
            word+=dict[in[post].index-1].word;
        }
        buf.id=dict.size()+1;
        buf.word = word;
        dict.push_back(buf);

        one_dict.clear();
        one_dict+=QString::number(buf.id);
        one_dict+=": ";
        one_dict+=buf.word;

        dict_word=word;
        one_word = dict[in[post].index-1].word;

        word.clear();
        word += dict[in[post].index-1].word;
        words.push_back(word);

    }
}

QString LZWDecoding::getResult()
{
    return out;
}

QString LZWDecoding::getOneDict()
{
    return one_dict;
}

void LZWDecoding::initDict()
{
    DataDict buf;
    QString init="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPRSTUVWXYZабвгдеёжзийклмнопрстуфхцчшщъыьэюяАВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ1234567890,. !?:;-~";
    for (int i=0;i<init.length();i++)
    {
        buf.word.clear();
        buf.id=i+1;
        buf.word+=init[i];
        dict.push_back(buf);
    }
}

QString LZWDecoding::setIn()
{
    return in_str;
}

void LZWDecoding::start()
{
    in_str.clear();
    dict.clear();
    initDict();
    post=0;
    in.clear();
    out.clear();
    word.clear();
    one_dict.clear();
}

void LZWDecoding::doClearInForPrevStepEnc()
{
    if(in_str.length()==2)
        in_str.clear();
    else
    {in_str.chop(1);
    while (in_str[in_str.length()-1]!=' ')
        in_str.chop(1);

    in.pop_back();
    }
}

void LZWDecoding::prevStep()
{
    if(post>0)
    {
        if (post==1)
        {
            dict_word.clear();
            word.clear();
            dict_prev.clear();
            for(int b=0;b<dict.size();b++)
            {
                dict_prev+=QString::number(dict[b].id);
                dict_prev+=": ";
                dict_prev+=dict[b].word;
                dict_prev+="\n";
            }
            dict_prev.chop(1);
            post--;
        }
        else
        {
            dict.pop_back();
        dict_prev.clear();
        for(int b=0;b<dict.size();b++)
        {
            dict_prev+=QString::number(dict[b].id);
            dict_prev+=": ";
            dict_prev+=dict[b].word;
            dict_prev+="\n";
        }
        dict_prev.chop(1);

        if (post==2)
            out.chop(1);
        else
        out.chop(words.back().length());

        words.pop_back();
        word=words.back();
        post--;
}
    }


    if (post==0)
    {
        one_dict.clear();
        out.clear();
        dict_prev.clear();
        for(int b=0;b<dict.size();b++)
        {
            dict_prev+=QString::number(dict[b].id);
            dict_prev+=": ";
            dict_prev+=dict[b].word;
            dict_prev+="\n";
        }
        dict_prev.chop(1);
    }


}
