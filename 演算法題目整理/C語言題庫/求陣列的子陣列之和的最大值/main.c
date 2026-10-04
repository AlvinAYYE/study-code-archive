/*
 * 【初學者詳細導讀】
 * 【這題要做什麼】在整數陣列中，找出總和最大的「連續」區段。連續表示中間的元素不能跳過。
 * 【輸入】整數 n，接著輸入 n 個整數。n 必須在 1 到 1,000,000 之間。
 * 【輸出】最大區段和，以及區段起點、終點的 0 起始索引。
 * 【閱讀順序】cur 是「必須以目前位置結尾」的最大和；best
 * 是目前看過的最大和。走到新數字時，比較「從新數字重新開始」與「接在舊區段後面」哪個較大，再更新
 * best。這就是 Kadane 演算法，時間複雜度 O(n)。 【C 語法】long long 可存比 int
 * 更大的總和；a[i] 的索引從 0 到 n-1；bs、be
 * 記錄最佳區段的起點和終點。
 *
 * 【共通讀法】程式從 main 開始執行。scanf 依格式讀入資料，printf 將答案印到螢幕；for/while
 * 重複執行大括號中的步驟。C 陣列索引從 0 開始。遇到函式時，可把它當成一段有名字、可重複使用的工作。
 */
/* 輸入 n 和 n 個整數；Kadane 演算法輸出最大連續子陣列和與 0-based 起訖索引。 */
#include <stdio.h>
#define MAXN 1000000
int main(void) {
    /* 先讀取並檢查輸入；接著依導讀中的演算法處理資料，最後輸出結果。 */
    int value_count;
    static int values[MAXN];
    if (scanf("%d", &value_count) != 1 || value_count < 1 || value_count > MAXN)
        return 1;
    for (int index = 0; index < value_count; index++)
        if (scanf("%d", &values[index]) != 1)
            return 1;
    long long current_sum = values[0], maximum_sum = values[0];
    int current_start = 0, best_start = 0, best_end = 0;
    for (int index = 1; index < value_count; index++) {
        if ((long long)values[index] > current_sum + values[index]) {
            current_sum = values[index];
            current_start = index;
        } else
            current_sum += values[index];
        if (current_sum > maximum_sum) {
            maximum_sum = current_sum;
            best_start = current_start;
            best_end = index;
        }
    }
    printf("最大和：%lld\n起訖索引：%d %d\n", maximum_sum, best_start, best_end);
    return 0;
}
