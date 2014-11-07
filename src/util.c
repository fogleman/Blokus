#include <time.h>
#include <stdlib.h>
#include "util.h"

double now() {
    return (double)clock() / CLOCKS_PER_SEC;
}

int rand_int(int n) {
    int result;
    while (n <= (result = rand() / (RAND_MAX / n)));
    return result;
}
