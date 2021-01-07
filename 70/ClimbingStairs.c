#include <stdio.h>

int climbStairs(int n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    int num1 = 2, num2 = 1, sum;
    for (int i = 3; i <= n; i++)
    {
        sum = num1+num2;
        num2 = num1;
        num1 = sum;
    }
    return sum;
}

int main()
{
    int col = 3;
    printf("%d\n", climbStairs(col));
    return 0;
}
