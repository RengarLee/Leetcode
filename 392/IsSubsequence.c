#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// 动态规则化
bool isSubsequence(char *s, char *t)
{
    
    int n = strlen(s);
    int m = strlen(t);
    if(n == 0)
    {
        return 1;
    }
    if(n > m)
    {
        return 0;
    }
    int *flag = (int *)malloc(m * (sizeof(int)));
    int g = 0;
    flag[0] = s[0] == t[0] ? 1 : 0;
    for (int i = 1; i < m; i++)
    {
        flag[i] = (t[i] == s[flag[i - 1]] ? (flag[i - 1] + 1) : flag[i - 1]);
    }

    return flag[m - 1] == n;
}

int main()
{
    char *s = "axc";
    char *t = "ahbgdc";
    printf("%d\n", isSubsequence(s, t));
    return 0;
}
