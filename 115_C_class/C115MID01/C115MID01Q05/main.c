/* Problem C115MID01Q05: Special Positions
 *
 * Input:
 * The first line contains two integers $n$ and $m\ (1 \le n \le 50, 1 \le m \le 50)$. Each of the next $n$ lines contains $m$ integers separated by single spaces: line $r$ holds $a[r][0]$ to $a[r][m - 1]$. Every value is between $0$ and $9$.
 *
 * Output:
 * On the first line, print $k$, the number of special positions. Then print the $k$ positions, one per line, as the row and the column separated by a single space, sorted by row and then by column. If there is no special position, print only the line `0`.
 *
 * **Do not print a newline (`\n`) after the last line of output.** An extra newline at the end is judged as a Presentation Error (PE).
 */
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    int input_y = 0, input_x = 0;
	if (scanf("%d %d",&input_y,&input_x) == -1 || input_x < 1|| input_y < 1)
	{
		return 0;
	}
	int map[50][50] = { 0 },ans_index = 0;
	int ans[3000][2] = {0};
	for (int i = 0; i < input_y; i++)
	{
		for (int x = 0; x < input_x; x++)
		{
			scanf("%d", &map[i][x]) ;
		}
	}
	for (int y = 0; y < input_y; y++)
	{
		for (int x = 0; x < input_x; x++)
		{
			int now = map[y][x];
			int total = now;

			for (int index = 1; index <= now; index++)
			{
				for (int dy = -index; dy <= index; dy++)
				{
					int dx = index - abs(dy);

					for (int sign = -1; sign <= 1; sign += 2)
					{
						if (dx == 0 && sign == 1)
							continue;

						int target_y = y + dy;
						int target_x = x + dx * sign;

						if (target_y >= 0 && target_y < input_y &&
							target_x >= 0 && target_x < input_x)
						{
							total += map[target_y][target_x];
						}
					}
				}
			}
			if (total % 10 == now)
			{
				ans[ans_index][0] = y;
				ans[ans_index][1] = x;
				ans_index++;
			}
		}
	}
	printf("%d\n", ans_index);
	for (int i = 0; i < ans_index; i++)
	{
		printf("%d %d", ans[i][0], ans[i][1]);

		if (i + 1 < ans_index)
		{
			printf("\n");
		}
	}
    return 0;
}
