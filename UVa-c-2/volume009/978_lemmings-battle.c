/*
 * ==========================================================================
 * UVa 978 - Lemmings Battle!
 * Title-CN: 旅鼠大對決！
 * Difficulty: Medium
 * Tags: Simulation, Priority Queue, Sorting
 * URL: https://onlinejudge.org/external/9/978.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Simulate a battle between green and blue lemmings on up to B battlefields where the highest power lemmings fight each round.
 *
 * [中文] 題目概述:
 *     在最多 B 個戰場上模擬綠色與藍色旅鼠軍團對戰，每輪雙方派出最強者決鬥，差額存活歸隊。
 *
 * [EN] Approach:
 *     Maintain sorted armies (or max-heaps). Pop top B lemmings from both, match them, insert survivors back, until one or both sides are empty.
 * [中文] 解題思路:
 *     維護雙方戰力排序（或最大堆積），每輪各取前 B 隻旅鼠對決，存活者減去對手戰力後重新入列，直到一方或雙方全滅。
 * ==========================================================================
 * UVa Online Judge Submission Template:
 * #include <stdio.h>
 * #include <stdlib.h>
 * #include <string.h>
 * #include <math.h>
 *
 * int main(void) {
 *     // Read input and call logic function
 *     return 0;
 * }
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

int cmp_desc(const void *a, const void *b) { return (*(int*)b - *(int*)a); }
int lemmings_fight(int b, int *green, int ng, int *blue, int nb) {
    while (ng > 0 && nb > 0) {
        qsort(green, ng, sizeof(int), cmp_desc);
        qsort(blue, nb, sizeof(int), cmp_desc);
        int fights = (ng < nb ? ng : nb);
        if (fights > b) fights = b;
        int next_g[100], next_b[100];
        int n_ng = 0, n_nb = 0;
        for (int i = 0; i < fights; i++) {
            if (green[i] > blue[i]) next_g[n_ng++] = green[i] - blue[i];
            else if (blue[i] > green[i]) next_b[n_nb++] = blue[i] - green[i];
        }
        for (int i = fights; i < ng; i++) next_g[n_ng++] = green[i];
        for (int i = fights; i < nb; i++) next_b[n_nb++] = blue[i];
        for (int i = 0; i < n_ng; i++) green[i] = next_g[i];
        for (int i = 0; i < n_nb; i++) blue[i] = next_b[i];
        ng = n_ng; nb = n_nb;
    }
    if (ng > 0 && nb == 0) return 1; // green wins
    if (nb > 0 && ng == 0) return 2; // blue wins
    return 0; // tie
}

int main(void) {

    int g[] = {50, 40}, b[] = {10, 10, 10};
    int res = lemmings_fight(2, g, 2, b, 3);
    int ok = (res == 1);
    printf("%s: UVa 978 - Lemmings Battle!\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
