//
// Created by Dawid on 13/03/2023.
//

#ifndef ZBIORY_CONTAINER_H
#define ZBIORY_CONTAINER_H

class Container
{

public:
    Container (){};
    virtual int Count () const = 0;
    virtual bool IsEmpty () const {return Count()==0;}; virtual bool IsFull () const = 0;
    virtual void MakeNull() = 0;
};




#endif //ZBIORY_CONTAINER_H
