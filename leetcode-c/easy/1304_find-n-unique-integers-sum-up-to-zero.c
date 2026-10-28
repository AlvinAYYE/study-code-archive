/*
 * Title-CN: 找出 N 個總和為零的相異整數
 * LeetCode 1304. Find N Unique Integers Sum up to Zero
 *
 * 題意完整翻譯：
 *   給定整數 n，回傳任意一個包含 n 個相異整數的陣列，並且所有整數的總和必須是 0。只要符合條件，任何答案都可以。
 *
 * 範例：
 *   1. n = 5，可回傳 [-7,-1,1,3,4]；[-5,-1,1,2,3] 等答案也接受。
 *   2. n = 3，可回傳 [-1,0,1]。
 *   3. n = 1，只能回傳 [0]。
 *
 * 限制：
 *   - 1 <= n <= 1000
 *
 * 解題步驟：
 *   1. 每次加入一組互為相反數的數字，例如 1 與 -1；這一組總和為 0，且數字不重複。
 *   2. 若 n 是奇數，再加入 0。
 *   3. 設定回傳陣列長度為 n。
 *
 * 複雜度：
 *   時間：O(n)，填入 n 個數字。
 *   空間：O(n)，回傳陣列需要 n 個整數。
 *
 * LeetCode C API：
 *   int* sumZero(int n, int* returnSize);
 */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int* sumZero(int n, int* returnSize) {
    int* answer = (int*)malloc(sizeof(int) * (size_t)n);
    int pairCount = n / 2;
    int i;

    for (i = 0; i < pairCount; ++i) {
        answer[i * 2] = i + 1;
        answer[i * 2 + 1] = -(i + 1);
    }
    if (n % 2 == 1) {
        answer[n - 1] = 0;
    }

    *returnSize = n;
    return answer;
}

int main(void) {
    int size;
    int n;
    for (n = 1; n <= 9; ++n) {
        int* values = sumZero(n, &size);
        int sum = 0;
        int i;
        assert(size == n);
        for (i = 0; i < size; ++i) {
            int j;
            sum += values[i];
            for (j = i + 1; j < size; ++j) {
                assert(values[i] != values[j]);
            }
        }
        assert(sum == 0);
        free(values);
    }
    puts("PASS 1304 sumZero");
    return 0;
}
