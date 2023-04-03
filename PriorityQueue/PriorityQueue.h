//
// Created by Dawid on 06/03/2023.
//

#ifndef UNTITLED1_PRIORITYQUEUE_H
#define UNTITLED1_PRIORITYQUEUE_H
#include "Countainer.h"
     template<typename T>
     class PriorityQueue : public Countainer{
     public:
         virtual ~ PriorityQueue(){};
         virtual void Enqueue (T element) =0;
         virtual T FindMin () const =0;
         virtual T DequeueMin () =0;


};


#endif //UNTITLED1_PRIORITYQUEUE_H
