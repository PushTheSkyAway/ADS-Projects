
#include "Number.h"

void Number::collatz() {
    unsigned int const LIMIT = 1431655765;
    if (value % 2 == 0)
        value = value / 2;
    else if (value < LIMIT)
        value = 3 * value + 1;
    else
        overflow = true;
}


