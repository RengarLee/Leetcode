#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool stoneGame(int* piles, int pilesSize){
    int A = 0, L = 0, i = 0, j = pilesSize-1;

    int temp = 0;
    if(pilesSize <=2)
    {
        return 1;
    }
    for (int t = 0; t < pilesSize-2; t++)
    {
        if(piles[i]+piles[j-1]>piles[j]+piles[i+1])
        {
            temp = piles[i++];
        }else
        {
            temp = piles[j--];
        }
        if(t%2 == 0)
        {
            A += temp;
        }else
        {
            L += temp;
        }
    }
    return A>L;
}


int main()
{
    int array[4] = {7,8,8,10};
    int col = 4;
    printf("%d\n", stoneGame((int *)array, col));
    return 0;
}
