#ifndef CODEWORDLZW_H
#define CODEWORDLZW_H


class CodeWordLZW
{
public:
    int id;//он не нужен, но это чтобы оправдать наличие класса
    int code; //на самом деле вообще не вижу смысла в этом классе ибо для ЛЗВ это просто массив интов (номера в словаре, но раз надо то пусть будет)
    CodeWordLZW();
};

#endif // CODEWORDLZW_H
