/* Problem C115PMIDQ04: Fibonacci Number
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
    int n[32] = { 0};
    // Write your solution here
    int input = 0;
    if (scanf("%d", &input) == -1 || input > 30 || input < 0)
    {
        return 0;
    }
    n[0] = 0;
    n[1] = 1;
    for (int i = 2; i <= 30; i++)
    {
        n[i] = n[i - 1] + n[i - 2];
    }
    printf("%d",n[input]);
    return 0;
}
