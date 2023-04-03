#include <iostream>
#include "BinaryHeap.h"
using namespace std;
int main() {
    cout << "Hello, World!" << endl;
    BinaryHeap<int> *heap = new BinaryHeap<int>(10);
    cout<<heap->IsEmpty()<<endl;
    heap->Enqueue(5);
    cout<<heap->IsEmpty()<<endl;
    heap->wypisz();
    cout<< heap->FindMin() << endl;
    heap->Enqueue(6);
    heap->wypisz();
    cout<< heap->FindMin() << endl;
    heap->Enqueue(8);
    heap->wypisz();
    cout<< heap->FindMin() << endl;
    heap->Enqueue(3);
    heap->wypisz();
    cout<< heap->FindMin() << endl;
    heap->Enqueue(9);
    heap->wypisz();
    cout<< heap->FindMin() << endl;
    heap->Enqueue(2);
    heap->wypisz();
    cout<< heap->FindMin() << endl;
    heap->Enqueue(1);
    heap->wypisz();
    cout<< heap->FindMin() << endl;
    heap->DequeueMin();
    heap->wypisz();
    cout<< heap->FindMin() << endl;
    heap->DequeueMin();
    heap->wypisz();
    cout<< heap->FindMin() << endl;
    heap->MakeNull();



    return 0;
}
