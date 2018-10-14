

#ifndef AIDS_HEAP_H
#define AIDS_HEAP_H


#include "Number.h"

class MaxHeap {
public:
    Number** array;
    int size;

    explicit MaxHeap(int n);
    Number* peek();
    void removeRoot();
    void heapify(int i);
    bool isEmpty();
    void buildHeap();
    void swap(int index1, int index2);
};


#endif //AIDS_HEAP_H
