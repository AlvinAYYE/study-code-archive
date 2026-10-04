/*
 * 【初學者詳細導讀】
 * 【這題要做什麼】讀取 a、b、m，計算 a 的 b 次方除以 m
 * 的餘數。程式用「快速冪」避免真的把 a 乘 b 次。 【輸入】三個非負整數：底數 a、指數
 * b、模數 m（m 必須大於 0）。【輸出】一個整數，也就是 a^b mod
 * m。 【閱讀順序】1. addmod 把兩數相加後取模，並避免加法溢位。2. mulmod
 * 用重複加法計算乘積的餘數。3. main 每次查看指數 b 的最低位：若為
 * 1，就把目前底數乘進答案；接著把 b 除以 2，並把底數平方。4. b 變成 0
 * 時，答案已完成。 【C 語法】unsigned long long 是可存較大非負整數的型別；% 是餘數運算；&a
 * 是把變數 a 的位置交給 scanf，讓 scanf 把輸入寫進去。
 *
 * 【共通讀法】程式從 main 開始執行。scanf 依格式讀入資料，printf 將答案印到螢幕；for/while
 * 重複執行大括號中的步驟。C 陣列索引從 0 開始。遇到函式時，可把它當成一段有名字、可重複使用的工作。
 */
/* 輸入：非負整數 a、指數 b、模數 m；輸出 a^b mod m。 */
#include <stdint.h>
#include <stdio.h>
static unsigned long long
add_modulo(unsigned long long base, unsigned long long exponent, unsigned long long modulus) {
    return base >= modulus - exponent ? base - (modulus - exponent) : base + exponent;
}
static unsigned long long
multiply_modulo(unsigned long long base, unsigned long long exponent, unsigned long long modulus) {
    unsigned long long result = 0;
    while (exponent) {
        if (exponent & 1)
            result = add_modulo(result, base, modulus);
        exponent >>= 1;
        if (exponent)
            base = add_modulo(base, base, modulus);
    }
    return result;
}
int main(void) {
    /* 先讀取並檢查輸入；接著依導讀中的演算法處理資料，最後輸出結果。 */
    unsigned long long base, exponent, modulus, result = 1;
    if (scanf("%llu%llu%llu", &base, &exponent, &modulus) != 3 || modulus == 0)
        return 1;
    base %= modulus;
    result %= modulus;
    while (exponent) {
        if (exponent & 1)
            result = multiply_modulo(result, base, modulus);
        exponent >>= 1;
        if (exponent)
            base = multiply_modulo(base, base, modulus);
    }
    printf("%llu\n", result);
    return 0;
}
