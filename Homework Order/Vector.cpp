#include <cstdio>
#include "Vector.h"


Vector::Vector() {
    size = 100;
    array = new int[size];
    numberOfElements = 0;
}

int Vector::get(int index) {
    return array[index];
}

int Vector::length() {
    return numberOfElements;
}

void Vector::insert(int value) {
    if (numberOfElements == size) {
        size *= 2;
        int *tmp = new int[size];
        for (int i = 0; i < size / 2; i++) {
            tmp[i] = array[i];
        }
        delete[] array;
        array = tmp;
        tmp = nullptr;
    }
    array[numberOfElements] = value;
    numberOfElements++;
}

void Vector::remove(int value) {
    for (int i = 0; i < numberOfElements; i++) {
        if (array[i] == value) {
            array[i] = array[numberOfElements - 1];
            numberOfElements--;
            return;
        }
    }
}

void Vector::sort() {
    int i, j;
    int x;

    for (i = 1; i < numberOfElements; i++) {
        x = array[i];
        for (j = i - 1; j >= 0 && x >= array[j]; j--) {
            array[j + 1] = array[j];
        }
        array[j + 1] = x;
    }
}

void Vector::merge(Vector &vector2) {
    for (int i = 0; i < vector2.length(); i++)
        insert(vector2.get(i));

    int len = vector2.length();
    for (int i = 0; i < len; i++)
        vector2.remove(vector2.get(i));
}

void Vector::display() {
    sort();
    for (int i = 0; i < length(); i++) {
        printf("%i ", array[i]);
    }
    printf("\n");
}

int Vector::extractMax() {
    int max = array[0];
    for (int i = 0; i < length(); i++) {
        if (array[i] > max) max = array[i];
    }
    int tmp = max;
    remove(tmp);
    return tmp;
}

void Vector::increase(int oldValue, int newValue) {

    for (int i = 0; i < numberOfElements; i++) {
        if (array[i] == oldValue) {
            array[i] = newValue;
            return;
        }
    }
    printf("na\n");

}
