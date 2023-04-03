//
// Created by Dawid on 27/03/2023.
//

#ifndef ZBIORY_ITERATOR_H
#define ZBIORY_ITERATOR_H

template<typename T>
class Iterator {
public:
    //virtual bool IsDone() const =0;
    //virtual T & operator*() const =0;
    virtual void operator++() =0;
};


#endif //ZBIORY_ITERATOR_H
