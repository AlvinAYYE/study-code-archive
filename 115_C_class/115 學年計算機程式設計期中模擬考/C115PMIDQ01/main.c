/* Problem C115PMIDQ01: Print an Hourglass Pattern
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

int main() {
    int input = 0;
    if (scanf("%d",&input) != -1 || input >= 50 || input <= 2)
    {
        return 0;
    }
    for (int i = 0; i < input; i++)
    {
        for (int e = 0; e < i; e++)
        {
            printf(" ");
        }
        for (int e = 1; e < input * 2 - i * 2 ; e++)
        {
            printf("*");
        }
        printf("\n");
    }
    for (int i = input - 1; i > 0; i--)
    {
        for (int e = 1; e < i; e++)
        {
            printf(" ");
        }
        for (int e = 0; e <abs(input - i + 1)  ; e++)
        {
            printf("*");
        }
        for (int e = 0; e < abs(input - i); e++)
        {
            printf("*");
        }
        if (i - 1 > 0)
        {
            printf("\n");
        } 
    }
    // Write your solution here
    return 0;
}
