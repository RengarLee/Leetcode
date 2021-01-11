#include <stdio.h>
#include <stdlib.h>

int maxSubArray(int *nums, int numsSize)
{
    int *pathSum = (int *)malloc(sizeof(int) * numsSize);
    pathSum[0] = nums[0];
    int maxNum = nums[0];
    for (int i = 1; i < numsSize; i++)
    {
        if (pathSum[i-1] >= 0)
        {
            pathSum[i] = pathSum[i - 1] + nums[i];
        }
        else
        {
            pathSum[i] = nums[i];
        }
        if (pathSum[i] > maxNum)
        {
            maxNum = pathSum[i];
        }
    }

    return maxNum;
}

int main()
{
    int array[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int col = 9;
    printf("%d\n", maxSubArray(array, col));
    return 0;
}
