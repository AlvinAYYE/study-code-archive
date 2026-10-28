/*
 * Title-CN: 有序陣列中的單一元素
 * LeetCode 540. Single Element in a Sorted Array
 *
 * 題目翻譯：一個已排序陣列中，除了某個數字只出現一次，其餘數字都剛好出現兩次。
 * 請在 O(log n) 時間與 O(1) 額外空間內找出只出現一次的數字。
 *
 * 例子：[1,1,2,3,3,4,4,8,8] 的答案是 2；[3,3,7,7,10,11,11] 的答案是 10。
 *
 * 限制：陣列長度為奇數，介於 1 到 100000；元素非負且已遞增排序。
 *
 * 解題步驟：把陣列視為一組組相鄰的數字對。用二分搜尋檢查第 mid 組：
 * 若 nums[2*mid] 和 nums[2*mid+1] 相同，單一元素在後半段；若不同，答案在前半段。
 * 最後剩下的那一組索引就是單一元素的位置。
 *
 * 複雜度：每次把候選配對數量減半，時間 O(log n)，額外空間 O(1)。
 *
 * LeetCode 提交區：保留 singleNonDuplicate 函式；main() 僅供本機測試。
 */

#include <assert.h>

int singleNonDuplicate(int *nums, int numsSize) {
    int left = 0;
    int right = numsSize / 2;
    while (left < right) {
        int pair = left + (right - left) / 2;
        if (nums[2 * pair] == nums[2 * pair + 1]) {
            left = pair + 1;
        } else {
            right = pair;
        }
    }
    return nums[2 * left];
}

int main(void) {
    int example1[] = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    int example2[] = {3, 3, 7, 7, 10, 11, 11};
    int single[] = {9};
    assert(singleNonDuplicate(example1, 9) == 2);
    assert(singleNonDuplicate(example2, 7) == 10);
    assert(singleNonDuplicate(single, 1) == 9);
    return 0;
}
