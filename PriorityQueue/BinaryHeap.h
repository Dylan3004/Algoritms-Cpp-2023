//
// Created by Dawid on 06/03/2023.
//
#include <iostream>
#include <vector>
#include "PriorityQueue.h"
#include "Countainer.h"
using namespace std;
#ifndef UNTITLED1_BINARYHEAP_H
#define UNTITLED1_BINARYHEAP_H

template<typename T>
class BinaryHeap : public PriorityQueue<T>{
private:
    ~BinaryHeap()
    {

    }
    void Heapify(int rozmiar,int iterator)
    {
        int naj = iterator;
        int leftson = iterator *2+1;
        int rightson = iterator *2+2;

        if(rightson<rozmiar &&  data.at(rightson)<data.at(leftson))
        {
            naj=rightson;
        }
        if(leftson<rozmiar && data.at(leftson)<data.at(naj))
        {
            naj=leftson;
        }
        if(naj!=iterator)
        {
            T temp = data[naj];
            data[naj]=data[iterator];
            data[iterator]=temp;
            Heapify(rozmiar,naj);
        }
    }


protected:
    int count;
    vector<T> data;
public:
    explicit BinaryHeap(int n)
    {
        count=0;

        data.resize(n);

    }
    void MakeNull()
    {
        count=0;
    }

    void Enqueue (T element)
    {
        data[count]=element;
        int son_index = count ;
        int father_index = (son_index - 1) / 2;

        while (son_index > 0 &&  data[son_index] < data[father_index]) {
            T temp = data[son_index];
            data[son_index]=data[father_index];
            data[father_index]=temp;
            son_index = father_index;
            father_index = (son_index - 1) / 2;
        }
        count++;
    }

    T FindMin () const
    {
        return data[0];
    }



    T DequeueMin ()
    {
        T temp = data[count-1];
        data[count-1]=data[0];
        data[0]=temp;
        count--;
        Heapify(count,0);

    }

    bool IsEmpty () const
    {
        return count ==0;
    }

    bool IsFull() const
    {
        return count == data.size();
    }

    unsigned int Count() const {return count;}

    void wypisz()
    {
        cout << "Początek" << endl;
        int level = 0, state = 1, i = 0;
        while (i < count) {
            for (int j = 0; j < state && i < count; j++) {
                cout << " (#" << level << ")"<< data[i++] ;
            }
            cout << endl;
            level+=1;
            state *= 2;
        }
        cout << "Koniec" << endl;
    }

};


#endif //UNTITLED1_BINARYHEAP_H
