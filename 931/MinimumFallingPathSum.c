#include <stdio.h>
#include <stdlib.h>

#define MAXINT 10000
int MinThree(int a, int b, int c)
{
    if (a > b)
    {
        a = b;
    }
    if (a > c)
    {
        a = c;
    }
    return a;
}

int MinTow(int a, int b)
{
    return a > b ? b : a;
}

// int minFallingPathSum(int **A, int ASize, int *AColSize)
// {
//     int n = ASize;
//     int m = *AColSize;
//     int **pathSum = (int **)malloc(sizeof(int *) * n);
//     for (int i = 0; i < n; i++)
//     {
//         pathSum[i] = (int *)malloc(sizeof(int) * m);
//     }
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if (i == 0)
//             {
//                 pathSum[i][j] = A[i][j];
//                 continue;
//             }
//             if (j == 0)
//             {
//                 if (j + 1 < m)
//                 {
//                     pathSum[i][j] = MinTow(pathSum[i - 1][j], pathSum[i - 1][j + 1]) + A[i][j];
//                 }
//                 else
//                 {
//                     pathSum[i][j] = pathSum[i - 1][j] + A[i][j];
//                 }
//                 continue;
//             }
//             if (j + 1 == m)
//             {
//                 pathSum[i][j] = MinTow(pathSum[i - 1][j - 1], pathSum[i - 1][j]) + A[i][j];
//                 continue;
//             }
//             pathSum[i][j] = MinThree(pathSum[i - 1][j - 1], pathSum[i - 1][j], pathSum[i - 1][j + 1]) + A[i][j];
//         }
//     }
//     int min = pathSum[n-1][0];
//     for (int i = 0; i < m; i++)
//     {
//         if(min > pathSum[n-1][i])
//         {
//             min = pathSum[n-1][i];
//         }
//     }
//     return min;
// }


// int minFallingPathSum(int **A, int ASize, int *AColSize)

int minFallingPathSum(int **A, int ASize, int *AColSize)
{
    int n = ASize;
    int m = *AColSize;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0)
            {
                continue;
            }
            if (j == 0)
            {
                if (j + 1 < m)
                {
                    A[i][j] = MinTow(A[i - 1][j], A[i - 1][j + 1]) + A[i][j];
                }
                else
                {
                    A[i][j] = A[i - 1][j] + A[i][j];
                }
                continue;
            }
            if (j + 1 == m)
            {
                A[i][j] = MinTow(A[i - 1][j - 1], A[i - 1][j]) + A[i][j];
                continue;
            }
            A[i][j] = MinThree(A[i - 1][j - 1], A[i - 1][j], A[i - 1][j + 1]) + A[i][j];
        }
    }
    int min = A[n-1][0];
    for (int i = 0; i < m; i++)
    {
        if(min > A[n-1][i])
        {
            min = A[n-1][i];
        }
    }
    return min;
}

int main()
{
    int array[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int col = 3;
    printf("%d\n", minFallingPathSum((int **)array, 3, &col));
    return 0;
}
