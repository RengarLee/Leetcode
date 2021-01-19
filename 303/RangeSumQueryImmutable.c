#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int sum;
    int value;
} NumArray;

NumArray *numArrayCreate(int *nums, int numsSize)
{
    if(numsSize == 0)
    {
        return NULL;
    }
    NumArray *numArray = (NumArray *)malloc(sizeof(NumArray) * numsSize);
    numArray[0].sum = nums[0];
    numArray[0].value = nums[0];
    for (int i = 1; i < numsSize; i++)
    {
        numArray[i].value = nums[i];
        numArray[i].sum = numArray[i - 1].sum + nums[i];
    }

    return numArray;
}

int numArraySumRange(NumArray *obj, int i, int j)
{
    int value = obj[j].sum - obj[i].sum + obj[i].value;
    return value;
}

void numArrayFree(NumArray *obj)
{
    free(obj);
}

int main()
{
    int nums[6] = {-2, 0, 3, -5, 2, -1};
    int numsSize = 6;
    NumArray *obj = numArrayCreate(nums, numsSize);
    int i = 0, j = 5;
    int param_1 = numArraySumRange(obj, i, j);
    printf("%d\n", param_1);
    return 0;
}
