/* Problem C1150921Q02: Nth Fibonacci Number
 *
 * Input:
 * The only input is an integer `n (0 <= n <= 30)`.
 *
 * Output:
 * With the given number `n`, calculate `F(n)`.
 */
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include <stdlib.h>


int main() {
    int input = 30;
    if (scanf("%d", &input) != 1)return 0;
    if (input < 0 || input >30)return 0;
    int fp[31];
    fp[0] = 0;
    fp[1] = 1;
    for (int i = 2; i <= input; i++)
    {
        fp[i] = fp[i - 1] + fp[i - 2];
    }
    printf("%d", fp[input]);
    // Write your solution here
    return 0;
}
