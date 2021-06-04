#include "lz78.h"

void LZ78::nextStep()
{
    int i;
    flag =0;
    DataDict buf;
    QString desc;
    StateData buf_state;

    word+=in[post];

    if (post==0)
    {
        buf_state.word.clear();
        buf_state.descrption="";
        buf_state.dict_flag=0;
        buf_state.out_flag=0;
        buf_state.post=0;
        buf_state.post_dict=0;
        state.push_back(buf_state);
        description.clear();
        code.letter.clear();
        in_dict.clear();
        code.index=0;
        code.letter+=in[post];
        code.flag=1;
        out.push_back(code);
        buf.id=1;
        buf.word=word;
        dictionary.push_back(buf);
        in_dict+=QString::number(buf.id);
        in_dict+=": ";
        in_dict+=word;
        description+="Префикс: \n";
        description+="Текущий символ: ";
        description+=code.letter;
        description+="\n";

        word.clear();
        post_dict=0;
        rezult_for_text+="<";
        rezult_for_text+=QString::number(code.index);
        rezult_for_text+=",";
        rezult_for_text+=code.letter;
        rezult_for_text+=">";
        code_res=rezult_for_text;
        description+="Кодовое слово: ";
        description+=rezult_for_text;
        description+="\n";
        description+="\nЭто первый шаг алгоритма. На данном шаге текущий символ заноситься в словарь, а на выход подается кодовое слово";
        flag=1;
        dict_flag=1;
        out_flag=1;

        buf_state.word=word;
        buf_state.descrption=description;
        buf_state.post=post+1;
        buf_state.post_dict=post_dict;
        buf_state.dict_flag=dict_flag;
        buf_state.out_flag=out_flag;

        state.push_back(buf_state);
        return;
    }
    for (i=0;i<dictionary.size();i++)
    {

        if(word==dictionary[i].word)
        {
            description.clear();
            in_dict.clear();
            post_dict=dictionary[i].id;
            flag=1;
            i=dictionary.size();
            code.flag=0;
            in_dict="";
            dict_flag=0;
            word.chop(1);
            description+="Префикс: ";
            description+=word;
            word+=in[post];
            description+="\n";
            description+="Текущий символ: ";
            description+=in[post];
            description+="\n";
            description+="\nНа данном шаге слово состоящее из префикса и текущего символа уже есть в словаре. Словарь и выходной поток остаются нетронутым, а префикс изменяется следующим образом ";
            description+=word;
            description+=".";
            out_flag=0;
        }
    }

    if (!flag)
    {
        code.letter.clear();
        code_res.clear();
        in_dict.clear();
        description.clear();
        code.index=post_dict;
        code.letter+=in[post];
        post_dict=0;
        buf.id=dictionary[dictionary.size()-1].id+1;
        buf.word=word;
        dictionary.push_back(buf);
        in_dict+=QString::number(buf.id);
        in_dict+=": ";
        in_dict+=word;
        out.push_back(code);
        word.chop(1);
        description+="Префикс: ";
        description+=word;
        description+="\n";
        description+="Текущий символ: ";
        description+=code.letter;
        description+="\n\nНа данном шаге в словаре не нашлось слова состояшего из префикса и текущего символа. В словарь заносим ";
        description+=buf.word;

        word.clear();

        desc+="<";
        desc+=QString::number(code.index);
        desc+=",";
        desc+=code.letter;
        desc+=">";
        code_res=desc;
        rezult_for_text+=desc;

        description+=", а в выходной поток ";
        description+=desc;
        description+=".";

        code.flag=1;
        dict_flag=1;
        out_flag=1;

    }

    buf_state.word=word;
    buf_state.descrption=description;
    buf_state.post=post+1;
    buf_state.post_dict=post_dict;
    buf_state.dict_flag=dict_flag;
    buf_state.out_flag=out_flag;

    state.push_back(buf_state);
}

void LZ78::prevStep()
{

    if(post>0)
    {

        if (dict_flag)
        {
            dictionary.pop_back();
            dictPrev.clear();
            for(int b=0;b<dictionary.size();b++)
              {  dictPrev+=QString::number(dictionary[b].id);
                dictPrev+=": ";
                dictPrev+=dictionary[b].word;
                dictPrev+="\n";
            }
            dictPrev.chop(1);
        }

        if (out_flag)
        {
            while (rezult_for_text[rezult_for_text.length()-1]!='<')
                rezult_for_text.chop(1);
            rezult_for_text.chop(1);
            out.pop_back();
        }


        state.pop_back();

            word=state.back().word;
            description=state.back().descrption;
            post=state.back().post;
            post_dict=state.back().post_dict;
            dict_flag=state.back().dict_flag;
            out_flag=state.back().out_flag;

    }
    else
    {
        rezult_for_text.clear();
        description.clear();
    }
    //спросить

}

void LZ78::setData(QString data)
{
    in=data;
}

void LZ78::setPost(int i)
{
    post=i;
}

int LZ78::getPost()
{
    return post;
}

QString LZ78::getTextRezult()
{
    return rezult_for_text;
}

void LZ78::start()
{
    out.clear();
    rezult_for_text.clear();
    post=0;
    post_dict=0;
    dictionary.clear();
    dictPrev.clear();
    word.clear();
    out_flag=0;
}

CodeWord LZ78::getCode()
{
    return code;
}

QString LZ78::getOneDict()
{
    return in_dict;
}

QString LZ78::getDescription()
{
    return description;
}

bool LZ78::getOutFlag()
{
    return out_flag;
}

QString LZ78::getDictPrev()
{
    return dictPrev;
}

QString LZ78::getOneCodeRes()
{
    return code_res;
}

bool LZ78::getDictFlag()
{
    return dict_flag;
}

QString LZ78::getOneDictWord()
{
    return dictionary.back().word;
}
