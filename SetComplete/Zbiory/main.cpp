#include <iostream>
#include "SetAsArray.h"
#include "AddingVisitor.h"
#include "Iterator.h"

using namespace std;
int main() {
    std::cout << "Hello, World!" << std::endl;
    unsigned int n = 10;
    SetAsArray A(n);
    SetAsArray B(n);
    SetAsArray C(n);
    SetAsArray D(n);
    for(int i=0;i<10;i++)
    {
        if(i%2==0)
        {
            B.Insert(i);
        } else
        {
            A.Insert(i);
        }
    }
    C=A+B;
    D=C-B;
    A.wypisz();
    B.wypisz();
    C.wypisz();
    D.wypisz();
    bool one = A==D;
    bool two = D<=A;
    bool three = C==B;
    bool four = B<=C;
    for(int i=0;i<10;i++)
    {
            A.Insert(i);

    }
    bool five = D==A;
    bool six = D<=A;
    cout<<one<<endl;
    cout<<two<<endl;
    cout<<three<<endl;
    cout<<four<<endl;
    cout<<five<<endl;
    cout<<six<<endl;
    AddingVisitor v_A;
    A.Accept(v_A);
    cout<<v_A.GetSum();
    SetAsArray E(n);
    E=A*B;
    AddingVisitor v_E;
    cout<<endl;
    E.Accept(v_E);
    cout<<v_E.GetSum();
    E.Withdraw(1);
    E.Accept(v_E);
    cout<<endl;
    cout<<v_E.GetSum();
    EvenVisitor ev_B;
    EvenVisitor ev_A;
    A.Accept(ev_A);
    cout<<ev_A.GetEven()<<endl;
    B.Accept(ev_B);
    cout<<ev_B.GetEven()<<endl;
//    Iter A_Iter  =A.NewIterator(A.GetVec(),10);
    int prev1 =-1;
    int prev2=-1;
    SetAsArray::Iter itA = A.NewIterator();
    while (!itA.IsDone(itA.GetPozition())) {

        if(prev1!=*itA)
        {
            cout << *itA << " ";
        }
        prev1=*itA;
        ++itA;
    }
    cout << endl;
    SetAsArray::Iter itB = B.NewIterator();
    while (!itB.IsDone(itB.GetPozition())) {
        if(prev2!=*itB)
        {
            cout << *itB << " ";
        }
        prev2=*itB;
        ++itB;
    }
//    cout << endl;
//    for (itA.First(); !itA.IsDone(itA.GetPozition()); ++itA) {
//        int element = *itA;
//        cout << element << endl;
//    }



    //cout<<add.GetSum();







    return 0;
}
