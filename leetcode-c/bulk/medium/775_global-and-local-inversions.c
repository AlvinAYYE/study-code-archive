/*
 * LeetCode 0775. Global and Local Inversions（全域與區域反轉）
 * 題意：排列中 nums[i] > nums[j] 且 i<j 是全域反轉；nums[i] > nums[i+1] 是區域反轉。
 *       判斷兩種反轉數量是否相同。
 * 範例：[1,0,2] -> true（兩者各 1）；[1,2,0] -> false（全域 2、區域 1）。
 * 限制：1 <= n <= 10^5；nums 是 0..n-1 的排列。
 * 解法：每個區域反轉必定也是全域反轉；兩者相等代表不能有跨過相鄰位置的反轉。
 *       對 0..n-1 的排列，等價條件是每個 nums[i] 與 i 的距離都不超過 1。
 * 複雜度：時間 O(n)，空間 O(1)。
 */
#include <stdbool.h>
#include <stdio.h>

/* ---- community solution ---- */
bool isIdealPermutation(int* nums, int numsSize) {
    for (int index = 0; index < numsSize; index++) {
        int displacement = nums[index] - index;
        if (displacement < -1 || displacement > 1) {
            return false;
        }
    }
    return true;
}

/* ---- generated tests ---- */
int main(void) {
    int first[] = {1, 0, 2};
    int second[] = {1, 2, 0};
    int third[] = {0, 1, 2, 3};
    int fourth[] = {2, 0, 1};
    bool passed = isIdealPermutation(first, 3) &&
                  !isIdealPermutation(second, 3) &&
                  isIdealPermutation(third, 4) &&
                  !isIdealPermutation(fourth, 3);
    printf("%s: 0775 isIdealPermutation tests=4\n",
           passed ? "PASS" : "FAIL");
    return passed ? 0 : 1;
}
