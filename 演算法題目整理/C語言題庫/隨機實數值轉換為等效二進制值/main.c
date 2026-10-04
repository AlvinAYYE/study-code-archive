/*
 * 【初學者詳細導讀】
 * 【這題要做什麼】把非負十進位實數轉成二進位表示。小數部分只計算前 10
 * 位，因此結果是有限精度近似值。 【輸入】一個非負實數，例如 10.25。【輸出】完整 10
 * 位小數二進位，以及移除尾端 0 的簡化版。 【閱讀順序】整數部分反覆除以
 * 2，將餘數倒序就是二進位。小數部分反覆乘以
 * 2；每次乘積的整數位就是下一個二進位小數位，之後留下新的小數部分。最後移除小數字串尾端多餘的 0。
 * 【C 語法】double 可保存小數；(unsigned long long)x 取出非負數的整數部分；floor
 * 取得不大於 x 的整數；char 陣列 ib、fb 用來暫存輸出位元。
 *
 * 【共通讀法】程式從 main 開始執行。scanf 依格式讀入資料，printf 將答案印到螢幕；for/while
 * 重複執行大括號中的步驟。C 陣列索引從 0 開始。遇到函式時，可把它當成一段有名字、可重複使用的工作。
 */
/* 輸入非負實數；顯示整數位及小數前 10 位二進位，並顯示移除尾端 0 的版本。 */
#include <math.h>
#include <stdio.h>
int main(void) {
    /* 先讀取並檢查輸入；接著依導讀中的演算法處理資料，最後輸出結果。 */
    double decimal_value;
    if (scanf("%lf", &decimal_value) != 1 || decimal_value < 0)
        return 1;
    unsigned long long integer_part = (unsigned long long)decimal_value;
    double fractional_part = decimal_value - integer_part;
    char integer_bits[70], fraction_bits[11];
    int integer_bit_count = 0;
    if (!integer_part)
        integer_bits[integer_bit_count++] = '0';
    while (integer_part) {
        integer_bits[integer_bit_count++] = (char)('0' + integer_part % 2);
        integer_part /= 2;
    }
    printf("Binary Value: ");
    for (int index = integer_bit_count - 1; index >= 0; index--)
        putchar(integer_bits[index]);
    putchar('.');
    for (int index = 0; index < 10; index++) {
        fractional_part *= 2;
        fraction_bits[index] = (char)('0' + (int)fractional_part);
        fractional_part -= floor(fractional_part);
    }
    for (int index = 0; index < 10; index++)
        putchar(fraction_bits[index]);
    int last_fraction_bit = 9;
    while (last_fraction_bit >= 0 && fraction_bits[last_fraction_bit] == '0')
        last_fraction_bit--;
    printf("\nFinal Binary Value: ");
    for (int index = integer_bit_count - 1; index >= 0; index--)
        putchar(integer_bits[index]);
    putchar('.');
    if (last_fraction_bit < 0)
        putchar('0');
    else
        for (int index = 0; index <= last_fraction_bit; index++)
            putchar(fraction_bits[index]);
    putchar('\n');
    return 0;
}
