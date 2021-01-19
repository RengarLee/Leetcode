#include <stdio.h>
#include <stdlib.h>

// int maxProfit(int* prices, int pricesSize){
//     int * values = (int *) malloc(sizeof(int)*pricesSize);
//     values[0] = 0;
//     for(int i = 1; i<pricesSize; i++)
//     {
//         if(values[i-1]<= 0)
//         {
//             if(prices[i]<=prices[i-1])
//             {
//                 values[i] = values[i-1];
//             }else
//             {
//                 values[i] = prices[i]-prices[i-1];
//             }
//         }else
//         {
//             values[i] = values[i-1]+prices[i]-prices[i-1];
//         }
//     }
//     int max = 0;
//     for(int i = 0; i< pricesSize; i++)
//     {
//        if( values[i] > max)
//          max = values[i];
//     }
//     return max;
// }

int maxProfit(int *prices, int pricesSize)
{
    int *values = (int *)malloc(sizeof(int) * pricesSize);
    int min = prices[0];
    int max = 0;
    values[0] = 0;
    for (int i = 1; i < pricesSize; i++)
    {
        int v = prices[i]-min;
        if(v>max)
        {
            max = v;
        }
        if(prices[i]<min)
        {
            min = prices[i];
        }
    }
    return max;
}

int main()
{
    int nums[6] = {7, 1, 5, 3, 6, 4};
    int numsSize = 6;
    int param_1 = maxProfit(nums, numsSize);
    printf("%d\n", param_1);
    return 0;
}
