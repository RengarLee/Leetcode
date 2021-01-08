#include <stdio.h>
#include <stdlib.h>


int maxSubArray(int* nums, int numsSize){
    int sum = nums[0];
    int fsum = 0;
    for (int i = 1; i < numsSize; i++)
    {
        if(nums[i]>sum)
        {
            sum = nums[i];
        }else
        {
            if(nums[i]<=0)
            {
                fsum += nums[i];
                continue;
            }
            if(nums[i]+fsum>=0)
            {
                sum += nums[i]+fsum;
                fsum = 0;
                continue;
            }else
            {
                fsum += nums[i];
            }
        }
    }
    return sum;
}

int main()
{
    int array[9] = {-2,1,-3,4,-1,2,1,-5,4};
    int col = 9;
    printf("%d\n", maxSubArray(array, col));
    return 0;
}
