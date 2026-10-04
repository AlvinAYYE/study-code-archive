/* Problem C1150928Q04: Largest Square
 *
 * Input:
 * The input starts with a line containing a single integer $T (< 21)$. This is followed by $T$ test cases. The first line of each of them will contain three integers $M$, $N$ and $Q (< 21)$ separated by a space where $M$, $N$ denotes the dimension of the grid. Next follows $M$ lines each containing $N$ characters. Finally, there will be $Q$ lines each containing two integers $r$ and $c$. The value of $M$ and $N$ will be at most 100.
 *
 * Output:
 * For each test case in the input produce $Q + 1$ lines of output. In the first line print the value of $M$ , $N$ and $Q$ in that order separated by single space. In the next $Q$ lines, output the length of a side of the largest square in the corresponding grid for each $(r, c)$ pair in the input.
 */
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)

#include <stdio.h>

int main()
{
    int T;

    if (scanf("%d", &T) != 1)
    {
        return 0;
    }

    for (int t = 0; t < T; t++)
    {
        int M, N, Q;
        char grid[100][101];

        if (scanf("%d %d %d", &M, &N, &Q) != 3)
        {
            return 0;
        }

        for (int i = 0; i < M; i++)
        {
            if (scanf("%100s", grid[i]) != 1)
            {
                return 0;
            }
        }

        printf("%d %d %d\n", M, N, Q);

        for (int q = 0; q < Q; q++)
        {
            int r, c;

            if (scanf("%d %d", &r, &c) != 2)
            {
                return 0;
            }

            char target = grid[r][c];

            int radius = 0;
            int max_radius = 0;

            while (1)
            {
                // 檢查擴張後是否超出畫布
                if (r - radius < 0 ||
                    r + radius >= M ||
                    c - radius < 0 ||
                    c + radius >= N)
                {
                    break;
                }

                int valid = 1;

                // 檢查正方形內是不是全部都是同一個字元
                for (int row = r - radius;
                    row <= r + radius && valid;
                    row++)
                {
                    for (int col = c - radius;
                        col <= c + radius;
                        col++)
                    {
                        if (grid[row][col] != target)
                        {
                            valid = 0;
                            break;
                        }
                    }
                }

                if (!valid)
                {
                    break;
                }

                max_radius = radius;
                radius++;
            }

            int answer = max_radius * 2 + 1;

            // 整份輸出的最後一行不能有 \n
            if (t == T - 1 && q == Q - 1)
            {
                printf("%d", answer);
            }
            else
            {
                printf("%d\n", answer);
            }
        }
    }

    return 0;
}