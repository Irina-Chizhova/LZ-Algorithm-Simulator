#ifndef DICTIONARY_H
#define DICTIONARY_H
#include "QString"

struct Node
{
    int id;
    QString word;
    Node *ptr;
};

class Dictionary
{
    Node *head;
    int count=0;

    Node* getFirst();
    Node* add(int id, QString word, Node*);
    void print();
    void clear();
    //поиск
    //следующий
    //предыдущий
    //вставить
public:

    Dictionary();
};

#endif // DICTIONARY_H
