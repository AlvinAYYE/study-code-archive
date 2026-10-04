/*
 * 【初學者詳細導讀】
 * 【這題要做什麼】找出數列中最長的嚴格遞增子序列。子序列可以跳過元素，但保留原本先後順序；嚴格遞增表示後一個數必須更大。
 * 【輸入】n 及 n
 * 個整數。【輸出】一組最長子序列及其長度；同長時程式偏好元素總和較小的序列。
 * 【閱讀順序】k[i] 是以 a[i] 結尾的最佳長度；sum[i]
 * 是該最佳序列的總和；pre[i] 記錄前一個元素索引。對每個 i，往前找比
 * a[i] 小的元素，嘗試接上它的最佳序列。最後從最佳終點沿 pre 倒走，再反向印出。
 * 【C 語法】pre=-1 表示沒有前一個元素；long long sum[]
 * 保存總和；更新時先比長度，長度相同再比總和。
 *
 * 【共通讀法】程式從 main 開始執行。scanf 依格式讀入資料，printf 將答案印到螢幕；for/while
 * 重複執行大括號中的步驟。C 陣列索引從 0 開始。遇到函式時，可把它當成一段有名字、可重複使用的工作。
 */
/* 輸入 n 與 n 個整數；輸出嚴格遞增 LIS，最長長度相同時取總和較小者。 */
#include <stdio.h>
#define N 5000
int main(void) {
    /* 先讀取並檢查輸入；接著依導讀中的演算法處理資料，最後輸出結果。 */
    int value_count, values[N], length_at_index[N], previous_index[N], best_index = -1;
    long long sequence_sum[N];
    if (scanf("%d", &value_count) != 1 || value_count < 1 || value_count > N)
        return 1;
    for (int index = 0; index < value_count; index++) {
        if (scanf("%d", &values[index]) != 1)
            return 1;
        length_at_index[index] = 1;
        previous_index[index] = -1;
        sequence_sum[index] = values[index];
        for (int inner_index = 0; inner_index < index; inner_index++)
            if (values[inner_index] < values[index]) {
                int candidate_length = length_at_index[inner_index] + 1;
                long long candidate_sum = sequence_sum[inner_index] + values[index];
                if (candidate_length > length_at_index[index] ||
                    (candidate_length == length_at_index[index] &&
                     candidate_sum < sequence_sum[index])) {
                    length_at_index[index] = candidate_length;
                    sequence_sum[index] = candidate_sum;
                    previous_index[index] = inner_index;
                }
            }
        if (best_index < 0 || length_at_index[index] > length_at_index[best_index] ||
            (length_at_index[index] == length_at_index[best_index] &&
             sequence_sum[index] < sequence_sum[best_index]))
            best_index = index;
    }
    int sequence[N], sequence_length = 0;
    for (int current_index = best_index; current_index != -1;
         current_index = previous_index[current_index])
        sequence[sequence_length++] = values[current_index];
    printf("長度：%d\n序列：", sequence_length);
    for (int index = sequence_length - 1; index >= 0; index--)
        printf("%d%c", sequence[index], index ? ' ' : '\n');
    return 0;
}
