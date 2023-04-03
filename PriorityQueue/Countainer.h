//
// Created by Dawid on 06/03/2023.
//

#ifndef UNTITLED1_COUNTAINER_H
#define UNTITLED1_COUNTAINER_H


class Countainer {
    //virtual ~Countainer() {};
    virtual unsigned int Count() const = 0;
    virtual bool IsEmpty() const
    {
        return Count() ==0;
    }
    virtual bool IsFull() const {return false;}
    virtual  void MakeNull() = 0;


};


#endif //UNTITLED1_COUNTAINER_H
