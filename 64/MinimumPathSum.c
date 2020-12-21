#include <stdio.h>
#include <stdlib.h>
// int minPathSum(int **grid, int gridSize, int *gridColSize)
// {
//     int n = gridSize;
//     int m = *gridColSize;
//     int **pathSum = (int **)malloc(sizeof(int *) * gridSize);
//     for (int i = 0; i < n; i++)
//     {
//         pathSum[i] = (int *)malloc(sizeof(int) * m);
//     }

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if(i<1||j<1)
//             {
//                 pathSum[i][j] = grid[i][j];
//                 continue;
//             }
//             if (i == 0)
//             {

//                 pathSum[i][j] = grid[i][j] + pathSum[i][j - 1];
//                 continue;
//             }
//             if (j == 0)
//             {
//                 pathSum[i][j] = grid[i][j] + pathSum[i - 1][j];
//                 continue;
//             }
//             pathSum[i][j] = grid[i][j] + (pathSum[i][j - 1] > pathSum[i - 1][j] ? pathSum[i - 1][j] : pathSum[i][j - 1]);
//         }
//     }

//     return pathSum[n - 1][m - 1];
// }

int minPathSum(int **grid, int gridSize, int *gridColSize)
{
    int n = gridSize;
    int m = *gridColSize;
    int **pathSum = (int **)malloc(sizeof(int *) * gridSize);
    for (int i = 0; i < n; i++)
    {
        pathSum[i] = (int *)malloc(sizeof(int) * m);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i < 1 && j < 1)
            {
                pathSum[i][j] = *((int *)grid + i * m + j);
                continue;
            }
            if (i == 0)
            {

                pathSum[i][j] = *((int *)grid + i * m + j) + pathSum[i][j - 1];
                continue;
            }
            if (j == 0)
            {
                pathSum[i][j] = *((int *)grid + i * m + j) + pathSum[i - 1][j];
                continue;
            }
            pathSum[i][j] = *((int *)grid + i * m + j) + (pathSum[i][j - 1] > pathSum[i - 1][j] ? pathSum[i - 1][j] : pathSum[i][j - 1]);
        }
    }

    return pathSum[n - 1][m - 1];
}

int main()
{
    int array[3][3] = {{1,3,1},{1,5,1},{4,2,1}};
    int col = 3;
    printf("%d\n", minPathSum((int **)array, 3, &col));
    return 0;
}
