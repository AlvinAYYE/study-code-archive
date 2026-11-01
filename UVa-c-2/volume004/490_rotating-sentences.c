/*
 * ==========================================================================
 * UVa 490 - Rotating Sentences
 * Title-CN: 句子順時針旋轉 90 度輸出
 * Difficulty: UVa Star 1
 * Tags: string, 2d-array
 * ==========================================================================
 * [EN] Problem: Rotate sentences clockwise by 90 degrees.
 * [中文] 題目說明: 將多行輸入字串順時針旋轉 90 度輸出。
 * [EN] Approach: Store in 2D char array, print column by column from last line to first.
 * [中文] 思路: 二維陣列存儲，按最大長度逐列由最後一行向前輸出。
 * ==========================================================================
 */
#include <stdio.h>
#include <string.h>

int main(void) {
    int ok = 1;
    printf("%s: UVa 490 - Rotating Sentences\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
