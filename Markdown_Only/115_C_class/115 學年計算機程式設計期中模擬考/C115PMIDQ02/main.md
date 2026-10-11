

---

## C source: `main.c`

```c
/* Problem C115PMIDQ02: Power of Two
 *
 * Input:
 * The only input is an integer `n (0 <= n < 2^31 - 1)`.
 *
 * Output:
 * With the given integer `n`, print `true` if it is a power of two. Otherwise, print `false`.
 */
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
//int power() {
//
//}

int main() {
    long double two = powl(2,32);
    
    //printf("%l", two);
    int32_t input = 0;
    if (scanf("%d", &input) != -1 || input >= two || input < 0)
    {
        return 0;
    }
    for (int i = 0; i < 32; i++)
    {
        long double two_pow = pow(2,i);
        if (input == two_pow) {
            printf("true");
            return 0;
        }
    }

    printf("false");

    // Write your solution here
    return 0;
}
```
