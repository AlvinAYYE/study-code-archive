/*
 * Title-CN: 旋轉函式
 * LeetCode 396. Rotate Function
 *
 * 題目翻譯：對陣列 A 定義 F(k) = 0*A[0] + 1*A[1] + ... + (n-1)*A[n-1]，
 * 再把陣列循環向右旋轉 k 格得到 F(k)。請回傳所有 F(k) 中的最大值。
 *
 * 例子：A=[4,3,2,6] 時，F(0)=25、F(1)=16、F(2)=23、F(3)=26，答案是 26。
 *
 * 限制：陣列長度為 1 到 100000；每個元素介於 -100 到 100。
 *
 * 解題步驟：先計算 F(0) 與陣列總和 total。右旋一格時，原本最後一個元素會從
 * 權重 n-1 移到權重 0，其餘元素的權重都增加 1，因此
 * F(k) = F(k-1) + total - n * A[n-k]。用這個公式逐次算出所有旋轉，不必真的搬動陣列。
 *
 * 複雜度：只走訪陣列數次，時間 O(n)，額外空間 O(1)。
 *
 * LeetCode 提交區：保留 maxRotateFunction 函式；main() 僅供本機測試。
 */

#include <assert.h>

int maxRotateFunction(int *nums, int numsSize) {
    long long total = 0;
    long long current = 0;
    for (int i = 0; i < numsSize; ++i) {
        total += nums[i];
        current += (long long)i * nums[i];
    }

    long long best = current;
    for (int i = numsSize - 1; i > 0; --i) {
        current += total - (long long)numsSize * nums[i];
        if (current > best) {
            best = current;
        }
    }
    return (int)best;
}

int main(void) {
    int example[] = {4, 3, 2, 6};
    int negative[] = {-1, -2, -3};
    int one[] = {9};
    assert(maxRotateFunction(example, 4) == 26);
    assert(maxRotateFunction(negative, 3) == -5);
    assert(maxRotateFunction(one, 1) == 0);
    return 0;
}
