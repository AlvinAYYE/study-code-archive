/*
 * Title-CN: 字典序排列數字
 * LeetCode 386. Lexicographical Numbers
 *
 * 題目翻譯：給定正整數 n，回傳從 1 到 n 按字典序排列的整數清單。
 * 字典序是把數字當成文字比較，例如 10 會排在 2 前面。
 *
 * 例子：n = 13，結果是 [1,10,11,12,13,2,3,4,5,6,7,8,9]。
 *
 * 限制：1 <= n <= 50000。
 *
 * 解題步驟：把數字看成十進位字首樹。先輸出目前字首，再依序接上 0 到 9，
 * 只遞迴到不大於 n 的數字。從 1 到 9 依序開始，先走完一個字首的所有延伸，
 * 自然會得到字典序，例如先輸出 1、10、11，再輸出 2。
 *
 * 複雜度：每個數字輸出一次，時間 O(n)；遞迴深度最多是數字位數，額外空間 O(log n)。
 *
 * LeetCode 提交區：保留 lexicalOrder 函式；main() 僅供本機測試。
 */

#include <assert.h>
#include <stdlib.h>

static void appendPrefix(int prefix, int n, int *result, int *size) {
    if (prefix > n) {
        return;
    }
    result[(*size)++] = prefix;
    for (int digit = 0; digit <= 9; ++digit) {
        long long child = (long long)prefix * 10 + digit;
        if (child > n) {
            break;
        }
        appendPrefix((int)child, n, result, size);
    }
}

int *lexicalOrder(int n, int *returnSize) {
    int *result = malloc((size_t)n * sizeof(*result));
    if (result == NULL) {
        *returnSize = 0;
        return NULL;
    }
    *returnSize = 0;
    for (int first = 1; first <= 9 && first <= n; ++first) {
        appendPrefix(first, n, result, returnSize);
    }
    return result;
}

static void checkOrder(int n, const int *expected, int expectedSize) {
    int size = 0;
    int *result = lexicalOrder(n, &size);
    assert(result != NULL && size == expectedSize);
    for (int i = 0; i < size; ++i) {
        assert(result[i] == expected[i]);
    }
    free(result);
}

int main(void) {
    const int expected13[] = {1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9};
    const int expected2[] = {1, 2};
    checkOrder(13, expected13, 13);
    checkOrder(2, expected2, 2);
    return 0;
}
