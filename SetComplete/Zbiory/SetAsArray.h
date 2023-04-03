//
// Created by Dawid on 13/03/2023.
//

#ifndef ZBIORY_SETASARRAY_H
#define ZBIORY_SETASARRAY_H
#include "Set.h"
#include <vector>
#include <iostream>
#include "AddingVisitor.h"
#include "Iterator.h"
#include "EvenVisitor.h"
using namespace std;
class SetAsArray : public Set<int>
{
    vector<bool> array;
public:
    class Iter: public Iterator<int>
    {
        vector<bool> data;
        int US;
        int pozition =0;
        int getter;
    public:
//        bool First() {
//            if (data.empty()) {
//                throw std::logic_error("Vector jest pusty");
//            }
//            return data[0];
//        }


        int GetPozition()
        {
            return pozition;
        }
        vector<bool> Getvec()
        {
            return data;
        }
        Iter(vector<bool> vec ,int num)
        {
            this->data=vec;
            this->US=num;
        }
        bool IsDone(int num)
        {
            if( pozition<data.size())
            {
                return false;
            } else
            {
                return true;
            }
        }
        int & operator*()
        {
            return getter;
        }
        void operator++()
        {
            pozition++;
            if(pozition==data.size())
                return;
                if(data.at(pozition))
                    getter=pozition;


        }


    };
public:
    SetAsArray(unsigned int n):Set(n),array(n)
    {
        for(int i=0;i<array.size();i++)
        {
            array.at(i)= false;
        }
    }
    vector<bool> GetVec()
    {
        return array;
    }
    //metody z containera
    bool IsFull() const {
        return (Count()==UniverseSize());
    }
    void MakeNull()
    {
        for(int i=0;i<array.size();i++)
        {
            if(array.at(i))
            {
                count--;
                array.at(i)= false;
                if(count==0)
                    break;
            }
        }
    }
    void Insert (int element)
    {
        array.at(element)= true;
        count++;
    }
    bool IsMember (int element) const
    {
        return array[element];
    }
    void Withdraw (int element)
    {
        array[element]= false;
        count--;
    }
    void SetCount()
    {
        count=0;
        for(int i=0;i<array.size();i++)
        {
            if(array.at(i))
                count++;
        }
    }
//friend- funkcja uzyska prawo dostepu do prywatnych elementów danej klasy.
    friend SetAsArray operator + (
            SetAsArray const& s, SetAsArray const& t)
    {

        unsigned int n;
        if(s.array.size()>t.array.size())
        {
            n=t.array.size();
            SetAsArray *out = new SetAsArray(s.array.size());
            for(int i=0;i<n;i++)
            {
                if(s.array[i] || t.array[i])
                {
                    out->array[i]= true;
                }
                else
                {
                    out->array[i]= false;
                }
            }
            for(int i=n;i<s.array.size();i++)
            {
                out->array[i]=s.array.at(i);
            }
            out->SetCount();
            return *out;
        }
        else
        {
            n=s.array.size();
            SetAsArray *out = new SetAsArray(t.array.size());
            for(int i=0;i<n;i++)
            {
                if(s.array[i] || t.array[i])
                {
                    out->array[i]= true;
                }
                else
                {
                    out->array[i]= false;
                }
            }
            for(int i=n;i<t.array.size();i++)
            {
                out->array[i]=t.array.at(i);
            }
            out->SetCount();
            return *out;
        }

    }
    friend SetAsArray operator - (
            SetAsArray const& s, SetAsArray const& t)
    {
        unsigned int n;
        if(s.array.size()>t.array.size())
        {
            n=t.array.size();
            SetAsArray *out = new SetAsArray(s.array.size());
            for(int i=0;i<n;i++)
            {
                if(s.array[i] && t.array[i])
                {
                    out->array[i]= false;
                }
                else
                {
                    out->array[i]= true;
                }
            }
            for(int i=n;i<s.array.size();i++)
            {
                out->array[i]=s.array.at(i);
            }
            out->SetCount();
            return *out;
        }
        else
        {
            n=s.array.size();
            SetAsArray *out = new SetAsArray(n);
            for(int i=0;i<n;i++)
            {
                if(s.array[i] && t.array[i])
                {
                    out->array[i]= false;
                }
                else
                {
                    out->array[i]= true;
                }
            }
            out->SetCount();
            return *out;
        }
    }
    friend SetAsArray operator * (
            SetAsArray const& s, SetAsArray const& t)
    {
        unsigned int n;
        if(s.array.size()>t.array.size())
            n=t.array.size();
        else
            n=s.array.size();
        SetAsArray *out = new SetAsArray(n);
        for(int i=0;i<n;i++)
        {
            out->array[i]= s.array[i] && t.array[i];
        }
        out->SetCount();
        return *out;
    }
    friend bool operator == (
            SetAsArray const& s, SetAsArray const& t)
    {
        int iterator;
        int max ;
        if(s.array.size()<t.array.size())
        {
            iterator=s.array.size();
            max=t.array.size();

            for(int i=0;i<iterator;i++)
            {
                if(s.array.at(i)!=t.array.at(i))
                {return false;}

            }
            for(int i=iterator;i<max;i++)
            {
                if(t.array.at(i))
                    return false;
            }
        } else {
            iterator = t.array.size();
            max = s.array.size();
            for (int i = 0; i < iterator; i++) {
                if (s.array.at(i) != t.array.at(i))
                {return false; }
            }
            if(max==iterator)
                return true;
            for (int i = iterator; i < max; i++) {
                if (s.array.at(i))
                    return false;
            }
        }
        return true;
    }
    friend bool operator <= (
            SetAsArray const& s, SetAsArray const& t)
    {

        for(int i=0;i<s.array.size();i++)
        {
            if(s.array.at(i))
            {
                if(!t.array.at(i))
                {
                    return false;
                }
            }
        }
        return true;

    }
    void wypisz ()
    {
        for(int i=0;i<array.size();i++)
        {
            cout<<array.at(i);
        }
        cout<<endl;
    }
    //void Accept (Visitor&) const{};
//o metodzie Accept powiemy na następnych zajęciach
    void Accept(AddingVisitor& v)
    {
        v.SetSum(0);
        for(int i=0;i<array.size();i++)
        {
            if(array.at(i))
            {
                v.Visit(i);
            }
        }
        //cout<<v.GetSum();
    }
    void Accept(EvenVisitor ev)
    {
        ev.SetSum();
        ev.SetEven();
        for(int i=0;i<array.size();i++)
        {
            if(array.at(i))
            {
                ev.Visit(i);
            }
            if(ev.IsDone())
            {
                //ev.SetEvenTue();
                cout<< "Znaleziono liczbe nieparzysta " << i<<endl;
                break;
            }

        }
        if(!ev.IsDone())
            cout<< "Nie znaleziono liczby nieparzystej";
    }
    Iter & NewIterator(){return * new Iter(array,array.size());};
};




#endif //ZBIORY_SETASARRAY_H
