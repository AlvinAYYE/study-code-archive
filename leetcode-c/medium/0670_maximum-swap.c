/*
 * Title-CN: 最大交換
 * LeetCode 670. Maximum Swap
 *
 * 題意翻譯：給定一個非負整數，最多交換其中兩個數字一次，請回傳能得到的最大數字。
 * 若不交換會比較大，也可以不交換。
 *
 * 範例：num = 2736，交換 2 和最後一位 6，回傳 7236。
 *
 * 限制：0 <= num <= 10^8。
 *
 * 解題思路：從左往右看數字，左邊位數的影響最大。先記錄每個數字最後出現的位置；
 * 對每一位，從 9 往當前數字+1 搜尋，若右側有更大的數字，就與最靠右的那個交換，
 * 立即回傳結果。若找不到可提升的位置，原數字就是最大值。
 *
 * 複雜度：時間 O(d)，d 為位數；額外空間 O(d)（數字陣列與固定 10 個位置）。
 * LeetCode 介面：保留 maximumSwap；main() 僅供本機測試。
 */

#include <assert.h>

int maximumSwap(int num) {
    int digits[10];
    int length = 0;
    if (num == 0) digits[length++] = 0;
    while (num > 0) {
        digits[length++] = num % 10;
        num /= 10;
    }
    for (int left = 0; left < length / 2; ++left) {
        int temp = digits[left];
        digits[left] = digits[length - left - 1];
        digits[length - left - 1] = temp;
    }

    int lastPosition[10];
    for (int digit = 0; digit < 10; ++digit) lastPosition[digit] = -1;
    for (int i = 0; i < length; ++i) lastPosition[digits[i]] = i;

    for (int i = 0; i < length; ++i) {
        for (int digit = 9; digit > digits[i]; --digit) {
            if (lastPosition[digit] > i) {
                int temp = digits[i];
                digits[i] = digits[lastPosition[digit]];
                digits[lastPosition[digit]] = temp;
                int answer = 0;
                for (int j = 0; j < length; ++j) answer = answer * 10 + digits[j];
                return answer;
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < length; ++i) answer = answer * 10 + digits[i];
    return answer;
}

int main(void) {
    assert(maximumSwap(2736) == 7236);
    assert(maximumSwap(9973) == 9973);
    assert(maximumSwap(98368) == 98863);
    assert(maximumSwap(0) == 0);
    return 0;
}
