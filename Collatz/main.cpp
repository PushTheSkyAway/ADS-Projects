/*
This program was made as a solution for an algorithmic exercise called "Collatz Numbers"
It takes a set of numbers and performs Collatz function on smallest or largest (at the moment)
number in given set, until number is equal to one or overflows integer (in this case number is printed as "m").

Solution contains two interconnected heaps (min and max) which are used to quickly find min or max of the set.

Maciej Stanuch @ 2018
*/


#include <iostream>
#include "MaxHeap.h"
#include "MinHeap.h"


int main() {

    int n;
    scanf("%i", &n);
    unsigned int tmp;
    auto *array = new Number[n + 1];
    auto *minHeap = new MinHeap(n);
    auto *maxHeap = new MaxHeap(n);

    int q = 1;
    for (int i = 1; i <= n; i++) {

        scanf("%u", &tmp);
        array[i].value = tmp;
        array[i].index = i;
        array[i].overflow = false;
        if (array[i].value != 1) {
            minHeap->array[q] = &array[i];
            maxHeap->array[q] = &array[i];
            minHeap->size++;
            maxHeap->size++;
            q++;

        }
    }

    int k, times;
    char operation = 's';
    char lastOperation = '\0';

    scanf("%i", &k);

    for (int i = 0; i < k; i++) {


        scanf("%i %c", &times, &operation);

        if (minHeap->isEmpty() && maxHeap->isEmpty()) break;

        for (int j = 0; j < times; j++) {
            if (operation == 's') {

                if (lastOperation != 's') {
                    minHeap->buildHeap();
                    while (minHeap->peek() != nullptr && (minHeap->peek()->value == 1 || minHeap->peek()->overflow))
                        minHeap->removeRoot();
                }

                if (minHeap->isEmpty()) break;

                minHeap->peek()->collatz();

                if (minHeap->peek()->value == 1 || minHeap->peek()->overflow) {
                    minHeap->removeRoot();
                } else
                    minHeap->heapify(1);

                lastOperation = operation;

            } else if (operation == 'l') {

                if (lastOperation != 'l') {
                    maxHeap->buildHeap();
                    while (maxHeap->peek() != nullptr && (maxHeap->peek()->value == 1 || maxHeap->peek()->overflow))
                        maxHeap->removeRoot();
                }

                if (maxHeap->isEmpty()) break;

                maxHeap->peek()->collatz();

                if (maxHeap->peek()->value == 1 || maxHeap->peek()->overflow) {
                    maxHeap->removeRoot();
                } else
                    maxHeap->heapify(1);

                lastOperation = operation;
            }

        }
    }

    for (int i = 1; i <= n; i++) {
        if (!array[i].overflow)
            printf("%u ", array[i].value);
        else
            printf("m ");
    }

    delete []array;
    delete minHeap;
    delete maxHeap;

    return 0;
}