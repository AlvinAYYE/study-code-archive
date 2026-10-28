/*
 * LeetCode 0344. Reverse String《反轉字串》
 * 難度：Easy；標籤：雙指標、字串
 * 題目連結：https://leetcode.com/problems/reverse-string/
 *
 * 題目說明：
 * 給定字元陣列 s，請直接在原陣列中將字元順序反轉。不能另建一個字串來
 * 放答案，額外記憶體只能使用 O(1)。函式不需要回傳值。
 *
 * 範例：
 * 1. s = ['h','e','l','l','o']，處理後為 ['o','l','l','e','h']。
 * 2. s = ['H','a','n','n','a','h']，處理後為 ['h','a','n','n','a','H']。
 *
 * 限制：1 <= s.length <= 10^5；每個 s[i] 都是可列印的 ASCII 字元。
 *
 * 解題思路：
 * 1. 用 left 指向陣列開頭，right 指向陣列結尾。
 * 2. 交換兩端字元，然後 left 往右、right 往左各移一格。
 * 3. 兩指標相遇或交錯時停止；每個字元已到達反轉後的位置。
 *
 * 複雜度：時間 O(n)，額外空間 O(1)。
 */
#include <assert.h>
#include <stdio.h>
#include <string.h>

void reverseString(char* s, int sSize) {
    int left = 0;
    int right = sSize - 1;

    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        ++left;
        --right;
    }
}

int main(void) {
    char first[] = "hello";
    char second[] = "Hannah";
    char one[] = "x";

    reverseString(first, 5);
    reverseString(second, 6);
    reverseString(one, 1);
    assert(strcmp(first, "olleh") == 0);
    assert(strcmp(second, "hannaH") == 0);
    assert(strcmp(one, "x") == 0);

    puts("PASS 0344 reverseString");
    return 0;
}
