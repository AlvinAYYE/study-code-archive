/* Problem C1150921Q04: Prime Factors of a Factorial
 *
 * Input:
 * Input will consist of a series of lines, each line containing a single integer $N$. The file will be terminated by a line consisting of a single '`0`'.
 *
 * Output:
 * Output will consist of a series of blocks of lines, one block for each line of the input. Each block will start with the number $N$, right justified in a field of width $3$, and the characters '`!`', space, '`=`' and space. This will be followed by a list of the number of times each prime number occurs in $N!$ separated with a single space.
 * Follow the layout of the example shown below exactly.
 */
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
static int is_prime(int64_t n)
{
    if (n < 2) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;

    for (int64_t i = 5; i <= n / i; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    }
    return 1;
}

int main() {
    int primes[100], primes_count = 0,input_index=0,input[100], prime_factor_count[1000];
    for (int i = 2; i < 100; i++)
    {
        if (is_prime(i))
        {
            primes[primes_count] = i;
            primes_count++;
        }
    }
    while (scanf("%d", &input[input_index]) == 1 && input[input_index] != 0) {
        input_index++;
    }
    for (int index = 0; index < input_index; index++)
    {
        int prime_factor_count[1000] = { 0 };
        for (int i = 2; i <= input[index]; i++)
        {
            int temp = i;
            for (int primes_index = 0; primes_index < primes_count; primes_index++)
            {
                while (temp % primes[primes_index] == 0) {

                    prime_factor_count[primes_index]++;
                    temp /= primes[primes_index];
                }
                if (temp == 1)
                {
                    break;
                }
            }
        }

        printf("%3d! =",input[index]);
        for (int i = 0; i < primes_count; i++)
        {
            if (primes[i] > input[index])
            {
                break;
            }

            printf(" %d", prime_factor_count[i]);
        }
        if (index + 1 < input_index)
        {
            printf("\n");
        }
    }
    // Write your solution here
    return 0;
}
