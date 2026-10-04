/* Problem C1150921Q05: Draw an Hourglass
 *
 * Input:
 * The only input is an integer `L (2 < L < 50)` that indicates how many top layers (half of the hourglass) there are.
 *
 * Output:
 * With the given number of top layers, print the top and bottom parts to complete a full hourglass with '`*`' symbols. Note that no additional spaces should be added after the last '`*`' symbol.
 */
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int input = 0;

    if (scanf("%d", &input) != 1 || input >= 50 || input <= 2)
    {
        return 0;
    }

    for (int i = 0; i < input * 2 - 1; i++)
    {
        int distance = abs((input - 1) - i);

        int spaces = input - 1 - distance;
        int stars = distance * 2 + 1;

        for (int w = 0; w < spaces; w++)
        {
            printf(" ");
        }

        for (int w = 0; w < stars; w++)
        {
            printf("*");
        }

        if (i + 1 <input * 2 - 1)
        {
            printf("\n");
        } 
    }

    return 0;
}