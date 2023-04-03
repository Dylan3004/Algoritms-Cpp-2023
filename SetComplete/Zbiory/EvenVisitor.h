//
// Created by Dawid on 26/03/2023.
//

#ifndef ZBIORY_EVENVISITOR_H
#define ZBIORY_EVENVISITOR_H
#include "Visitor.h"

class EvenVisitor: public Visitor<int>{

    int sum=0;

public:
    bool even ;
    void Visit(int element)
    {
        sum=element%2;
    }
    bool IsDone()
    {
        if(sum==1)
        {
            return true;
        }
        return false;
    }
    void SetSum()
    {
        sum=0;
    }
    void SetEven()
    {
        even= false;
    }
    void SetEvenTue()
    {
     even= true;
    }
    int GetSum()
    {
        return sum;
    }
    bool GetEven()
    {
        return even;
    }
};


#endif //ZBIORY_EVENVISITOR_H
