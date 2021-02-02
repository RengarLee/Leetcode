#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int num, int* returnSize){
    int* Bits = (int*) malloc(*returnSize*sizeof(int));
    Bits[0] = 0;
    Bits[1] = 1;
    while (Bits[])
    {
        /* code */
    }
    
}
int main()
{
    int array[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int col = 3;
    printf("%d\n", minFallingPathSum((int **)array, 3, &col));
    return 0;
}
