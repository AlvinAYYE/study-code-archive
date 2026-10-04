/* Problem C1150928Q07: Sorting Points
 *
 * Input:
 * The input begins with an integer `N (0 < N ≤ 10)` in the first line by itself representing the number of points to follow. Each following line consists of two floating numbers separated by a space. The numbers are the values of `x` and `y` in point respectively.
 *
 * Output:
 * Show the reordered result. Each number should be rounded to 2 decimal places.
 */
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)

#include <stdio.h>

int main()
{
    int n;
    double point[10][2];

    if (scanf("%d", &n) != 1 || n <= 0 || n > 10)
        return 0;

    for (int i = 0; i < n; i++)
    {
        if (scanf("%lf %lf", &point[i][0], &point[i][1]) != 2)
            return 0;
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (point[j][0] > point[j + 1][0] ||
                (point[j][0] == point[j + 1][0] &&
                    point[j][1] > point[j + 1][1]))
            {
                double tempX = point[j][0];
                double tempY = point[j][1];

                point[j][0] = point[j + 1][0];
                point[j][1] = point[j + 1][1];

                point[j + 1][0] = tempX;
                point[j + 1][1] = tempY;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%.2f %.2f", point[i][0], point[i][1]);

        if (i != n - 1)
            printf("\n");
    }

    return 0;
}