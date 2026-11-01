/* Problem C115MID01Q03: Hartals
 *
 * Input:
 * The first line contains an integer $T\ (1 \le T \le 50)$, the number of test cases. Each test case is given on the following lines:
 *
 * - a line with an integer $N\ (7 \le N \le 3650)$, the number of days to simulate;
 * - a line with an integer $P\ (1 \le P \le 100)$, the number of parties;
 * - $P$ lines, each with one integer $h\ (1 \le h \le 3650)$, the hartal parameter of one party. No $h$ is a multiple of $7$. Two parties may have the same parameter.
 *
 * Output:
 * For each test case, print the number of working days lost in days $1$ to $N$ on its own line.
 *
 * **Do not print a newline (`\n`) after the last line of output.** An extra newline at the end is judged as a Presentation Error (PE).
 */
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include <stdlib.h>

int main() {
    int input_count = 0;
    if (scanf("%d", &input_count) == -1 || input_count > 50 || input_count < 1)
    {
        return 0;
    }
    for (int c = 0; c < input_count; c++)
    {
        int day = 0, party = 0, party_array[100] = {0};
        if (scanf("%d", &day) == -1 || day > 3650 || day < 7)
        {
            return 0;
        }

        if (scanf("%d", &party) == -1 || party > 100 || party < 1)
        {
            return 0;
        }

        for (int i = 0; i < party; i++)
        {

            if (scanf("%d", &party_array[i]) == -1 || party_array[i] > 3650 || party_array[i] < 1)
            {
                return 0;
            }
        }

        int lost = 0;
        int week[7] = { 0,0,0,0,0,1,1},week_index = 0;
        for (int d = 1; d <= day; d++)
        {
            if (week_index == 7)
            {
                week_index = 0;
            }
            if (week[week_index] == 0)
            {
                for (int p = 0; p < party; p++)
                {
                    if (d % party_array[p] == 0) {
                        lost++;
                        break;
                    }
                }
            }
            week_index++;
        }
        printf("%d", lost);
        if (c + 1 < input_count)
        {
            printf("\n");
        }
    }
    
    return 0;
}/*
2
14
3
3
4
8
100
4
12
15
25
40*/
