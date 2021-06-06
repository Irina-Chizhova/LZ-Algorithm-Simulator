#include "header/lzw.h"
#include "vector"
#include "header/codeword.h"
#include "header/mainwindow.h"
#include "QList"
#include "header/datadict.h"

//#include "QMessageBox"

LZW::LZW()
{

}


LZW::~LZW()
{

}

void LZW::nextStep()
{

    bool flag=0;
    DataDict buf_dict;
    QString cur;
    StateLZW buf;
    int buf_prev;
    cur.clear();
    cur+=in[post];

    for (int i=0;i<dict.size();i++)
    {

        if (cur==dict[i].word)
        {
            flag=true;
            buf_prev=i+1;
            i=dict.size();

        }
    }

    if(!flag)
        error=true;
    else
    {
        flag=false;
        error=false;
        if(post==0)
        {
            buf.post=0;
            buf.prev=0;
            buf.out_flag=0;
            buf.dict_flag=0;
            states.push_back(buf);
            prev=buf_prev;
            word=dict[prev-1].word;
            one_dict="";
            code_word.flag=0;
            out_flag=0;
            dict_flag=0;
            description+="Текущий символ: ";
            description+= in[post];
            description+="\n\nПредыдущая последовательность: -\n\n";
            description+="Это первый шаг алгоритма, символ последовательности есть  в словаре. Словарь и выходной поток не обновляются, а текущий символ переностится в предыдущую последовательность.";
        }

        else
        {
            word+=in[post];
            for (int i=0;i<dict.size();i++)
            {
                if (word==dict[i].word)
                {
                   flag=true;
                   one_dict="";
                   code_word.flag=0;
                   out_flag=0;
                   dict_flag=0;
                   description.clear();
                   description+="Текущий символ: ";
                   description+= in[post];
                   description+="\n\nПредыдущая последовательность: ";
                   word.chop(1);
                   description+=word;
                   word+=in[post];
                   description+="\n\nПредыдущая последовательность и текущий символ есть в словаре. Словарь и выходной поток не обновляются. Текущий символ добавляется в предыдущую последовательность.";
                }
            }

            if (!flag)
                {
                    word.chop(1);
                    for (int i=0;i<dict.size();i++)
                    {
                        if (word==dict[i].word)
                        {
                            out_flag=1;
                            dict_flag=1;

                           one_dict.clear();
                           prev=i;
                           code_word.index=prev+1;
                           code_word.flag=true;
                           buf_dict.id=dict.size()+1;
                           word+=in[post];
                           buf_dict.word=word;
                           one_dict+=QString::number(buf_dict.id);
                           one_dict+=": ";
                           one_dict+=word;
                           dict.push_back(buf_dict);
                           out.push_back(code_word);
                           code_res=QString::number(prev+1);
                           outStr+=QString::number(prev+1);
                           outStr+=" ";
                           i=dict.size();
                           description.clear();
                           description+="Текущий символ: ";
                           description+=in[post];
                           description+="\n\nПредыдущая последовательность: ";
                           word.chop(1);
                           description+=word;
                           description+="\n\n Предыдущей последовательности и текущего слова нет в словаре. В словарь добавится слово ";
                           description+=buf_dict.word;
                           description+=" . В выходной поток будет добавлен номер предыдущего слова в словаре ";
                           description+= code_res;
                           description+=". Предыдущая последовательность очищается. Текущий символ добавляется в предыдущую последовательность.";
                           word.clear();
                           word+=in[post];


                        }
                    }
                }
        }
    }

    buf.descrption=description;
    buf.dict_flag=dict_flag;
    buf.out_flag=out_flag;
    buf.post=post+1;
    buf.prev=prev;
    buf.word=word;

    states.push_back(buf);
}

void LZW::prevStep()
{
    if(post>0)
    {

        if (dict_flag)
        {
            dict.pop_back();
            dict_prev.clear();
            for(int b=0;b<dict.size();b++)
              {  dict_prev+=QString::number(dict[b].id);
                dict_prev+=": ";
                dict_prev+=dict[b].word;
                dict_prev+="\n";
            }
            dict_prev.chop(1);
        }

        if (out_flag)
        {
            outStr.chop(1);
            if(outStr.length()==1)
            {
                out.pop_back();
                outStr.clear();
            }
            else
            {
                while (outStr[outStr.length()-1]!=' ')
                outStr.chop(1);
            out.pop_back();
            }
        }


            states.pop_back();

            word=states.back().word;
            description=states.back().descrption;
            post=states.back().post;
            prev=states.back().prev;

            dict_flag=states.back().dict_flag;
            out_flag=states.back().out_flag;


    }
    else
    {
        outStr.clear();
        description.clear();
        dict_prev.clear();
        for(int b=0;b<dict.size();b++)
          {  dict_prev+=QString::number(dict[b].id);
            dict_prev+=": ";
            dict_prev+=dict[b].word;
            dict_prev+="\n";
        }
        dict_prev.chop(1);
    }

}

void LZW::start()
{
    word.clear();
    out.clear();
    post=0;
    dict.clear();
    initDict();
    outStr.clear();
    out_flag=0;
}

QString LZW::getName()
{
    return "LZW";
}

void LZW::setData(QString data)
{
    in=data;
}

void LZW::initDict()
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

bool LZW::errorFlag()
{
    return error;
}

QString LZW::getTextRezult()
{
    return outStr;
}

QString LZW::getOneDict()
{
    return one_dict;
}

int LZW::getPosition()
{
    return post;
}

void LZW::setPosition(int i)
{
    post=i;
}


QString LZW::getDescription()
{
    return description;
}

bool LZW::getOutFlag()
{
    return out_flag;
}

QString LZW::getDictPrev()
{
    return dict_prev;
}

QString LZW::getOneCodeRes()
{
    return code_res;
}

bool LZW::getDictFlag()
{
    return dict_flag;
}

QString LZW::getOneDictWord()
{
    return dict.back().word;
}
