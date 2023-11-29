#include <stdio.h>
#include <math.h>
 void main() 
{
	int i;
    int n = 10;
    long long numPermutations = 1;
    for (i = n; i > 0; i--)
        numPermutations *= i;
    long long numRotations = n;
    long long totalKeys = numPermutations * numRotations;
    int exponent = log2(totalKeys);
    printf("Approximate number of possible keys: 2^%d\n", exponent);
}
