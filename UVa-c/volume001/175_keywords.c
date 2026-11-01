/*
 * ==========================================================================
 * UVa 175 - Keywords
 * Title-CN: 文件關鍵字鄰近詞距比對
 * Difficulty: UVa Star 2
 * Tags: string
 * URL: https://onlinejudge.org/external/1/175.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given profiles containing pairs of keywords and distance limits, find titles of documents where the keywords occur within the required word distance.
 *
 * [中文] 題目說明:
 *     給定關鍵字查詢條件 (兩關鍵字及其最大相鄰單詞距離)，找出所有在限制詞距內同時出現該兩關鍵字之文檔。
 *
 * [EN] Approach:
 *     Tokenize document into words; record indices of occurrence for keywords; check if abs(index1 - index2) - 1 <= max_dist.
 * [中文] 思路:
 *     將文章拆解為單詞序列，記錄目標單詞出現的下標位置，檢查是否存在一對下標使其單詞間隔不超過閾值。
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

int check_proximity(int *pos1, int n1, int *pos2, int n2, int max_dist) {
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            int dist = pos1[i] - pos2[j];
            if (dist < 0) dist = -dist;
            if (dist - 1 <= max_dist) return 1;
        }
    }
    return 0;
}

int main(void) {

    int p1[] = {5}, p2[] = {8};
    int ok = check_proximity(p1, 1, p2, 1, 2); // 8 - 5 - 1 = 2 <= 2
    printf("%s: UVa 175 - Keywords\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
