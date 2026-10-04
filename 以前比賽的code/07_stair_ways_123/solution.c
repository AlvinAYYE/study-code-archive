#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

/* Number of ways to climb n stairs when each move is 1, 2, or 3 steps.
 * Input follows the PHP solution's stated range: positive n <= 50.
 */
int main(void)
{
    uint64_t ways[51] = {0};
    ways[0] = 1;
    for (int n = 1; n <= 50; ++n) {
        ways[n] = ways[n - 1];
        if (n >= 2) ways[n] += ways[n - 2];
        if (n >= 3) ways[n] += ways[n - 3];
    }

    int n;
    while (scanf("%d", &n) == 1) {
        if (n < 0 || n > 50) {
            fputs("Input must be in the range 0..50.\n", stderr);
            return 1;
        }
        printf("%" PRIu64 "\n", ways[n]);
    }
    return 0;
}
