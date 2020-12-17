#include <stdio.h>
#include<stdlib.h>
#include<string.h>

// int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
//     int n = obstacleGridSize;
//     int m = obstacleGridColSize[0];
//     int path[n][m];
//     int temp = 1;
//     for (int i = 0; i < n; i++)
//     {
//         if(obstacleGrid[i][0] == 1)
//         {
//             temp = 0;
//         }
//         path[i][0] = temp;
//     }
//     temp = 1;
//     for (int i = 0; i < m; i++)
//     {
//         if(obstacleGrid[0][i] == 1)
//         {
//             temp = 0;
//         }
//         path[0][i] = temp;
//     }

//     for (int i = 1; i < n; i++)
//     {
//         for (int j = 1; j < m; j++)
//         {
//             if(obstacleGrid[i][j] == 1)
//             {
//                 path[i][j] = 0;
//             }else
//             {
//                 path[i][j] = path[i-1][j]+path[i][j-1];
//             }
//         }
//     }
//     return path[n-1][m-1];
// }

// int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
//     int n = obstacleGridSize;
//     int m = obstacleGridColSize[0];

//     if(obstacleGrid[0][0] == 1)
//     {
//         return 0;
//     }

//     int path[m];
//     int temp = 1;
//     for (int i = 0; i < m; i++)
//     {
//         if(obstacleGrid[0][i] == 1)
//         {
//             temp = 0;
//         }
//         path[i] = temp;
//     }
//     temp = 1;
//     for (int i = 1; i < n; i++)
//     {
//         if(obstacleGrid[i][0] == 1)
//         {
//             temp = 0;
//         }
//         path[0] = temp;
//         for (int j = 1; j < m; j++)
//         {
//             if(obstacleGrid[i][j] == 1)
//             {
//                 path[j] = 0;
//             }else
//             {
//                 path[j] += path[j-1];
//             }
//         }
//     }
//     return path[m-1];
// }

int uniquePathsWithObstacles(int **obstacleGrid, int obstacleGridSize, int *obstacleGridColSize)
{
    int n = obstacleGridSize;
    int m = obstacleGridColSize[0];
    int path[m];
    memset(path, 0, sizeof(path));
    path[0] = (obstacleGrid[0][0] == 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (obstacleGrid[i][j] == 1)
            {
                path[j] = 0;
                continue;
            }
            if (j >= 1 && obstacleGrid[i][j - 1] == 0)
            {
                path[j] += path[j - 1];
            }
        }
    }
    return path[m - 1];
}

int main()
{
    int array[3][3] = {{0,0,0},{0,1,0},{0,0,0}};
    int col = 3;
    printf("%d\n", uniquePathsWithObstacles((int**)array, 3, &col));
    return 0;
}
