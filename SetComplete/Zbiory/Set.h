//
// Created by Dawid on 13/03/2023.
//

#ifndef ZBIORY_SET_H
#define ZBIORY_SET_H
#include "Container.h"
#include "Visitor.h"


template <typename T>
class Set : public virtual Container {
protected:
    int count;
    int universeSize;
public:
    Set (int n) : universeSize (n) {}

    Set() {};

    int UniverseSize() const {return universeSize;} int Count() const {return count;};
    virtual void Insert (T element)=0;
    virtual bool IsMember (T element) const=0; virtual void Withdraw (T element)=0;};




#endif //ZBIORY_SET_H
