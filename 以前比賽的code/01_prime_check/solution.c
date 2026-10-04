#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * Prime test: trial division by candidates of the form 6k +/- 1.
 * The PHP source returns true for every value <= 3, including 0 and 1.
 * This C version fixes that boundary case; valid contest inputs are assumed
 * to fit in a signed 64-bit integer.
 */
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

int main(void)
{
    char line[256];
    while (fgets(line, sizeof line, stdin) != NULL) {
        char *end;
        int64_t n = (int64_t)strtoll(line, &end, 10);
        if (end == line) continue;
        puts(is_prime(n) ? "Y" : "N");
    }
    return 0;
}
