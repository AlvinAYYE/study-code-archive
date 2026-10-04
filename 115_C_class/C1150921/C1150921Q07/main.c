/* Problem C1150921Q07: Happy or Unhappy Number
 *
 * Input:
 * The input consists of several test cases, the number of which you are given in the first line of the input. Each test case consists of one line containing a single positive integer $N$ smaller than $10^9$.
 *
 * Output:
 * For each test case, you must print one of the following messages:
 *
 * ```
 * Case #p: N is a Happy number.
 * Case #p: N is an Unhappy number.
 * ```
 *
 * Here $p$ stands for the case number (starting from $1$). You should print the first message if the number $N$ is a happy number. Otherwise, print the second line.
 */
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)

#include <stdio.h>

int next_number(int number)
{
    int sum = 0;

    while (number > 0)
    {
        int digit = number % 10;
        sum += digit * digit;
        number /= 10;
    }

    return sum;
}

int main()
{
    int test_cases;
    scanf("%d", &test_cases);

    for (int i = 1; i <= test_cases; i++)
    {
        int input;
        scanf("%d", &input);

        int current = input;
        int visited[1000] = { 0 };

        while (current != 1)
        {
            current = next_number(current);

            if (visited[current] == 1)
            {
                break;
            }

            visited[current] = 1;
        }

        if (current == 1)
        {
            printf("Case #%d: %d is a Happy number.", i, input);
        }
        else
        {
            printf("Case #%d: %d is an Unhappy number.", i, input);
        }
        if (i  < test_cases)
        {
            printf("\n");
        }
    }

    return 0;
}