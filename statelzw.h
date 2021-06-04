#ifndef STATELZW_H
#define STATELZW_H
#include "QString"
#endif // STATELZW_H

struct StateLZW
{
    QString word;
    QString descrption;
    int post;
    int prev;
    bool dict_flag;
    bool out_flag;
};
