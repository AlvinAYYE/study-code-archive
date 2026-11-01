/*
 * ==========================================================================
 * UVa 482 - Permutation Arrays
 * Title-CN: 排列陣列還原
 * Difficulty: UVa Star 1
 * Tags: sorting, array
 * ==========================================================================
 * [EN] Problem: Permute array elements according to given 1-based index mapping.
 * [中文] 題目說明: 依據給定的 1-indexed 位置索引將資料元素重新排回正確位置。
 * [EN] Approach: Place value i into output[index[i] - 1].
 * [中文] 思路: 陣列置換映射。
 * ==========================================================================
 */
#include <stdio.h>
#include <string.h>

int main(void) {
    const char *in[3] = {"3.14", "2.71", "1.41"};
    int pos[3] = {2, 3, 1};
    const char *out[3];
    for (int i = 0; i < 3; i++) out[pos[i] - 1] = in[i];
    int ok = (strcmp(out[0], "1.41") == 0);
    printf("%s: UVa 482 - Permutation Arrays\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
