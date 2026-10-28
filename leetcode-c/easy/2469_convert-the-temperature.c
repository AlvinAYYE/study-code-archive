/*
 * LeetCode 2469. Convert the Temperature
 * Title-CN: 溫度轉換
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/convert-the-temperature/
 *
 * [中文] 題目說明
 *     給定四捨五入到小數點後兩位的攝氏溫度 celsius，請依序回傳
 *     [開氏溫度, 華氏溫度]。公式為 Kelvin = Celsius + 273.15，
 *     Fahrenheit = Celsius * 1.8 + 32。答案誤差在 10^-5 內即可。
 *
 * [中文] 範例
 *     1. celsius = 36.50，輸出 [309.65000, 97.70000]。
 *     2. celsius = 122.11，輸出 [395.26000, 251.79800]。
 *
 * [中文] 限制
 *     - 0 <= celsius <= 1000。
 *
 * [中文] 解題步驟
 *     1. 使用公式分別算出開氏與華氏溫度。
 *     2. 依題目要求的順序放進長度 2 的動態陣列並回傳。
 *     3. 時間 O(1)，回傳陣列使用 O(1) 空間。
 *
 * LeetCode C 函式簽名：double* convertTemperature(double celsius, int* returnSize)
 */
#include <stdio.h>
#include <stdlib.h>

double *convertTemperature(double celsius, int *returnSize) {
    double *answer = (double *)malloc(2 * sizeof(double));
    answer[0] = celsius + 273.15;
    answer[1] = celsius * 1.8 + 32.0;
    *returnSize = 2;
    return answer;
}

static int closeEnough(double actual, double expected) {
    double difference = actual - expected;
    if (difference < 0) difference = -difference;
    return difference < 0.00001;
}

int main(void) {
    int ok = 1, size;
    double *answer = convertTemperature(36.50, &size);
    ok = ok && size == 2 && closeEnough(answer[0], 309.65) && closeEnough(answer[1], 97.7);
    free(answer);
    answer = convertTemperature(122.11, &size);
    ok = ok && size == 2 && closeEnough(answer[0], 395.26) && closeEnough(answer[1], 251.798);
    free(answer);
    printf("%s: 2469 convert-the-temperature\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
