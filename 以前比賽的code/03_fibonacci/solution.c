#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/* Precompute F(0)..F(93), matching the PHP table's intended input range.
 * uint64_t keeps F(93) exact; output is separated by lines for multiple cases.
 */
int main(void)
{
    uint64_t fib[94] = {0, 1};
    for (size_t i = 2; i < 94; ++i) fib[i] = fib[i - 1] + fib[i - 2];

    char line[256];
    while (fgets(line, sizeof line, stdin) != NULL) {
        char *end;
        long n = strtol(line, &end, 10);
        if (end == line) continue;
        if (n < 0 || n > 93) {
            fputs("Input must be in the range 0..93.\n", stderr);
            return 1;
        }
        printf("%" PRIu64 "\n", fib[n]);
    }
    return 0;
}
