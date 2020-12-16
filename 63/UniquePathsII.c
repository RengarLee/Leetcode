#include <stdio.h>

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    int n = obstacleGridSize;
    int m = obstacleGridColSize[0];
    int path[n][m];
    int temp = 1;
    for (int i = 0; i < n; i++)
    {
        if(obstacleGrid[i][0] == 1)
        {
            temp = 0;
        }
        path[i][0] = temp;
    }
    temp = 1;
    for (int i = 0; i < m; i++)
    {
        if(obstacleGrid[0][i] == 1)
        {
            temp = 0;
        }
        path[0][i] = temp;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            path[i][j] = path[i-1][j]+path[i][j-1]; 
        }
    }
    return path[i][j];
}

int main()
{
    printf("%d\n", UniquePath(2,3));
    return 0;
}
