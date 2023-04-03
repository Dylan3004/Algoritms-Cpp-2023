//
// Created by Dawid on 17/03/2023.
//

#ifndef ZBIORY_VISITOR_H
#define ZBIORY_VISITOR_H

template<typename T>
class Visitor {
public:
    virtual void Visit(T& element) {};
    virtual bool IsDone() const {return false;}
};


#endif //ZBIORY_VISITOR_H
