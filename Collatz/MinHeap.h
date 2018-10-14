
#ifndef AIDS_MINHEAP_H
#define AIDS_MINHEAP_H


#include "Number.h"

class MinHeap {
public:
    Number** array;
    int size;

    explicit MinHeap(int n);
    Number* peek();
    void removeRoot();
    void heapify(int i);
    bool isEmpty();
    void buildHeap();
    void swap(int index1, int index2);
};


#endif //AIDS_MINHEAP_H
