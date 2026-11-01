/*
 * ==========================================================================
 * UVa 10227 - Forests
 * Title-CN: 森林意見意見調查 (等價集合分類計數)
 * Difficulty: Easy
 * Tags: Set Operations, Hash, Disjoint Set Union
 * URL: https://onlinejudge.org/external/102/10227.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count the number of distinct opinions among P people about which trees they heard fall in an forest of T trees.
 *
 * [中文] 題目描述:
 *     P 個人各自聽到若干樹倒下的聲音，求對倒下樹木集合看法完全相同的人群分組數量（相異集合數）。
 *
 * [EN] Approach:
 *     Represent each person's heard trees as a bitset or sorted list. Count the number of unique opinions.
 *
 * [中文] 解題思維:
 *     用 64 位元整數遮罩或布林數組表示每個人聽到的樹木集合，統計其中相異的集合個數。
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

int count_distinct_opinions(int p, const long long *opinion_masks) {
    int unique = 0;
    for (int i = 0; i < p; i++) {
        bool seen = false;
        for (int j = 0; j < i; j++) {
            if (opinion_masks[i] == opinion_masks[j]) { seen = true; break; }
        }
        if (!seen) unique++;
    }
    return unique;
}

int main(void) {

    long long op[] = {3, 3, 5}; // person 0 and 1 have same opinion (3), person 2 has (5) -> 2 distinct opinions
    int ok = (count_distinct_opinions(3, op) == 2);
    printf("%s: UVa 10227 - Forests\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
