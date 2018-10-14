

#include <cstdio>
#include "MaxHeap.h"

MaxHeap::MaxHeap(int n) {
    array = new Number *[n + 1];
    size = 0;
}


Number *MaxHeap::peek() {
    if (size != 0) {
        return array[1];
    }
    return nullptr;
}

void MaxHeap::removeRoot() {
    array[1] = array[size];
    size--;
    heapify(1);
}

void MaxHeap::heapify(int i) {
    if (size == 0 || i == size) return;
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if (left <= size) {
        if (array[left]->value > array[i]->value)
            largest = left;
        else if (array[left]->value == array[i]->value)
            if (array[left]->index < array[i]->index)
                largest = left;
    }
    if (right <= size) {
        if (array[right]->value > array[largest]->value)
            largest = right;
        else if (array[right]->value == array[largest]->value)
            if (array[right]->index < array[largest]->index)
                largest = right;
    }

    if (i != largest) {
        swap(i, largest);
        heapify(largest);
    }

}

bool MaxHeap::isEmpty() {
    return size == 0;
}

void MaxHeap::buildHeap() {
    for (int i = size / 2; i >= 1; i--) {
        heapify(i);
    }
}

void MaxHeap::swap(int index1, int index2) {

    Number *tmp = array[index1];
    array[index1] = array[index2];
    array[index2] = tmp;

}

