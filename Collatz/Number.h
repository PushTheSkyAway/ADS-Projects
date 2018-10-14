
#ifndef AIDS_NUMBER_H
#define AIDS_NUMBER_H


struct Number {
    unsigned int value;
    int index;
    bool overflow;

    void collatz();
};


#endif //AIDS_NUMBER_H
