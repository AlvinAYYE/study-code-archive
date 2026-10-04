/*
 * 【初學者詳細導讀】
 * 【這題要做什麼】依序建立費波那契數列，查詢兩個項次並相加。這版把第一項定為 F1=1、第二項
 * F2=1，符合原解答移除開頭 0 後的索引方式。 【輸入】兩個項次 i、j，範圍 1 到
 * 92。【輸出】兩個數值和它們的十進位總和；總和用字串加法處理，因此 F92+F92 不會溢位。
 * 【閱讀順序】f[1] 和 f[2] 設為 1，之後每項等於前兩項相加。snprintf
 * 把兩個項次轉成十進位字串；接下來從個位數往左逐位相加，carry 保存進位，再把結果字串反轉。
 * 【C 語法】陣列 f 以項次當索引；char 陣列存文字；strlen 取得文字長度；字元數字要先減 '0'
 * 才能轉成數字。
 *
 * 【共通讀法】程式從 main 開始執行。scanf 依格式讀入資料，printf 將答案印到螢幕；for/while
 * 重複執行大括號中的步驟。C 陣列索引從 0 開始。遇到函式時，可把它當成一段有名字、可重複使用的工作。
 */
/* 輸入兩個索引 i j（從 1 起算，F1=F2=1），輸出對應數值及總和。 */
#include <stdio.h>
#include <string.h>
int main(void) {
    /* 先讀取並檢查輸入；接著依導讀中的演算法處理資料，最後輸出結果。 */
    int index, inner_index;
    unsigned long long fibonacci[93] = {0, 1, 1};
    for (int fibonacci_index = 3; fibonacci_index <= 92; fibonacci_index++)
        fibonacci[fibonacci_index] =
            fibonacci[fibonacci_index - 1] + fibonacci[fibonacci_index - 2];
    if (scanf("%d%d", &index, &inner_index) != 2 || index < 1 || inner_index < 1 || index > 92 ||
        inner_index > 92)
        return 1;
    char first_text[32], second_text[32], sum_text[33];
    snprintf(first_text, sizeof first_text, "%llu", fibonacci[index]);
    snprintf(second_text, sizeof second_text, "%llu", fibonacci[inner_index]);
    int first_digit_index = (int)strlen(first_text) - 1,
        second_digit_index = (int)strlen(second_text) - 1, sum_digit_count = 0, carry_digit = 0;
    while (first_digit_index >= 0 || second_digit_index >= 0 || carry_digit) {
        int digit_sum = carry_digit +
                        (first_digit_index >= 0 ? first_text[first_digit_index--] - '0' : 0) +
                        (second_digit_index >= 0 ? second_text[second_digit_index--] - '0' : 0);
        sum_text[sum_digit_count++] = (char)('0' + digit_sum % 10);
        carry_digit = digit_sum / 10;
    }
    sum_text[sum_digit_count] = 0;
    for (int reversal_index = 0; reversal_index < sum_digit_count / 2; reversal_index++) {
        char temporary_character = sum_text[reversal_index];
        sum_text[reversal_index] = sum_text[sum_digit_count - 1 - reversal_index];
        sum_text[sum_digit_count - 1 - reversal_index] = temporary_character;
    }
    printf("F%d = %llu\nF%d = %llu\nSum = %s\n",
           index,
           fibonacci[index],
           inner_index,
           fibonacci[inner_index],
           sum_text);
    return 0;
}
