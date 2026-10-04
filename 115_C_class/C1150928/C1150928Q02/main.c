#pragma warning(disable : 4996)
#pragma warning(disable : 6031)

#include <stdio.h>

int main()
{
    int n;
    int matrix1[8][8];
    int matrix2[8][8];
    int result[8][8] = { 0 };

    // 檢查 N
    if (scanf("%d", &n) != 1 || n < 1 || n > 8)
    {
        return 0;
    }

    // 讀取第一個矩陣
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (scanf("%d", &matrix1[row][col]) != 1)
            {
                return 0;
            }
        }
    }

    // 讀取第二個矩陣
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (scanf("%d", &matrix2[row][col]) != 1)
            {
                return 0;
            }
        }
    }

    // 矩陣乘法
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            for (int k = 0; k < n; k++)
            {
                result[row][col] +=
                    matrix1[row][k] * matrix2[k][col];
            }
        }
    }

    // 輸出
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (col > 0)
            {
                printf(" ");
            }

            printf("%d", result[row][col]);
        }
        if (row + 1 < n)
        {

            printf("\n");
        }
    }

    return 0;
}