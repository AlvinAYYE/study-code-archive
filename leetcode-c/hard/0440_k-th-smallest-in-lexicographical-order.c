/*
 * Title-CN: 字典序的第 K 小數字
 * LeetCode 440. K-th Smallest in Lexicographical Order
 *
 * 題意翻譯：給定正整數 n 和 k，把 1 到 n 的整數依字典序排列，回傳第 k 個數字。
 * 字典序把整數當成文字比較，例如 10 排在 2 前面。
 *
 * 範例：n = 13、k = 2，回傳 10。
 * 說明：字典序為 [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9]。
 *
 * 限制：1 <= k <= n <= 1,000,000,000。
 *
 * 解題思路：把數字想成字首樹。以 1 為字首的數字構成一個子樹，接著是 2、3……。
 * 計算某個字首子樹在 1..n 中有幾個數：逐層擴大字首區間，累加該層落在 n 範圍內的數量。
 * 若整個子樹的數量不超過 k，就跳到下一個字首；否則答案仍在此子樹內，往下一層走。
 *
 * 複雜度：每次計數最多走 O(log n) 層，最多跳過 O(n) 個字首，總時間 O((log n)^2)。
 * 額外空間 O(1)。LeetCode 介面：保留 findKthNumber；main() 僅供本機測試。
 */

#include <assert.h>

static long long countPrefix(long long prefix, int n) {
    long long next = prefix + 1;
    long long count = 0;
    while (prefix <= n) {
        long long upper = next < (long long)n + 1 ? next : (long long)n + 1;
        count += upper - prefix;
        prefix *= 10;
        next *= 10;
    }
    return count;
}

int findKthNumber(int n, int k) {
    long long prefix = 1;
    --k; /* 起點 1 已經是第一個數字。 */
    while (k > 0) {
        long long subtreeSize = countPrefix(prefix, n);
        if (subtreeSize <= k) {
            ++prefix;             /* 略過整個子樹，移到下一個字首。 */
            k -= (int)subtreeSize;
        } else {
            prefix *= 10;         /* 子樹仍包含目標，往更長的字首前進。 */
            --k;
        }
    }
    return (int)prefix;
}

int main(void) {
    assert(findKthNumber(13, 2) == 10);
    assert(findKthNumber(1, 1) == 1);
    assert(findKthNumber(100, 10) == 17);
    assert(findKthNumber(1000000000, 1000000000) == 999999999);
    return 0;
}
