/*
 * 【初學者詳細導讀】
 * 【這題要做什麼】求一組最長嚴格遞增子序列。子序列不必連續，但元素順序必須和原陣列相同。
 * 【輸入】n 和 n 個整數。【輸出】最長長度及一組符合條件的序列。
 * 【閱讀順序】k[i] 先設為 1，代表只選 a[i] 自己。查看所有
 * j<i；若 a[j]<a[i]，就能把 a[i] 接在以 j
 * 結尾的遞增序列後。更新最長長度及 pre[i]。最後沿 pre
 * 回溯，得到反向序列，再倒序印出。 【C 語法】pre[i]=-1 表示序列到此沒有前驅；陣列
 * out 暫存回溯結果；輸出的長度就是回溯收集到的元素數。
 *
 * 【共通讀法】程式從 main 開始執行。scanf 依格式讀入資料，printf 將答案印到螢幕；for/while
 * 重複執行大括號中的步驟。C 陣列索引從 0 開始。遇到函式時，可把它當成一段有名字、可重複使用的工作。
 */
/* 輸入 n 與 n 個整數，輸出一組最長嚴格遞增子序列（O(n^2) DP）。 */
#include <stdio.h>
#define N 10000
int main(void) {
    /* 先讀取並檢查輸入；接著依導讀中的演算法處理資料，最後輸出結果。 */
    int value_count, values[N], sequence_length_at_index[N], previous_index[N], best_index = 0;
    if (scanf("%d", &value_count) != 1 || value_count < 1 || value_count > N)
        return 1;
    for (int index = 0; index < value_count; index++) {
        if (scanf("%d", &values[index]) != 1)
            return 1;
        sequence_length_at_index[index] = 1;
        previous_index[index] = -1;
        for (int inner_index = 0; inner_index < index; inner_index++)
            if (values[inner_index] < values[index] &&
                sequence_length_at_index[inner_index] + 1 > sequence_length_at_index[index]) {
                sequence_length_at_index[index] = sequence_length_at_index[inner_index] + 1;
                previous_index[index] = inner_index;
            }
        if (sequence_length_at_index[index] > sequence_length_at_index[best_index])
            best_index = index;
    }
    int sequence_values[N], sequence_length = 0;
    for (int index = best_index; index >= 0; index = previous_index[index])
        sequence_values[sequence_length++] = values[index];
    printf("長度：%d\n序列：", sequence_length);
    for (int index = sequence_length - 1; index >= 0; index--)
        printf("%d%c", sequence_values[index], index ? ' ' : '\n');
    return 0;
}
