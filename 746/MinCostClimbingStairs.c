#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int fmins(int a, int b)
{
    return a>b ? b:a;
}

int minCostClimbingStairs(int* cost, int costSize){
    int *costSum = (int*)malloc(sizeof(int)*(costSize+1));
    costSum[0] =costSum[1]= 0;
    int temp = 0;
    for (int i = 2; i <= costSize; i++)
    {
        costSum[i] = fmins(costSum[i-1]+cost[i-1],costSum[i-2]+cost[i-2]);
    }
    return costSum[costSize];
}


int main()
{
    int array[10] = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    int col = 10;
    printf("%d\n", minCostClimbingStairs((int *)array, col));
    return 0;
}
