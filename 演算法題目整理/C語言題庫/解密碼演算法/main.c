/*
 * 【初學者詳細導讀】
 * 【這題要做什麼】照舊解答中的固定公式解開一組五個十六進位數字。這不是通用加密工具，公式和常數直接依照原始解答保留。
 * 【輸入】五個十六進位整數，可用空白隔開；例如原解答註解中的五個值。【輸出】五個解出的字元。
 * 【閱讀順序】1. scanf 的 %x 讀取十六進位值。2. 每個值減去對應的固定 h
 * 常數。3. 每輪把陣列向左移一格，尾端放入反向 h 常數。4. 依原程式的係數 4、常數 0x5a82
 * 和兩個中間值算出一個字元。5. 最後將五個結果反向輸出。 【C 語法】uint32_t 是固定 32
 * 位元的無號整數；int64_t 是固定 64 位元的有號整數，避免減法中間值太小時溢位；陣列索引 0 到 4
 * 對應五個輸入。
 *
 * 【共通讀法】程式從 main 開始執行。scanf 依格式讀入資料，printf 將答案印到螢幕；for/while
 * 重複執行大括號中的步驟。C 陣列索引從 0 開始。遇到函式時，可把它當成一段有名字、可重複使用的工作。
 */
/* 輸入 5 個十六進位數字；依原始 C# 解答的固定轉換式輸出解密字元。 */
#include <stdint.h>
#include <stdio.h>
int main(void) {
    /* 先讀取並檢查輸入；接著依導讀中的演算法處理資料，最後輸出結果。 */
    uint32_t encrypted_values[5];
    const int64_t key_values[5] = {0xabcd, 0xcdef, 0x2266, 0xceed, 0xaccd};
    for (int index = 0; index < 5; index++)
        if (scanf("%x", &encrypted_values[index]) != 1)
            return 1;
    int64_t working_values[5];
    for (int index = 0; index < 5; index++)
        working_values[index] = (int64_t)encrypted_values[index] - key_values[index];
    int64_t reversed_keys[5] = {
        key_values[4], key_values[3], key_values[2], key_values[1], key_values[0]};
    unsigned char decoded_characters[5];
    for (int index = 0; index < 5; index++) {
        int64_t saved_value = working_values[0];
        for (int inner_index = 0; inner_index < 4; inner_index++)
            working_values[inner_index] = working_values[inner_index + 1];
        working_values[4] = reversed_keys[index];
        int64_t decoded_value = saved_value - 4 * working_values[0] - 0x5a82 - working_values[4] -
                                (working_values[1] + working_values[2]);
        decoded_characters[index] = (unsigned char)(decoded_value + 32);
    }
    for (int index = 4; index >= 0; index--)
        putchar(decoded_characters[index]);
    putchar('\n');
    return 0;
}
