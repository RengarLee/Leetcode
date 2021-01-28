
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int num, int* returnSize){
    int * bits = (int *)malloc(((*returnSize)+1) *sizeof(int));
    bits[0] = 0;
    bits[1] = 1;
    int t =0;
    for (int i = 2; i <= num; i++)
    {
        t = i/2;
        bits[i] = i%2 + bits[t];
    }
    return bits;
}


int main()
{
    int col = 5;
    int row = 5;
    int * t = countBits(col, &row);
    return 0;
}
