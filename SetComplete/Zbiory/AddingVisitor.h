//
// Created by Dawid on 17/03/2023.
//

#ifndef ZBIORY_ADDINGVISITOR_H
#define ZBIORY_ADDINGVISITOR_H
#include "Visitor.h"

class AddingVisitor : public Visitor<int>{

    int sum =0;
public:
    void Visit(int element)
    {
        sum+=element;
    }
    int GetSum()
    {
        return sum;
    }
    int SetSum(int num)
    {
        sum=num;
    }
    //metoda is done nie jest tutaj potrzebna poniewaz zliczanie nie ma elemrnu granicznego od ktorego przestajemy iterowac
};


#endif //ZBIORY_ADDINGVISITOR_H
