#include <stdio.h>

/* Greedy change for the canonical denominations 50, 10, 5, and 1.
 * Each whitespace-separated amount produces four denomination counts and
 * the total number of coins, in the same order as the selected PHP version.
 */
int main(void)
{
    const int denomination[] = {50, 10, 5, 1};
    long long amount;
    while (scanf("%lld", &amount) == 1) {
        long long count[4] = {0, 0, 0, 0};
        long long total = 0;
        for (int i = 0; i < 4; ++i) {
            count[i] = amount / denomination[i];
            amount %= denomination[i];
            total += count[i];
        }
        for (int i = 3; i >= 0; --i)
            printf("%d %lld\n", denomination[i], count[i]);
        printf("%lld\n", total);
    }
    return 0;
}
