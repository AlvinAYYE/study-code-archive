/*
 * 【初學者詳細導讀】
 * 【這題要做什麼】依商科 96 年原始 VB
 * 解答的輸出形式，計算至少要刪掉幾個數，才能留下嚴格遞增子序列。答案是 n
 * 減去最長遞增子序列長度。 【輸入】可有多筆資料。每筆先輸入 n，再輸入 n
 * 個整數；輸入 n=0 結束。【輸出】每筆資料一個最少刪除數。
 * 【閱讀順序】d[i] 記錄以第 i 個數結尾的 LIS 長度。對每個 i，查看前面的
 * j；若 a[j]<a[i]，代表可以把 a[i] 接在 j
 * 的序列後面。找出最大長度後，用 n-best 得到最少刪除數。 【C
 * 語法】while(scanf(...)==1) 可逐筆讀到檔案結尾；n=0 是題目指定的終止標記；內層 for
 * 只看目前位置之前的元素。
 *
 * 【共通讀法】程式從 main 開始執行。scanf 依格式讀入資料，printf 將答案印到螢幕；for/while
 * 重複執行大括號中的步驟。C 陣列索引從 0 開始。遇到函式時，可把它當成一段有名字、可重複使用的工作。
 */
/* 商科 96 題庫版本：多筆資料以 n 開始，n=0
 * 結束；每筆輸出最少刪除數使剩下數列嚴格遞增。 */
#include <stdio.h>
#define N 10000
int main(void) {
    /* 先讀取並檢查輸入；接著依導讀中的演算法處理資料，最後輸出結果。 */
    int value_count;
    while (scanf("%d", &value_count) == 1 && value_count) {
        if (value_count < 1 || value_count > N)
            return 1;
        int values[N], sequence_length[N], best_length = 0;
        for (int index = 0; index < value_count; index++) {
            if (scanf("%d", &values[index]) != 1)
                return 1;
            sequence_length[index] = 1;
            for (int inner_index = 0; inner_index < index; inner_index++)
                if (values[inner_index] < values[index] &&
                    sequence_length[inner_index] + 1 > sequence_length[index])
                    sequence_length[index] = sequence_length[inner_index] + 1;
            if (sequence_length[index] > best_length)
                best_length = sequence_length[index];
        }
        printf("%d\n", value_count - best_length);
    }
    return 0;
}
