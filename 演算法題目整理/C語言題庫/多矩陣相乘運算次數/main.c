/*
 * 【初學者詳細導讀】
 * 【這題要做什麼】矩陣相乘的結果相同，但括號順序會改變乘法次數；本程式找出最省乘法的括號順序。
 * 【輸入】矩陣數 n，再輸入 n+1 個維度 p0 到 pn；矩陣 Ai 的大小為
 * p(i-1)×pi。【輸出】最少純量乘法次數與括號順序。
 * 【閱讀順序】dp[i][j] 是連乘 Ai 到 Aj 的最低成本。對每個區間長度
 * len，試所有切割點
 * k；成本是左半成本、右半成本，加上最後合併兩個結果矩陣的乘法次數。cut
 * 保存最佳切點；show 依 cut 遞迴輸出括號。 【C 語法】LLONG_MAX 是 long long
 * 可表示的最大值，先當作「還沒找到答案」；遞迴函式會呼叫自己處理較小區間。
 *
 * 【共通讀法】程式從 main 開始執行。scanf 依格式讀入資料，printf 將答案印到螢幕；for/while
 * 重複執行大括號中的步驟。C 陣列索引從 0 開始。遇到函式時，可把它當成一段有名字、可重複使用的工作。
 */
/* 輸入矩陣數 n，再輸入 n+1 個維度 p0..pn；輸出最少純量乘法次數與括號順序。 */
#include <limits.h>
#include <stdio.h>
#define N 101
long long minimum_cost[N][N];
int split_point[N][N];
void show(int index, int last_matrix) {
    if (index == last_matrix) {
        printf("A%d", index);
        return;
    }
    putchar('(');
    show(index, split_point[index][last_matrix]);
    show(split_point[index][last_matrix] + 1, last_matrix);
    putchar(')');
}
int main(void) {
    /* 先讀取並檢查輸入；接著依導讀中的演算法處理資料，最後輸出結果。 */
    int matrix_count, dimensions[N];
    if (scanf("%d", &matrix_count) != 1 || matrix_count < 1 || matrix_count >= N)
        return 1;
    for (int index = 0; index <= matrix_count; index++)
        if (scanf("%d", &dimensions[index]) != 1 || dimensions[index] <= 0)
            return 1;
    for (int chain_length = 2; chain_length <= matrix_count; chain_length++)
        for (int index = 1; index + chain_length - 1 <= matrix_count; index++) {
            int last_matrix = index + chain_length - 1;
            minimum_cost[index][last_matrix] = LLONG_MAX;
            for (int split_index = index; split_index < last_matrix; split_index++) {
                long long candidate_cost = minimum_cost[index][split_index] +
                                           minimum_cost[split_index + 1][last_matrix] +
                                           (long long)dimensions[index - 1] *
                                               dimensions[split_index] * dimensions[last_matrix];
                if (candidate_cost < minimum_cost[index][last_matrix])
                    minimum_cost[index][last_matrix] = candidate_cost,
                    split_point[index][last_matrix] = split_index;
            }
        }
    printf("最少乘法次數：%lld\n順序：", minimum_cost[1][matrix_count]);
    show(1, matrix_count);
    putchar('\n');
    return 0;
}
