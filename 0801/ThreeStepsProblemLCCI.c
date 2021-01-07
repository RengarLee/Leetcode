#include <stdio.h>
#include <stdlib.h>

// int waysToStep(int n){
//     int *pathSum = (int *)malloc(sizeof(int ) * 1000001);
//     pathSum[1] = 1;
//     pathSum[2] = 2;
//     pathSum[3] = 4;
//     for (int i = 4; i <= n; i++)
//     {
//         pathSum[i] = (((pathSum[i-1]+pathSum[i-2]))%1000000007+pathSum[i-3])%1000000007;
//     }
//     return pathSum[n];
// }

//空间优化
int waysToStep(int n){
    if(n == 1)
        return 1;
    if(n == 2)
        return 2;
    if(n == 3)
        return 4;
    int num1 = 4, num2 = 2, num3 = 1, sum;
    for (int i = 4; i <= n; i++)
    {
        sum = (((num1+num2))%1000000007+num3)%1000000007;
        num3 = num2;
        num2 = num1;
        num1 = sum;
    }
    return sum;
}

int main()
{
    int col = 5;
    printf("%d\n", waysToStep(col));
    return 0;
}
