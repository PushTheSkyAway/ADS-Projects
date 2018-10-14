/*
Program made as a solution for "Homework Order" problem.


Maciej Stanuch @ 2018
*/
#include <iostream>
#include "Vector.h"


int main() {
    auto *arrayOfVectors = new Vector[1000];

    char operation;
    int n;
    scanf("%i\n",&n);
    int g1, g2, p, q;
    for (int i = 0; i < n; i++) {
        scanf("%c\n", &operation);
        switch (operation) {
            case 'a': {
                scanf("%i %i", &g1, &p);
                arrayOfVectors[g1].insert(p);
                break;
            }
            case 'e': {
                scanf("%i", &g1);
                if (arrayOfVectors[g1].length() == 0)
                    printf("na\n");
                else
                    printf("%i\n", arrayOfVectors[g1].extractMax());
                break;
            }
            case 'm': {
                scanf("%i %i", &g1, &g2);
                arrayOfVectors[g1].merge(arrayOfVectors[g2]);
                break;
            }
            case 'i': {
                scanf("%i %i %i", &g1, &p, &q);
                arrayOfVectors[g1].increase(p, q);
                break;
            }
            case 'p': {
                scanf("%i", &g1);
                arrayOfVectors[g1].display();
                break;
            }
        }
    scanf("\n");

    }
    delete[] arrayOfVectors;
    return 0;
}