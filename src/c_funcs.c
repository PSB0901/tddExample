#include "c_funcs.h"

int gcd(int a, int b) {
    if (a == 0) return b < 0 ? -b : b;
    if (b == 0) return a < 0 ? -a : a;
    int aa = a < 0 ? -a : a;
    int bb = b < 0 ? -b : b;
    while (bb != 0) {
        int t = aa % bb;
        aa = bb;
        bb = t;
    }
    return aa;
}

int fizzbuzz(int inputNumber)
{
    int result = 0;

    if ( (inputNumber % 15) == 0 )
    {
        result = 15000;
    } else if ( (inputNumber % 3) == 0 )
    {
        result = 300;
    } else if ( (inputNumber % 5) == 0 )
    {
        result = 500;
    } 

    return result;
}