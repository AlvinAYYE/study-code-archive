/*
 * LeetCode 0744. Find Smallest Letter Greater than Target《尋找比目標大的最小字母》
 * 難度：Easy；標籤：陣列、二分搜尋
 * 題目連結：https://leetcode.com/problems/find-smallest-letter-greater-than-target/
 *
 * 題目說明：
 * 給定已按非遞減順序排列的英文字母陣列 letters，以及字母 target。請回傳
 * letters 中字典順序上嚴格大於 target 的最小字母。若沒有任何字母比 target
 * 大，則回傳陣列第一個字母；陣列中至少有兩種不同字母。
 *
 * 範例：
 * 1. letters = ['c','f','j']，target = 'a'，回傳 'c'。
 * 2. letters = ['c','f','j']，target = 'c'，回傳 'f'。必須嚴格大於 target。
 * 3. letters = ['x','x','y','y']，target = 'z'，回傳 'x'，因為需要循環回第一項。
 *
 * 限制：
 * - 2 <= letters.length <= 10^4。
 * - letters 和 target 都是小寫英文字母。
 * - letters 依非遞減順序排列，且至少包含兩種不同字母。
 *
 * 解題思路：
 * 1. 用二分搜尋尋找第一個「大於 target」的位置。
 * 2. 若 letters[mid] <= target，答案只能在 mid 右邊；否則 mid 可能是答案，
 *    將右界移到 mid，繼續尋找更靠左的位置。
 * 3. 搜尋結束後，若位置等於陣列長度，代表沒有更大的字母，回傳 letters[0]；
 *    否則回傳找到的位置。
 *
 * 複雜度：時間 O(log n)，額外空間 O(1)。
 */
#include <assert.h>
#include <stdio.h>

char nextGreatestLetter(char* letters, int lettersSize, char target) {
    int left = 0;
    int right = lettersSize;

    /* 找到第一個嚴格大於 target 的索引（upper bound）。 */
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (letters[mid] <= target) left = mid + 1;
        else right = mid;
    }
    return letters[left % lettersSize];
}

int main(void) {
    char first[] = {'c', 'f', 'j'};
    char second[] = {'x', 'x', 'y', 'y'};

    assert(nextGreatestLetter(first, 3, 'a') == 'c');
    assert(nextGreatestLetter(first, 3, 'c') == 'f');
    assert(nextGreatestLetter(first, 3, 'j') == 'c');
    assert(nextGreatestLetter(second, 4, 'z') == 'x');

    puts("PASS 0744 nextGreatestLetter");
    return 0;
}
