/*
 * LeetCode 1720. Decode XORed Array
 * Title-CN: 解碼異或後的陣列
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/decode-xored-array/
 *
 * [中文] 題目說明
 *     有一個由 n 個非負整數組成的原陣列 arr，並用 encoded[i] =
 *     arr[i] XOR arr[i + 1] 產生長度為 n - 1 的 encoded。現在給定
 *     encoded 和原陣列第一個值 first = arr[0]，請還原並回傳 arr。
 *     題目保證答案存在且唯一。XOR（互斥或）有「a XOR b XOR b = a」的特性。
 *
 * [中文] 範例
 *     1. encoded = [1,2,3]、first = 1，輸出 [1,0,2,1]。
 *        依序計算 1 XOR 1 = 0、0 XOR 2 = 2、2 XOR 3 = 1。
 *     2. encoded = [6,2,7,3]、first = 4，輸出 [4,2,0,7,4]。
 *
 * [中文] 限制
 *     - 2 <= n <= 10^4，encoded.length = n - 1。
 *     - 0 <= encoded[i]、first <= 10^5。
 *
 * [中文] 解題步驟
 *     1. 已知 arr[0] = first，先將它放進答案陣列。
 *     2. 由 encoded[i] = arr[i] XOR arr[i + 1] 可得
 *        arr[i + 1] = arr[i] XOR encoded[i]。
 *     3. 從左到右套用公式填完陣列。時間 O(n)，額外空間 O(n)（回傳陣列）。
 *
 * LeetCode C 函式簽名：
 *     int* decode(int* encoded, int encodedSize, int first, int* returnSize)
 */
#include <stdio.h>
#include <stdlib.h>

int *decode(int *encoded, int encodedSize, int first, int *returnSize) {
    int *arr = (int *)malloc((size_t)(encodedSize + 1) * sizeof(int));
    int i;
    *returnSize = encodedSize + 1;
    arr[0] = first;
    for (i = 0; i < encodedSize; ++i) {
        arr[i + 1] = arr[i] ^ encoded[i];
    }
    return arr;
}

static int check(const int *actual, int actualSize, const int *expected, int expectedSize) {
    int i;
    if (actualSize != expectedSize) return 0;
    for (i = 0; i < expectedSize; ++i) if (actual[i] != expected[i]) return 0;
    return 1;
}

int main(void) {
    int ok = 1, size;
    int encoded1[] = {1, 2, 3}, expected1[] = {1, 0, 2, 1};
    int encoded2[] = {6, 2, 7, 3}, expected2[] = {4, 2, 0, 7, 4};
    int *answer = decode(encoded1, 3, 1, &size);
    ok = ok && check(answer, size, expected1, 4);
    free(answer);
    answer = decode(encoded2, 4, 4, &size);
    ok = ok && check(answer, size, expected2, 5);
    free(answer);
    printf("%s: 1720 decode-xored-array\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
