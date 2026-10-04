#include <stdio.h>
#include <stdlib.h>

/* Enumerate integer partitions in non-increasing order, as in p04_CP.php. */
static long long *parts;

static void print_partition(int depth)
{
    for (int i = 0; i < depth; ++i)
        printf("%s%lld", i == 0 ? "" : " ", parts[i]);
    putchar('\n'); 
}

static void dfs(long long remaining, long long maximum, int depth)
{
    if (remaining == 0) {
        print_partition(depth);
        return;
    }
    long long first = remaining < maximum ? remaining : maximum;
    for (long long part = first; part >= 1; --part) {
        parts[depth] = part;
        dfs(remaining - part, part, depth + 1);
    }
}

int main(void)
{
    long long n;
    if (scanf("%lld", &n) != 1 || n < 0) return 0;
    if ((unsigned long long)n > (unsigned long long)(SIZE_MAX / sizeof *parts) - 1)
        return 1;
    parts = (long long *)malloc(((size_t)n + 1) * sizeof *parts);
    if (parts == NULL) return 1;
    dfs(n, n, 0);
    free(parts);
    return 0;
}
